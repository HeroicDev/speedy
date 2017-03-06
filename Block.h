// Block.h

#ifndef _BLOCK_h
#define _BLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define DEFAULT_VALUE -1
	
class Block;

//Block object attributes
int x;
int y;
int weight;
bool westWall;
bool eastWall;
bool northWall;
bool southWall;

//Block Object functions
void setDefaults();
void setCoordinate(int xCord, int yCord);
bool unMapped();

#endif

