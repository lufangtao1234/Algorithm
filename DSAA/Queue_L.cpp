#include<stdio.h>
#include<stdlib.h>
#include"Queue_L.h"
#include"Error.h"
struct QueueNode
{
	ElementType Element;
	PtrToQueueNode Next;

};
struct LQueueNode
{
	PtrToQueueNode head;
	PtrToQueueNode rear;
};

LQueue LQueue_CreateQueue()
{
	LQueue q=(PtrToLQueue)malloc(sizeof(LQueueNode));
	PtrToQueueNode p=(PtrToQueueNode)malloc(sizeof(QueueNode));
	p->Next=NULL;
	if(q==NULL)
		FateErrors("malloc error!");
	q->head=p;
	q->rear=p;

	return q;
}
void LQueue_DisposeQueue(LQueue Q)
{

}
int LQueue_IsEmpty(LQueue Q)
{
	return Q->head==Q->rear;
}
void LQueue_MakeEmpty(LQueue Q)
{

}
void LQueue_Enqueue(ElementType X,LQueue Q)
{
	PtrToQueueNode p=(PtrToQueueNode)malloc(sizeof(QueueNode));
	p->Element=X;
	p->Next=Q->rear->Next;
	Q->rear->Next=p;
	Q->rear=p;
}
void LQueue_Dequeue(LQueue Q)
{
	if(LQueue_IsEmpty(Q))
		FateErrors("Queue is Empty!");
	Q->head=Q->head->Next;
}
ElementType LQueue_Front(LQueue Q)
{
	if(LQueue_IsEmpty(Q))
		FateErrors("Queue is Empty!");
	return Q->head->Next->Element;
}