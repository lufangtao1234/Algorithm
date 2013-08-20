#include<stdio.h>
#include<stdlib.h>
#include"Queue_A.h"
#include"Error.h"
struct QueueARecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

Queue AQueue_CreateQueue(int maxElements)
{
	Queue q=(Queue)malloc(sizeof(QueueARecord));
	if(q==NULL)
		FateErrors("Malloc error!");
	q->Array=(ElementType*)malloc(sizeof(ElementType)*maxElements);
	if(q->Array==NULL)
		FateErrors("Malloc error!");
	q->Capacity=maxElements;
	q->Front=-1;
	q->Rear=-1;
	q->Size=0;
	return q;
}
void AQueue_DisposeQueue(Queue Q)
{
	if(Q!=NULL)
	{
		if(Q->Array!=NULL)
			free(Q->Array);
		free(Q);
	}
}
void AQueue_MakeEmpty(Queue Q)
{
	if(Q!=NULL)
	{
		Q->Front=0;
		Q->Rear=0;
		Q->Size=0;
	}
}

int AQueue_IsEmpty(Queue Q)
{
	if(Q==NULL)
		FateErrors("Q is NULL");
	return Q->Size==0;
}
int AQueue_IsFull(Queue Q)
{
	if(Q==NULL)
		FateErrors("Q is NULL");
	return Q->Size==Q->Capacity;	
}
void AQueue_Enqueue(ElementType X,Queue Q)
{
	if(Q==NULL)
		FateErrors("Q is NULL");
	if(AQueue_IsFull(Q))
		FateErrors("Q is Full");
	Q->Array[Q->Rear]=X;
	Q->Size++;
	if(Q->Rear==Q->Capacity-1)
		Q->Rear=0;
	else 
		Q->Rear++;

}
void AQueue_Dequeue(Queue Q)
{
	if(Q==NULL)
		FateErrors("Q is NULL");
	if(AQueue_IsEmpty(Q))
		FateErrors("Q is Empty");
	if(Q->Front==Q->Capacity-1)
		Q->Front=0;
	else
		Q->Front++;
	Q->Size--;

}

ElementType AQueue_Front(Queue Q)
{
	if(Q==NULL)
		FateErrors("Q is NULL");
	if(AQueue_IsEmpty(Q))
		FateErrors("Q is Empty");
	return Q->Array[Q->Front];
}
ElementType AQueue_FrontAndDequeue(Queue Q)
{
	ElementType x=AQueue_Front(Q);
	AQueue_Dequeue(Q);
	return x;
}