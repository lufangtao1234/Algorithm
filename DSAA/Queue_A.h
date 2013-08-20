#ifndef _QUEUE_A_H
#define _QUEUE_A_H

typedef int ElementType;
struct QueueARecord;
typedef struct QueueARecord *Queue;
int AQueue_IsEmpty(Queue Q);
int AQueue_IsFull(Queue Q);
Queue  AQueue_CreateQueue(int maxElement);
void AQueue_DisposeQueue(Queue Q);
void AQueue_MakeEmpty(Queue Q);
void AQueue_Enqueue(ElementType X,Queue Q);
ElementType AQueue_Front(Queue Q);
void AQueue_Dequeue(Queue Q);
ElementType AQueue_FrontAndDequeue(Queue Q);

#endif