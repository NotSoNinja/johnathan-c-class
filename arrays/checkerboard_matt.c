#include <stdio.h>

void print2dArray(int xSize, int ySize, char array[xSize][ySize]);

int main(int argc, char **argv) {
	const int SIZE = 80;
	int x, y;
	char array[SIZE][SIZE];

	for (x = 0; x < SIZE; x++) {
		for (y = 0; y < SIZE; y++) {
			if (x % 2 == y % 2) {
				array[x][y] = '#';
			} else {
				array[x][y] = ' ';
			}
		}
	}

	print2dArray(SIZE, SIZE, array);
}

void print2dArray(int xSize, int ySize, char array[xSize][ySize]) {
	int x, y;
	for (x = 0; x < xSize; x++) {
		for (y = 0; y < ySize; y++) {
			printf("%c", array[x][y]);
		}
		printf("\n");
	}
}