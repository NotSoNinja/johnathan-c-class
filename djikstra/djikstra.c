#include <stdio.h>
#include <stdlib.h>

int traverse(int array[7][7], int loc, int target, int dist,int init, int *distances){
	int i;
	static int disdex;
	disdex = init;
	int temp;
	for(i = 0; i < 7; i++){
		if(disdex >99){
			return 0;
		}
		if(arrcmp(distances, disdex, dist)){
			return 0;
		}else if(loc == target && dist > 0){
			printf("Dist: %d\n", dist);
			distances[disdex] = dist;
			disdex++;
			return dist;
		}else if(dist > 100){
			return 0;
		}else if(array[loc][i] > 0){
			return traverse(array, i, target, dist + array[loc][i], disdex, distances);
		}
	}
	
	return dist;
}

int arrcmp(int *array, int length, int compare){
	int i;
	for(i = 0; i <= length; i++){
		if(compare < array[i]){
			return 1;
		}
	}
	return 0;
}

int printarray(int *array, int size){
	int i;
	for(i = 0; i <= size; i++){
		printf("Distances[%d]: %d\n",i, array[i]);
	}

	return 0;
}

int selectleast(int *distances, int size){
	int i;
	int temp;
	temp =  distances[0];
		for(i = 0; i < size; i++){
			if(distances[i] > 0){
				if(distances[i] < temp){
					temp = distances[i];
				}
			}
		}
	printarray(distances, size);
	return temp;
}