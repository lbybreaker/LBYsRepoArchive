#pragma once
#pragma warning( disable : 4307 ) // '*': integral constant overflow
#pragma warning( disable : 4244 ) // possible loss of data
#pragma warning( disable : 4800 ) // forcing value to bool 'true' or 'false'
#pragma warning( disable : 4838 ) // conversion from '::size_t' to 'int' requires a narrowing conversion

// You can define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
#define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

using ulong_t = unsigned long;

// windows / stl includes.
#include <Windows.h>
#include <cstdint>
#include <intrin.h>
#include <xmmintrin.h>
#include <array>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <deque>
#include <functional>
#include <map>
#include <shlobj.h>
#include <filesystem>
#include <streambuf>

 // other includes.
#include "Misc/Hash.h"
#include "Misc/XORString.h"
#include "Misc/PE.h"
#include "Misc/WinAPI.h"
#include "Misc/Address.h"
#include "Misc/Utility.h"
#include "Misc/Modules.h"
#include "Misc/Pattern.h"
#include "Misc/VMT.h"
#include "Misc/NT.h"
#include "Misc/x86.h"
#include "Misc/SYSCall.h"
#include "Misc/Unique Vector.h"

#include "Misc/Base64.h"
#include "Misc/JSON.h"
#include "Misc/SDK/SDK.h"
#include "Misc/Interfaces.h"

 // hack includes.
 // nothing yet, check back later :3

