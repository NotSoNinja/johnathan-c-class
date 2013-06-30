ll: main.o ll.o
	gcc -g -o ll ll.o main.o

main.o: main.c ll.h
	gcc -g -c main.c

ll.o: ll.h ll.c
	gcc -g -c ll.c