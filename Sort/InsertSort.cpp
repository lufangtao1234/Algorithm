#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SortData.h"
#include"CountSort.h"
int main()
{
	clock_t start,finish;
	double duration;

	int wait;
	printf("Before Sort:");
	getRandData();
	printRandData();
	start=clock();
	CountSort(randData,RAND_NUM);
	finish=clock();
	printf("After Sort:");
	printRandData();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "Sort Used time:%f seconds\n", duration );
	scanf("%d",&wait);
}

