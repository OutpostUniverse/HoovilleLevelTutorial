
// Library, API, Custom Imports
// ============================

#include <Outpost2DLL/Outpost2DLL.h>	// Main Outpost 2 header to interface with the game
#include <OP2Helper/OP2Helper.h>		// Optional header to make level building easier


// Note: ** Editing BaseData.cpp is a good way to build bases. **
// Declare the StartLocation array in BaseData.cpp. (So it is available in this file).
extern StartLocation startLocation[];


// Level Info Exports
// ==================

// Note: ** Be sure to set these when you build your own level **
// Note: These exports are required by Outpost2.exe from every level
//		 DLL. They give values for the map and tech trees used by the
//		 level and a description to place in the level listbox. The
//		 last export is used to define characteristics of the level.
//		 See RequiredExports.h for more details.
// Defines a Multiplayer Last-One-Standing 4 player game (the DLL must be named with a "ml4" prefix).
// Required data exports  (Description, Map, TechTree, GameType, NumPlayers)
ExportLevelDetails("4 Player, LastOne, 'Hooville' map", "on4_01.map", "MULTITEK.TXT", MultiLastOneStanding, 4)


// Global Script Data
// ==================

// Holder for global script variables (for Saved Game files)
// Note: ** Place any Global script variables in this following struct **
// Note: Any DLL variables in this struct will survive a game save/load.
//		 If your script needs to remember something from one tick/mark to another,
//		 it needs to go in here. If it's not in here, then it will be forgotten
//		 after saving and loading the game.
struct ScriptGlobal
{
};
ScriptGlobal scriptGlobal;		// Declare a global instance of the struct

// Outpost 2 learns about the global variable struct by calling the following function:
// Note: You probably won't ever need to edit this yourself.
// Note: Called by Outpost 2 to obtain an area of the DLL's memory that needs
//		 to be saved to (or loaded from) Saved Game files. (That is, script Global variables).
//		 Either or both of bufferStart and length can be safely set to 0.
// Note: Setting bufferStart to 0 means no data (including the buffer size)
//		 is read or written to saved game files. Setting bufferStart to
//		 non-zero, and length to 0, causes the length to be saved and
//		 loaded from saved game files. (Uses extra 4 bytes)
Export void GetSaveRegions(BufferDesc& bufferDesc)
{
	// Buffer for Saved Game files
	bufferDesc.bufferStart = &scriptGlobal;		// Store address of global variable struct
	bufferDesc.length = sizeof(scriptGlobal);	// Store size of global variable struct
}
// Note: The save/load system implies all global level data must be statically sized.
//		 It also means the level doesn't know when it's about to be saved,
//		 or when it was just loaded.


// Game Entry Point
// ================

// Note: ** Be sure to edit/fill in the following function. **
// Note: The following function is called once by Outpost2.exe when the
//		 level is first initialized. This is where you want to create
//		 all the initial units and structures as well as setup any 
//		 map/level environment settings such as day and night.
Export int InitProc()
{
	int i;
	int combatUnitX, combatUnitY;

	// Randomize starting locations
	RandomizeList(4, startLocation);	// Randomize (first) 4 starting locations
	// Place all bases on the map
	for (i = 0; i < TethysGame::NoPlayers(); ++i)
	{
		InitPlayerResources(i);				// Set resources for Player i
		CreateBase(i, startLocation[i]);	// Create a base for Player i, using their selected start location
		// Determine placement of combat units (1/4 way from start to center of map) and place them
		combatUnitX = (startLocation[i].x * 3 + 96) / 4;
		combatUnitY = (startLocation[i].y * 3 + 64) / 4;
		CreateInitialCombatUnits(i, combatUnitX, combatUnitY);
	}

	// Misc initialization
	TethysGame::CreateWreck(95, 63, (map_id)techTigerSpeedModification, false); // Not initially visible

	// Set morale conditions according to Uses Morale checkbox
	TethysGame::ForceMoraleGood(PlayerAll);
	if (TethysGame::UsesMorale())
		TethysGame::FreeMoraleLevel(PlayerAll);

	// Set map lighting conditions according to Uses Day/Night checkbox
	// Force daylight everywhere if they don't want to use day/night
	TethysGame::SetDaylightEverywhere(TethysGame::UsesDayNight() == 0);
	// Now for some fun...: if day/night is enabled, force night everywhere all the time =)
	TethysGame::SetDaylightMoves(false);	// Freeze position of day/night
	GameMap::SetInitialLightLevel(-32);		// Set daylight off the map, to feeze it in darkness

	// Optionally setup some random meteor disasters according to Uses Disasters checkbox
	if (TethysGame::CanHaveDisasters())
	{
		// Create a meteor every 2500-5000 ticks (25-50 marks)
		Trigger &meteorTrigger = CreateTimeTrigger(true, false, 2500, 5000, "CreateMeteor");
	}

	// Just use a stock victory condition from OP2Helper
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


// Trigger Call Backs
// ==================

// Note: To perform an action when a trigger fires (an event happens), 
//		 create a function, with a name matching what was passed to the trigger,
//		 of the following form:
// Export void CallBackNamePassedToTrigger()
// {
// }


// Empty dummy trigger used by victory condition (does nothing when event fires)
Export void NoResponseToTrigger()
{
}

// Note: ** Define your own trigger callbacks here **

Export void CreateMeteor()
{
	// Note: GetRand(x) returns a number in the range 0..(x-1)
	// The map used is 128x128 (and the bottom line doesn't seem to be used)
	int x = 32 + TethysGame::GetRand(128);			// Random x coordinate: x ranges from 32..(width+32)
	int y = TethysGame::GetRand(127);				// Random y coordinate: y ranges from 0..(height-2)
	int disasterSize = TethysGame::GetRand(3);		// Small, Medium, or Large

	// Create the meteor (which will appear in 10 ticks, to allow both warnings to be issued)
	TethysGame::SetMeteor(x, y, disasterSize);
}
