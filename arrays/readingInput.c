#include <stdio.h>
#include <string.h>

char str[100];
char num[100];

int main(){
	
	printf("\nEnter some text: ");
	fgets(str, sizeof(str), stdin);
	
	printf("Enter up to four numbers: ");
	fgets(num, sizeof(num), stdin);
	
	/* prettifies the first string before concatenation by removing it's \n character */
	int i;	
	for(i = 0; i < 100; i++){
		if(str[i] == '\n'){
			str[i] = ' ';
		}
	}
	
	/* Makes the two strings one */
	char whole[200];
	strcat(whole, str);
	strcat(whole, num);
	printf("Your two strings, added as strings: %s", whole);
	
	/* demonstration of sscanf */
	int value;
	sscanf(num, "%d", &value);
	printf("The second string, now an int: %d\n", value);
	
	/* practical application of the above */
	long int sum = 0;
	for(i = 0; i < 100; i++){
		sum += (int) str[i];
	}
	sum += value;
	printf("Your two strings as a number: %ld\n", sum);
	
	/* having fun with char array math, demonstration of why sscanf is useful */
	sum = 0;
	for(i = 0; i < 200; i++){
		sum += (int) whole[i];
	}
	printf("Your two strings as a different number: %ld\n\n", sum);
}