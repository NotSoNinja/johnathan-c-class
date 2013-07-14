#include "stack.h"

#include <stdlib.h>

Stack *top = 0;

Stack *newStackItem(Stack *head, void *data){
	Stack *new;
	new = malloc(sizeof(Stack));
	new->data = data;
	new->next = head;
	top = new;
	return new;
	
}

Stack *removeTopStackItem(){
	Stack *temp = top;
	top = temp->next;
	free(temp);
	return top;
}

// Stack *removeTopStackItem(Stack *head){
// 	if(*head == *top){
// 		Stack *temp = head;
// 		top = temp->next;
// 		free(temp);
// 		return top;
// 	}else{
// 		return 0;
// 	}
//}