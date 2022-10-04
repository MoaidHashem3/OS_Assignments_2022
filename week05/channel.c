#include<stdio.h>
#include<unistd.h>

int main() {
   int fd[2];
   char writemessages[256];
   char readmessage[256];
   if (pipe(fd)== -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   int pid = fork();
   if (pid == 0) {
      
      close(fd[0]);
      scanf("%256[0-9a-zA-Z ]", writemessages);
      write(fd[1], writemessages, sizeof(char[256]));
      close(fd[1]);
   } else { 
      close(fd[1]);
      read(fd[0], readmessage, sizeof(char[256]));
      printf("%s",readmessage);
      close(fd[0]);
     
   }
   return 0;
}