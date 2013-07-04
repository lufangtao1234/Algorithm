#include<stdio.h>
#include<stdlib.h>
int heap_size=0;
int array_length=0;

/*
返回结点i的左结点
*/
int LEFT(int i)
{
	return 2*i;
}
/*
返回结点i的右结点
*/
int RIGHT(int i)
{
	return 2*i+1;
}
/*
返回结点i的父节点
*/
int PARENT(int i)
{
	return i/2;
}
/*
保持最大堆性质
LEFT(i)和RIGHT(i)为最大堆
*/
void MAX_HEAPIFY(int a[],int i)
{
	int r=RIGHT(i);
	int l=LEFT(i);
	int largest=-1;
	int temp;
	if((l<=heap_size)&&(a[l]>a[i]))
		largest=l;
	else 
		largest=i;
	if((r<=heap_size)&&(a[r]>a[largest]))
		largest=r;
	if(largest!=-1&&largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		MAX_HEAPIFY(a,largest);
	}

}
/*
对数组a，建立最大堆
*/
void BUILD_MAX_HEAP(int a[])
{
	heap_size=array_length;
	for (int i = heap_size/2; i >= 0; i--)
		MAX_HEAPIFY(a,i);
}
/*
堆排序
*/
void HEAPSORT(int a[],int length)
{
	int temp;
	array_length=length;
	BUILD_MAX_HEAP(a);
	for (int i = array_length; i >0; i--)
	{
		temp=a[0];
		a[0]=a[heap_size];
		a[heap_size]=temp;
		heap_size--;
		MAX_HEAPIFY(a,0);
	}
}