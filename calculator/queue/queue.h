#ifndef __queue_h__
#define __queue_h__

#include <stdlib.h>

typedef struct q {
	struct q *next;
	void *data;
} Queue;

Queue *addToQueue(void *);
Queue *removeEndOfQueue();

#endif