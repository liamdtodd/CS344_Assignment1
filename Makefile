CC = gcc --std=c99 -g

run: driver.c movie.o linkedlist.o
	$(CC) driver.c movie.o linkedlist.o

movie.o: movie.c movie.h node.h
	$(CC) -c movie.c -o movie.o

linkedlist.o: linkedlist.c linkedlist.h movie.h node.h
	$(CC) -c linkedlist.c -o linkedlist.o

clean:
	rm -f *.o run
