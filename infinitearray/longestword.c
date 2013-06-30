#include <stdio.h>
#include <string.h>

int main(){
	char word[80];
	char *errorCheck;
	int maxlen = 0;
	long int numberOfWords = 0;
	
	FILE * dictionary = fopen("/usr/share/dict/words", "r");
	if(!dictionary){
		printf("null dictionary\n");
		return 1;
	}
	
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		numberOfWords++;
		if(maxlen < strlen(word)){
			maxlen = strlen(word);
		}
	}while(errorCheck);
	printf("The longest word is %d characters long.\n", maxlen);
	return 0;
}