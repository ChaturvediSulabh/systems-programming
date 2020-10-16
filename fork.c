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
    if (rc < 0){
        printf("Fork failed, %d",rc);
        exit(1);
    } else if (rc == 0){
        printf("This is a Child Process of %d, (Child PID: %d)", pid, (int)getpid);
    } else {
        printf("This is a Parent Process (PID: %d)\n", (int)getpid);
    }
    return 0;
}