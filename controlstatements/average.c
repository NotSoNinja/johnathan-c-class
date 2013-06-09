/************************************************
 *	Average, a program by Johnathan				*
 *												*
 *	It gets the average of 'n' numbers.			*
 *												*
 *	That's really it.  So far, anyway.			*
 *												*
 ************************************************/

#include <stdio.h>
#include <string.h>

int main(){
	/* User inputs numbers */
	char input[100];	/* the user's input, as a string */
	printf("Enter a series of up to 5 numbers to be averaged, seperated by spaces: ");
	fgets(input, sizeof(input), stdin);
	
	/* figures out how many spaces (and, by extension, how many numbers) */
	int i;
	int spaces = 0;		/* number of spaces */
	for(i = 0; i < sizeof(input); i++){
		if(input[i] == ' '){
			spaces++;
		}
	}
	
	int numbers[51];	/* the numbers to be averaged */
	int index = 0;			/* index of numbers*/
	for(i = strlen(input); i >= 0; i--){
		if(input[i] == ' ' || i == 0){
			sscanf(input+i, "%d", &numbers[index]);
			index++;
			input[i] = '\0';
		}
	}
	// for(i = 0; i < (spaces + 1); i++){
	// 		printf("## Numbers: ");
	// 		printf("%d ",numbers[i]);
	// 		printf("\n");
	// 	}
	/* gets the average */
	float average = 0;
	i = 0;
	/* addes the numbers up */
	for(i = 0; i <= spaces; i++){
		average += numbers[i];
		//printf("## average as numbers added: %f\n", average);
	}
	/* divides by the number of numbers (one more than the number of spaces) */
	average /= (spaces + 1);
	
	/* returns and prints the result */
	printf("The average of your %d numbers is: %f.\n", (spaces + 1), average);
	return 0;
}