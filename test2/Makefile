CC = gcc
CFLAGS = -c -g
LDFLAGS =  
OBJECTS = main.o hello.o

run: all
	program

all: program

program : $(OBJECTS)
	$(CC)  $(LDFLAGS) -o program $(OBJECTS)

main.o : main.c
	$(CC) $(CFLAGS) main.c 

hello.o : hello.c
	$(CC) $(CFLAGS) hello.c