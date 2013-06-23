/* A program that reads a dictionary into memory, no matter the size.
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	/* copied from hangmanA3, reads in dictionary and counts words */
	char word[80];
	int i;
	char * dict; 
	char *errorCheck;
	char * * ptrs;
	char *tempword;
	
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
	rewind(dictionary);
	
	//new, works.
	dict = malloc(80 * numberOfWords * sizeof(char));
	ptrs = malloc(numberOfWords * sizeof(char *));
	if(NULL == dict || NULL == ptrs){
		printf("Null Pointer Exception\n");
		return 2;
	}
	for (i = 0; i < numberOfWords; i++) {
		errorCheck = fgets(word, sizeof(word), dictionary);
		word[strlen(word) - 1] = '\0';
		tempword = malloc(strlen(word) * sizeof(char));
		strcpy(tempword, word);
		*(ptrs+i) = tempword;
	}
	for (i = 0; i < numberOfWords; i++) {
		printf("%s\n", *(ptrs+i));
	}
	free(dict);
	return 0;
}