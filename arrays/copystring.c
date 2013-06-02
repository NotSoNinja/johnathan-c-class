//implement a function that does the same thing as strcopy

#include <stdio.h>

int main(){
	char str1[] = "Happy Birthday";
	char str2[] = "Panda";
	totallyNotStrcopy(str1, str2);
	printf("%s", str1);
	return 0;
}

int totallyNotStrcopy(char a[], char b[]){
	int index;
	int aLength;
	int bLength;
	char carrot = ' '; // char-at
	while(carrot != '\0'){
		carrot = a[index];
		index++;
	}
	aLength = index + 1;
	index = 0;
	
	while(carrot != '\0'){
		carrot = a[index];
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