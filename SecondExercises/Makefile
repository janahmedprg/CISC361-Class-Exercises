CC = gcc
CFLAGS = -Wall -Werror

secondExPriority: secondExPriority.c util.o
	$(CC) $(CFLAGS) -o secondExPriority secondExPriority.c linkedList.o

linkedList.o: linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c

clean:
	rm -f main linkedList.o
