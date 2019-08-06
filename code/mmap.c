#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(void) {
  int *shared = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0); 
  int childPid;
  int childStatus;

  *shared = 0;

  if ((childPid = fork()) == 0) {
    // Child
    for (int i = 0; i < 10; i++) {
      printf("I'm pid %d and shared is now %d\n", getpid(), (*shared)++);
    }
  } else {
    // Parent
    for (int i = 0; i < 10; i++) {
      printf("I'm pid %d and shared is now %d\n", getpid(), (*shared)++);
    }
    waitpid(childPid, &childStatus, 0); // wait for child
  }
  return 0;
}