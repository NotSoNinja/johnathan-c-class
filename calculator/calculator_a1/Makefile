test: test.o shuntyard.o stacknqueue.o btree.o
	gcc -g -o test test.o shuntyard.o stacknqueue.o btree.o

test.o: test.c *.h
	gcc -c test.c

btree.o: btree.c *.h
	gcc -c btree.c

shuntyard.o: shuntyard.c *.h
	gcc -c shuntyard.c

stacknqueue.o: stacknqueue.c *.h
	gcc -c stacknqueue.c

clean:
	rm -f *.o test