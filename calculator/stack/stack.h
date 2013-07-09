#ifndef __stack_h__
#define __stack_h__

#include <stdlib.h>

	
typedef struct st {
	struct st *next;
	void *data;
} Stack;

Stack *newStackItem(Stack *, void *);
Stack *removeTopStackItem();


#endif

// #include <stdlib.h>
// 
// // typedef LinkedList;
// typedef struct ll {
// 	struct ll *next;
// 	struct ll *prev;
// 	void *data;
// } LinkedList;
// 
// LinkedList *newLLItem();
// LinkedList *addLLItem(LinkedList *, void *);
// LinkedList *lastItem(LinkedList *);

