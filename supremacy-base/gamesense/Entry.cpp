#include "Includes.h"

int __stdcall DllMain( HMODULE self, ulong_t reason, void *reserved )
{

	if ( reason == DLL_PROCESS_ATTACH )
	{
	
		HANDLE Thread = CreateThread( nullptr, 0, Client::Initialize, nullptr, 0, nullptr );

		if ( !Thread )
			return 0;

		return 1;

	}

	return 0;

}