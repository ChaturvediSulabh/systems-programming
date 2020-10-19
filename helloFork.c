#include <stdio.h>
#include <unistd.h>

/*
Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
*/
int main(){
    int rc = fork();
    if (rc < 0){
        printf("fork failed");
    } else if (rc == 0){
        printf("Hello\n");
        // child
    } else {
        sleep(1);
        printf("GoodBye!\n");
        //parent
    }
    return 0;
}