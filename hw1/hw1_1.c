#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_LINE 80

int main(void)
{
	//char *arg[MAX_LINE/2+1]; /*command line arguments*/
	int should_run = 1; /*flag to determine when to exit program*/
	
	while(should_run){
		//sleep(1);
		printf("osh>");
		char *arg[MAX_LINE/2+1];
		fflush(stdout);
		/*
		* your code!
		* After reading user input, the step are:
		* (1) fork a child process using fork()
		* (2) the child process will invoke execvp()
		* (3) if command included &, parent will not invoke wait()
		*/
		char buffer[500] = {0};
	//	printf("buffer = %s\n", buffer);
		fgets(buffer, sizeof(buffer), stdin);
		if(!strcmp(buffer,"\n"))	continue;
		char *pch;
		pid_t pid;
		//printf("buffer = %s", buffer);
		pch = strtok(buffer, " \n");
		//printf("pch = %s+++\n",pch);
		int i = 1;
		arg[0] = pch;
		while (pch != NULL){
			pch = strtok(NULL, " \n");
			arg[i] = pch;
			//printf("arg[%d] = %s+++\n", i, arg[i]);
			i++;
		}
		//printf("arg[i - 2] = %s\n", arg[i - 2]);
		if(strcmp(arg[0],"exit")){
			pid = fork();
			if (pid == 0){
				if(!strcmp(arg[i - 2],"&"))	arg[i - 2] = NULL;
				execvp(arg[0], arg);
				fprintf(stderr, "Child process could not do execvp\n");
				exit(0);
			}else if (pid > 0){
				if(strcmp(arg[i - 2],"&")){
					waitpid(pid, NULL, 0);
					//printf("Child Complete already waited, pid = %d\n", pid);
				}else{
					waitpid(pid,NULL,WNOHANG);
					//printf("zombie child no wait, pid = %d\n", pid);
				}
			}
		}else	exit(0);
	}
	return 0;
}

