#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(int argc, char **argv) {
	char *s;
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
		head = addLLItem(head, tempword);
	}while(errorCheck);
	
	curr = head;
		
		
	while(curr && curr->next) {
		s = curr->data;
		printf("%s\n", s);
		curr = curr->next;
	}
	
	while(curr && curr->prev){
		s = curr->data;
		printf("%s\n", s);
		curr = curr ->prev;
	}
	
	printf("%s\n", curr->data);
}