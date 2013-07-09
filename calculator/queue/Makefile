queue: test.o queue.o
	gcc -g -o queue queue.o test.o
	
test.o: test.c queue.h
	gcc -g -c test.c
	
stack.o: queue.h queue.c
	gcc -g -c queue.c