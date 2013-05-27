#include <stdio.h>

int main(void) {
	int i;
	int j=0, k=1, l;

	for (i = 0; i < 10; i++) {
		printf("%d\n", j);
		l = k;
		k = k + j;
		j = l;
	}
}