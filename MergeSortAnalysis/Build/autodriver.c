#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char * argv[])
{
	for(int c = 1; c <= atoi(argv[1]); c+=atoi(argv[2]))
	{
		clock_t start=clock(); //clock begin
		srand(time(NULL));
		int *a, N, sw;
		if(argc < 3)
			printf("Not enough arguments: N, sw and file name required!!\n");
		else
		{
			N=atoi(argv[1]);
			sw=atoi(argv[2]);
			a=malloc(c * sizeof(int));
			srand(time(0));
			if(sw)
				for(int i = 0; i < c; i++)
					a[i]=rand()%10000+1;
			else
				while(scanf("%d", &a[N]) == 1)
					N++;
			printf("Initial Array...\n");
			for(int i=0; i < c; i++)
				printf("%d ", a[i]);
			merge_sort(a, 0, c-1);
			printf("\nSorted Array...\n");
			for(int i=0; i < c; i++)
				printf("%d ", a[i]);
		}
		clock_t end=clock();
		double seconds=((double)(end-start))/CLOCKS_PER_SEC; //time
		printf("\n Time taken: %f \n", seconds);
		char *loc[]={"./testDatas/"};
		char str[41];
		strcpy(str, loc[0]);
		strcat(str, argv[3]);
		FILE *fp = fopen(str, "a");
		fprintf(fp, "%d\t%f\n", c, seconds);
		fclose(fp);
	}
	return 0;
}
