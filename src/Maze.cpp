/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include<stdbool.h>
int isMaze(int *maze, int rows, int columns, int x1, int y1, int x2, int y2);
int isFinal(int *maze, int rows, int columns, int x1, int y1, int x2, int y2,int *arr);

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int arr[30] = { 0 };
	
	return isFinal(maze, rows, columns, x1, y1, x2, y2, arr);
}
int isFinal(int *maze, int rows, int columns, int x1, int y1, int x2, int y2,int *arr){
	if (isMaze(maze, rows, columns, x1, y1, x2, y2) == 1)
	{
		if ((x1 == x2 && y1 == y2))
		{
			return 1;
		}
		else if (*((int *)arr + (x1*columns + y1)) == 1)
			return 0;
		if (isFinal(maze, rows, columns, x1, y1 + 1, x2, y2,arr) == 1) // move down
		{
			//	printf("(%d,%d)->",x1,y1+1,x2,y2);
			return 1;
		}
		if (isFinal(maze, rows, columns, x1 + 1, y1, x2, y2,arr) == 1) // move right
		{
			//	printf("(%d,%d)->",x1+1,y1,x2,y2);
			return 1;
		}
		(*((int *)arr + (x1*columns + y1))) = 1;
		if (isFinal(maze, rows, columns, x1, y1 - 1, x2, y2,arr) == 1) // move up
		{
			//printf("(%d,%d)->",x1,y1-1,x2,y2);
			return 1;
		}
		if (isFinal(maze, rows, columns, x1 - 1, y1, x2, y2,arr) == 1) // move left
		{
			//printf("(%d,%d)->",x1-1,y1,x2,y2);
			return 1;
		}
	}
	return 0;
}
int isMaze(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows >0 && columns >0 && x1 >= 0 && x1 < rows && y1 >= 0 && y1 < columns && x2 >= 0 &&
		x2 < rows && y2 >= 0 && y2 < columns && (*((int *)maze + (x1*columns + y1)) == 1))
		return 1;
	return 0;
}
