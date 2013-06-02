// "I want you to print me a checkerboard of arbitrary size"

// so I could have done this the easy way.  But I didn't.

#include <stdio.h>

#define xSize 10
#define ySize 10

void print2DCharArray(int x, int y, char [x][y]); //does what it says it does

int main(){
	char board[ySize][xSize];
	const char A = '+'; //the black squares
	const char B = ' '; // the white squares
	int xIndex;
	int yIndex;
	char lastChar = A; // last char used
	char lastLine = B; // char the previous line began with
	int newline = 0; //is this the first char in a line?
	
	for(yIndex = 0; yIndex < ySize; yIndex++){
		for(xIndex = 0; xIndex < xSize; xIndex++){
			
			if(newline == 1){ //if this is the first character on a line
				if(lastLine == A){ //if the previous line started with B, it starts this one with A, etc.
					board[yIndex][xIndex] = B;
					lastChar = lastLine = B;
				}else if(lastLine == B){
					board[yIndex][xIndex] = A;
					lastChar = lastLine = A;
				}else{ // in chase things go way wrong.
					break;
				}
				newline = 0;
			
			}else{ // if it isn't the first character on a line, basically the same thing
				if(last == A){
					board[yIndex][xIndex] = B;
					lastChar = B;
				}else if(last == B){
					board[yIndex][xIndex] = A;
					lastChar = A;
				}else{
					break;
				}
			}
		}
		newline = 1;
	}
	print2DCharArray(xSize, ySize, board);
	
	return 0;
}

void print2DCharArray(int x, int y, char toPrint[x][y]){
	int xIndex;
	int yIndex;
	for(yIndex = 0; yIndex < y; yIndex++){
		for(xIndex = 0; xIndex < x; xIndex++){
			printf("%c", toPrint[xIndex][yIndex]);
		}
		printf("\n");
	}
	printf("\n");
}