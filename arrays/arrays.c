/*
 *  arrays.c
 *  
 *
 *  Created by Johnathan on 6/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

void printArray(int [], int);
void print2DCharArray(int x, int y, char [x][y]);

int main(){
	const int TOAD = 1000;
	char str1[] = {"This is a string."};
	printf("First use of arrays: %s\n", str1);
	
	int index;
	int arr1[TOAD];
	for(index = 0; index < TOAD; index++){
		arr1[index] = index + 1;
	}
	
	int res = 0;
	
	for(index = 0; index < TOAD; index++){
		res += arr1[index];
	}
	
	int count = 0;
	int arr2[TOAD];
	for(index = TOAD - 1; index >=0; index--){
		arr2[count] = arr1[index];
		count++;
	}
	
	printf("Second use: the sum of the numbers 0-9: %d\n", res);
	
	print1DIntArray(arr1, TOAD);
	print1DIntArray(arr2, TOAD);
	const int X = 5;
	const int Y = 7;
	char art[5][7] = {{'H','H','H','H','H','H','H'},{' ',' ',' ','H',' ',' ',' '},{' ',' ',' ','H',' ',' ',' '},{' ',' ',' ','H',' ',' ',' '},{'H','H','H','H','H','H','H'}};
	print2DCharArray(X, Y, art);
}

void print1DIntArray(int toPrint[], int size){
	int index; 
	for(index = 0; index < size - 1; index++){	
		printf("%d, ", toPrint[index]);
	}
	printf("%d\n", toPrint[index]);
}

void print2DCharArray(int x, int y, char toPrint[x][y]){
	int xIndex;
	int yIndex;
	for(yIndex = 0; yIndex < y; yIndex++){
		for(xIndex = 0; xIndex < x; xIndex++){
			printf("%c", toPrint[xIndex][yIndex]);
		}
		printf("\n");
	}
	printf("\n");
}