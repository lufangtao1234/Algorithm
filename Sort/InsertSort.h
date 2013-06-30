#include<stdio.h>
void InsertSort(int a[],int length)
{
	int key;
	int j;
	if(length<=0)
		return ;
	for (int i = 1; i < length; i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	
}