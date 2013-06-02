//implement a function that does the same thing as strcopy

#include <stdio.h>

int main(){
	char str1[] = "Happy Birthday";
	char str2[] = "Panda";
	printf("1 for error: %d\n", totallyNotStrcopy(str1, str2));
	printf("%s\n", str1);
	return 0;
}

int totallyNotStrcopy(char a[], char b[]){
	int index;
	int aLength;
	int bLength;
	char carrot = ' '; // char-at
	// gets the length of a
	while(carrot != '\0'){
		carrot = a[index];
		index++;
	}
	aLength = index + 1;
	index = 0;
	carrot = ' ';
	
	//gets the length of b
	while(carrot != '\0'){
		carrot = b[index];
		index++;
	}
	bLength = index + 1;
	
	if(bLength > aLength){
		return 1;
	}else{
		for(index = 0; index < bLength; index ++){
			a[index] = b[index];
		}
		return 0;
	}
	 
}