#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stacknqueue.h"

//PEMDAS

int pemdas(char,char);

char *shunt(char *rawin){
	printf("##preim check.\n");
	char input[100];
	int index = 0;
	Stack *tempstack = makestack(100);
	char output[100];
	int outdex = 0;
	char tempchar;
	
	strcpy(input, rawin);
	printf("## First checkpoint.\n");
	while(strlen(input)){
		if((int)input[index] >= 48 && (int)input[index] <= 57){
			printf("## Second checkpoint.\n");
			output[outdex] = input[index];
			outdex++;
			printf("## Third checkpoint.\n");
		}else if(input[index] == '('){
			push(tempstack, &input[index]);
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
			printf("## Fourth checkpoint.\n");
			tempchar = *(char *)peekhead(tempstack);
			printf("## Fifth checkpoint.\n");
			while(pemdas(tempchar, input[index])){
				printf("## Sixth checkpoint.\n");
				output[outdex] = *(char *)pop(tempstack);
				outdex++;
			}
			printf("## Seventh checkpoint.\n");
			push(tempstack, &input[index]);
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
		output[outdex] = *(char *)pop(tempstack);
		outdex++;
	}
	
	//this is where code to make output into a real queue would go.
	strcpy(rawin,output);
	return rawin;
}

int pemdas(char o1, char o2){
	const char pemdas[] = "^*/+-";
	char *onechar;
	char *twochar;
	int onedex;
	int twodex;
	onechar = index(pemdas, o1);
	twochar = index(pemdas, o2);
	onedex = pemdas-onechar;
	twodex = pemdas - twochar;
	// char *o1s, *o2s;
	// 	sprintf(o1s, "%c", o1);
	// 	sprintf(o2s, "%c", o2);
	// 	onedex = strstr(o1s, pemdas);
	// 	twodex = strstr(o2s, pemdas);
	if(onedex >= 0){
		if(twodex >= 0){
			if(onedex >= twodex){
				return 1;
			}else{
				return 0;
			}
		}else{
			printf("PEMDAS Error 2.");
			return 0;
		}
	}else{
		printf("PEMDAS Error 1.");
		return 0;
	}
	
}

// /*this is the confusing part*/
// int pemdas(char o1, char o2){
// 	//only to be called with +, -, *, /, ^, %
// 	if(o1 == o2){
// 		return 1;
// 	}else if(o1 == '+'){
// 		return 0;
// 	}else if(o1 == '-'){
// 		return 0;
// 	}else if(o1 == '*'){
// 		if(o2 == '/'){
// 			return 1;
// 		}else if(o2 == '^'){
// 			return 0;
// 		}else if(o2 == '%'){
// 			return 1;
// 		}
// 	}else if(o1 == '/'){
// 		if(o2 == '*'){
// 			return 1;
// 		}else if(o2 == '^'){
// 			return 0;
// 		}else if(o2 == '%'){
// 			return 1;
// 		}
// 	}else if(o1 == '%'){
// 		if(o2 == '/'){
// 			return 1;
// 		}else if(o2 == '^'){
// 			return 0;
// 		}else if(o2 == '*'){
// 			return 1;
// 		}
// 	}// removed 'cause I don't know how it should actually work
// 	//  else if(o1 == '^'){
// 	// 		if(o2 == '/'){
// 	// 			return 1;
// 	// 		}else if(o2 == '^'){
// 	// 			return 0;
// 	// 		}else if(o2 == '%'){
// 	// 			return 1;
// 	// 		}
// 	// 	}
// 	/*If it gets here, there's a problem*/
// 	printf("Ya got problems in PEMDAS.\n");
// 	return 0;
// }