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
	char str1[] = {"This is a string."};
	printf("First use of arrays: %s\n", str1);
	
	int arr1[] = {0,1,2,3,4,5,6,7,8,9};
	int res = 0;
	int index;
	for(index = 0; index < 10; index++){
		res += arr1[index];
	}
	printf("Second use: the sum of the numbers 0-9: %d\n", res);
}
