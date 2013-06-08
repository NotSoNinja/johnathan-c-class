#include <stdio.h>

int main(int argc, char **argv) {
	int a = 5, *b;
	void *c;
	c = &a;
	b = c;
	printf("%d\n", *b);

	return 0;
}