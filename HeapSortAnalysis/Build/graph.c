#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define NUM_COMMANDS 1

int main(int argc, char *argv[])
{
	char *loc[]={"../testDatas/"};
	char str[41];
	strcpy(str, loc[0]);
	strcat(str, argv[1]);
	
	FILE *fp, *c;
	fp = fopen(str, "r");
	c = fopen(str, "r");
	
	int count = 0;
	char ch = getc(c);
	while(ch != EOF)
	{
		if(ch == '\n')
			count++;
		ch = getc(c);
	}
	printf("Number of entries: %d\n", count);
	fclose(c);
	
	int X[count];
	float Y[count];
	char x[21], y[21];
	int i = 0;
	while(!feof(fp))
	{
		fscanf(fp, "%s%s", x, y);
		X[i] = atoi(x);
		Y[i] = atof(y);
		i++;
	}
	fclose(fp);

	//char * commandsForGnuplot[] = {"set title \"MergeSort Analysis\", plot 'data.temp'"};
	//FILE * temp = fopen("data.temp", "w"); //Istructions are written to this file using temp in fprintf() instead of gnuplotPipe.
	FILE * gnuplotPipe = popen("gnuplot -persistent", "w");
	
	fprintf(gnuplotPipe, "set title \"MergeSort Analysis\"\n");
	fprintf(gnuplotPipe, "set xlabel \"Number of Inputs\"\n");
	fprintf(gnuplotPipe, "set ylabel \"Time taken \"\n");
	fprintf(gnuplotPipe, "plot '-' with points\n");
	for (i = 0; i < count; i++)
		fprintf(gnuplotPipe, "%d %lf\n", X[i], Y[i]);
	/*
	for (i=0; i < NUM_COMMANDS; i++)
	{
		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
	}
	This method uses a temporary file named data.temp for plotting.
	*/
	fprintf(gnuplotPipe, "e\n");
	fflush(gnuplotPipe);
	return 0;
}	
