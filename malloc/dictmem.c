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
	int index = 0;
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
	rewind(dictionary);
	
	//new, I think it might work?
	char * dict = malloc(80 * numberOfWords * sizeof(char));
	if(NULL == dict){
		printf("Null Pointer Exception\n");
		return 2;
	}
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		word[strlen(word) - 1] = '\0';
		strcpy((dict + index), word);
		index += 80;
	}while(errorCheck);
	index = 0;
	// causes bus error
	for(i = 0; i < numberOfWords; i++){
		printf("%s\n", );
		index += 80;
	}
	
	free(dict);
	return 0;
}