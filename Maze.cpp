//#include <iostream>
//#include <string>
#include <QueueList.h>
#include "Maze.h"

using namespace std;

#define mazeSize 6

// main maze array 
// maze[x][y] gives the presumed distance from (x, y) to the origin.
Block maze[mazeSize][mazeSize];
Block currentBlock;
Block previousBlock;

int currentX; //x location
int currentY; //y location
int currentDir; //current direction
int minDist;
int nextDir = NORTH;

QueueList <Block> queue;
int qIndex = 0;
Block stack[mazeSize * mazeSize];
int sPos = 0;

int main()
{
	//initializeMaze();
	//createTestMaze();
	//printMaze();

	//makeMove();

	int x = 0;
	return 0;
}

/* Makes a move*/
void makeMove()
{
	currentBlock = maze[currentY][currentX];

	nextDir = getNextDir(currentBlock);
	moveToDir(nextDir);

	minDist = getMinDistance(currentBlock);

	if ((currentBlock.weight - 1) < minDist) {
		currentBlock.weight = minDist + 1;
		pushNeighborsToStack(currentBlock);
		floodFill();
	}
}

void moveToDir(int direction)
{
	switch (direction)
	{
	case NORTH:
		moveForward();
		break;
	case SOUTH:
		moveBackward();
		break;
	case EAST:
		moveRight();
		break;
	case WEST:
		moveLeft();
		break;
	}
}

//get the next direction the mouse should head to based on current location
int getNextDir(Block blk)
{
	//mouse should head to neightbor with the smallest weight where there is no wall preventing it
	//we're moving from big to small
	int dir = 0;
	if (blk.eastWall && blk.westWall && !blk.northWall) {
		dir = NORTH;
	}
	else if (blk.eastWall && !blk.westWall && blk.northWall) {
		dir = WEST;
	}
	else if (!blk.eastWall && blk.westWall && blk.northWall) {
		dir = EAST;
	}
	else {
		//head south
		dir = SOUTH;
	}

	return dir;
}

void createTestMaze()
{
	//row 0
	maze[0][2].southWall = true;
	maze[0][3].southWall = true;
	maze[0][4].southWall = true;

	//row 1
	maze[1][0].eastWall = true;
	maze[1][1].westWall = true;
	maze[1][2].northWall = true;
	maze[1][2].southWall = true;
	maze[1][3].northWall = true;
	maze[1][3].southWall = true;
	maze[1][4].northWall = true;
	maze[1][5].southWall = true;

	//row 2
	maze[2][0].eastWall = true;
	maze[2][1].westWall = true;
	maze[2][2].northWall = true;
	maze[2][3].northWall = true;
	maze[2][5].northWall = true;
	maze[2][5].southWall = true;

	//row 3
	maze[3][0].southWall = true;
	maze[3][1].northWall = true;
	maze[3][1].eastWall = true;
	maze[3][2].westWall = true;
	maze[3][2].southWall = true;
	maze[3][3].southWall = true;
	maze[3][3].eastWall = true;
	maze[3][4].westWall = true;
	maze[3][4].southWall = true;
	maze[3][5].northWall = true;

	//row 4
	maze[4][0].northWall = true;
	maze[4][1].eastWall = true;
	maze[4][2].westWall = true;
	maze[4][2].northWall = true;
	maze[4][3].northWall = true;
	maze[4][3].eastWall = true;
	maze[4][4].westWall = true;
	maze[4][4].northWall = true;

	//row 5
	maze[5][0].eastWall = true;
	maze[5][1].westWall = true;
	maze[5][2].eastWall = true;
	maze[5][3].westWall = true;
	maze[5][4].eastWall = true;
	maze[5][5].westWall = true;
}

/*
* Instansiates the maze.
* It sets the weight and the cordinate of each block.
*/
void initializeMaze()
{
	for (int y = 0; y < mazeSize; y++) {
		for (int x = 0; x < mazeSize; x++) {
			//left walls
			if (x == 0 && y < mazeSize) {
				maze[y][x].westWall = true;
			}
			//right walls
			if (x == (mazeSize - 1) && y < mazeSize) {
				maze[y][x].eastWall = true;
			}
			//top wall
			if (y == 0 && x < mazeSize) {
				maze[y][x].northWall = true;
			}
			//bottom wall
			if (y == (mazeSize - 1) && x < mazeSize) {
				maze[y][x].southWall = true;
			}

			maze[y][x].y = y;
			maze[y][x].x = x;
			maze[y][x].weight = calculateCenter(x, y);
		}
	}
	//set position
	currentX = 0;
	currentY = 5;
	currentDir = NORTH;
}

//finds how far a block is from the center
//this distance is the weight
int calculateCenter(int x, int y)
{
	int center = (mazeSize / 2);
	int weight = 0;
	int top = center - 1;

	//top side of maze
	if (y <= top) {
		//top left maze
		if (x <= top) {
			weight = calculateWeight(x, y, (center - 1), (center - 1));
		}
		else {
			//top right
			weight = calculateWeight(x, y, center, (center - 1));
		}
	}
	//bottom of maze
	else {
		//bottom left
		if (x <= top) {
			weight = calculateWeight(x, y, (center - 1), center);
		}
		else {
			//bottom right
			weight = calculateWeight(x, y, center, center);
		}
	}
	return weight;
}

/*
* Calcuate the distance of a cell from the center
*/
int calculateWeight(int x, int y, int desiredX, int desitedY)
{
	return abs(desitedY - y) + abs(desiredX - x);
}

int getMinDistance(Block b)
{
	int md = mazeSize * mazeSize;
	int ini = mazeSize * mazeSize * mazeSize;
	int mds[] = { ini,ini,ini,ini };
	int posX = b.x;
	int posY = b.y;

	if (!b.northWall) {
		if (maze[posY + 1][posX].weight < md) {
			mds[0] = maze[posY + 1][posX].weight;
		}
	}

	if (!b.westWall) {
		if (maze[posY][posX - 1].weight < md) {
			mds[1] = maze[posY][posX - 1].weight;
		}
	}

	if (!b.eastWall) {
		if (maze[posY][posX + 1].weight < md) {
			mds[2] = maze[posY][posX + 1].weight;
		}
	}

	if (!b.southWall) {
		if (maze[posY - 1][posX].weight < md) {
			mds[3] = maze[posY - 1][posX].weight;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (mds[i] < md) {
			md = mds[i];
		}
	}
	
	return md;
}

//push currentBlock neighbors to stack
void pushNeighborsToStack(Block b)
{
	int x, y;
	if (!b.westWall) {
		x = b.x - 1;
		y = b.y;

		if (maze[y][x].weight != 0) {
			queue.push(maze[y][x]);
		}
	}

	if (!b.northWall) {
		x = b.x;
		y = b.y + 1;
		if (maze[y][x].weight != 0) {
			queue.push(maze[y][x]);
		}
	}

	if (!b.eastWall) {
		x = currentBlock.x+1;
		y = currentBlock.y;
		if (maze[y][x].weight != 0) {
			queue.push(maze[y][x]);
		}
	}

	if (!b.southWall) {
		x = currentBlock.x;
		y = currentBlock.y - 1;
		if (maze[y][x].weight != 0) {
			queue.push(maze[y][x]);
		}
	}
}

/*
* Prints out the maze for debugging purposes
*/
void printMaze()
{
	for (int y = 0; y < mazeSize; y++) {
		//first loop print north wall's
		for (int x = 0; x < mazeSize; x++) {
			printf("+");
			if (maze[y][x].northWall) {
				printf("------");
			}
			else {
				printf("      ");
			}
		}
		printf("+\n");

		//second loop, print left/right wall and weight
		for (int x = 0; x < mazeSize; x++) {
			//left wall
			if (x == 0 && maze[y][x].westWall) {
				printf("|");
			}

			printf("  %d  ", maze[y][x].weight);

			if (currentX == x && currentY == y) {
				printf("^");
			}
			else {
				printf(" ");
			}

			if (maze[y][x].eastWall) {
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	int end = 0;
	while (end != mazeSize) {
		printf("+------");
		end++;
	}
	printf("+\n");
}

//print contents of the stack
void printStack()
{
	int i = 0;
	int end = mazeSize * mazeSize;
	while (i < end && i != sPos) {
		printf("|  %d  |", stack[i].weight);
		i++;
	}
}

//push block onto the stack
/*
void push(Block b)
{
	sPos++;
	stack[sPos] = b;
}

//remove last block from the stack
Block pop()
{
	Block b = stack[sPos];
	sPos--;
	return b;
}
*/

//move the mouse forward
//idea: these type of functions should also update the current x or y position instead of the trackPosition function
void moveForward()
{
	//update currentX and currentY;
	//todo: add code here
}

void moveBackward()
{
	//update currentX and currentY;
}

void moveLeft()
{
	//update currentX and currentY;
}

void moveRight()
{
	//update currentX and currentY;
}

//updates weight of current cell and neighboring blocks
void floodFill()
{
	Block b;
	int md;
	while (!queue.isEmpty()) {
		b = queue.pop();
		md = getMinDistance(b);

		if ((b.weight - 1) < md) {
			b.weight = md + 1;
			pushNeighborsToStack(b);
			floodFill();
		}
	}

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

