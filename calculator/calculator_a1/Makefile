test: test.o shuntyard.o stacknqueue.o btree.o
	gcc -g -o test test.o shuntyard.o stacknqueue.o btree.o

test.o: test.c *.h
	gcc -g -c test.c

btree.o: btree.c *.h
	gcc -g -c btree.c

shuntyard.o: shuntyard.c *.h
	gcc -g -c shuntyard.c

stacknqueue.o: stacknqueue.c *.h
	gcc -g -c stacknqueue.c

clean:
	rm -f *.o test