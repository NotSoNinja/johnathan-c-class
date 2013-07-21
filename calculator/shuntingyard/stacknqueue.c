#include <stdlib.h>
#include <stdio.h>
#include "stacknqueue.h"


int arraysize(Stack *);

int push(Stack *target, void *data){ //add to front
	int i;
	for(i = target->used; i > 0; i--){
		target->array[i] = target->array[(i - 1)];
	}
	target->array[i] = data;
	target->used++;
	return target->used;
}


int shift(Stack * target, void * data){//add to end
	target->array[target->used] = data;
	target->used++;
	return target->used;
} 

//remove from end
void *unshift(Stack *stack) {
	if(stack->used <= 0){
		printf("Woah, son. Outta Stack.");
	}
	stack->used--;
	return stack->array[stack->used];
} 

Stack *makestack(int size){
	Stack *new;
	new = malloc(sizeof(Stack));
	new->array = malloc(sizeof(void *) * size);
	new->size = size;
	new->used = 0;
	return new;
}

int deletestack(Stack * target){
	free(target->array);
	free(target);
	return 0;
}

int arraysize(Stack * target){
	return target->used;
}

int totalarraylength(Stack * target){
	return target->size;
}

//Return the first element in the array and remove it from the array.
void *pop(Stack *stack) {
	if(stack->used <= 0){
		printf("Woah, son. Outta Stack.");
	}
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

void *peekhead(Stack *stack){
	void *ret;
	ret = stack->array[0];
	return ret;
}
void *peektail(Stack *stack){
	return stack->array[arraysize(stack)];
}