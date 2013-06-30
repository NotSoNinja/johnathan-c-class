#ifndef __ll_h__
#define __ll_h__

#include <stdlib.h>

// typedef LinkedList;
typedef struct ll {
	struct ll *next;
	struct ll *prev;
	void *data;
} LinkedList;

LinkedList *newLLItem();
LinkedList *addLLItem(LinkedList *, void *);
LinkedList *lastItem(LinkedList *);

#endif