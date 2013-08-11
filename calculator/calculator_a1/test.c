/*add function to tree code to visit each node in a depth first left to right self traversal, executes arbitrary function on each node visited*/
#include <stdio.h>
#include "stacknqueue.h"
#include "shuntyard.h"
#include "btree.h"

void printIt(Btree *);
void traverse(Btree *, void(*function)(Btree *));
Btree *processIt(char *, int, Btree*);
void math(Btree *);
char *ftoa(float);

int main(int argc, char **argv){
	Btree *head;
	//gets and shunts input
	char *revpolish;
	revpolish = shunt(argv[1]);
	// printf("Reverse polish input: %s\n", revpolish);
	int poledex = strlen(revpolish) - 1;
	//put this into a tree
	head = processIt(revpolish, poledex, 0);
	//traverse the tree and do math
	traverse(head, &printIt);
	traverse(head, &math);
	printf("Solution: %f\n", atof((char *)head->data));
}

Btree *processIt(char *pole, int poledex, Btree *node){
	Btree *temp;
	int locdex = poledex - 1;
	//printf("Poledex: %d\n", poledex);

	char *data;
	data = malloc(sizeof(char) * 2);
	*data = pole[poledex];
	*(data + 1) = 0;

	if(poledex < 0){
		/*base*/
		return 0;
	}else if(pole[poledex + 1] - 48 <= 9 && pole[poledex + 1] - 48 >= 0 && node->previous != 0){
		/*If the last placed was a number, don't place nodes of the numbers' node*/
		node = node->previous;
		if(node->left && node->right){
			processIt(pole, poledex, node->previous);
		}else if(node->right){
			temp = insertNode(node, 'L', (data));
			processIt(pole, locdex, (temp));
		}else{
			temp = insertNode(node, 'R', (data));
			processIt(pole, locdex, (temp));
		}
	}else if(!node){
		/*creates the head*/
		temp = insertNode(0,0,(data));
		processIt(pole, locdex, (temp));
		// printf("Created head with data: %s\n", data);
	}else{
		/*for non-special cases*/
		if(node->left && node->right){
			processIt(pole, poledex, node->previous);
		}else if(node->right){
			temp = insertNode(node, 'L', (data));
			processIt(pole, locdex, (temp));
		}else{
			temp = insertNode(node, 'R', (data));
			processIt(pole, locdex, (temp));
		}
	}
	return temp;
}

void traverse(Btree *nub, void(*function)(Btree *)){
	//call traverse on other branches if they exist: left and depth before right
	if(nub->left){
		traverse(nub->left, (*function));
	}
	if(nub->right){
		traverse(nub->right, (*function));
	}
	//use function pointer to do function on data in this branch
	(*function)(nub);
	//(*function)(nub);
}


void printIt(Btree *node){
	printf("Node %p\n", node);
	printf("Left %p\tRight %p\n", node->left, node -> right);
	printf("Data: %c\n\n", *(char *)(node->data));
}

void math(Btree *node){
	//static float res = 0;
	static float numbers[100];
	static int numdex = 0;
	float temp = 0;
	char data = *(char *)(node->data);
	//printf("%c\n", data);
	switch(data){
		case '+': 
			temp += atof((char *)(node->left->data));
			temp += atof((char *)(node->right->data));
			numbers[numdex] = temp;
			node->data = ftoa(numbers[numdex]);
			numdex++;
			break;
		case '-': break;
			temp += atof((char *)(node->left->data));
			temp -= atof((char *)(node->right->data));
			numbers[numdex] = temp;
			node->data = ftoa(numbers[numdex]);
			numdex++;
			break;
		case '*': 
			temp += atof((char *)(node->left->data));
			temp *= atof((char *)(node->right->data));
			numbers[numdex] = temp;
			node->data = ftoa(numbers[numdex]);
			numdex++;
			break;
		case '/': 
			temp += atof((char *)(node->left->data));
			if(atof((char *)(node->right->data))){
				temp /= atof((char *)(node->right->data));
			}else{
				printf("Error: division by zero;");
				temp = 0;
			}
			numbers[numdex] = temp;
			node->data = ftoa(numbers[numdex]);
			numdex++;
			break;
		default:
			//it should alteady be a number
			if(!node->data){
				printf("Null value error.\n");
			}else{
				//printf("As char: %c  As int: %d\n", *(char *)node ->data, *(int *)node->data);
				//numbers[numdex] = atof((char *)node->data);
				//node->data = (numbers + numdex);
				//printf("## Check %s\n\n", numbers[numdex]);
				//printf("## Check %f\n\n", atof((char *)node->data));
				numdex++;
			}
			break;
	}
}

char *ftoa(float f){
	//an imperfect implementation to be sure.
	//printf("ftoa input %f\n", f);
	char *string;
	int stringdex = 0;
	string = malloc(sizeof(char) * 20);
	sprintf(string, "%f",f);

	return string;
}