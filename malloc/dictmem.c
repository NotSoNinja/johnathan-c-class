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
	int count = 0;
	char * dict; 
	char *errorCheck;
	char * * ptrs;
	
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
	dict = malloc(80 * numberOfWords * sizeof(char));
	ptrs = malloc(numberOfWords + sizeof(char *));
	if(NULL == dict || NULL == ptrs){
		printf("Null Pointer Exception\n");
		return 2;
	}
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		word[strlen(word) - 1] = '\0';
		strcpy((dict + index), word);
		ptrs[count] = &(dict + index);
		count++;
		index += 80;
	}while(errorCheck);
	index = 0;
	// causes bus error
	
	free(dict);
	return 0;
}