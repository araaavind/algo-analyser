#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void maxHeapify(int [], int, int);
void heap_sort(int [], int);
void buildHeap(int [], int); 

int main(int argc, char * argv[])
{
	clock_t start=clock(); //clock begin
	srand(time(NULL));
	int *A, N, sw;
	if(argc < 3)
		printf("Not enough arguments: N and sw required!!\n");
	else
	{
		N=atoi(argv[1]);
		sw=atoi(argv[2]);
		A=malloc(N * sizeof(int));
		srand(time(0));
		if(sw)
			for(int i = 0; i < N; i++)
				A[i]=rand()%100+1;
		else
		{
		    int c = 0;
			while(c < N && (scanf("%d", &A[c]) == 1))
				c++;
		}
		printf("Initial Array...\n");
		for(int i=0; i < N; i++)
			printf("%d ", A[i]);
		heap_sort(A, N);
		printf("\nSorted Array...\n");
		for(int i=0; i < N; i++)
			printf("%d ", A[i]);
	}
	clock_t end=clock();
	double seconds=((double)(end-start))/CLOCKS_PER_SEC; //time
	printf("\n Time taken: %f \n", seconds);
	
	char *loc[]={"./testDatas/"};
	char str[41];
	strcpy(str, loc[0]);
	strcat(str, argv[3]);
	FILE *fp = fopen(str, "a");
	fprintf(fp, "%d\t%f\n", N, seconds);
	fclose(fp);
	
	return 0;
}
