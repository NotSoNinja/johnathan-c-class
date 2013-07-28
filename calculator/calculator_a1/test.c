#include "shuntyard.h"
#include "stacknqueue.h"
#include "btree.h"
#include <stdio.h>

int main(int argc, char **argv){
	//variables
	Stack *qstack = makestack(100);
	Btree *parser;
	Btree *node;
	int loop;
	int L, R;
	int values[100];
	int valdex;
	char temp;
	char last;
	char *shunted;
	int converted;
	shunted = shunt(argv[1]);
	int i;
	printf("%s\n", shunted);
	while(strlen(shunted+i)){
		push(qstack, (shunted+i));
	}
	
	//section adds to tree, as both chars and ints for easy use later
	last = *(char *)pop(qstack);
	parser = insertNode(0,'\0', &last);
	node = parser;
	while(arraysize(qstack)){
		temp = *(int *)pop(qstack);
		if((int)temp <= 48 && (int)temp >= 57){
			if(((int)last <= 48) && ((int)last >= 57)){
				values[valdex] = (int)temp - 48;
				node = insertNode(parser, 'L', values+valdex);
				valdex++;
			}else{
				values[valdex] = (int)temp - 48;
				node = insertNode(parser, 'R', values+valdex);
				valdex++;
			}
		}else{
			if((int)last <= 48 && (int)last >= 57){
				loop = 1;
				while(loop){
					if(node->previous->left){
						if(node->previous != 0){
							node = node->previous;
						}else{
							printf("Fatal Error.\n");
							return 1;
						}
					}else{
						loop = 0;
						node = insertNode(node->previous, 'L', &temp);
					}
				}
			}else{
				node = insertNode(parser, 'R', &temp);
			}
		}
		last = temp;
	}
	
	//section does math based on tree
	node = parser->right;
	while(node->right->right){
		node = node->right;
	}
	do{
		printf("loop.\n");
		if(node->left->left){
			node = node->left;
		}else{
			R = *(int *)removeNode(node->right);
			L = *(int *)removeNode(node->left);
			temp = *(char *)node->data;
			if(temp == '+'){
				values[valdex] = L + R;
				node->data = values+valdex;
			}else if(temp = '-'){
				values[valdex] = L - R;
				node->data = values+valdex;
			}else if(temp = '*'){
				values[valdex] = L * R;
				node->data = values+valdex;
			}else if(temp = '/'){
				values[valdex] = L / R;
				node->data = values+valdex;
			}else{
				printf("Invalid operator.\n");
				return 2;
			}
			if(node->previous){
				node = node->previous;
			}else{
				printf("Done.\n");
				printf("Solution: %d\n", *(int *)node->data);
			}
		}
	}while(node->previous || node->left);
	
	return 0;
}