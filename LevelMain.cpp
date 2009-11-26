#include <Outpost2DLL/Outpost2DLL.h>	// Main Outpost 2 header to interface with the game
#include <OP2Helper/OP2Helper.h>		// Optional header to make level building easier

// Note: Editing BaseData.cpp is a good way to build bases.
// Declare the StartLocation array in BaseData.cpp
extern StartLocation startLocation[];


// Note: These exports are required by Outpost2.exe from every level
//		 DLL. They give values for the map and tech trees used by the
//		 level and a description to place in the level listbox. The
//		 last export is used to define characteristics of the level.
//		 See RequiredExports.h for more details.
// Note: ** Be sure to set these when you build your own level**

// Required data exports  (Description, Map, TechTree, GameType, NumPlayers)
ExportLevelDetails("4 Player, LastOne, 'Hooville' map", "on4_01.map", "MULTITEK.TXT", MultiLastOneStanding, 4)


// Holder for global script variables (for Saved game files)
struct ScriptGlobal
{
};
ScriptGlobal scriptGlobal;


// Note: The following function is called once by Outpost2.exe when the
//		 level is first initialized. This is where you want to create
//		 all the initial units and structures as well as setup any 
//		 map/level environment settings such as day and night.

Export int InitProc()
{
	int i;

	// Randomize starting locations
	RandomizeList(4, startLocation);	// Randomize (first) 4 starting locations
	// Place all bases on the map
	for (i = 0; i < TethysGame::NoPlayers(); i++)
	{
		InitPlayerResources(i);
		CreateBase(i, startLocation[i]);
	}

	// Misc initialization
	TethysGame::CreateWreck(95, 63, (map_id)techTigerSpeedModification, false); // Not initially visible

	TethysGame::ForceMoraleGood(PlayerAll);
	if (TethysGame::UsesMorale())
		TethysGame::FreeMoraleLevel(PlayerAll);
	TethysGame::SetDaylightEverywhere(TethysGame::UsesDayNight() == 0);
	TethysGame::SetDaylightMoves(false);
	GameMap::SetInitialLightLevel(-32);

	CreateLastOneStandingVictoryCondition();

	return 1; // return 1 if OK; 0 on failure
}


// Note: The following function seems to be intended for use in
//		 controlling an AI. It is called once every game cycle. 
//		 Use it for whatever code needs to run on a continual basis.
// Note: The standard level DLLs released by Sierra leave this function
//		 empty and handle all AI controls through triggers.

Export void AIProc() 
{
}


// Note: Called by Outpost 2 to obtain an area of the DLL's memory that
//		 needs to be saved/loaded to/from Saved Game files.
//		 Either or both values can be safely set to 0.
// Note: Setting bufferStart to 0 means no data (including the buffer size)
//		 is read or written to saved game files. Setting bufferStart to
//		 non-zero, and length to 0, causes the length to be saved and
//		 loaded from saved game files. (Uses extra 4 bytes)
// Note: This system implies all global level data must be statically sized.
//		 It also means the level doesn't know when it's about to be
//		 saved, or when it was just loaded.

Export void GetSaveRegions(BufferDesc& bufferDesc)
{
	// Buffer for Saved Game files
	bufferDesc.bufferStart = &scriptGlobal;
	bufferDesc.length = sizeof(scriptGlobal);
}
