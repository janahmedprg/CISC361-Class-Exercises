Commands:
gcc singleThread.c -o singleThread.exe
./singleThread
gcc multiThread.c -o multiThread.exe
./multiThread.exe

Answers to questions:
When running the single threaded program the average time taken to sum
is around 0.1 seconds. When having only two processes the average is around
0.1 seconds as well.

When increasing the number of threads the average time starts to get little
bit higher. But then goes down after 50. When we increase the number of
threads to 100-500 we get an average of 0.05 seconds.