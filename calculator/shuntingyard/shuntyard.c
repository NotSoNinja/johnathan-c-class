#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stacknqueue.h"

//PEMDAS

char *shunt(char *rawin){
	char input[100];
	int index = 0;
	Stack *tempstack = makestack(100);
	char output[100];
	int outdex = 0;
	char tempchar;
	strcpy(input, rawin);
	
	while(strlen(input)){
		if((int)input[index] >= 48 && (int)input[index] <= 57){
			output[outdex] = input[index];
			outdex++;
		}else if(input[index] == '('){
			push(tempstack, input[index]);
		}else if(input[index] == ')'){
			while(*(char *)tempstack->array[0] != '('){
				if(arraysize(tempstack)){
					output[outdex] = *(char *)pop(tempstack);
					outdex++;
				}else{
					printf("Shunting Failed: incorrect use of parentheses.\n");
					return 0;
				}
			}
			pop(tempstack);
		}else if(input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/'){
			tempchar = *(char *)tempstack->array[0];
			while(pemdas(tempchar, input[index])){
				output[outdex] = pop(tempstack);
				outdex++;
			}
			push(tempstack, input[index]);
		}else if(input[index] == '^'){
			printf("Shunting Failed: exponent functionality unavailable.\n");
			return 0;
		}else if(input[index] == '%'){
			printf("Shunting Failed: modulo functionality unavailable.\n");
			return 0;
		}else{
			printf("Invalid syntax.");
			return 0;
		}
		
		index++;
	}
	while(arraysize(tempstack)){
		output[outdex] = pop(tempstack);
		outdex++;
	}
	
	//this is where code to make output into a real queue would go.
	return output;
}


int pemdas(char o1, char o2){
	//only to be called with +, -, *, /, ^, %
	if(o1 == o2){
		return 1;
	}else if(o1 == '+'){
		return 0;
	}else if(o1 == '-'){
		return 0;
	}else if(o1 == '*'){
		if(o2 == '/'){
			return 1;
		}else if(o2 == '^'){
			return 0;
		}else if(o2 == '%'){
			return 1;
		}
	}else if(o1 == '/'){
		if(o2 == '*'){
			return 1;
		}else if(o2 == '^'){
			return 0;
		}else if(o2 == '%'){
			return 1;
		}
	}else if(o1 == '%'){
		if(o2 == '/'){
			return 1;
		}else if(o2 == '^'){
			return 0;
		}else if(o2 == '*'){
			return 1;
		}
	}// removed 'cause I don't know how it should actually work
	//  else if(o1 == '^'){
	// 		if(o2 == '/'){
	// 			return 1;
	// 		}else if(o2 == '^'){
	// 			return 0;
	// 		}else if(o2 == '%'){
	// 			return 1;
	// 		}
	// 	}
	/*If it gets here, there's a problem*/
	printf("Ya got problems in PEMDAS.\n");
	return 0;
}