#include <stdio.h>
#include "ll.h"

int main(int argc, char **argv) {
	char data[4][5] = {"this","is","a","test"};
	char *s;
	int i;
	LinkedList *head = 0, *curr = 0;

	// head = newLLItem();
	// head->data = data[0];

	for (i = 0; i < 4; i++) {
		head = addLLItem(head, data[i]);
	}

	curr = head;

	while(curr && curr->next) {
		s = curr->data;
		printf("%s\n", s);
		curr = curr->next;
	}
	printf("%s\n", curr->data);
}