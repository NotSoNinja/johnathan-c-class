#include <stdio.h>

int main(void) {
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d\n", fibb(i));
	}
	return 0;
}

int fibb(i) {
	if (i == 0) {
		return 0;
	} else if (i == 1 || i == 2) {
		return 1;
	} else {
		return (fibb(i-1) + fibb(i-2));
	}
}