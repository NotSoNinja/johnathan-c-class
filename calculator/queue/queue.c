#include <stdlib.h>
#include "queue.h"

// typedef struct q {
// 	struct q *next;
// 	void *data;
// } Queue;
Queue *end = 0;

Queue *addToQueue(void *data){
	Queue *new;
	Queue *attach;
	new = malloc(sizeof(Queue));
	new->data = data;
	if(end){
		attach = end;
		while(attach->next){
			attach = attach->next;
		}
		attach->next = new;
		new->next = 0;
	}else{
		new->next = 0;
		end = new;
	}
	return end;
}

Queue *removeEndOfQueue(){
	Queue *temp;
	temp = end;
	end = end->next;
	free(temp);
	return end;
}