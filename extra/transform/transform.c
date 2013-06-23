#include <stdio.h>

int transform(int [], int, void (*)(int));
void printIt(int);

int main(int argc, char **argv) {
	int array[10];
	int i;
	void (*functionPtr)(int) = &printIt;

	for (i = 0; i < 10; i++) {
		array[i] = i;
	}

	transform(array, 10, functionPtr);

	return 0;
}

int transform(int array[], int size, void (*function)(int)) {
	int i;
	for (i = 0; i < size; i++) {
		(*function)(array[i]);
	}
}

void printIt(int item) {
	printf("%d\n", item);
}
