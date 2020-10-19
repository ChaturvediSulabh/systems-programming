#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the pipe() system call.
*/

/*
A pipe is a system call that creates a unidirectional communication link between two file descriptors. The pipe system call is called with a pointer to an array of two integers. Upon return, the first element of the array contains the file descriptor that corresponds to the output of the pipe (stuff to be read). The second element of the array contains the file descriptor that corresponds to the input of the pipe (the place where you write stuff). Whatever bytes are sent into the input of the pipe can be read from the other end of the pipe.
 */
int main(){
    int i;
    int fd[2];
    char *data = "Hello From child 1";
    char buf[1025];
    pipe(fd);


    // for (i = 0; i < 2; i++){
    //     int rc = fork();
    //     int status;
    //     int fD = fileno(STDOUT_FILENO);
    //     if (rc < 0){
    //         printf("Fork Failed\n");
    //         exit(EXIT_FAILURE);
    //     } else if (rc == 0){
    //         // child
    //         if (i == 0 ){
    //             write(fd[fD], data, strlen(data));
    //         } else {
    //             int n;
    //             if ((n = read(fd[fD], buf, 1024)) >= 0) {
	// 	            buf[n] = 0;	/* terminate the string */
	// 	            printf("read %d bytes from the pipe: \"%s\"\n", n, buf);
    //                 close(STDOUT_FILENO);
    //             }	
    //             else{
    //                 perror("read");
    //             }
    //         }
    //     } else {
    //         // parent
    //         waitpid(rc, &status, 0);
    //         printf("GoodBye!");
    //     }
    // }

    return 0;
}