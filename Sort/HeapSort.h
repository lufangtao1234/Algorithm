#include<stdio.h>
#include<stdlib.h>
int heap_size=0;
int array_length=0;

/*
���ؽ��i������
*/
int LEFT(int i)
{
	return 2*i;
}
/*
���ؽ��i���ҽ��
*/
int RIGHT(int i)
{
	return 2*i+1;
}
/*
���ؽ��i�ĸ��ڵ�
*/
int PARENT(int i)
{
	return i/2;
}
/*
������������
LEFT(i)��RIGHT(i)Ϊ����
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
������a����������
*/
void BUILD_MAX_HEAP(int a[])
{
	heap_size=array_length;
	for (int i = heap_size/2; i >= 0; i--)
		MAX_HEAPIFY(a,i);
}
/*
������
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