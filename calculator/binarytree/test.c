#include <stdio.h>
#include "btree.h"

int main(){
	int values[] = {1,2,3,4};
	int *out;
	Btree *root;
	root = insertNode(0, 'R', (values + 1));
	printf("##checked 1\n");
	insertNode(root, 'L', (values + 2));
	insertNode(root, 'R', (values + 3));
	insertNode(root->left, 'L', (values + 4));
	printf("##checked 2\n");
	
	*out = removeAll(root->left);
	printf("0 if successfully deleted 2 and 4: %d\n", *out);
	
	out = (int *)removeNode(root->right);
	printf("3 if successfully deleted 3: %d\n", *out);
	
	printf("Should be 1: %d\n", (int *)root->data);
}