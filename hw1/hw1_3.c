#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){
	pid_t pid, mainpid, child1, child2, child3;
	printf ("Main Process ID : %d\n", getpid());
	mainpid = getpid();
	pid = fork(); //fork1
	if(pid == 0){
		printf ("Fork 1. I'm the child %d, my parent is %d\n", getpid(), mainpid);
		child1 = getpid();
		pid = fork(); //fork2
		if(pid == 0){
			printf("Fork 2. I'm the child %d, my parent is %d\n",getpid(), child1);
			child2 = getpid();
			pid = fork(); //fork3
			if(pid == 0)	printf("Fork 3. I'm the child %d, my parent is %d\n", getpid(), child2);
			else if (pid > 0)	wait(NULL);
		}else if(pid > 0){
			pid = fork(); //fork2
			if(pid == 0){
				printf("Fork 2. I'm the child %d, my parent is %d\n", getpid(), child1);
				child3 = getpid();
				pid = fork(); //fork3
				if(pid == 0)	printf("Fork 3. I'm the child %d, my parent is %d\n", getpid(), child3);
				else if (pid > 0)	wait(NULL);
			}else if (pid > 0)	wait(NULL);
			wait(NULL);
		}
	}else if(pid > 0)	wait(NULL);
}
