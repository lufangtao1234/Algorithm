#include<stdio.h>
/*
冒泡排序：
数组a,需要排序数组
length为数组长度
*/
void BubbleSort(int *a,int length)
{
	int flage=0;
	int i=length-1;
	int j;
	int swap;
	for (; i >-1; i--)
	{
		if(flage==1)
			break;
		j=0;
		while(j<i)
		{flage=1;
		if(a[j+1]<a[j])
		{
			swap=a[j];
			a[j]=a[j+1];
			a[j+1]=swap;
			flage=0;
		}
		j++;
		}
	}
}