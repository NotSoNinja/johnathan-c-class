#ifndef _djikstra_h_
#define _djikstra_h_
#include <stdio.h>
#include <stdlib.h>
// #include "djikstra.c"

int traverse(int [7][7], int, int, int, int, int *);
int arrcmp(int *, int, int);
int printarray(int *, int, char *);
int selectleast(int *, int);
int traverse2(int [7][7], int, int, int *, int, int, int);

#endif