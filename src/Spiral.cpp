/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void generate_array(int **input_array, int rows, int columns, int seq);
int *spiral_final(int **input_array, int rows, int columns, int k, int index, int *arr);

int *spiral(int rows, int columns, int **input_array)
{
	//int *arr = (int *)malloc((rows*columns) * (sizeof(int)));
	if ((input_array == NULL) || (rows <= 0 || columns <= 0))
		return NULL;
	int index = 0;
	int *arr = (int *)malloc((rows*columns) * (sizeof(int)));
	int *output_array = spiral_final(input_array, rows, columns, 0, index, arr);
	return output_array;
}
int *spiral_final(int **input_array, int rows, int columns, int k, int index, int *arr){
	int j, i;
	int m = 0;
	if (rows == 1){
		for (j = 0; j < columns; j++){
			int local_5 = input_array[k][k + j];
			(*(arr + index)) = local_5;
			index++;
		}
		return arr;
	}
	if (columns == 1){
		for (j = 0; j < rows; j++){
			int local_6 = input_array[k + j][k];
			(*(arr + index)) = local_6;
			index++;
		}
		return arr;
	}
	for (j = 0; j < columns - 1; j++){
		int local_1 = input_array[k][k + j];
		(*(arr + index)) = local_1;

		index++;
	}
	for (i = 0; i < rows - 1; i++){
		int local_2 = input_array[k + i][k + columns - 1];
		(*(arr + index)) = local_2;
		index++;
	}

	for (j = 0; j < columns - 1; j++){
		int local_3 = input_array[k + rows - 1][k + columns - 1 - j];
		(*(arr + index)) = local_3;
		index++;
	}

	for (i = 0; i < rows - 1; i++){
		int local_4 = input_array[k + rows - 1 - i][k];
		(*(arr + index)) = local_4;
		index++;
	}
	spiral_final(input_array, rows - 2, columns - 2, k + 1, index, arr);
	return arr;
}