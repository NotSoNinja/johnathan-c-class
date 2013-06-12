//"You have to be able to do this and you have to go figure out how: read in the list of words in /usr/share/dict/words and print all the words that begin with a 'q'.  Go." -Matt Harris

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printHangman(int);
int notLowercase(char[]);

int main(){
	srandomdev();
	long int index;
	int difficulty;
	char usrIn[5];
	do{
		printf("\nEnter a number between 3 (easy) and 6 (hard) to determine your difficulty: ");
		fgets(usrIn, sizeof(usrIn), stdin);
		sscanf(usrIn,"%d", &difficulty);
	}while((difficulty > 6) || (difficulty < 3));
	
	char word[80];
	char *errorCheck;
	FILE * dictionary = fopen("/usr/share/dict/words", "r");
	if(!dictionary){
		printf("null dictionary\n");
		return 1;
	}
	long int numberOfWords = 0;
	
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		numberOfWords++;
	}while(errorCheck);
	int i;
	
	do{
		rewind(dictionary);
		index = (random() % (numberOfWords));
		for(i = 0; i <=index; i++){
			errorCheck = fgets(word, sizeof(word), dictionary);
		}
	}while((strlen(word) < difficulty) || (notLowercase(word)));
	
	word[strlen(word) - 1] = '\0';
	fclose(dictionary);
	char incorrectLetters[26] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
	char guessResults[50];
	for(i = 0; i < strlen(word); i++){
		if(i == (strlen(word) - 1)){
			guessResults[i] = '\0';
		}else{
			guessResults[i] = '_';
		}
	}
	int restart = 1;
	int correct = 0;
	do{
		correct = 0;
		printf("\n");
		printHangman(strlen(incorrectLetters));
		
		printf("\nIncorrect Letters: ");
		for(i = 0; i < strlen(incorrectLetters); i++){
			printf("%c ", incorrectLetters[i]);
		}
		
		printf("\nYour Guesses: ");
		for(i = 0; i < strlen(guessResults); i++){
			printf("%c ", guessResults[i]);
		}
		do{
			restart = 0;
			printf("\nEnter a single, lowercase letter: ");
			fgets(usrIn, sizeof(usrIn), stdin);
			usrIn[1] = '\0';
			if(notLowercase(usrIn)){
				printf("Please enter a lowercase letter next time.\n");
			}
			for(i = 0; i < strlen(incorrectLetters); i++){
				if(incorrectLetters[i] == usrIn[0] ){
					printf("You already guessed that!\n");
					restart = 1;
					break;
				}
			}
		}while(notLowercase(usrIn) || restart);
		
		for(i = 0; i < strlen(word); i++){
			if(word[i] == usrIn[0]){
				guessResults[i] = usrIn[0];
				correct = 1;
			}
		}
		if(!correct){
			strcat(incorrectLetters, usrIn);
		}
		
	}while(strcmp(guessResults, word) && strlen(incorrectLetters) < 6);
	if(strlen(incorrectLetters) >= 6){
		printHangman(6);
		printf("You Loose.\nThe word was: %s.\n", word);
	}else{
		printf("%s\n", guessResults);
		printf("You Win!");
	}
	return 0;
}

int printHangman(int failures){
	printf("\n----------+\n");
	switch(failures){
		case 0:
			printf("|\n|\n|\n|\n|\n--------------\n\n");
			break;
		case 1:
			printf("|         O\n|\n|\n|\n|\n--------------\n\n");
			break;
		case 2:
			printf("|         O\n|         |\n|         |\n|         ^\n|\n--------------\n\n");
			break;
		case 3:
			printf("|         O\n|      +--|\n|         |\n|         ^\n|\n--------------\n\n");
			break;
		case 4:
			printf("|         O\n|      +--|--+\n|         |\n|         ^\n|\n--------------\n\n");
			break;
		case 5:
			printf("|         O\n|      +--|--+\n|         |\n|         ^\n|        /\n--------------\n\n");
			break;
		case 6:
			printf("|         O\n|      +--|--+\n|         |\n|         ^\n|        / \\\n--------------\n\n");
			break;
		default:
			printf("You're calling printHangman with an invalid number!");
			return 1;
			break;
	}
	return 0;
}

int notLowercase(char word[]){
	int i;
	for(i = 0; i < strlen (word); i++){
		if((int)word[i] >= 97 && (int)word[i] <= 122){
			return 0;
		}
	}
	return 1;
}