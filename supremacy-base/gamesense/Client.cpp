#include "Includes.h"
Client g_cl{ };

ulong_t __stdcall Client::Initialize( void* arg )
{

	// if not in interwebz mode, the driver will not set the username.
	g_cl.m_user = XOR( "User" );

	if ( !g_csgo.Initialize( ) )
		return 0;

	// welcome the user.
	g_notify.add( tfm::format( XOR( "Welcome, %s\n" ), g_cl.m_user ) );


	return 1;

}

void Client::OnPaint( )
{

		// update screen size.
	g_csgo.m_engine->GetScreenSize( m_width, m_height );

	// render stuff.
	//g_visuals.think( );
	//g_grenades.paint( );
	g_notify.think( );

	//DrawHUD( );
	//KillFeed( );

	// menu goes last.
	g_gui.think( );

}

void Client::Print( const std::string text, ... )
{

	va_list     list;
	int         size;
	std::string buf;

	if( text.empty( ) )
		return;

	va_start( list, text );

	// count needed size.
	size = std::vsnprintf( 0, 0, text.c_str( ), list );

	// allocate.
	buf.resize( size );

	// print to buffer.
	std::vsnprintf( buf.data( ), size + 1, text.c_str( ), list );

	va_end( list );

	// print to console.
	g_csgo.m_cvar->ConsoleColorPrintf( g_gui.m_color, XOR( "[gamesense] " ) );
	g_csgo.m_cvar->ConsoleColorPrintf( Colors::white, buf.c_str( ) );

}