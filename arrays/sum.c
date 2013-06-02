#include <stdio.h>

int main(int argc, char **argv) {
	const int TOAD = 1000;

	int sum = 0, i;

	for (i = 1; i <= TOAD; i++) {
		sum += i;
	}

	printf("%d\n", sum);
}