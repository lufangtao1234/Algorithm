#ifndef SORT_DATA
#define SORT_DATA
#include<stdio.h>
#include<stdlib.h>
#define RAND_NUM 10000
int sortData[]={1,4,2,3,9,7,8,5};
int sortLength=8;
int  *randData;

void printSortData()
{
	for (int i = 0; i < 8; i++)
		printf("%4d",sortData[i]);
	printf("\n");
}

void getRandData()
{
	int i=0;
	randData=(int*)malloc(RAND_NUM*sizeof(int));
	for ( i = 0; i < RAND_NUM; i++)
		randData[i]=1+(int)(RAND_NUM*1.0*rand()/(RAND_MAX+1.0)); 
}

void printRandData()
{
	int i=0;
	for ( i = 0; i < RAND_NUM; i++)
	{
		if(i%15==0)
			printf("\n");
		printf("%5d",randData[i]);
	}
	printf("\n");
}
#endif
