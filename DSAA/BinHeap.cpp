#include<stdio.h>
#include"BinHeap.h"
#include"Error.h"
struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

PriorityQueue Initialzie(int MaxElements)
{
	PriorityQueue H;
	if(MaxElements < MinLength)
		FateErrors("MaxElement is too smaller!");
	H=(PriorityQueue)malloc(sizeof(HeapStruct));
	if(!H)
		FateErrors("malloc is error!");
	H->Elements=(ElementType*)malloc(sizeof(ElementType)*(MaxElements+1));
	if(!(H->Elements))
		FateErrors("malloc is error!");
	H->Capacity=MaxElements;
	H->Size=0;
	H->Elements[0]=MinElement;
	return H;
}
int IsEmpty(PriorityQueue H)
{
	return H->Size==0;
}
int IsFull(PriorityQueue H)
{
	return H->Size==H->Capacity;
}
void Insert(ElementType X,PriorityQueue H)
{
	int i;
	if(IsFull(H))
	{
		FateErrors("Priority queue is full");
		return ;
	}
	for ( i = ++H->Size; H->Elements[i/2]>X ; i/=2)
		H->Elements[i]=H->Elements[i/2];
	H->Elements[i]=X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i,Child;
	ElementType M,LastElement;
	if(IsEmpty(H))
	{
		FateErrors("Priority queue is empty");
		return H->Elements[0];
	}
	M=H->Elements[1];
	LastElement=H->Elements[H->Size--];
	for ( i = 1; i*2 <H->Size ; i=Child)
	{
		Child=2*i;
		if(Child!=H->Size&&H->Elements[Child+1]<H->Elements[Child])
			Child++;
		if(LastElement>H->Elements[Child])
			H->Elements[i]=H->Elements[Child];
		else
			break;
	}
	H->Elements[i]=LastElement;
	return M;
}
void DecreaseKey(int position,ElementType key,PriorityQueue H)
{
	ElementType t;
	int i;
	if(position>=H->Size)
		FateErrors("Position is over!");
	H->Elements[position]-=key;
	for ( i = position; i >0; i/=2)
	{
		if(i/2==0)
			break;
		if(H->Elements[i/2]<H->Elements[i])
		{
			t=H->Elements[i/2];
			H->Elements[i/2]=H->Elements[i];
			H->Elements[i]=t;
		}else
			break;
	}
}


