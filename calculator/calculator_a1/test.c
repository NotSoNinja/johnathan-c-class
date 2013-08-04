/*add function to tree code to visit each node in a depth first left to right self traversal, executes arbitrary function on each node visited*/
#include <stdio.h>
#include "stacknqueue.h"
#include "shuntyard.h"
#include "btree.h"

void printIt(Btree *);
void traverse(Btree *);
Btree *processIt(char *, int, Btree*);
void math(Btree *);

int main(int argc, char **argv){
	Btree *head;
	//gets and shunts input
	char *revpolish;
	revpolish = shunt(argv[1]);
	int poledex = strlen(revpolish);
	poledex--;
	//put this into a tree
	head = processIt(revpolish, poledex, 0);	
	//traverse the tree and do math
	traverse(head);
	printf("Solution: %d", *(int *)head->data);
}

Btree *processIt(char *pole, int poledex, Btree *node){
	Btree *temp;
	int locdex = --poledex;
	if(poledex < 0){
		return 0;
	}else if(!node){
		temp = insertNode(0,0,(pole+poledex));
		processIt(pole, locdex, (temp));
	}else{
		if(node->left && node->right){
			processIt(pole, poledex, node->previous);
		}else if(node->right){
			temp = insertNode(node, 'L', (pole+poledex));
			processIt(pole, locdex, (temp));
		}else{
			temp = insertNode(node, 'R', (pole+poledex));
			processIt(pole, locdex, (temp));
		}
	}
	return temp;
}

void traverse(Btree *nub){
	//decides the function to be executed
	void (*function)(Btree *);
	function = &printIt;
	//call traverse on other branches if they exist: left and depth before right
	if(nub->left){
		traverse(nub->left);
	}
	if(nub->right){
		traverse(nub->right);
	}
	//use function pointer to do function on data in this branch
	(*function)(nub);
}


void printIt(Btree *node){
	printf("Node %p\n", node);
	printf("Left %p\tRight %p\n", node->left, node -> right);
	printf("Data: %c\n\n", *(char *)(node->data));
}

void math(Btree *node){
	static float res = 0;
	static float numbers[100];
	static int numdex = 0;
	float temp = 0;
	char data = *(char *)(node->data);
	switch(data){
		case '+': 
			temp += *(int *)(node->left->data);
			res += *(int *)(node->right->data);
			numbers[numdex] = temp;
			node->data = numbers + numdex;
			numdex++;
			break;
		case '-': break;
			temp += *(int *)(node->left->data);
			temp -= *(int *)(node->right->data);
			numbers[numdex] = temp;
			node->data = numbers + numdex;
			numdex++;
			break;
		case '*': 
			temp += *(int *)(node->left->data);
			temp *= *(int *)(node->right->data);
			numbers[numdex] = temp;
			node->data = numbers + numdex;
			numdex++;
			break;
		case '/': 
			temp += *(int *)(node->left->data);
			if(*(int *)(node->right->data)){
				temp /= *(int *)(node->right->data);
			}else{
				printf("Error: division by zero;");
				temp = 0;
			}
			numbers[numdex] = temp;
			node->data = numbers + numdex;
			numdex++;
			break;
		default:
			//it should alteady be a number
			if(!node->data){
				printf("Null value error.\n");
			}
			break;
	}
}