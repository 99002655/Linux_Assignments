#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
int main()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	sleep(5);
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds*1000000)+end.tv_usec) - (start.tv_usec);
	printf("Time elapsed is %ld seconds and %ld micros\n", seconds, micros);
	return 0;
}
