# Commands:
```
gcc q1BinSemaphore.c -o q1BinSemaphore.exe
./q1BinSemaphore.exe
gcc q2ProdCons.c -o q2ProdCons.exe
./q2ProdCons.exe
```

# Summary:
When we alter the NumProducer and NumConsumer to 5 and 2 respectively
we get into a deadlock situation. When we set NumProducer to 0 nothing
outputs because the consumers are waiting for producers to place in the
buffer but they never do so the consumers will wait forever (deadlock).
When we set NumConsumer to 0 the producers will fill up the buffer
and since no consumer will take away from the buffer the program
will never terminate becase the producers are waiting for consumers
to consume (deadlock).