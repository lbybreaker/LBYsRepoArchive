#include "Includes.h"

bool Callbacks::IsConfigMM( ) {
	return g_menu.Main.Misc.AntiUntrusted.get( ) == 0;
}

bool Callbacks::IsConfigUT( ) {
	return g_menu.Main.Misc.AntiUntrusted.get( ) == 1;
}

bool Callbacks::IsConfig1( ) {
	return g_menu.Main.Misc.config.get( ) == 0;
}

bool Callbacks::IsConfig2( ) {
	return g_menu.Main.Misc.config.get( ) == 1;
}

bool Callbacks::IsConfig3( ) {
	return g_menu.Main.Misc.config.get( ) == 2;
}

bool Callbacks::IsConfig4( ) {
	return g_menu.Main.Misc.config.get( ) == 3;
}

bool Callbacks::IsConfig5( ) {
	return g_menu.Main.Misc.config.get( ) == 4;
}

bool Callbacks::IsConfig6( ) {
	return g_menu.Main.Misc.config.get( ) == 5;
}

void Callbacks::SaveHotkeys( ) {
	g_config.SaveHotkeys( );
}

void Callbacks::ConfigLoad1( ) {
	g_config.load( &g_menu.Main, XOR( "1.cfg" ) );
	g_menu.Main.Misc.config.select( 1 - 1 );

	g_notify.add( tfm::format( XOR( "Loaded config 1\n" ) ) );
}

void Callbacks::ConfigLoad2( ) {
	g_config.load( &g_menu.Main, XOR( "2.cfg" ) );
	g_menu.Main.Misc.config.select( 2 - 1 );
	g_notify.add( tfm::format( XOR( "Loaded config 2\n" ) ) );
}

void Callbacks::ConfigLoad3( ) {
	g_config.load( &g_menu.Main, XOR( "3.cfg" ) );
	g_menu.Main.Misc.config.select( 3 - 1 );
	g_notify.add( tfm::format( XOR( "Loaded config 3\n" ) ) );
}

void Callbacks::ConfigLoad4( ) {
	g_config.load( &g_menu.Main, XOR( "4.cfg" ) );
	g_menu.Main.Misc.config.select( 4 - 1 );
	g_notify.add( tfm::format( XOR( "Loaded config 4\n" ) ) );
}

void Callbacks::ConfigLoad5( ) {
	g_config.load( &g_menu.Main, XOR( "5.cfg" ) );
	g_menu.Main.Misc.config.select( 5 - 1 );
	g_notify.add( tfm::format( XOR( "Loaded config 5\n" ) ) );
}

void Callbacks::ConfigLoad6( ) {
	g_config.load( &g_menu.Main, XOR( "6.cfg" ) );
	g_menu.Main.Misc.config.select( 6 - 1 );
	g_notify.add( tfm::format( XOR( "Loaded config 6\n" ) ) );
}

void Callbacks::ConfigLoad( ) {
	std::string config = g_menu.Main.Misc.config.GetActiveItem( );
	std::string file   = tfm::format( XOR( "%s.cfg" ), config.data( ) );

	g_config.load( &g_menu.Main, file );
	g_notify.add( tfm::format( XOR( "Loaded config %s\n" ), config.data( ) ) );
}

void Callbacks::ConfigSave( ) {
	std::string config = g_menu.Main.Misc.config.GetActiveItem( );
	std::string file   = tfm::format( XOR( "%s.cfg" ), config.data( ) );

	g_config.save( &g_menu.Main, file );
	g_notify.add( tfm::format( XOR( "Saved config %s\n" ), config.data( ) ) );
}