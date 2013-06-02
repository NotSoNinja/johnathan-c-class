#include <stdio.h>

void printArray (int [], int);

int main(int argc, char **argv) {
	const int TOAD = 1000;
	int a[TOAD], b[TOAD];
	int i;

	for (i = 0; i < TOAD; i++) {
		a[i] = i;
	}

	printf("Initial array: ");
	printArray(a, TOAD);

	for (i = 0; i < TOAD; i++) {
		b[(TOAD - i) - 1] = a[i];
	}
	printf("Reversed array: ");
	printArray(b, TOAD);

	return 0;
}

void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[i]);
}