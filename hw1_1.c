#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_LINE 80

int main(void)
{
	char *arg[MAX_LINE/2+1]; /*command line arguments*/
	int should_run = 1; /*flag to determine when to exit program*/
	
	while(should_run){
		printf("osh>");
		fflush(stdout);
		/*
		* your code!
		* After reading user input, the step are:
		* (1) fork a child process using fork()
		* (2) the child process will invoke execvp()
		* (3) if command included &, parent will not invoke wait()
		*/
		char buffer[500] = {0};
		//printf("buffer = %s", buffer);
		fgets(buffer, sizeof(buffer), stdin);
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
				execvp(arg[0], arg);
			//	printf("Done\n");	
			}else{
				if(strcmp(arg[i - 2],"&")){
					wait (NULL);
					printf("Child Complete\n");
				}
			}
		}else
			exit(0);
	}

	return 0;
}

