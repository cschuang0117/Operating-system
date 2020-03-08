#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

pthread_t thread[4];
sem_t num[10];
long long len;
char* series;
int tnum;
long long sum[10] = {0};
void* count(void* arg){
	char *check = (char *)arg;
	//printf("wtf = = %s\n", check);
	if(tnum == 1){
		for(long long i = 0 ; i < len ; i++){
			sum[series[i]-'0']++;
		}
	}else if(tnum == 2){
		if(!strcmp(check, "first")){
			for(long long i = 0 ; i < len/2 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "second")){
			for(long long i = len/2 ; i < len ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}
	}else if(tnum == 3){
		if(!strcmp(check, "first")){
			for(long long i = 0 ; i < len/3 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "second")){
			for(long long i = len/3 ; i < (len/3) * 2 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "third")){
			for(long long i = (len/3)*2 ; i < len ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}
	}else if(tnum == 4){	
		if(!strcmp(check, "first")){
			for(long long i = 0 ; i < len/4 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "second")){
			for(long long i = len/4 ; i < (len/4) * 2 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "third")){
			for(long long  i = (len/4)*2 ; i < (len/4)*3 ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}else if(!strcmp(check, "fourth")){
			for(long long  i = (len/4)*3 ; i < len ; i++){
				sem_wait(&num[series[i]-'0']);
				sum[series[i]-'0']++;
				sem_post(&num[series[i]-'0']);
			}
		}
	}
	pthread_exit(NULL);
}
int main (int argc, const char * argv[]){
	puts("0616241");
	scanf("%d %lld", &tnum, &len);
	series = (char*)malloc((len + 10)* sizeof(char));
	scanf("%s", series);
	//puts(series);
	//printf("strlen = %d", strlen(series));
	for(int i = 0 ; i < 10 ; i++)
		sem_init(&num[i], 0, 1);
	if(tnum > 0){
		pthread_create(&thread[0], NULL, count, (void *)"first");
	//	puts("= =fuck you");
	}
	if(tnum > 1)
		pthread_create(&thread[1], NULL, count, (void *)"second");
	if(tnum > 2)
		pthread_create(&thread[2], NULL, count, (void *)"third");
	if(tnum > 3)
		pthread_create(&thread[3], NULL, count, (void *)"fourth");
	for(int i = 0 ; i < tnum ; i++){
		pthread_join(thread[i], NULL);
	}
	for(int i = 0 ; i < 10 ; i++)	printf("The total number of %d:%lld\n", i, sum[i]);
	for(int i = 0 ; i < 10 ; i++)	sem_destroy(&num[i]);
	free(series);
	return 0;
}
