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
	
	printArray(arr1, TOAD);
	printArray(arr2, TOAD);
}

void printArray(int toPrint[], int size){
	int index; 
	for(index = 0; index < size; index++){	
		printf("%d, ", toPrint[index]);
	}
}