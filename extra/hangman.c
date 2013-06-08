#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadDictionary(char *, char ***);
void startGame(char *);

int main(int argc, char **argv) {
	int fileLength;
	int i,j;
	char **dictionary;

	srandomdev();

	if (argc == 2) {
		fileLength = loadDictionary(argv[1], &dictionary);
		// printf("%p\n",*dictionary);
		// printf("%ld\n", sizeof(*dictionary));
		// for (i = 0; i < fileLength; i++) {
		// 	printf("%s\n", dictionary[i]);
		// }
		// printf("Random word of the day is %s\n", dictionary[random() % fileLength]);
		startGame(dictionary[random() % fileLength]);
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

void startGame(char *word) {
	int lettersRemaining = strlen(word);
	char guess;
	char *displayWord;
	int guessNumber = 0;
	int i;
	char buf[80];
	char guesses[80] = "";

	// printf("%s\n", word);

	displayWord = malloc(sizeof(char) * strlen(word) * 2);

	for (i = 0; i < lettersRemaining; i++) {
		displayWord[i*2] = '_';
		displayWord[i*2+1] = ' ';
	}

	while (lettersRemaining > 0) {
		printf("Guesses: %d\n", guessNumber);
		printf("Letters remaining: %d\n", lettersRemaining);
		printf("Already guessed:  %s\n", guesses);
		printf("%s\n", displayWord);

		fgets(buf, 80, stdin);
		sscanf(buf, "%c", &guess);
		
		if (!index(guesses, guess)) {
			guesses[strlen(guesses)] = guess;
			guessNumber++;
			if (index(word, guess)) {
				lettersRemaining = 0;
				for (i = 0; i < strlen(word); i++) {
					if (displayWord[i*2] == '_' && word[i] == guess) {
						displayWord[i*2] = word[i];
					} else if (displayWord[i*2] == '_') {
						lettersRemaining++;
					}
				}
			}
		} else {
			printf("You already guessed that!\n");
		}
	}

	printf("Done!  You took %d guesses!\n", guessNumber);
	printf("The word was %s\n", word);
}