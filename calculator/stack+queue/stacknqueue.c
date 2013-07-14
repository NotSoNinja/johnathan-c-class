#include <stdlib.h>
#include "stacknqueue.h"


int arraysize(Stack *);

int push(Stack *, void *); //add to front
void *pop(Stack *); //remove from front
int shift(Stack * target, void * data){//add to end
	target->array[target->used] = data;
	target->used++;
	return target->used;
} 
void *unshift(Stack *); //remove from end

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

// 
// typedef struct st {
// 	void *array[];
// 	int size;
// } Stack;