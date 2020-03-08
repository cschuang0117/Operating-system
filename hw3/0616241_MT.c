#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int num[1000000], n = 0;
pthread_t thread[7];
int ans[1000000], tmp[2][500000];
/* function definitions */
void sortnum(int list[], int start, int n){
	// Sorting algorithm can be brute‐force methods, e.g., bubble sort 
	/*
		your code here
	*/
	for(int i = start ; i < n ; i++){
		for(int j = i  + 1 ; j < n ; j++){
			if(list[i] > list[j]){
				int temp;
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}	
	}
}
void* sort(void* arg){
	char *type = (char *) arg;
	//printf("type = %s\n", type);
	if(!strcmp(type,"first")){
		sortnum(num, 0, n/4);
	//	puts("thread 1 complete...");
	}else if(!strcmp(type, "second")){
		sortnum(num, n/4, n/2);
	//	puts("thread 2 complete...");
	}else if(!strcmp(type, "third")){
		sortnum(num, n/2, n/2 + n/4);
	//	puts("thread 3 complete...");
	}else if(!strcmp(type, "fourth")){
		sortnum(num, n/2 + n/4, n);
	//	puts("thread 4 complete...");
	}
	pthread_exit(NULL);
}
void* merge(void* arg){
	if(!strcmp(arg, "first")){
		pthread_join(thread[3], NULL);
		pthread_join(thread[4], NULL);
		int flag1 = 0, flag2 = n/4;
		for(int i = 0 ; i < n/2 ; i++){
			if(flag1 != n/4 && flag2 != n/2){
				if(num[flag1] <= num[flag2]){
					tmp[0][i] = num[flag1];
					flag1++;
				}
				else{
					tmp[0][i] = num[flag2];
					flag2++;
				}
			}else if(flag1 == n/4 && flag2 != n/2){
				tmp[0][i] = num[flag2];
				flag2++;
			}else if(flag2 == n/2 && flag1 != n/4){
				tmp[0][i] = num[flag1];
				flag1++;
			}
		}
	//	for(int i = 0 ; i < n / 2 ; i++)	printf("tmp0 = %d\n", tmp[0][i]);
	}else if(!strcmp(arg, "second")){
		pthread_join(thread[5], NULL);
		pthread_join(thread[6], NULL);
		//...
		int flag1 = n/2, flag2 = n/2 + n/4;
		for(int i = 0 ; i < n / 2 ; i++){	
			if(flag1 != n/2 + n/4 && flag2 != n){
				if(num[flag1] <= num[flag2]){
					tmp[1][i] = num[flag1];
					flag1++;
				}
				else{
					tmp[1][i] = num[flag2];
					flag2++;
				}
			}else if(flag1 == n/2 + n/4 && flag2 != n){
				tmp[1][i] = num[flag2];
				flag2++;
			}else if(flag2 == n && flag1 != n/2 + n/4){
				tmp[1][i] = num[flag1];
				flag1++;
			}
		}
	//	for(int i = 0 ; i < n / 2 ; i++)	printf("tmp1 = %d\n", tmp[1][i]);
	}else if(!strcmp(arg, "third")){
		pthread_join(thread[0], NULL);
		pthread_join(thread[1], NULL);
		//...
		int flag1 = 0, flag2 = 0;
		for(int i = 0 ; i < n ; i++){
			if(flag1 != n/2 && flag2 != n/2){
				if(tmp[0][flag1] <= tmp[1][flag2]){
					ans[i] = tmp[0][flag1];
					flag1++;
				}else{
					ans[i] = tmp[1][flag2];
					flag2++;
				}
			}else if(flag1 == n/2 && flag2 != n/2){
				ans[i] = tmp[1][flag2];
				flag2++;
			}else if(flag2 == n/2 && flag1 != n/2){
				ans[i] = tmp[0][flag1];
				flag1++;
			}
		}
	}
	pthread_exit(NULL);
}

int main (int argc, const char * argv[]) 
{
	/* Use STDIN (e.g. scanf, cin) to take the input */
	while(scanf("%d", &num[n]) != EOF){
		n++;
	//	printf("n = %d\n", n);
	}
	/* Do the sorting */
	pthread_create(&thread[3], NULL, sort, "first");
	pthread_create(&thread[4], NULL, sort, "second");
	pthread_create(&thread[5], NULL, sort, "third");
	pthread_create(&thread[6], NULL, sort, "fourth");
	
	pthread_create(&thread[0], NULL, merge, "first");
	pthread_create(&thread[1], NULL, merge, "second");
	pthread_create(&thread[2], NULL, merge, "third");
	
	pthread_join(thread[2], NULL);
	for(int i = 0 ; i < n ; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	/* Use STDOUT (e.g. printf, cout) to output the sorted array */
	/*
		your code here
	*/

    return 0;
}
