#include <stdio.h>
#include "shuntyard.h"
#include "stacknqueue.h"

int main(int argc, char **argv) {
	printf("Running tests.\n\n");
	
	printf("Testing PEMDAS\n");
	char tests[5][2] = {
		{'+', '+'},
		{'+', '-'},
		{'-', '+'},
		{'+', '*'},
		{'+', '/'}
	};
	int i;
	
	for (i = 0; i <5; i++) {
		printf("Comparing %c and %c: %d\n", tests[i][0], tests[i][1], pemdas(tests[i][0], tests[i][1]));
	}
	return 0;
}