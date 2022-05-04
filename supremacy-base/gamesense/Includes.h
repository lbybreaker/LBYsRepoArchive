#pragma once

#pragma warning( disable : 4307 ) // '*': integral constant overflow
#pragma warning( disable : 4244 ) // possible loss of data
#pragma warning( disable : 4800 ) // forcing value to bool 'true' or 'false'
#pragma warning( disable : 4838 ) // conversion from '::size_t' to 'int' requires a narrowing conversion

// You can define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
#define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

using ulong_t = unsigned long;

// Windows / STL includes.
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

// Our custom wrapper.
#include "Unique Vector.h"
#include "TinyFormat.h"

// Other includes.
#include "Hash.h"
#include "XORString.h"
#include "PE.h"
#include "WinAPI.h"
#include "Address.h"
#include "Utilities.h"
#include "Modules.h"
#include "Pattern.h"
#include "VMT.h"
#include "Stack.h"
#include "NT.h"
#include "x86.h"

// Hack includes.
#include "Interfaces.h"
#include "SDK.h"
#include "CSGO.h"
#include "Netvars.h"
#include "EntityOffsets.h"
#include "Entity.h"
#include "Client.h"
#include "Hooks.h"
#include "Render.h"
#include "Notify.h"

// gui includes.
#include "JSON.h"
#include "Base64.h"
#include "Element.h"
#include "Checkbox.h"
#include "Dropdown.h"
#include "MultiDropdown.h"
#include "Slider.h"
#include "Colorpicker.h"
#include "Edit.h"
#include "Keybind.h"
#include "Button.h"
#include "Tab.h"
#include "Form.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Menu.h"
#include "Config.h"