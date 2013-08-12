#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "djikstra.h"

int main(){
	int array[6] = {0};
	printf("1 is greater than any of the elements in an array filled with 0\n");
	assert(!arrcmp(array, 5, 1));
	printf("1 is not greater than an array filled with 2\n");
	int array2[6] = {2,3,5,11,7,18};
	assert(arrcmp(array2, 5, 1));
	int *distances = malloc(sizeof(int) * 100);
	int start = 0;
	int target = 6;
	int array3[7][7] = {
		{ 0,-1,-1,-1,-1, 1, 1},
		{-1, 0,-1,-1,-1,-1,-1},
		{-1,-1, 0,-1,-1,-1,-1},
		{-1,-1,-1, 0,-1,-1,-1},
		{-1,-1,-1,-1, 0,-1,-1},
		{ 1,-1,-1,-1,-1, 0,-1},
		{ 1,-1,-1,-1,-1,-1, 0}
	};
	int a = traverse(array3, 0, 6, 0, 0, distances);
	a = selectleast(distances, 100);
	printf("the shortest distance between 1 and 6 is 1\n");
	assert(1 == a);
	return 0;
}