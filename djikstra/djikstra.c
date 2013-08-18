#include <stdio.h>
#include <stdlib.h>
#include "djikstra.h"

int traverse(int array[7][7], int loc, int target, int dist,int init, int *distances){
	/* DEFUNCT! DO NOT USE */
	/* returns 0 every time on purpose */
	return 0;
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

int traverse2(int array[7][7], int start, int end, int *visited, int visitsize, int visdex, int distance){
	int i;
	int tempdistance = 0;
	int tempvisdex = visdex;
	int tempvisited[49];
	for(i = 0; i < 49; i++){
		tempvisited[i] = visited[i];
	}
	int options[7];
	printf("Is current node (%d) already visited: %d\n", start, contains(start, visited, visitsize));
	//printarray(visited, visdex, "visited");
	if(contains(start, visited, visitsize)){
		//printf("Already visited here.\n");
		return 0;
	}else if(start == end){
		visited[visdex] = end;
		visdex++;
		printf("Path: start --> ");
		for(i = 0; i < visdex; i++){
			printf("%d --> ", visited[i]);
		}
		printf("end\n");
		//printf("distance: %d\n", distance);
		return distance;
	}else{
		printf("Continuing from %d\n", start);
		tempvisited[tempvisdex] = start;
		tempvisdex++;
		//printarray(tempvisited, tempvisdex, "visited");
		for(i = 0; i < 7; i++){
			//printf("%d ", i);
			tempdistance = 0;
			if(array[start][i] > 0){
				//printf("true\n");
				tempdistance = distance + array[start][i];
				//printf("distance: %d, array: %d\n", distance, array[start][i]);
				options[i] = traverse2(array, i, end, tempvisited, visitsize, tempvisdex, tempdistance);
			}
			//printf("\n");
		}
		tempdistance = 100;
		for(i = 0; i < 7; i++){
			printf("%d\n", tempdistance);
			if(options[i] > 0 && options[i] < tempdistance){
				tempdistance = options[i];
			}
		}
		return tempdistance;
	}
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

int printarray(int *array, int size, char *name){
	int i;
	for(i = 0; i <= size; i++){
		printf("%s[%d]: %d\n",name, i, array[i]);
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
	printarray(distances, size, "distances");
	return temp;
}

int contains(int i, int *array, int size){
	int j;
	for(j = 0; j < size; j++){
		if(array[j] == i){
			return 1;
		}
	}
	return 0;
}