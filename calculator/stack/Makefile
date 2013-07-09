stack: test.o stack.o
	gcc -g -o stack stack.o test.o
	
test.o: test.c stack.h
	gcc -g -c test.c
	
stack.o: stack.h stack.c
	gcc -g -c stack.c
