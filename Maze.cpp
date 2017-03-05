// 
// Main Class to for the maze
// 

#include "Maze.h"
#include "Block.h"
#include <Block.cpp>

//Size of the maze
#define mazeSize 16

int locX; //x location
int locY; //y location

// main maze array 
// maze[x][y] gives the presumed distance from (x, y) to the origin.
int maze[mazeSize][mazeSize];
Block mazeBlocks[mazeSize][mazeSize];

Block currentBlock;
Block previousBlock;


/*
 * Initilze the maze to the deault values
 * A state of -1 indicates that the cordinate has not been mapped
 */
void initializeMaze()
{
	Block* block = new Block();
	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			maze[i][j] = -1;
			mazeBlocks[i][j].setDefaults();
		}
	}

	//set the current block to the first one
	currentBlock = mazeBlocks[0][0];
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

}


void moveToNextBlock()
{
	previousBlock = currentBlock;
	//get the current x and y coordinate and advance by 1 unit
}

// Iterates over the maze to find the shortest possible path to the center
void findShortestPath()
{

}

