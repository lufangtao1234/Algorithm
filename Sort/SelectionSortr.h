#include<stdio.h>
/*
选择排序：
数组a：待排序数组
length:数组长度
*/
void SelectionSort(int a[],int length)
{
	int i,j,min,swap,index;
	for ( i = 1; i < length; i++)
	{
		min=a[i-1];
		j=i;
		index=i-1;
		while (j<length)
		{
			if(a[j]<min)
			{
				min=a[j];
				index=j;
			}
			j++;
		}
		if(index!=i-1){
			swap=a[i-1];
			a[i-1]=min;
			a[index]=swap;
		}

	}
}