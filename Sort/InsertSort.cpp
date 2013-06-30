#include<stdio.h>
#include"SortData.h"
#include"InsertSort.h"
int main()
{
	int wait;
	printf("Before Sort:");
	printSortData();
	InsertSort(sortData,sortLength);
	printf("After Sort:");
	printSortData();
	scanf("%d",&wait);
}

