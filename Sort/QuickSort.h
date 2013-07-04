#include<stdio.h>
/*
对数组a[p...r]进行划分，返回划分的位置
*/
int PARTITION(int a[],int p,int r)
{
	int key=a[r];
	int i=p-1;
	int temp;
	for (int j = p; j < r; j++)
		if(a[j]<=key)
		{
			temp=a[j];
			a[j]=a[++i];
			a[i]=temp;
		}
		temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;
		return i+1;
}
/*
对数组a[p...r]进行快速排序
*/
void QUICKSORT(int a[],int p,int r)
{
	if(p>=r)
		return ;
	int q=PARTITION(a,p,r);
	QUICKSORT(a,p,q-1);
	QUICKSORT(a,q+1,r);
}