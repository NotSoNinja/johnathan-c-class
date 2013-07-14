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

// 
// typedef struct st {
// 	void *array[];
// 	int size;
// } Stack;