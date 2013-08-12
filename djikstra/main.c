#include <stdio.h>
#include <stdlib.h>
#include "djikstra.h"

int main(){
	int start = 0;
	int target = 6;
	int *distances = malloc(sizeof(int) * 100);
	int array[7][7] = {
		{0,3,6,-1,3,-1,-1},
		{3,0,-1,4,-1,-1,-1},
		{6,-1,0,1,-1,7,-1},
		{-1,4,1,0,-1,-1,7},
		{3,-1,-1,-1,0,8,-1},
		{-1,-1,7,-1,8,0,2},
		{-1,-1,-1,7,-1,2,0}
	};


	int shortpath = traverse(array, start, target, 0, 0, distances);
	
	printf("The shortest distance from %d to %d is %d\n", start, target, shortpath);
	return 0;
}