btree: test.o btree.o
	gcc -g -o btree btree.o test.o
	
test.o: test.c btree.h
	gcc -g -c test.c
	
btree.o: btree.h btree.c
	gcc -g -c btree.c