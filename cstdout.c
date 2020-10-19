#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Write a program that creates a child process, and then in the child closes standard output (STDOUT_FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
*/

int main(){
    int rc = fork();
    // FILE f;
    if(rc < 0){
        printf("Fork Failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0){
        close(STDOUT_FILENO);
        int i;
        for(i = 0; i < 100; i++){
            printf("I won't print\n");
        }
    } else {
        wait(0);
        printf("Goodbye!\n");
        // parent
    }
}