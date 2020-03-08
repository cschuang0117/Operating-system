#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
int tnum;
long long len;
char* series;
long long sum[10];
int main (int argc, const char * argv[]){
	//puts("0616241");
	scanf("%d", &tnum);
	puts("wtf");
	scanf("%lld", &len);
	for(int i = 0 ; i < 10 ; i++)	sum[i] = 0;
	series = (char*)malloc((len + 10)* sizeof(char));
	puts("hi");
	scanf("%s", series);
	puts("hihi");
	//puts(series);
	//printf("strlen = %d", strlen(series));
	for(long long i = 0 ; i < len ; i++){
//		puts("1");
		sum[series[i]-'0']++;
	}
	for(int i = 0 ; i < 10 ; i++)	printf("The total number of %d:%lld\n", i, sum[i]);
	free(series);
	return 0;
}
