#include <stdio.h>

int main(int argc, char **argv) {
	const int arraySize = 6;
	int array[arraySize] = {0, 1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < arraySize; i++) {
		printf("array[%d]: %d\n", i, array[i]);
	}

	printf("\n");

	for (i = 0; i < arraySize; i++) {
		printf("*(array+%d): %d\n", i, *(array+i));
	}

	printf("\n");

	for (i = 0; i < arraySize; i++) {
		printf("array+%d: %p\n", i, array+i);
	}

	printf("\n");

	for (i = 0; i < arraySize; i++) {
		printf("%d+array: %p\n", i, i+array);
	}

	printf("\n");

	for (i = 0; i < arraySize; i++) {
		printf("*(%d+array): %d\n", i, *(i+array));
	}

	printf("\n");

	for (i = 0; i < arraySize; i++) {
		printf("%d[array]: %d\n", i, i[array]);
	}

	printf("\n");

	return 0;
}