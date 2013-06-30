#include<stdio.h>
int sortData[]={1,4,2,3,9,7,8,5};
int sortLength=8;

void printSortData()
{
	for (int i = 0; i < 8; i++)
		printf("%4d",sortData[i]);
	printf("\n");
}