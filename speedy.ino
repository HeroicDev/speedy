#include <QueueList.h>
#include "Maze.h"


/*
  Potential Functions Needed
  1. To decided which move to make. eg moveForward, moveLeft, etx
  2. 

*/

void setup()
{
	/* add setup code here */
	Serial.begin(9600);
	initializeMaze();
}

/* add main program code here */
void loop()
{
  Serial.println("initializing maze");
	makeMove();
}
