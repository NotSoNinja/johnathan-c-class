#include <stdio.h>
#include "stack.h"

int main(){
	//variables
	Stack *head = 0;
	Stack *current = 0;
	int i;
	int values[] = {1,2,3,4,5,6,7};
	int *j;
	
	for(i = 0; i < 7; i++){
		head = newStackItem(head, (values + i));
	}
	//block prints like a normal linked list
	printf("In this test, you should see integers 1 to 7 in reverse order.\n");
	current = head;
	while(current->next){
		j = (int *)current->data;
		printf("%d\n", *j);
		current = current->next;
	}
	j = (int *)current->data;
	printf("%d\n", *j);
	
	//block processes like a stack
	printf("In this test, you should see integers 1 to 7.\n");
	current = head;
	while(current->next){
		j = (int *)current->data;
		printf("%d\n", *j);
		current = removeTopStackItem();
	}
	j = (int *)current->data;
	printf("%d\n", *j);
	current = removeTopStackItem();
	
	//makes sure that the stack is all gone
	if(!current){
		printf("Test complete.\n");
	}else{
		printf("Woops.\n");
	}
}