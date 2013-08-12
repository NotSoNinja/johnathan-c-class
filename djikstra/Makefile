main: main.o djikstra.o
	gcc -g -o main main.o

main.o: main.c djikstra.h
	gcc -g -c main.c

test: test.o djikstra.o
	gcc -g -o test test.c

test.o: test.c djikstra.h
	gcc -g -c test.c

djikstra.o: djikstra.c djikstra.h
	gcc -g -c djikstra.c