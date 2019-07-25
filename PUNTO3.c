
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv){
   pid_t pid,pid2;
   int status;
        
   pid = fork();
   if (pid != 0){
     printf("soy el padre y termine mi proceso\n");
  } else{
    pid2 = wait(&status);
    int w= wait(NULL);
    printf("soy el hijo y termine mi proceso\n");
    
  }

 return 0;
}

    
