#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SortData.h"
#include"QuickSort.h"
int main()
{
	clock_t start,finish;
	double duration;
	
	int wait;
	printf("Before Sort:");
	getRandData();
	printRandData();
	start=clock();
	QUICKSORT(randData,0,RAND_NUM-1);
	finish=clock();
	printf("After Sort:");
	printRandData();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "Sort Used time:%f seconds\n", duration );
	scanf("%d",&wait);
}

