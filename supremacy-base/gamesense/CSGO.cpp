#include "Includes.h"
CSGO	   g_csgo{ };
WinAPI	   g_winapi{ };
Netvars	   g_netvars{ };
EntOffsets g_entoffsets{ };
Menu       g_menu{ };
Notify     g_notify{ };

bool CSGO::Initialize( )
{
	m_done = false;

	if ( m_done )
		return false;

	// Wait for the game to initizlize.
	// "serverbrowser.dll" is the last module to be loaded.
	// If it gets loaded we can be ensured that the entire game done loading.

	while ( !serverbrowser_dll )
	{
		serverbrowser_dll = PE::GetModule( HASH( "serverbrowser.dll" ) );

		if ( !serverbrowser_dll )
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
	
	// Grab modules.
	kernel32_dll = PE::GetModule( HASH( "kernel32.dll" ) );
	user32_dll   = PE::GetModule( HASH( "user32.dll" ) );
	shell32_dll  = PE::GetModule( HASH( "shell32.dll" ) );
	shlwapi_dll  = PE::GetModule( HASH( "shlwapi.dll" ) );
	client_dll   = PE::GetModule( HASH( "client.dll" ) );
	engine_dll   = PE::GetModule( HASH( "engine.dll" ) );
	vstdlib_dll  = PE::GetModule( HASH( "vstdlib.dll" ) );
	tier0_dll    = PE::GetModule( HASH( "tier0.dll" ) );

	// Import WinAPI functions.
	g_winapi.WideCharToMultiByte = PE::GetExport( kernel32_dll, HASH( "WideCharToMultiByte" ) ).as< WinAPI::WideCharToMultiByte_t >( );
	g_winapi.MultiByteToWideChar = PE::GetExport( kernel32_dll, HASH( "MultiByteToWideChar" ) ).as< WinAPI::MultiByteToWideChar_t >( );
	g_winapi.GetTickCount        = PE::GetExport( kernel32_dll, HASH( "GetTickCount" ) ).as< WinAPI::GetTickCount_t >( );
	g_winapi.VirtualProtect      = PE::GetExport( kernel32_dll, HASH( "VirtualProtect" ) ).as< WinAPI::VirtualProtect_t >( );
	g_winapi.VirtualQuery        = PE::GetExport( kernel32_dll, HASH( "VirtualQuery" ) ).as< WinAPI::VirtualQuery_t >( );
	g_winapi.CreateDirectoryA    = PE::GetExport( kernel32_dll, HASH( "CreateDirectoryA" ) ).as< WinAPI::CreateDirectoryA_t >( );
	g_winapi.SetWindowLongA      = PE::GetExport( user32_dll, HASH( "SetWindowLongA" ) ).as< WinAPI::SetWindowLongA_t >( );
	g_winapi.CallWindowProcA     = PE::GetExport( user32_dll, HASH( "CallWindowProcA" ) ).as< WinAPI::CallWindowProcA_t >( );
	g_winapi.SHGetFolderPathA    = PE::GetExport( shell32_dll, HASH( "SHGetFolderPathA" ) ).as< WinAPI::SHGetFolderPathA_t >( );
	g_winapi.PathAppendA         = PE::GetExport( shlwapi_dll, HASH( "PathAppendA" ) ).as< WinAPI::PathAppendA_t >( );

	// Run interface collection code.
	Interfaces Interfaces{ };

	m_client             = Interfaces.Get< CHLClient* >( HASH( "VClient" ) );
	m_cvar               = Interfaces.Get< ICvar* >( HASH( "VEngineCvar" ) );
	m_engine             = Interfaces.Get< IVEngineClient* >( HASH( "VEngineClient" ) );
	m_entlist            = Interfaces.Get< IClientEntityList* >( HASH( "VClientEntityList" ) );
	m_input_system       = Interfaces.Get< IInputSystem* >( HASH( "InputSystemVersion" ) );
	m_surface            = Interfaces.Get< ISurface* >( HASH( "VGUI_Surface" ) );
	m_panel              = Interfaces.Get< IPanel* >( HASH( "VGUI_Panel" ) );
	m_engine_vgui        = Interfaces.Get< IEngineVGui* >( HASH( "VEngineVGui" ) );
	m_localize           = Interfaces.Get< ILocalize* >( HASH( "Localize_" ) );
	
	// Convars.
	mp_teammates_are_enemies                = m_cvar->FindVar( HASH( "mp_teammates_are_enemies" ) );
	weapon_accuracy_shotgun_spread_patterns = m_cvar->FindVar( HASH( "weapon_accuracy_shotgun_spread_patterns" ) );

	// Classes by signature.
	m_game               = pattern::find( engine_dll, XOR( "A1 ? ? ? ? B9 ? ? ? ? FF 75 08 FF 50 34" ) ).add( 1 ).get< CGame* >( );

	// Classes by offset from virtual.
	m_globals     = Utilities::GetMethod( m_client, CHLClient::INIT ).add( 0x1b ).get< CGlobalVarsBase* >( 2 );
	m_client_mode = Utilities::GetMethod( m_client, CHLClient::HUDPROCESSINPUT ).add( 0x5 ).get< IClientMode* >( 2 );
	m_input       = Utilities::GetMethod( m_client, CHLClient::INACTIVATEMOUSE ).at< CInput* >( 0x1 );

	// Functions.

	MD5_PseudoRandom                = pattern::find( client_dll, XOR( "55 8B EC 83 E4 F8 83 EC 70 6A 58" ) ).as< MD5_PseudoRandom_t >( );
	SetAbsAngles                    = pattern::find( client_dll, XOR( "55 8B EC 83 E4 F8 83 EC 64 53 56 57 8B F1 E8" ) );
	InvalidateBoneCache             = pattern::find( client_dll, XOR( "80 3D ? ? ? ? ? 74 16 A1 ? ? ? ? 48 C7 81" ) );
	LockStudioHDR                   = pattern::find( client_dll, XOR( "55 8B EC 51 53 8B D9 56 57 8D B3" ) );
	SetAbsOrigin                    = pattern::find( client_dll, XOR( "55 8B EC 83 E4 F8 51 53 56 57 8B F1" ) );
	SetAbsVelocity                  = pattern::find( client_dll, XOR( "55 8B EC 83 E4 F8 83 EC 0C 53 56 57 8B 7D 08 8B F1" ) );
	AngleMatrix                     = pattern::find( client_dll, XOR( "E8 ? ? ? ? 8B 07 89 46 0C" ) ).rel32( 0x1 ).as< AngleMatrix_t >( );
	ComputeHitboxSurroundingBox     = pattern::find( client_dll, XOR( "E9 ? ? ? ? 32 C0 5D" ) ).rel32( 0x1 );
	GetSequenceActivity             = pattern::find( client_dll, XOR( "53 56 8B F1 8B DA 85 F6 74 55" ) );
	HasC4						    = pattern::find( client_dll, XOR( "E8 ? ? ? ? 38 83" ) ).rel32( 0x1 );
	InvalidatePhysicsRecursive      = pattern::find( client_dll, XOR( "E8 ? ? ? ? 89 5E 18" ) ).rel32( 0x1 );
	GetEconItemView                 = pattern::find( client_dll, XOR( "8B 81 ? ? ? ? 81 C1 ? ? ? ? FF 50 04 83 C0 40 C3" ) ).as< GetEconItemView_t >( );
	GetStaticData                   = pattern::find( client_dll, XOR( "55 8B EC 51 56 57 8B F1 E8 ? ? ? ? 0F B7 8E" ) ).as< GetStaticData_t >( );
	GetShotgunSpread                = pattern::find( client_dll, XOR( "E8 ? ? ? ? EB 38 83 EC 08" ) ).rel32< GetShotgunSpread_t >( 1 );
	BoneAccessor                    = pattern::find( client_dll, XOR( "8D 81 ? ? ? ? 50 8D 84 24" ) ).add( 2 ).to< size_t >( );
	AnimOverlay                     = pattern::find( client_dll, XOR( "8B 80 ? ? ? ? 8D 34 C8" ) ).add( 2 ).to< size_t >( );
	SpawnTime                       = pattern::find( client_dll, XOR( "F3 0F 5C 88 ? ? ? ? 0F" ) ).add( 4 ).to< size_t >( );
	IsLocalPlayer                   = pattern::find( client_dll, XOR( "74 ? 8A 83 ? ? ? ? 88" ) ).add( 4 ).to< size_t >( );

	UTIL_TraceLine                  = pattern::find( client_dll, XOR( "55 8B EC 83 E4 F0 83 EC 7C 56 52" ) );
    CTraceFilterSimple_vmt          = UTIL_TraceLine.add( 0x3D ).to( );
    CTraceFilterSkipTwoEntities_vmt = pattern::find( client_dll, XOR( "E8 ? ? ? ? F3 0F 10 84 24 ? ? ? ? 8D 84 24 ? ? ? ? F3 0F 58 44 24" ) ).rel32( 1 ).add( 0x59 ).to( );
	LastBoneSetupTime               = InvalidateBoneCache.add( 0x11 ).to< size_t >( );
	MostRecentModelBoneCounter      = InvalidateBoneCache.add( 0x1B ).to< size_t >( );
	
	// Exported Functions.
	RandomSeed  = PE::GetExport( vstdlib_dll, HASH( "RandomSeed" ) ).as< RandomSeed_t >( );
	RandomInt   = PE::GetExport( vstdlib_dll, HASH( "RandomInt" ) ).as< RandomInt_t >( );
	RandomFloat = PE::GetExport( vstdlib_dll, HASH( "RandomFloat" ) ).as< RandomFloat_t >( );


	// Some weird tier0 stuff that prevents me from debugging properly...
#ifdef _DEBUG
	Address DebugBreak = pattern::find( client_dll, XOR( "CC F3 0F 10 4D ? 0F 57 C0" ) );

	DWORD Old;
	g_winapi.VirtualProtect( DebugBreak, 1, PAGE_EXECUTE_READWRITE, &Old );

	DebugBreak.set< uint8_t >( 0x90 );

	g_winapi.VirtualProtect( DebugBreak, 1, Old, &Old );
#endif

	// Initialize everything else.

	g_config.init( );

	g_netvars.init( );
    g_entoffsets.init( );

	Render::init( );
	g_menu.init( );
	g_config.LoadHotkeys( );
	g_hooks.init( );

	m_done = true;
	return true;

}