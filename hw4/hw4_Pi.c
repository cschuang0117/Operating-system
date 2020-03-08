#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include<sys/time.h>
#include<string.h>

//struct timeval start[4], end[4];
pthread_t thread[4];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long pnum;
int tnum;
long long points = 0; 
long long sum[4] ={0};

void* count(void *arg){	
	unsigned int seed = time(NULL);
	double x, y;
	long long fuckyou = 0;
	if(tnum == 1){
		if(!strcmp((char *)arg, "first")){
//			gettimeofday(&start[0], 0);
			for(long long i = 0 ; i < pnum ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[0]+=fuckyou;
			points+=sum[0];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[0], 0);
//			int sec = end[0].tv_sec - start[0].tv_sec;
//			int usec = end[0].tv_usec - start[0].tv_usec;
		//	printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}
	}else if(tnum == 2){
		if(!strcmp((char *)arg, "first")){
//			gettimeofday(&start[0], 0);
			seed += 1;
			for(long long i = 0 ; i < pnum/2 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[0]+=fuckyou;
			points+=sum[0];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[0], 0);
//			int sec = end[0].tv_sec - start[0].tv_sec;
//			int usec = end[0].tv_usec - start[0].tv_usec;
			//printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "second")){
//			gettimeofday(&start[1], 0);
			seed += 2;
			for(long long i = pnum/2 ; i < pnum ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[1]+=fuckyou;
			points+=sum[1];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[1], 0);
//			int sec = end[1].tv_sec - start[1].tv_sec;
//			int usec = end[1].tv_usec - start[1].tv_usec;
		//	printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}
	}else if(tnum == 3){
		if(!strcmp((char *)arg, "first")){
//			gettimeofday(&start[0], 0);
			seed += 1;
			for(long long i = 0 ; i < pnum/3 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[0]+=fuckyou;
			points+=sum[0];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[0], 0);
//			int sec = end[0].tv_sec - start[0].tv_sec;
//			int usec = end[0].tv_usec - start[0].tv_usec;
//			printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "second")){
//			gettimeofday(&start[1], 0);
			seed += 2;
			for(long long i = pnum/3 ; i < (pnum/3)*2 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[1]+=fuckyou;
			points+=sum[1];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[1], 0);
//			int sec = end[1].tv_sec - start[1].tv_sec;
//			int usec = end[1].tv_usec - start[1].tv_usec;
//			printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "third")){
//			gettimeofday(&start[2], 0);
			seed += 3;
			for(long long i = (pnum/3)*2 ; i < pnum ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[2]+=fuckyou;
			points+=sum[2];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[2], 0);
//			int sec = end[2].tv_sec - start[2].tv_sec;
//			int usec = end[2].tv_usec - start[2].tv_usec;
		//	printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}
	}else if(tnum == 4){
		if(!strcmp((char *)arg, "first")){
//			gettimeofday(&start[0], 0);
			seed += 1;
			for(long long i = 0 ; i < pnum/4 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[0]+=fuckyou;
			points+=sum[0];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[0], 0);
//			int sec = end[0].tv_sec - start[0].tv_sec;
//			int usec = end[0].tv_usec - start[0].tv_usec;
//			printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "second")){
//			gettimeofday(&start[1], 0);
			seed += 2;
			for(long long i = pnum/4 ; i < pnum/2 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[1]+=fuckyou;
			points+=sum[1];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[1], 0);
//			int sec = end[1].tv_sec - start[1].tv_sec;
//			int usec = end[1].tv_usec - start[1].tv_usec;
	//		printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "third")){
//			gettimeofday(&start[2], 0);
			seed += 3;
			for(long long i = pnum/2 ; i < pnum - pnum/4 ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[2] += fuckyou;
			points+=sum[2];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[2], 0);
//			int sec = end[2].tv_sec - start[2].tv_sec;
//			int usec = end[2].tv_usec - start[2].tv_usec;
	//		printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}else if(!strcmp((char *)arg, "fourth")){
//			gettimeofday(&start[3], 0);
			seed += 4;
			for(long long i = pnum - pnum/4 ; i < pnum ; i++){
				x = (double)rand_r(&seed)/RAND_MAX;
				y = (double)rand_r(&seed)/RAND_MAX;
				if(x*x + y*y < 1)	fuckyou++;
			}
			pthread_mutex_lock(&mutex);
			sum[3]+=fuckyou;
			points+=sum[3];
			pthread_mutex_unlock(&mutex);
//			gettimeofday(&end[3], 0);
//			int sec = end[3].tv_sec - start[3].tv_sec;
//			int usec = end[3].tv_usec - start[3].tv_usec;
			//printf("elapsed %f ms\n", sec*1000+(usec/1000.0));
		}
	}
	
	pthread_exit(NULL);
}
int main() 
{ 
	// Initializing rand() 
	puts("0616241");
	scanf("%d %lld", &tnum, &pnum);
//	pthread_mutex_init(&mutex, NULL);
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
	// Total Random numbers generated = possible x 
	// values * possible y values 
	for(int i = 0 ; i < tnum ; i++)	pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&mutex);
	// Final Estimated Value 
//	cout << "\nFinal Estimation of Pi = " << pi; 
	for(int i = 0 ; i < tnum ; i++)
		printf("Thread %d,there are %lld points in the circle\n", i, sum[i]);
	printf("Pi:%lf\n", 4 * (double)points / (double)pnum);
	return 0; 
}
