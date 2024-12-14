#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ 0
#define WRITE 1

int main() {
  int fds[2];
  pipe( fds );
  char line[100];
  char buffer[100];

  pid_t f = fork();
  if (f == 0) {
    close( fds[WRITE] ); 
    ssize_t bytes = read( fds[READ], buffer, sizeof(buffer)-1 );
    buffer[bytes] = '\0';
    printf("pid %d: Recieved message: %s\n",getpid(),buffer);
  }
  else {
    close( fds[READ] );
    printf("pid %d: Enter message: ",getpid());
    fgets(line,sizeof(line),stdin);
    write( fds[WRITE], line, strlen(line));
  }
}