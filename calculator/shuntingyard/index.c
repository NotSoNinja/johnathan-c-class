#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char needle = 'x';
	char *haystack = "This is a test wherein we try to find where x marks the spot.";
	printf("%d\n", index(haystack, needle) - haystack);
	return 0;
}
