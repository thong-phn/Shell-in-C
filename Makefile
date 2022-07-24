all: main.o
	gcc -o Cshell main.o

main.o: main.c
	gcc -c main.c -o main.o

clean: 
	rm *.o
	rm shell