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
	int visited[49] = {-1};
	int a = traverse2(array3, 0, 6, visited, 49, 0, 0);
	printf("%d\n", a);
	printf("the shortest distance between 0 and 6 is 1\n");
	assert(1 == a);
	// a = traverse(array3, 0, 6, 0, 0, distances);
	// a = selectleast(distances, 100);
	// printf("the shortest distance between 0 and 6 is 1\n");
	// assert(1 == a);
	int array4[7][7] = {
		{ 0,-1,-1,-1,-1, 2, 1},
		{-1, 0,-1, 1,-1, 3,-1},
		{-1,-1, 0,-1,-1,-1,-1},
		{-1, 1,-1, 0,-1,-1, 1},
		{-1,-1,-1,-1, 0,-1,-1},
		{ 2, 3,-1,-1,-1, 0,-1},
		{ 1,-1,-1, 1,-1,-1, 0}
	};
	int visited2[49] = {-1};
	a = traverse2(array4, 0, 1, visited2, 49, 0, 0);
	printf("%d\n", a);
	printf("the shortest distance between 0 and 1 is 3\n");
	assert(3 == a);
	return 0;
}