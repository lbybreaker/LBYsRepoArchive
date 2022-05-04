#pragma once

// Padding macro, please use, counts pads in class automaticly
#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )
#define PAD( size ) uint8_t MACRO_CONCAT( _pad, __COUNTER__ )[ size ];

// Pre-Declares.
class Player;
class Weapon;
class Entity;
class WeaponInfo;
class matrix3x4_t;
class vec3_t;
class ang_t;

struct BoxTraceInfo_t;
struct CBaseTrace;

#include "Game.h"
#include "Math.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Angle.h"
#include "Matrix.h"
#include "BaseHandle.h"
#include "Color.h"
#include "UTLVector.h"
#include "ClientClass.h"
#include "DataMap.h"
#include "EntityList.h"
#include "ClientDLL.h"
#include "ClientMode.h"
#include "EngineClient.h"
#include "CVar.h"
#include "GlobalVars.h"
#include "Input.h"
#include "Surface.h"
#include "StudioHDR.h"
#include "Trace.h"
#include "Localize.h"