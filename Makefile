all: main.o builtInCommands.o
	gcc -o Cshell main.o builtInCommands.o

main.o: main.c 
	gcc -c main.c -o main.o

builtInCommands.o: builtInCommands.c builtInCommands.h
	gcc -c builtInCommands.c -o builtInCommands.o

clean: 
	rm *.o
	rm Cshell