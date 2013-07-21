test: test.o shuntyard.o stacknqueue.o
	gcc -g -o test test.o shuntyard.o stacknqueue.o

test.o: test.c *.h
	gcc -c test.c

shuntyard.o: shuntyard.c *.h
	gcc -c shuntyard.c

stacknqueue.o: stacknqueue.c *.h
	gcc -c stacknqueue.c

clean:
	rm -f *.o test
