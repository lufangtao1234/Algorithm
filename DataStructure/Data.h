#include<stdio.h>
int SourceData[]={1,4,2,3,9,7,8,5};
int DesData[]={-1,-1,-1,-1,-1,-1,-1,-1};
int Length=8;

void printData(int data[])
{
	for (int i = 0; i < 8; i++)
		printf("%4d",data[i]);
	printf("\n");
}