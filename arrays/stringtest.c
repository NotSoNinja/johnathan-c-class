#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char s[] = "This is a test string.";
	char sPrime[50];
	int i;

	strcpy(sPrime, s);

	printf("This is the copied string: %s\n", sPrime);
	
	for (i = 0; sPrime[i]; i++) {
		printf("%c", sPrime[i]);
	}
	printf("\n");

	return 0;
}