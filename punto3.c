
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char**argv){
	pid_t pid,pid2;
   	int status;

        printf("********* Waitpid() para esperar el hijo ***********\n");
   	pid2 = fork();
   	if (pid2 == 0){
     		pid = waitpid(pid2,&status,0);
     		printf("Soy el hijo y terminé mi proceso\n");
  	} else {
    		printf("Soy el padre y terminé mi proceso\n");
  	}

	return 0;
}

