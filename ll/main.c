#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(int argc, char **argv) {
	
	char word[80];
	int i;
	char *errorCheck;
	char *tempword;
	LinkedList *head = 0, *curr = 0;
	
	FILE * dictionary = fopen("/usr/share/dict/words", "r");
	if(!dictionary){
		printf("null dictionary\n");
		return 1;
	}
	
	do{
		errorCheck = fgets(word, sizeof(word), dictionary);
		tempword = malloc(strlen(word) * sizeof(char));
		word[strlen(word) - 1] = '\0';
		strcpy(tempword, word);
		head = add LLItem(head, tempword)
	}while(errorCheck);
	
	curr = head;
		
		
	while(curr && curr->next) {
		s = curr->data;
		printf("%s\n", s);
		curr = curr->next;
	}
	printf("%s\n", curr->data);
}