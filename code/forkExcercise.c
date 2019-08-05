#include  <stdio.h>
#include <unistd.h>
#include  <sys/types.h>

int main(void) {
  printf("Hello from pid: %d\n", getpid());
  int fork1 = fork(); // actually a pid_t
  printf("Forked! I'm pid %d and fork returned %d\n", getpid(), fork1);
  int fork2 = fork(); // actually a pid_t
  printf("Forked again! I'm pid %d and fork returned %d\n", getpid(), fork2);
  return 0;
}