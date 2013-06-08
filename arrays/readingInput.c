#include <stdio.h>
#include <string.h>

char str[100];
char num[100];

int main(){
	
	printf("Enter some text: ");
	fgets(str, sizeof(str), stdin);
	printf("\n");
	
	printf("Enter some numbers: ");
	fgets(num, sizeof(num), stdin);
	printf("\n");
	
	char whole[sizeof(str) + sizeof(num)] = strcat(str, num);
	
	printf("Your two strings, added as strings: %s\n", whole);
	
	int value;
	
	sscanf(num, "%d", &value);
	
	long int sum = 0;
	
	int i;
	for(i = 0; i < 100; i++){
		sum += (int) str[i];
	}
	
	sum += value;
	
	printf("Your two strings as a number: %ld\n", sum)	
	
}