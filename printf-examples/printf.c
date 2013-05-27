#include <stdio.h>

int main(void) {
	int i;
	printf("%%d\t%%.2f\t%%x\t%%c\n");
	for (i = 0; i < 64; i++) {
		printf("%d\t%.2f\t%x\t%c\n", i, i+0.0, i, (char) i+65);
	}
}