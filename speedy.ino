#include "Maze.h"


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
	//solve the maze if mouse is done mapping the maze
	if (doneMapping) {
		findShortestPath();
	}

	//keep navigating the maze;
	while (currentBlock.weight == -1) {
		mapCurrentBlock();
		//moveToNextBlock();
	}

}
