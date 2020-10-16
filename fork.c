#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
 Write a program that calls fork(). Before calling fork(), have the main process access a variable (e.g., x) and set its value to something (e.g., 100). 
 What value is the variable in the child process?
 What happens to the variable when both the child and parent change the value of x?
*/
int main(){
    fflush(stdout);

    int pid = getpid();
    printf("Starting program (PID: %d)\n", (int)pid);
    int x = 100;

    int rc = fork();
    /*
    RETURN VALUES
     Upon successful completion, fork() returns a value of 0 to the child
     process and returns the process ID of the child process to the parent
     process.
    */
    printf("rc: %d\n", (int)rc);
    if (rc < 0){
        printf("Fork failed, %d\n",rc);
        exit(1);
    } else if (rc == 0){
        printf("This is a Child Process of %d, (PID: %d)\n", pid, (int)getpid());
        printf("x = %d\n", (int)x);
        x++;
        printf("x = %d\n", (int)x);
    } else {
        printf("This is a Parent Process of %d, (PID: %d)\n",rc, (int)getpid());
        printf("x = %d\n", (int)x);
        x++;
        printf("x = %d\n", (int)x);
    }
    return 0;
}