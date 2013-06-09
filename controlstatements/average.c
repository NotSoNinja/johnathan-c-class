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
	int j; 				/* loop variable for removing used part */
	int k;				/* another counter - allows me not to mess with i when removing used wtuff*/
	int l = 0;			/* another counter - again a replacement for i, when giving a thing its own string*/
	char readin[10];
	/* runs this sequence for each number*/
	for(i = 0; i <= (spaces + 1); i++){
		/* takes the first number and gives it its own string */
		// printf("## i: %d\n", i);
		while(input[l] != ' '){
			readin[l] = input[l];
			// printf("## l: %d\n", l);
			l++;
		}
		/* sets count variables for next part */
		l = 0;
		k = i;
		/* removes the used part of input */
		for(j = 0; j < (sizeof(input) - i); j++){
			input[j] = input[k];
			// printf("## j: %d\n", j);
			// 		printf("## k: %d\n", k);
			k++;
		}
		/* adds the number to numbers */
		sscanf(readin, "%d", &numbers[i]);
		
	}

	// switch (spaces){
	// 	case 0:
	// 		sscanf(input, "%d", &numbers[0]);
	// 		break;
	// 	case 1:
	// 		sscanf(input, "%d %d", &numbers[0], &numbers[1]);
	// 		break;
	// 	case 2:
	// 		sscanf(input, "%d %d %d", &numbers[0], &numbers[1], &numbers[2]);
	// 		break;
	// 	case 3:
	// 		sscanf(input, "%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
	// 		break;
	// 	case 4:
	// 		sscanf(input, "%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);
	// 		break;
	// 	default:
	// 		printf("Either you entered too many numbers, or something went way wrong.");
	// 		break;
	// }
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