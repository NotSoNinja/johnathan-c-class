#include <stdlib.h>
#include "stacknqueue.h"

int push(Stack *, void *); //add to front
void *pop(Stack *); //remove from front
int shift(Stack *, void *); //add to end
void *unshift(Stack *); //remove from end

Stack *makestack(int size){
	Stack *new;
	new = malloc(sizeof(Stack));
	new->array = malloc(sizeof(void *) * size);
	new->size = size;
	new->used = 0;
	return new;
}

int deletestack(Stack *);
int arraysize(Stack *);

//Return the first element in the array and remove it from the array.
void *pop(Stack *stack) {
	int i;
	void *ret;

	ret = stack->array[0];  //Save the head element so we don't lose it.

	//Move all the next elements up one;
	for (i = 1; i < stack->used; i++) {
		stack->array[i-1] = stack->array[i];
	}
	//Clear the end element
	stack->array[i] = 0;

	//Decrement the stack size;
	stack->used--;

	//Done!
	return ret;
}


// 
// typedef struct st {
// 	void *array[];
// 	int size;
// } Stack;