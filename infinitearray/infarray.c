#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char word[30];
	char *errorCheck;
	char *tempword;
	long int numberOfWords = 0;
	int index = 0;
	int numberofbuckets = 1;
	char * currentbucket;
	char * previousbucket; //only exists to help with printing backwards
	char * firstbucket;
	/* Bucket contains pointers to words
	 * infinite array is made of buckets
	 */
	struct bucket{
		char bucket[10 * sizeof(char *)];
		struct bucket *nextptr;
		struct bucket *prevptr;
	}
	
	firstbucket = malloc(sizeof(struct bucket));
	currentbucket = firstbucket;
	currentbucket.prevptr = NULL;
	if(currentbucket == NULL){
		printf("Something's wrong.");
		return 1;
	}
	
	FILE * dictionary = fopen("/usr/share/dict/words", "r");
	if(!dictionary){
		printf("null dictionary\n");
		return 1;
	}
	
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		numberOfWords++;
		word[strlen(word) - 1] = '\0';
		tempword = malloc(strlen(str) * sizeof(char));
		strcpy(tempword, str);
		if(index > 9){
			currentbucket = previousbucket;
			currentbucket.nextptr = malloc(sizeof(struct bucket));
			currentbucket = currentbucket.nextptr;
			currentbucket.prevptr = previousbucket;
			if(currentbucket == NULL){
				printf("Something's wrong.");
				return 1;
			}
			index = 0;
			numberofbuckets++;
			*(bucket+index) = tempword;
			index++;
		}else{
			*(bucket+index) = tempword;
			index++;
		}
	}while(errorCheck);
	
	return 0;
}