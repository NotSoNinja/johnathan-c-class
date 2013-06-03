#include "ll.h"

LinkedList *newLLItem() {
	LinkedList *this = malloc(sizeof(LinkedList));
	this->data = 0;
	this->next = 0;
	return this;
}

LinkedList *addLLItem(LinkedList *head, void *data) {
	LinkedList *last, *curr;
	curr = newLLItem();
	last = lastItem(head);
	if (last) {
		last->next = curr;
	} else {
		last = head = curr;
	}
	curr->data = data;
	return head;
}

LinkedList *lastItem(LinkedList *head) {
	LinkedList *curr;
	curr = head;
	while (curr && curr->next) {
		curr = curr->next;
	}
	return curr;
}