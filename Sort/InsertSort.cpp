#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SortData.h"
#include"InsertSort.h"
#include"SelectionSortr.h"
#include"MergeSort.h"
int main()
{
	clock_t start,finish;
	double duration;
	start=clock();
	int wait;
	printf("Before Sort:");
	printSortData();
	//InsertSort(sortData,sortLength);
	//SelectionSort(sortData,sortLength);
	MergeSort(sortData,0,7);
	printf("After Sort:");
	printSortData();
	finish=clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "%f seconds\n", duration );
	scanf("%d",&wait);
}

