#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//write a program that uses wait() to wait for the child process to finish in the parent.

int main(){
    int rc = fork();
    if (rc < 0){
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0){
        // child
        printf("Hello from the child, pid: %d\n", (int)getpid());
    } else {
        // master
        int cpid = wait(0);
        /* wait():
           on success, returns the process ID of the terminated child;
           on error, -1 is returned.
        */
       if (cpid < 0){
           printf("Program error, unable to gracefully shutdown the child process");
           exit(EXIT_FAILURE);
       }
       printf("Suucessfully terminated pid: %d\nGoodBye!\n",(int)cpid);
    }
    return 0;
}