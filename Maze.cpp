// 
// Main Class to for the maze
// 

#include "Block.h"
#include "Maze.h"

//Size of the maze
#define mazeSize 16
#define mazeIsMapped false

int currentX; //x location
int currentY; //y location

// main maze array 
// maze[x][y] gives the presumed distance from (x, y) to the origin.
int maze[mazeSize][mazeSize];
Block mazeBlocks[mazeSize][mazeSize];

Block currentBlock;
Block previousBlock;
Block genericBlock;


/*
 * Initilze the maze to the deault values
 * A state of -1 indicates that the cordinate has not been mapped
 */
void initializeMaze()
{
	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			//mazeBlocks[i][j] = block;
		}
	}

	//set the current block to the first one
	currentBlock = mazeBlocks[0][0];
	currentX = currentY = 0;
}

/* Updates the current position of the mouse*/
void trackPosition()
{
	//which way are we facing. either north, south, west, east
	//todo: @ade change these to use currentBlock object
	// make void functions to increment and decrement x and y for a block
	int facing = NORTH;
	switch (facing) {
		case NORTH:
			currentY++;
			break;
		case SOUTH:
			currentY--;
			break;
		case WEST:
			currentX++;
			break;
		case EAST:
			currentX--;
			break;
	}
}

/* Makes a move*/
void makeMove()
{
	moveForward();
	trackPosition();
	mapCurrentBlock();
}

//move the mouse forward
//idea: these type of functions should also update the current x or y position instead of the trackPosition function
void moveForward()
{
	//todo: add code here
}

/* 
 * Read sensors to get the current (x, y) position of the mouse
*/
void getCoordinate()
{

}

/* 
 * Maps the current block by setting the cordinate and 
 * assiging an approprate weight to it
 */
void mapCurrentBlock()
{
	checkForWalls();
}

/*
 * Checks the current position for a wall
 */
void checkForWalls()
{
	//todo: read left, right, front sensors
	//idea: if the measured distance is < 10cm
}


void moveToNextBlock()
{
	previousBlock = currentBlock;
	//get the current x and y coordinate and advance by 1 unit
}

// Iterates over the maze to find the shortest possible path to the center
void findShortestPath()
{
	//we should maybe set a flag saying the maze has been fully mapped


}

