#include <stdio.h>
#include <stdlib.h>

/* function definitions */
void sort(int list[], int n);

int num[1000000];

int main (int argc, const char * argv[]) 
{
	/* Use STDIN (e.g. scanf, cin) to take the input */
	int n = 0;
	while(scanf("%d", &num[n]) != EOF){
		n++;
	//	printf("n = %d\n", n);
	}
	/* Do the sorting */
	sort(num, n);	
	for(int i = 0 ; i < n ; i++){
		printf("%d ", num[i]);
	}
	printf("\n");
	/* Use STDOUT (e.g. printf, cout) to output the sorted array */
	/*
		your code here
	*/

    return 0;
}

void sort(int list[], int n)
{
	// Sorting algorithm can be brute‐force methods, e.g., bubble sort 
	/*
		your code here
	*/
	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			if(list[i] > list[j]){
				int temp;
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}	
	}
}

