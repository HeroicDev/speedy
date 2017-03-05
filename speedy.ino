#include "Maze.h"
#include "Block.h"
#include "MazeSolver.h"


/*
  Potential Functions Needed
  1. To decided which move to make. eg moveForward, moveLeft, etx
  2. 

*/

void setup()
{

  /* add setup code here */
	initializeMaze();

}

/* add main program code here */
void loop()
{
	//keep navigating the maze;
	while (currentBlock.unMapped()) {
		mapCurrentBlock();
		//moveToNextBlock();
	}

}
