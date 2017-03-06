// Maze.h

#ifndef _MAZE_h
#define _MAZE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

void initializeMaze();
Block currentBlock;


#endif

