#include<stdio.h>
#include<stdlib.h>
#include"SortData.h"
void CountSort(int a[],int length)
{
	int *C=(int*)malloc(RAND_NUM*sizeof(int));;
	int *b=(int*)malloc(length*sizeof(int));;
	int i,j,k;
	for ( i = 0; i < RAND_NUM+1; i++)
		C[i]=0;
	for (j = 0; j < length; j++)
		C[a[j]]++;
	for ( i = 1; i < RAND_NUM+1; i++)
		C[i]=C[i]+C[i-1];
	for (k= length-1; k>-1 ; k--)
	{
		b[C[a[k]]]=a[k];
		C[a[k]]--;
	}
	for ( k = 0; k < length; k++)
		a[k]=b[k];
}