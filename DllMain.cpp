#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>


// Note: This is the DLL entry point which is called by Windows when the
//		 DLL is first loaded into a processes address space or unloaded
//		 from the process address space. This function also be called for
//		 each thread owned by the process, but this has been disabled
//		 for efficiency reasons by the DisableThreadLibraryCalls during
//		 the first time the method is run.
// Note: You most likely do NOT need to edit this and unless you really
//		 know what you're doing you probably shouldn't.

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH) 
	{
		DisableThreadLibraryCalls(hinstDLL);
	}

    return TRUE;
}