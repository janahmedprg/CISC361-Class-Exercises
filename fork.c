#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t parent, child, grandchild;
    parent = getpid();
    fork();
    child = getpid();
    if (child != parent){
        fork();
        grandchild = getpid();
        if(grandchild != child){
            printf("I am the grandchild (#%d), where ‘#’ is the pid of the grandchild process\n",grandchild);
            printf("I am the child (#%d), where ‘#’ is the pid of the child process\n", child);
            printf("I am the parent (#%d), where ‘#’ is the pid of the parent process\n",parent);
        }
    }
    return 0;
}