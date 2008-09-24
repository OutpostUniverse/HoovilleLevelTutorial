
// Note: We are using this file to define starting resource 
//		 and base/player starting locations. Building locations
//		 are given relative to some center. The idea is to define
//		 a base layout without specifying the base. This allows
//		 the same layout to be used to create multiple bases.
// Note: See OP2Helper.h for the definitions of the structures used
//		 here. As a general reminder, location (x and y coordinates)
//		 are given before other values and are typically the first two
//		 values in each structure.
// Note: The structure of this file was completely arbitrary
//		 and there is no requirement to do things the way they
//		 are done here. This is however a recommended method
//		 for designing resource and base layouts.


#include "..\OP2Helper\OP2Helper.h"

// Used to make autosizing the arrays easier
#define numof(array) (sizeof(array)/sizeof(array[0]))
// Used to make specifying the size of the array and the array easier
#define autosize(array) numof(array), array



// Note: We are arbitrarily defining 5 components for each base here.
//		 Each component type is defined using relative coordinates to
//		 some center point (to be specified later). Essentially what we
//		 are doing is defining a base layout (for each of the 5 base 
//		 components seperately). This allows base components to be mixed
//		 and matched when specifying an overall base layout. In other
//		 words, you can specify a set a buildings once and two sets of
//		 vehicles to create two base layouts that share the same
//		 buildings (in the same relative positions) but have different
//		 starting units.
// Note: In this simple example, we are defining 4 seperate bases and not
//		 reusing any components of the base layouts. Furthur, to keep
//		 things simple, and fair for multiplayer, the base components are
//		 just reflections about the x and y axis. Also, we have (arbirarily)
//		 chosen the Command Center to be at the center of the base
//		 (relative coordinates (0,0)), which is of course the dead center
//		 of the bases we are defining.




// Note: Here we are defining the map resources. This includes
//		 all mining beacons, both common ore and rare ore, 
//		 fumaroles and magma vents.
// Note: For fumaroles and magma vents, not all fields make sense
//		 and should be set to -1.
// Note: For mining beacons, the last three fields are "rare",
//		 "bar", and "variant". Set rare = 0 to make the mine a common
//		 ore mine and rare = 1 to make the mine a rare ore mine.
//		 Set bar = 0 for a 3 bar mine, bar = 1 for a 2 bar mine,
//		 and bar = 2 for a 1 bar mine.
//		 The variant field controls which type of 1 bar, 2 bar, 
//		 or 3 bar mine is created. See Mines.txt from Sheets.vol 
//		 for details. Set variant = -1 to randomly select which 
//		 variant is created.
// Note: Here we are defining four sets of beacon layouts to be
//		 attached to each base layout. This allows the beacons to
//		 be automatically moved with the base if the base coordinates
//		 are changed. This is useful for specifying starting ore
//		 that each player should have, and helps maintain fairness.
// Note: One big list containing all the resources is not really
//		 the best idea. Such a list can be used to place beacons
//		 around the map that aren't associated with any starting
//		 location. However, specifying starting ore can lead to
//		 problems this way. If the ore needs to be randomized, you'll
//		 want to avoid having all the ore appear in one players base.
//		 If randomizing a list of seperate types of resources, you'll
//		 want to avoid all resources of the same type being picked.
//		 To avoid this, one of the best setups is to use seperate
//		 lists for the resources around each person's base, and
//		 to use seperate lists for each type of resource.

struct BeaconInfo beaconSet1[] = 
{
	{ 12,  -7, mapMiningBeacon, 0, 0, -1},
	{ 31,  17, mapMiningBeacon, 0, 0, -1},
	{ -9,  17, mapMiningBeacon, 1, 0, -1},
	{ 22,  -3, mapFumarole, -1, -1, -1},
};

struct BeaconInfo beaconSet2[] = 
{
	{ -2,  -7, mapMiningBeacon, 0, 0, -1},
	{-11,  30, mapMiningBeacon, 0, 0, -1},
	{  9,  17, mapMiningBeacon, 1, 0, -1},
	{-16,  -6, mapFumarole, -1, -1, -1},
};

struct BeaconInfo beaconSet3[] = 
{
	{ 12,   9, mapMiningBeacon, 0, 0, -1},
	{ 11, -29, mapMiningBeacon, 0, 0, -1},
	{ -9, -18, mapMiningBeacon, 1, 0, -1},
	{ 19,   2, mapFumarole, -1, -1, -1},
};

struct BeaconInfo beaconSet4[] = 
{
	{ -2,   9, mapMiningBeacon, 0, 0, -1},
	{-13, -30, mapMiningBeacon, 0, 0, -1},
	{  9, -18, mapMiningBeacon, 1, 0, -1},
	{-25,   5, mapFumarole, -1, -1, -1},
};



// Note: Here we define what buildings we want and their relative positions.
// Note: Due to a lack of field values, you can't specify the contents of
//		 factories here. Instead, you can either enter the location and type
//		 of the factory in a structure below search for the unit using
//		 a building enum after it has been created, or you can call
//		 CreateUnit directly rather than specifying the factory in one
//		 of the structures below. Either way gets you a unit class which
//		 may then be used to call Unit.SetFactoryCargo.
// Note: Due to lack of a field for specifying the weapon, you also may not
//		 be able to create Guard Posts here. You can either create Guard
//		 Posts manually by calling CreateUnit, or you can stuff in the 
//		 appropraite fields for a GuardPost in the vehicle section below.

struct BuildingInfo buildingSet1[] = 
{
	{ 0,  0, mapCommandCenter},
	{ 7,  7, mapStructureFactory},
	{ 7, -7, mapCommonOreSmelter},
	{-7, -7, mapTokamak},
	{-7,  7, mapStandardLab},
	{-7,  0, mapAgridome}
};

struct BuildingInfo buildingSet2[] = 
{
	{ 0,  0, mapCommandCenter},
	{-7,  7, mapStructureFactory},
	{-7, -7, mapCommonOreSmelter},
	{ 8, -7, mapTokamak},
	{ 7,  7, mapStandardLab},
	{ 7,  0, mapAgridome}
};

struct BuildingInfo buildingSet3[] = 
{
	{ 0,  0, mapCommandCenter},
	{ 7, -7, mapStructureFactory},
	{ 7,  7, mapCommonOreSmelter},
	{-7,  7, mapTokamak},
	{-7, -7, mapStandardLab},
	{-7,  0, mapAgridome}
};

struct BuildingInfo buildingSet4[] = 
{
	{ 0,  0, mapCommandCenter},
	{-7, -7, mapStructureFactory},
	{-7,  7, mapCommonOreSmelter},
	{ 8,  7, mapTokamak},
	{ 7, -7, mapStandardLab},
	{ 7,  0, mapAgridome}
};


// Note: Here we define the tubes connecting the buildings. These
//		 are specified as two (x,y) pairs for each end of the tube.
// Note: The tubes are built using the CreateTubeOrWallLine function
//		 defined in OP2Helper.cpp. This function allows bent lines of
//		 tubes to be constructed if the coordinates given don't
//		 represent a straigh horizontal or vertical line. In that case,
//		 tubes are built along two edges of the rectangle defined by
//		 the given coordinates. Which two sides of the rectangle are
//		 chosen is based on the order of the endpoints. (They are draw
//		 along the y1 and then the x2 coordinates). If it draws along
//		 the wrong sides of the rectangle, interchange the first (x,y)
//		 value pair with the second (x,y) value pair.
// Note: Below we are only defining tubes and no walls, but the
//		 process is exactly the same. 

struct TubeWallInfo tubeSet1[] = 
{
	{ 3,  0,  7, -4},	// Command Center to Smelter
	{ 7,  1,  7,  5},	// Command Center to Smelter joint to Structure Factory
	{-2,  0, -4,  0},	// Command Center to Agridome
	{-7,  2, -7,  5}	// Agridome to Standard Lab
};

struct TubeWallInfo tubeSet2[] = 
{
	{-2,  0, -7, -4},	// Command Center to Smelter
	{-7,  1, -7,  5},	// Command Center to Smelter joint to Structure Factory
	{ 3,  0,  5,  0},	// Command Center to Agridome
	{ 7,  2,  7,  5}	// Agridome to Standard Lab
};

struct TubeWallInfo tubeSet3[] = 
{
	{ 3,  0,  7,  5},	// Command Center to Smelter
	{ 7, -1,  7, -4},	// Command Center to Smelter joint to Structure Factory
	{-2,  0, -4,  0},	// Command Center to Agridome
	{-7, -2, -7, -5}	// Agridome to Standard Lab
};

struct TubeWallInfo tubeSet4[] = 
{
	{-2,  0, -7,  5},	// Command Center to Smelter
	{-7, -1, -7, -4},	// Command Center to Smelter joint to Structure Factory
	{ 3,  0,  5,  0},	// Command Center to Agridome
	{ 7, -2,  7, -5}	// Agridome to Standard Lab
};



// Note: Here we define the starting vehicles, their relative
//		 positions, what cargo/weapon they are carrying, and
//		 the direction they are facing at startup.
// Note: In this simple example, no vehicle has any starting
//		 cargo or weapon. To add cargo or weapon, replace the
//		 mapNone with the cargo or weapon type.
// Note: You can also specify Guard Posts in the vehicle list
//		 since the weapon could not be specified in the 
//		 building list. If you feel this is a cheap hack then
//		 you can also create the Guard Posts directly using
//		 a call to CreateUnit. (Yes, I admit this is a bit of
//		 a hack, but I don't want to add a field to the 
//		 BuildingInfo structure which can only be used by one
//		 building type and needs a dummy value filled in for
//		 all the other building types. Especially not when
//		 this list has all the required fields. )

struct VehicleInfo unitSet1[] = 
{
	{  4,  10, mapConVec,			mapNone, 3},
	{  7,  10, mapConVec,			mapNone, 1},
	{ 10,  -6, mapCargoTruck,		mapNone, 0},
	{ 10,  -4, mapCargoTruck,		mapNone, 1},
	{  8,  -4, mapCargoTruck,		mapNone, 2},
	{ 12,  -6, mapRoboSurveyor,		mapNone, 7},
	{ 12,  -4, mapRoboMiner,		mapNone, 7},
	{  3,   1, mapEarthworker,		mapNone, 1},
	{  3,  -1, mapRoboDozer,		mapNone, 7}
};

struct VehicleInfo unitSet2[] = 
{
	{ -5,  10, mapConVec,			mapNone, 1},
	{ -8,  10, mapConVec,			mapNone, 3},
	{ -4,  -6, mapCargoTruck,		mapNone, 0},
	{ -4,  -4, mapCargoTruck,		mapNone, 1},
	{ -6,  -4, mapCargoTruck,		mapNone, 2},
	{ -2,  -6, mapRoboSurveyor,		mapNone, 7},
	{ -2,  -4, mapRoboMiner,		mapNone, 7},
	{ -3,   1, mapEarthworker,		mapNone, 3},
	{ -3,  -1, mapRoboDozer,		mapNone, 5}
};

struct VehicleInfo unitSet3[] = 
{
	{  4,  -4, mapConVec,			mapNone, 3},
	{  7,  -4, mapConVec,			mapNone, 1},
	{ 10,   8, mapCargoTruck,		mapNone, 0},
	{ 10,  10, mapCargoTruck,		mapNone, 1},
	{  8,  10, mapCargoTruck,		mapNone, 2},
	{ 12,   8, mapRoboSurveyor,		mapNone, 1},
	{ 12,   6, mapRoboMiner,		mapNone, 1},
	{  3,  -1, mapEarthworker,		mapNone, 7},
	{  3,   1, mapRoboDozer,		mapNone, 1}
};

struct VehicleInfo unitSet4[] = 
{
	{ -5,  -4, mapConVec,			mapNone, 1},
	{ -8,  -4, mapConVec,			mapNone, 3},
	{ -4,   8, mapCargoTruck,		mapNone, 0},
	{ -4,  10, mapCargoTruck,		mapNone, 1},
	{ -6,  10, mapCargoTruck,		mapNone, 2},
	{ -2,   8, mapRoboSurveyor,		mapNone, 1},
	{ -2,   6, mapRoboMiner,		mapNone, 1},
	{ -3,  -1, mapEarthworker,		mapNone, 5},
	{ -3,   1, mapRoboDozer,		mapNone, 3}
};






// Note: Here we collect (any) five componets of base layout
//		 into a single layout for the entire base. 
// Note: We must specify the number of elements in each array
//		 so the creation functions know how many items to create
//		 This is partly a C++ limitation where detail like this
//		 isn't hidden from the programmer (since that info isn't
//		 associated with the array data itself). This array of
//		 structures has 10 fields which consist of 5 pairs of 
//		 (arraySize, arrayPointer). The macro autosize will take
//		 an array and output an (arraySize, arrayPointer) pair.
//		 If you don't use this macro, you must specify all fields
//		 yourself.
// Note: Since there are no walls, we are using a size of zero
//		 for the array and a null pointer to it (a null pointer
//		 is a value of 0). This is where the double zeros come 
//		 from below. The autosize macro can't be used to specify
//		 both these values since the autosize macro can't make
//		 use of a null array pointer. (Although, ideally it should
//		 output two zeros for you if passed a null pointer but
//		 I can't get this to work. If you know how, let me know.)

struct BaseInfo base[] = 
{
	{ autosize(beaconSet1), autosize(buildingSet1), autosize(tubeSet1), 0, 0, autosize(unitSet1) },
	{ autosize(beaconSet2), autosize(buildingSet2), autosize(tubeSet2), 0, 0, autosize(unitSet2) },
	{ autosize(beaconSet3), autosize(buildingSet3), autosize(tubeSet3), 0, 0, autosize(unitSet3) },
	{ autosize(beaconSet4), autosize(buildingSet4), autosize(tubeSet4), 0, 0, autosize(unitSet4) },
};



// Note: And finally, this is where we specify the actual bases.
//		 All we do is select a location for the base and a base
//		 layout defined above. All relative coordinates have the
//		 base coordinates defined here added to them before the
//		 Building, Tube, Wall, or Unit is placed.
// Note: The last parameter is a pointer to the array which defines
//		 the base layout.
// Note: You may want to randomize the locations of the bases before
//		 placing them. This will allow people to start at one of the
//		 random base locations in a multiplayer game. If this array is
//		 not randomized, then players will always start in the same
//		 place, depending on the order in which the join the game.
//		 See RandomizeStartingLocations in OP2Helper.cpp.
// Note: In our simple example, the Command Center is at the center of
//		 each base layout, so these coordinates will refer to the
//		 location of the Command Center.

struct StartLocation startLocation[] = 
{
	{ 49,  14, &base[0]},
	{142,  14, &base[1]},
	{ 49, 112, &base[2]},
	{142, 112, &base[3]}
};
