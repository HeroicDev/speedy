/* 
 * Main Class to for the maze 
*/

//#include <QueueList.h>
#include "Maze.h"

#define mazeSize 16

// main maze array 
// maze[x][y] gives the presumed distance from (x, y) to the origin.

Block maze[mazeSize][mazeSize];
Block currentBlock;
Block previousBlock;

bool doneMapping = false;
int currentX; //x location
int currentY; //y location

//the stack
//Should be a stack of blocks not of ints
int stack[mazeSize * mazeSize];

/*
 * Initilze the maze to the deault values
 * A state of -1 indicates that the cordinate has not been mapped
 */
void initializeMaze()
{
	//set the center to 0
	//set neighbor cell from the center to ++

	//currentBlock.x = currentBlock.y = -1;
	// assuming the currentBlock is still the default block
	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {
			//currentBlock.x = j;
			//currentBlock.y = i;
			maze[i][j] = currentBlock;
		}
	}

	//set the current block to the first element
	currentBlock.x = currentBlock.y = 0;
	currentX = currentY = 0;
}

/* Updates the current position of the mouse*/
void trackPosition()
{
	//which way are we facing. either north, south, west, east
	//todo: @ade change these to use currentBlock object
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
	//set the positions to the blocks;
	currentBlock.x = currentX;
	currentBlock.y = currentY;
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
	previousBlock = currentBlock;

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

// Iterates over the maze to find the shortest possible path to the center
void findShortestPath()
{
	//we should maybe set a flag saying the maze has been fully mapped
	//starts from the top of the maze (0, 0) and tries to go from small to big in terms of weight
	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {

		}
	}
}

void printMaze()
{

}

/*
Notes - Flood Fill:
1. First assume there are no walls;
2. Give each cell a distance from the goal. The goal has distance 0
3. Repeat until we reach the goal
	- Go to the neighboring cell with the smallest distance to the goal
	- Run the update distance algorithm 

Maze Representation
	- Each cell has a distance (0 - 252 for 16 x 16 maze) and 4 walls (1 bit each).
	  You may also want to have a "visited" bit for speed runs
	- When you discorver a wall, you need to update it in the current cell and the 
	  neighboring cell
	- If you use the "visited" bit, then you don't need to run the floodfill update algorithm
	  on cells that you have visited already, meaning go faster

Debugging
	Have a printMaze function for debugging. 
	Use + for posts, --- for north/south walls, | for east/west walls, * for visited cell and space for no wall.
	Use <, >, ^, V for the direction of the mouse.
	Should look like
	+---+---+---+
	|*5  *4  V3 |
	+---+---+   +
	| 0   1   2 |
	+---+---+---+

Update distances algorithm (no recursion) using a stack
	- Make sure the stack is empty
	- If there are any new walls discovered:
	  - Push the current cell and the cell adjacent to the new wall onto the stack
	  - While the stack is not empty:
	    - currentCell = pop the top of the stack
		- The distance of currentCell should be minimum open neighbor distance + 1
		- If it's not, then set it to that value and push all the open neighbors to the stack

Tips
- Run your floodfill algorithm as soon as your mouse enters the cell not when it reaches the center of the cell
- Write a simulator in VS to test your function
  - Use green's maze generation excel sheet to create test mazes
- The stack for the update distances algorithm should be 512.
  - Note that it is possible to add a cell more than once, therefore 255 may not be enough
- Place your stack outside of any function (make it global)
  - You might run out of memory if you place large arrays inside a function
  - Global variables go into a region with more spaces
- Don't use recursion
  - it's slow on embedded systems and wastes a lot of memory than a stack-based method





*/

