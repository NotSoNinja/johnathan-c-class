#include <stdio.h>
#include "queue.h"

int main(){
	//variables
	Queue *q = 0;
	Queue *current = 0;
	int i;
	int values[] = {1,2,3,4,5,6,7};
	int *j;
	
	for(i = 0; i < 7; i++){
		q = addToQueue((values + i));
	}
	
	//block processes like a queue
	printf("In this test, you should see integers 1 to 7.\n");
	current = q;
	while(current->next){
		j = (int *)current->data;
		printf("%d\n", *j);
		current = removeEndOfQueue();
	}
	j = (int *)current->data;
	printf("%d\n", *j);
	current = removeEndOfQueue();
	
	//makes sure that the stack is all gone
	if(!current){
		printf("Test complete.\n");
	}else{
		printf("Woops.\n");
	}
}