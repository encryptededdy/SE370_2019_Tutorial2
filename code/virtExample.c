#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
    int *data = malloc(sizeof(int));
    *data = 9001;
    int fork1 = fork(); // actually a pid_t
    if (fork1 == 0) {
        *data = 9000;
    }
    printf("Forked! I'm pid %d and the data is at %p is %d\n", getpid(), data, *data);
    return 0;
}