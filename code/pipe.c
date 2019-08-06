#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 

char* msg1 = "Creeper"; 
char* msg2 = "Aw Man"; 
char* msg3 = "So we back in the mine";

#define MAX_BUFFER 128

int main() 
{ 
    int p[2], pid; // could use struct instead of p[]
  
    if (pipe(p) < 0) {
        fprintf(stderr, "Pipe Failed" ); 
        return 1;
    }
  
    if ((pid = fork()) > 0) { 
        // Parent process, let's read
        // close(p[1]); // Close the input side since we don't need it.
        printf("Reading\n"); 
        int nbytes;
        char readBuffer[MAX_BUFFER];
        while ((nbytes = read(p[0], readBuffer, MAX_BUFFER)) > 0) {
            printf("Read %d bytes: %s\n", nbytes, readBuffer); 
        }
    } else {
      // Child process, let's write
        // close(p[0]); // Close the output side since we don't need it
        write(p[1], msg1, strlen(msg1)+1); // +1 to include NULL character, or just use sizeof
        sleep(1);
        write(p[1], msg2, strlen(msg2)+1); 
        sleep(1);
        write(p[1], msg3, strlen(msg3)+1); 
        return(0); // Child is done.
    }
    return 0; 
} 