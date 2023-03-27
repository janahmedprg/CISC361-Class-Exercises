#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t parent, child, grandchild;
    parent = getpid();
    if (fork() == 0){
        child = getpid();
        if(fork() == 0){
            grandchild = getpid();
            printf("I am the grandchild (#%d), where ‘#’ is the pid of the grandchild process\n",grandchild);
        }
        else{
            wait(NULL);
            printf("I am the child (#%d), where ‘#’ is the pid of the child process\n", child);
        }
    }
    else{
        wait(NULL);
        printf("I am the parent (#%d), where ‘#’ is the pid of the parent process\n",parent);
    }
    return 0;
}