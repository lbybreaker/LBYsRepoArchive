#pragma once

class CSGO
{
public:
	// Prototypes.
	using MD5_PseudoRandom_t = uint32_t(__thiscall *)(uint32_t);
	using RandomSeed_t		 = void(__cdecl *)(int);
	using RandomInt_t		 = int(__cdecl *)(int, int);
	using RandomFloat_t		 = float(__cdecl *)(float, float);
	using AngleMatrix_t		 = void(__fastcall *)(const ang_t &, matrix3x4_t &);
	using GetEconItemView_t  = C_EconItemView * (__thiscall *)(Weapon *);
	using GetStaticData_t	 = CEconItemDefinition * (__thiscall *)(C_EconItemView *);
	using GetShotgunSpread_t = void(__stdcall *)(int, int, int, float *, float *);

public:
	
	bool m_done;

	// Modules.
	PE::Module kernel32_dll;
	PE::Module user32_dll;
	PE::Module shell32_dll;
	PE::Module shlwapi_dll;
	PE::Module client_dll;
	PE::Module engine_dll;
	PE::Module vstdlib_dll;
	PE::Module tier0_dll;
	PE::Module serverbrowser_dll;

public:
	// Interface ptrs.
	CHLClient*		   m_client;
	ICvar*			   m_cvar;
	IVEngineClient*    m_engine;
	IClientEntityList* m_entlist;
	IInputSystem*	   m_input_system;
	ISurface*		   m_surface;
	IPanel*			   m_panel;
	IEngineVGui*       m_engine_vgui;
	ILocalize*         m_localize;

	IClientMode		  *m_client_mode;
	CGlobalVarsBase   *m_globals;
	CInput			  *m_input;

	CGame			  *m_game;

public:
	// Convars.
	ConVar* mp_teammates_are_enemies;
	ConVar* weapon_accuracy_shotgun_spread_patterns;

public:
	// Functions.

	MD5_PseudoRandom_t	     MD5_PseudoRandom;
	Address                  SetAbsAngles;
	Address				     SetAbsOrigin;
	Address					 SetAbsVelocity;
	AngleMatrix_t            AngleMatrix;
	Address					 InvalidateBoneCache;
	Address					 LockStudioHDR;
	RandomSeed_t             RandomSeed;
	RandomInt_t              RandomInt;
	RandomFloat_t            RandomFloat;
	Address					 ComputeHitboxSurroundingBox;
	Address					 GetSequenceActivity;
	Address					 HasC4;
	Address                  InvalidatePhysicsRecursive;
	GetEconItemView_t        GetEconItemView;
	GetStaticData_t          GetStaticData;
	GetShotgunSpread_t       GetShotgunSpread;

	Address UTIL_TraceLine;
	Address CTraceFilterSimple_vmt;
	Address CTraceFilterSkipTwoEntities_vmt;
	
	size_t BoneAccessor;
	size_t AnimOverlay;
	size_t SpawnTime;
	size_t MostRecentModelBoneCounter;
	size_t LastBoneSetupTime;
	size_t IsLocalPlayer;
	size_t PlayerAnimState;
	size_t studioHdr;

public:
	// Initialize class.
	bool Initialize( );
};

extern CSGO g_csgo;