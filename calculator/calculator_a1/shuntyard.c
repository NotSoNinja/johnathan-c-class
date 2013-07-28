#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stacknqueue.h"

//PEMDAS

int pemdas(char,char);

char *shunt(char *rawin){
	char input[100];
	int index = 0;
	Stack *tempstack = makestack(100);
	char output[100];
	int outdex = 0;
	char tempchar;
	
	strcpy(input, rawin);
	while(index < strlen(input)){
		if((int)input[index] >= 48 && (int)input[index] <= 57){
			output[outdex] = input[index];
			outdex++;
		}else if(input[index] == '('){
			push(tempstack, &input[index]);
		}else if(input[index] == ')'){
			while(*(char *)peekhead(tempstack) != '('){
				if(arraysize(tempstack)){
					output[outdex] = *(char *)pop(tempstack);
					outdex++;
				}else{
					printf("You done goofed.\n");
					return 0;
				}
			}
			pop(tempstack);
		}else if(input[index] == '+' || input[index] == '-' || input[index] == '*' || input[index] == '/'){
			if(arraysize(tempstack)){
				tempchar = *(char *)peekhead(tempstack);
				while(arraysize(tempstack) && pemdas(tempchar, input[index])){
					output[outdex] = *(char *)pop(tempstack);
					outdex++;
					tempchar = *(char *)peekhead(tempstack);
				}
				push(tempstack, &input[index]);
			}else{
				push(tempstack, &input[index]);
			}
		}else if(input[index] == '^'){
			printf("You done goofed.\n");
			return 0;
		}else if(input[index] == '%'){
			printf("You done goofed.\n");
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
	
	output[outdex] = '\0';
	strcpy(rawin,output);
	return rawin;
}

int pemdas(char o1, char o2){
	const char pemdas[] = "*/+-";
	char *onechar;
	char *twochar;
	int onedex;
	int twodex;
	onechar = index(pemdas, o1);
	twochar = index(pemdas, o2);
	onedex = pemdas-onechar;
	twodex = pemdas - twochar;
	onedex *= -1;
	twodex *= -1;
	if(onedex >= 0){
		if(twodex >= 0){
			if(onedex <= twodex){
				return 1;
			}else{
				if(onedex == 2 && twodex == 2){
					return 1;
				}else if(onedex == 0 && twodex == 1){
					return 1;
				}else{
					return 0;
				}
			}
		}else{
			printf("PEMDAS Error 2.\n");
			return 0;
		}
	}else{
		printf("PEMDAS Error 1.\n");
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