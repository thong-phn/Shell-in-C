all: main.o
	gcc -c shell main.o

main.o: main.c
	gcc -c main.c -o main.o

clean: 
	rm *.o
	rm shell