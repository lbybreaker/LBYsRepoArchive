#pragma once

class AimbotTab : public Tab
{
public:
	Checkbox	  Enable;
	Dropdown	  TargetSelection;
	MultiDropdown TargetHitbox;
	MultiDropdown MultiPoint;
	Slider        StomachHitboxScale;
	Checkbox	  AutoFire;
	Checkbox      AutoPen;
	Checkbox	  SilentAim;
	Slider        MinHitchance;
	Slider        MinDamage;
	Checkbox      OverrideAWP;
	Checkbox      AutoScope;
	Checkbox      ReduceAimStep;
	Slider		  MaxFOV;
	Checkbox      LogSpreadMisses;
	MultiDropdown FPSMitigations;

	Checkbox      RemoveSpread;
	Checkbox      RemoveRecoil;
	Dropdown      AccuracyBoost;
	Dropdown      QuickStop;
	Checkbox      QuickPeek;
	Checkbox      AntiAimCorrection;
	Keybind       ForceBodyAim;
	Keybind       DuckPeekAssist;
	Keybind       Doubletap;

public:
	void Init( )
	{
		SetTitle( "Aimbot" );

		Enable.setup( XOR( "Enable" ), XOR( "Enable" ) );
		RegisterElement( &Enable );

		TargetSelection.setup( XOR( "Target selection" ), XOR( "TargetSelection" ), { XOR( "Cycle" ), XOR( "Cycle (2x)" ), XOR( "Near crosshair" ), XOR( "Highest damage" ), XOR( "Lowest ping" ), XOR( "Highest K/D ratio" ), XOR( "Best hit chance" ) } );
		RegisterElement( &TargetSelection );

		TargetHitbox.setup( XOR( "Target hitbox" ), XOR( "TargetHitbox" ), { XOR( "Head" ), XOR( "Chest" ), XOR( "Stomach" ), XOR( "Arms" ), XOR( "Legs" ), XOR( "Feet" ), } );
		RegisterElement( &TargetHitbox );

		MultiPoint.setup( XOR( "Multi-point" ), XOR( "MultiPoint" ), { XOR( "uh" ), XOR( "idk what this one is" ) } );
		RegisterElement( &MultiPoint );

		StomachHitboxScale.setup( XOR( "Stomach hitbox scale" ), XOR( "StomachHitboxScale" ), 0.f, 100.f, true, 0.f, 100.f, 1.f, XOR( L"%" ) );
		RegisterElement( &StomachHitboxScale );

		AutoFire.setup( XOR( "Automatic fire" ), XOR( "AutoFire" ) );
		RegisterElement( &AutoFire );

		AutoPen.setup( XOR( "Automatic penitration" ), XOR( "AutoPen" ) );
		RegisterElement( &AutoPen );

		SilentAim.setup( XOR( "Silent aim" ), XOR( "SilentAim" ) );
		RegisterElement( &SilentAim );

		MinHitchance.setup( XOR( "Minimum hitchance" ), XOR( "MinHitchance" ), 0.f, 100.f, true, 0.f, 50.f, 1.f, XOR( L"%" )  );
		RegisterElement( &MinHitchance );

		MinDamage.setup( XOR( "Minimum damage" ), XOR( "MinDamage" ), 0.f, 100.f, true, 0.f, 10.f, 1.f );
		RegisterElement( &MinDamage );

		OverrideAWP.setup( XOR( "Override AWP" ), XOR( "OverrideAWP" ) );
		RegisterElement( &OverrideAWP );

		AutoScope.setup( XOR( "Auto scope" ), XOR( "AutoScope" ) );
		RegisterElement( &AutoScope );

		ReduceAimStep.setup( XOR( "Reduce aim step" ), XOR( "ReduceAimStep" ) );
		RegisterElement( &ReduceAimStep );
	
		MaxFOV.setup( XOR( "Maximum FOV" ), XOR( "MaxFOV" ), 0.f, 180.f, true, 0.f, 180.f, 1.f );
		RegisterElement( &MaxFOV );

		LogSpreadMisses.setup( XOR( "Log misses due to spread" ), XOR( "LogSpreadMisses" ) );
		RegisterElement( &LogSpreadMisses );

		FPSMitigations.setup( XOR( "FPS Mitigations" ), XOR( "FPSMitigations" ), { XOR( "uh" ), XOR( "idk what this one is" ) } );
		RegisterElement( &FPSMitigations );


		RemoveSpread.setup( XOR( "Remove spread" ), XOR( "RemoveSpread" ) );
		RegisterElement( &RemoveSpread, 1 );

		RemoveRecoil.setup( XOR( "Remove recoil" ), XOR( "RemoveRecoil" ) );
		RegisterElement( &RemoveRecoil, 1 );

		AccuracyBoost.setup( XOR( "Accuracy boost" ), XOR( "AccuracyBoost" ), { XOR( "Off" ), XOR( "Low" ), XOR( "Medium" ), XOR( "High" ), XOR( "Maximum" ) } );
		RegisterElement( &AccuracyBoost, 1 );

		QuickStop.setup( XOR( "Quick stop" ), XOR( "QuickStop" ), { XOR( "Off" ), XOR( "uh" ) } );
		RegisterElement( &QuickStop, 1 );

		QuickPeek.setup( XOR( "Quick peek" ), XOR( "QuickPeek" ) );
		RegisterElement( &QuickPeek, 1 );

		AntiAimCorrection.setup( XOR( "Anti-aim correction" ), XOR( "AntiAimCorrection" ) );
		RegisterElement( &AntiAimCorrection, 1 );

		ForceBodyAim.setup( XOR( "Force body aim" ), XOR( "ForceBodyAim" ) );
		RegisterElement( &ForceBodyAim, 1 );

		DuckPeekAssist.setup( XOR( "Duck peek assist" ), XOR( "DuckPeekAssist" ) );
		RegisterElement( &DuckPeekAssist, 1 );

		Doubletap.setup( XOR( "Double tap" ), XOR( "Doubletap" ) );
		RegisterElement( &Doubletap, 1 );

	}
};

class AntiAimTab : public Tab
{
public:
	Checkbox Enable;

public:
	void Init( )
	{

		SetTitle( "Anti-Aim" );

		Enable.setup( XOR( "Enable" ), XOR( "Enable" ) );
		RegisterElement( &Enable );

	}
};

class LegitTab : public Tab
{
public:

public:
	void Init( )
	{

		SetTitle( "Legit" );

	}
};

class VisualsTab : public Tab
{
public:

public:
	void Init( )
	{
		SetTitle( "Visuals" );
	}
};

class MiscTab : public Tab
{
public:
	
	Keybind	    MenuKey;
	Colorpicker menu_color;
	Checkbox    AntiUntrusted;
	Checkbox    AntiOBS;
	Checkbox    LowFPSWarning;
	Dropdown    config;
	Keybind	    key1;
	Keybind     key2;
	Keybind     key3;
	Keybind	    key4;
	Keybind	    key5;
	Keybind     key6;
	Button      save;
	Button      load;

public:

	void Init( ) {
		SetTitle( XOR( "Miscellaneous" ) );

		MenuKey.setup( XOR( "Menu key" ), XOR( "MenuKey" ), 0x2D );
		RegisterElement( &MenuKey, 1 );

		menu_color.setup( XOR( "Menu color" ), XOR( "menu_color" ), Colors::lime_green, &g_gui.m_color );
		RegisterElement( &menu_color, 1 );

		AntiUntrusted.setup( XOR( "Anti-untrusted" ), XOR( "AntiUntrusted" ) );
		RegisterElement( &AntiUntrusted, 1 );

		AntiOBS.setup( XOR( "Hide from OBS" ), XOR( "AntiOBS" ) );
		RegisterElement( &AntiOBS, 1 );

		LowFPSWarning.setup( XOR( "Low FPS warning" ), XOR( "LowFPSWarning" ) );
		RegisterElement( &LowFPSWarning, 1 );

		config.setup( XOR( "Presets" ), XOR( "Presets" ), { XOR( "Legit" ), XOR( "2" ), XOR( "3" ), XOR( "4" ), XOR( "5" ), XOR( "6" ) } );
		config.RemoveFlags( ElementFlags::SAVE );
		RegisterElement( &config, 1 );

		key1.setup( XOR( "Configuration key 1" ), XOR( "cfg_key1" ) );
		key1.RemoveFlags( ElementFlags::SAVE );
		key1.SetCallback( Callbacks::SaveHotkeys );
		key1.AddShowCallback( Callbacks::IsConfig1 );
		key1.SetToggleCallback( Callbacks::ConfigLoad1 );
		RegisterElement( &key1, 1 );

		key2.setup( XOR( "Configuration key 2" ), XOR( "cfg_key2" ) );
		key2.RemoveFlags( ElementFlags::SAVE );
		key2.SetCallback( Callbacks::SaveHotkeys );
		key2.AddShowCallback( Callbacks::IsConfig2 );
		key2.SetToggleCallback( Callbacks::ConfigLoad2 );
		RegisterElement( &key2, 1 );

		key3.setup( XOR( "Configuration key 3" ), XOR( "cfg_key3" ) );
		key3.RemoveFlags( ElementFlags::SAVE );
		key3.SetCallback( Callbacks::SaveHotkeys );
		key3.AddShowCallback( Callbacks::IsConfig3 );
		key3.SetToggleCallback( Callbacks::ConfigLoad3 );
		RegisterElement( &key3, 1 );

		key4.setup( XOR( "Configuration key 4" ), XOR( "cfg_key4" ) );
		key4.RemoveFlags( ElementFlags::SAVE );
		key4.SetCallback( Callbacks::SaveHotkeys );
		key4.AddShowCallback( Callbacks::IsConfig4 );
		key4.SetToggleCallback( Callbacks::ConfigLoad4 );
		RegisterElement( &key4, 1 );

		key5.setup( XOR( "Configuration key 5" ), XOR( "cfg_key5" ) );
		key5.RemoveFlags( ElementFlags::SAVE );
		key5.SetCallback( Callbacks::SaveHotkeys );
		key5.AddShowCallback( Callbacks::IsConfig5 );
		key5.SetToggleCallback( Callbacks::ConfigLoad5 );
		RegisterElement( &key5, 1 );

		key6.setup( XOR( "Configuration key 6" ), XOR( "cfg_key6" ) );
		key6.RemoveFlags( ElementFlags::SAVE );
		key6.SetCallback( Callbacks::SaveHotkeys );
		key6.AddShowCallback( Callbacks::IsConfig6 );
		key6.SetToggleCallback( Callbacks::ConfigLoad6 );
		RegisterElement( &key6, 1 );

		save.setup( XOR( "Save" ) );
		save.SetCallback( Callbacks::ConfigSave );
		RegisterElement( &save, 1 );

		load.setup( XOR( "Load" ) );
		load.SetCallback( Callbacks::ConfigLoad );
		RegisterElement( &load, 1 );
	}
};

class SkinsTab : public Tab
{
public:

public:
	void Init( )
	{
		SetTitle( "Skins" );
	}
};

class PlayersTab : public Tab
{
public:

public:
	void Init( )
	{
		SetTitle( "Players" );
	}
};

class MainForm : public Form {
public:
	
	AimbotTab	  Aimbot;
	AntiAimTab    AntiAim;
	LegitTab      Legit;
	VisualsTab    Visuals;
	MiscTab		  Misc;
	SkinsTab	  Skins;
	PlayersTab    Players;

public:
	void init( ) {
		SetPosition( 50, 50 );
		SetSize( 660, 560 );

		// aim.
		RegisterTab( &Aimbot );
		Aimbot.Init( );

		RegisterTab( &AntiAim );
		AntiAim.Init( );

		RegisterTab( &Legit );
		Legit.Init( );

		RegisterTab( &Visuals );
		Visuals.Init( ); 

		RegisterTab( &Misc );
		Misc.Init( );

		RegisterTab( &Skins );
		Skins.Init( );
		
		RegisterTab( &Players );
		Players.Init( );

	}
};

class Menu {
public:
	MainForm Main;

public:
	void init( ) {
		Colorpicker::init( );

		Main.init( );
		g_gui.RegisterForm( &Main, Main.Misc.MenuKey.get( ) );
	}
};

extern Menu g_menu;