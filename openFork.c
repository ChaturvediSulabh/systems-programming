#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
Write a program that opens a file (with the open() system call) and then calls fork() to create a new process. Can both the child and parent access the file descriptor returned by open()? What happens when they are writing to the file concurrently, i.e., at the same time?
 */

int main(){
    fflush(stdout);
    int pid = getpid();
    printf("Started with PID: %d\n", pid);

    int fd = open("sample.yml", O_CREAT, 0744);
    if (fd < 0){
        printf("Failed to open the file %d\n", fd);
        exit(1);
    } else{
         FILE *fptr;
         fptr = fopen("sample.yml", "a");
        int rc =  fork();
        if(rc < 0){
            printf("Fork Failed, %d\n", rc);
        }else if(rc == 0){
            printf("Child Process of %d (PID: %d)\n", pid, (int)getpid());
            int i;
            for (i = 0; i < 100; i++){
              fputs("- message: Written from a child process\n",fptr);
            }
        }else{
            printf("Parent Process of %d\n", rc);
            int j;
            for (j = 0; j < 100; j++){
              fputs("- message: Written from a parent process\n",fptr);
            }
        }
        fclose(fptr);
    }
    return 0;
}

// This is not yet a correct answer as concurrency is not achieved. 
// Marking as Working in Progress