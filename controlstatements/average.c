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
	
	//printf("## spaces = %d\n", spaces);
	
	/* switches on number of spaces to decide which sscanf version to use */
	int numbers[50];	/* the numbers to be averaged */
	switch (spaces){
		case 0:
			sscanf(input, "%d", &numbers[0]);
			break;
		case 1:
			sscanf(input, "%d %d", &numbers[0], &numbers[1]);
			break;
		case 2:
			sscanf(input, "%d %d %d", &numbers[0], &numbers[1], &numbers[2]);
			break;
		case 3:
			sscanf(input, "%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
			break;
		case 4:
			sscanf(input, "%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);
			break;
		default:
			printf("Either you entered too many numbers, or something went way wrong.");
			break;
	}
	//printf("## The numbers in numbers: %d %d %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5]);
	
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
	return average;
}