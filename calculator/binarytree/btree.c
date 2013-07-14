#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void *removeNode(Btree *node){
	printf("##Test again\n");
	void *extracted = node->data;
	Btree *current;
	Btree *prev;
	prev = node->previous;
	if(prev->left == node){
		node->left->previous = prev;
		prev->left = node->left;
		//this is the questionable bit
		if(prev->right){
			current = prev->left;
			while(current->right){
				current = current->right;
			}
			node->right->previous = current;
			current->right = node->right;
		}else{
			prev->right = node->right;
		}
		//end questionable bit (but it occurs below, too)
	}else if(prev->right == node){
		node->right->previous = prev;
		prev->right = node->right;
		if(prev->left){
			current = prev->right;
			while(current->right){
				current = current->left;
			}
			node->left->previous = current;
			current->left = node->left;
		}else{
			prev->left = node->left;
			prev->left->previous = prev;
		}
	}
	free(node);
	return extracted;
}

int removeAll(Btree * node){
	printf("##Test\n");
	int errorcount = 0;
	if(&(node->previous->left) == &node){
		node->previous->left = 0;
	}else if(&(node->previous->right) == &node){
		node->previous->right = 0;
	}else{
		printf("Node->previous not set properly.\n");
		return 1;
	}
	
	if(node->left){
		printf("recurse left\n");
		errorcount += removeAll(node->left);
	}
	if(node->right){
		printf("recurse right\n");
		errorcount += removeAll(node->right);
	}
	free(node);
	return errorcount;
}


Btree *insertNode(Btree * node, char branch, void * data){
	Btree *new;
	new = malloc(sizeof(Btree));
	new->data = data;
	new->previous = node;
	if(node){
		switch (branch) {
			case 'l' : 
			case 'L' : 
				new->left = node->left;
				node->left = new;
				new->right = 0;
				break;
			case 'R' : 
			case 'r' : 
				new->right = node->right;
				node->right = new;
				new->left = 0;
				break;
			default :
				printf("Invalid branch, use L,l,R,r.\n");
				return 0;
				break;
		}
	}else{
		new->left = 0;
		new->right = 0;
	}
	return new;
}