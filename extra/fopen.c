#include <stdio.h>

int main(int argc, char **argv) {
	FILE *dict;
	char buf[80];
	char word[80];

	if (argc == 2) {
		dict = fopen(argv[1], "r");
		while(fgets(buf, 80, dict)) {
			sscanf(buf, "%s", word);
			printf("%s\n", word);
		}
		fclose(dict);
	} else {
		printf("Usage:  %s <file>\n", argv[0]);
	}
}