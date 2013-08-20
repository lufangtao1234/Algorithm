#ifndef _QUEUE_L_H
#define _QUEUE_L_H
typedef int ElementType;
struct QueueNode;
typedef struct QueueNode *PtrToQueueNode;
struct LQueueNode;
typedef struct LQueueNode *PtrToLQueue;
typedef PtrToLQueue LQueue;


int LQueue_IsEmpty(LQueue Q);
int LQueue_IsFull(LQueue Q);
LQueue  LQueue_CreateQueue();
void LQueue_DisposeQueue(LQueue Q);
void LQueue_MakeEmpty(LQueue Q);
void LQueue_Enqueue(ElementType X,LQueue Q);
ElementType LQueue_Front(LQueue Q);
void LQueue_Dequeue(LQueue Q);
ElementType LQueue_FrontAndDequeue(LQueue Q);
#endif