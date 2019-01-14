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

struct Block
{
	int x = 0;
	int y = 0;
	int weight = -1;
	bool visited = false; //same as weight
	bool northWall = false;
	bool southWall = false;
	bool eastWall = false;
	bool westWall = false;
};

//Global variables
extern Block currentBlock;
extern bool doneMapping;

//functions
void makeMove();
void moveToDir(int direction);
int getNextDir(Block blk);

void createTestMaze();
void initializeMaze();

int calculateCenter(int x, int y);
int calculateWeight(int x, int y, int desiredX, int desitedY);
int getMinDistance(Block b);
void pushNeighborsToStack(Block b);
void printMaze();
void printStack();

//movements
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();

void floodFill();


#endif

