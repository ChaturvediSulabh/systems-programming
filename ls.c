#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int rc = fork();
    if (rc < 0){
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0){
        //child
        printf("Child (PID: %D)\n", (int)getpid());
        char * argv_list[] = {"/bin/ls", "./", NULL};
        execv("/bin/ls", argv_list);
    } else {
        //parent
        printf("Parent of: %d\n", (int)rc);
    }
    return 0;
}