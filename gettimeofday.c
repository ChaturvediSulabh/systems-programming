#include <sys/time.h>

int main(){
    int run = gettimeofday();
    if (run < 0){
        printf("Failed to run gettimeofday\n");
    }
    return 0;
}