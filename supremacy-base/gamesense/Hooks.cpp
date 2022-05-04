#include "Includes.h"
Hooks g_hooks{ };

void Hooks::LockCursor( )
{
	if( g_gui.m_open ) {

		// un-lock the cursor.
		g_csgo.m_surface->UnlockCursor( );

		// disable input.
		g_csgo.m_input_system->EnableInput( false );
	}

	else {
		// call the original.
		g_hooks.m_surface.GetOldMethod< LockCursor_t >( ISurface::LOCKCURSOR )( this );

		// enable input.
		g_csgo.m_input_system->EnableInput( true );
	}
}

LRESULT WINAPI Hooks::WNDProc( HWND wnd, uint32_t msg, WPARAM wp, LPARAM lp ) {
	switch( msg ) {
	case WM_LBUTTONDOWN:
		g_input.SetDown( VK_LBUTTON );
		break;

	case WM_LBUTTONUP:
		g_input.SetUp( VK_LBUTTON );
		break;

	case WM_RBUTTONDOWN:
		g_input.SetDown( VK_RBUTTON );
		break;

	case WM_RBUTTONUP:
		g_input.SetUp( VK_RBUTTON );
		break;

	case WM_MBUTTONDOWN:
		g_input.SetDown( VK_MBUTTON );
		break;

	case WM_MBUTTONUP:
		g_input.SetUp( VK_MBUTTON );
		break;

	case WM_XBUTTONDOWN:
		if( GET_XBUTTON_WPARAM( wp ) == XBUTTON1 )
			g_input.SetDown( VK_XBUTTON1 );

		else if( GET_XBUTTON_WPARAM( wp ) == XBUTTON2 )
			g_input.SetDown( VK_XBUTTON2 );

		break;

	case WM_XBUTTONUP:
		if( GET_XBUTTON_WPARAM( wp ) == XBUTTON1 )
			g_input.SetUp( VK_XBUTTON1 );

		else if( GET_XBUTTON_WPARAM( wp ) == XBUTTON2 )
			g_input.SetUp( VK_XBUTTON2 );

		break;

	case WM_KEYDOWN:
		if( ( size_t )wp < g_input.m_keys.size( ) )
			g_input.SetDown( wp );

		break;

	case WM_KEYUP:
		if( ( size_t )wp < g_input.m_keys.size( ) )
			g_input.SetUp( wp );

		break;

	case WM_SYSKEYDOWN:
		if( wp == VK_MENU )
			g_input.SetDown( VK_MENU );

		break;

	case WM_SYSKEYUP:
		if( wp == VK_MENU )
			g_input.SetUp( VK_MENU );

		break;

	case WM_CHAR:
		switch( wp ) {
		case VK_BACK:
			if( !g_input.m_buffer.empty( ) )
				g_input.m_buffer.pop_back( );
			break;

		case VK_ESCAPE:
		case VK_TAB:
		case VK_RETURN:
			break;

		default:
			if( std::isdigit( static_cast< char >( wp ) ) )
				g_input.m_buffer += static_cast< char >( wp );

			break;
		}

		break;

	default:
		break;
	}

	return g_winapi.CallWindowProcA( g_hooks.m_old_wndproc, wnd, msg, wp, lp );
}

void Hooks::PaintTraverse( VPANEL panel, bool repaint, bool force )
{
	static VPANEL tools{}, zoom{};

	// cache CHudZoom panel once.
	if( !zoom && FNV1a::get( g_csgo.m_panel->GetName( panel ) ) == HASH( "HudZoom" ) )
		zoom = panel;

	// cache tools panel once.
	if( !tools && panel == g_csgo.m_engine_vgui->GetPanel( PANEL_TOOLS ) )
		tools = panel;

	// render hack stuff.
	if( panel == tools )
		g_cl.OnPaint( );

	// don't call the original function if we want to remove the scope.
	//if( panel == zoom && g_menu.Main.visuals.noscope.get( ) )
		//return;
		
	g_hooks.m_panel.GetOldMethod< PaintTraverse_t >( IPanel::PAINTTRAVERSE )( this, panel, repaint, force );

}

void Hooks::init( )
{

	// hook wndproc.
	m_old_wndproc = ( WNDPROC )g_winapi.SetWindowLongA( g_csgo.m_game->m_hWindow, GWL_WNDPROC, Utilities::ForceCast< LONG >( Hooks::WNDProc ) );

	// setup normal VMT hooks.
	m_panel.init( g_csgo.m_panel );
	m_panel.add( IPanel::PAINTTRAVERSE, Utilities::ForceCast( &Hooks::PaintTraverse ) );

	m_surface.init( g_csgo.m_surface );
	//m_surface.add( ISurface::GETSCREENSIZE, util::force_cast( &Hooks::GetScreenSize ) );
	m_surface.add( ISurface::LOCKCURSOR, Utilities::ForceCast( &Hooks::LockCursor ) );
	//m_surface.add( ISurface::PLAYSOUND, Utilities::ForceCast( &Hooks::PlaySound ) );
	//m_surface.add( ISurface::ONSCREENSIZECHANGED, Utilities::ForceCast( &Hooks::OnScreenSizeChanged ) );


}
