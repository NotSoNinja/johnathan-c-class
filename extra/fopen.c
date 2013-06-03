#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadDictionary(char *, char ***);

int main(int argc, char **argv) {
	int fileLength;
	int i,j;
	char **dictionary;

	if (argc == 2) {
		fileLength = loadDictionary(argv[1], &dictionary);
		// printf("%p\n",*dictionary);
		// printf("%ld\n", sizeof(*dictionary));
		for (i = 0; i < fileLength; i++) {
			printf("%s\n", dictionary[i]);
		}
	} else {
		printf("Usage:  %s <dictionary file>\n", argv[0]);
		printf("(try /usr/share/dict/words)\n");
	}
}

int loadDictionary(char *dictionaryFile, char ***dictionary) {
	FILE *dict;
	char buf[80];
	char *word;
	int fileLength = 0;
	int i;

	dict = fopen(dictionaryFile, "r");
	while (fgets(buf, 80, dict)) {
		fileLength++;
	}
	rewind(dict);
	i = 0;
	printf("Allocating %ld bytes for dictionary pointer array.\n", sizeof(char *) * fileLength);
	*dictionary = malloc(sizeof(char *) * fileLength);
	if (*dictionary == 0) {
		printf("Error allocating memory for dictionary.\n");
	}
	while(fgets(buf, 80, dict)) {
		// printf("%ld\n", strlen(buf));
		word = (*dictionary)[i] = malloc(sizeof(char) * (strlen(buf) + 1));
		if (word == 0) {
			printf("Error allocating memory for word.\n");
		}
		sscanf(buf, "%s", word);
		// printf("%s\n", (*dictionary)[i]);
		i++;
	}
	fclose(dict);

	return fileLength;
}