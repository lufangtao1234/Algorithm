#include<stdio.h>
/*
������a[p...r]���л��֣����ػ��ֵ�λ��
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
������a[p...r]���п�������
*/
void QUICKSORT(int a[],int p,int r)
{
	if(p>=r)
		return ;
	int q=PARTITION(a,p,r);
	QUICKSORT(a,p,q-1);
	QUICKSORT(a,q+1,r);
}