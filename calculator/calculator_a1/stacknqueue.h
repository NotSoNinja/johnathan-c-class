#ifndef __stacknqueue_h__
#define __stacknqueue_h__

#include <stdlib.h>

typedef struct st {
	int size;
	int used;
	void **array;
} Stack;

int push(Stack *, void *); //add to front
void *pop(Stack *); //remove from front
int shift(Stack *, void *); //add to end
void *unshift(Stack *); //remove from end
void *peekhead(Stack *);
void *peektail(Stack *);
Stack *makestack(int);
int deletestack(Stack *);
int arraysize(Stack *);
int totalarraylength(Stack *);

#endif