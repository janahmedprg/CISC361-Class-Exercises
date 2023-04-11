CC = gcc

secondExPriority: secondExPriority.c linkedList.o
	$(CC) -o secondExPriority secondExPriority.c linkedList.o

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c

clean:
	rm -f secondExPriority linkedList.o
