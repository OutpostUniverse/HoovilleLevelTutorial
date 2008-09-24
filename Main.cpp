#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

// Include important header files needed to interface with Outpost 2
#include "..\Outpost2DLL\Outpost2DLL.h"
// Include header files to make it easier to build levels
#include "..\OP2Helper\OP2Helper.h"

// Include base layout data
// Note: Editing this file is a good way to build bases.
#include "BaseData.h"



// Note: These exports are required by Outpost2.exe from every level
//		 DLL. They give values for the map and tech trees used by the
//		 level and a description to place in the level listbox. The
//		 last export is used to define characteristics of the level.
//		 See RequiredExports.h for more details.
//		 ** Be sure to set these when you build your own level**

char MapName[]			= "on4_01.map";							// The .map file used for this level
char LevelDesc[]		= "4 Player, LastOne, 'Hooville' map";	// Description appearing in the game list box
char TechtreeName[]		= "MULTITEK.TXT";						// File to use for the tech tree
SDescBlock DescBlock	= { MultiLastOneStanding, 4, 12, 0 }; // Important level details



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



// Note: The following function is called once by Outpost2.exe when the
//		 level is first initialized. This is where you want to create
//		 all the initial units and structures as well as setup any 
//		 map/level environment settings such as day and night.

int InitProc()
{
	int i;

	// Randomize starting locations
	RandomizeStartingLocations(autosize(startLocation));

	// Place all bases on the map
	for (i = 0; i < TethysGame::NoPlayers(); i++)
	{
		InitPlayerResources(i);

		StartLocation &sLoc = startLocation[i];
		CreateBase(i, sLoc.x, sLoc.y, *sLoc.baseInfo);
		Player[i].CenterViewOn(sLoc.x, sLoc.y);
	}


	// Misc initialization
	TethysGame::CreateWreck(95, 63, (map_id)11999, 0); // Tech #11999 - tiger speed upgrade

	TethysGame::ForceMoraleGood(-1);
	if (TethysGame::UsesMorale())
		TethysGame::FreeMoraleLevel(-1);
	TethysGame::SetDaylightEverywhere(TethysGame::UsesDayNight() == 0);
	TethysGame::SetDaylightMoves(0);
	GameMap::SetInitialLightLevel(-32);

	CreateLastOneStandingVictoryCondition();

	return 1; // return 1 if OK; 0 on failure
}


// Note: The following function seems to be intended for use in
//		 controlling an AI. It is called once every game cycle. 
//		 Use it for whatever code needs to run on a continual basis.
// Note: The standard level DLLs released by Sierra leave this function
//		 empty and handle all AI controls through triggers.

void AIProc() 
{
}


// Note: This function is called by Outpost2.exe to obtain a description
//		 of a buffer that is saved to saved game files. Outpost2.exe
//		 calls this function and passes it a pointer to a structure
//		 which describes this buffer. This function is required to set
//		 the fields of this structure. If no buffer needs to be saved
//		 to a saved game file, then the buffer pointer needs to be set
//		 to 0, and the length should also be set to 0.
// Note: This function is called once when the DLL is first initialized.
//		 This means that all data to be saved must have space reserved
//		 ahead of time at the start of the level. (Static sized storage)
//		 In other words, there is no way to dynamically grow the size of
//		 the buffer if more space is needed than originally specified.
// Note: You can probably stretch the above limitation by saving the
//		 pointer to the buffer description passed by Outpost2.exe. This
//		 may allow you to increase the buffer size dynamically but the
//		 idea is yet untested. Keep in mind that you have no idea when
//		 a game may be saved (or just loaded). 

void __cdecl GetSaveRegions(struct BufferDesc &bufDesc)
{
	bufDesc.bufferStart = 0;	// Pointer to a buffer that needs to be saved
	bufDesc.length = 0;			// sizeof(buffer)
}





// Note: These last two functions aren't absolutely required by a level
//		 but they found in almost all DLLs anyways.


// Note: This export usually exists, but does nothing other than return 0.
//		 It's use may have been for checking for victory/failure conditions
//		 that are not easily checked for by using triggers.

int StatusProc()
{
	return 0; // must return 0
}


// Note: This is a trigger callback function. This function is
//		 intentionally left empty and is used as the trigger
//		 callback function for triggers that don't want or need
//		 any special callback function.
// Note: The use of SCRIPT_API is used by all trigger functions
//		 to ensure they are exported correctly. (Although, 
//		 technically it's not needed in this case since this
//		 function has a function prototype defined in 
//		 RequiredExports.h which contains the SCRIPT_API macro
//		 in it. However, most other trigger callback functions
//		 won't have a function prototype anywhere (and you really
//		 don't need to declare a function prototype since you
//		 should never be calling a callback function yourself)
//		 so you should use the SCRIPT_API macro when you define
//		 the function.
//		 Might as well set a good example. =)

SCRIPT_API void NoResponseToTrigger()
{
}


