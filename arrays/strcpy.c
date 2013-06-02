#include <stdio.h>

void string_copy(char [], char []);

int main(int argc, char **argv) {
	char a[] = "This is a test string.";
	char b[50];

	string_copy(a,b);

	printf("String a: %s\n", a);
	printf("String b: %s\n", b);

	return 0;
}

void string_copy(char a[], char b[]) {
	int i;
	for (i = 0; a[i]; i++) {
		b[i] = a[i];
	}
	b[i] = 0;
}