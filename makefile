CC=gcc
CFLAGS=-Wall -ansi

fleschIndex: fleschIndex.o
	$(CC) -o fleschIndex fleschIndex.o

enterStudents.o: fleschIndex.c
	$(CC) $(CFLAGS) -c fleschIndex.c
clean:
	rm fleschIndex fleschIndex.o
