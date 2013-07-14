#include <stdio.h>
#include "btree.h"

int main(){
	int out;
	Btree *root;
	root = insertNode(0, 'R', 1);
	insertNode(root, 'L', 2);
	insertNode(root, 'R', 3);
	insertNode(root->left, 'L', 4);
	
	out = removeAll(root->left);
	printf("0 if successfully deleted 2 and 4: %d\n", out);
	
	out = (int *)removeNode(root->right);
	printf("3 if successfully deleted 3: %d\n", out);
	
	printf("Should be 1: %d\n", (int *)root->data);
}