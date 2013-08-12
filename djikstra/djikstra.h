#include <stdio.h>
#include <stdlib.h>
#include "djikstra.c"

int traverse(int [7][7], int, int, int, int, int *);
int arrcmp(int *, int, int);
int printarray(int *, int);
int selectleast(int *, int);