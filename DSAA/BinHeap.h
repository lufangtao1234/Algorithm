#ifndef _BINHEAP_H
#define _BINHEAP_H
#define MinElement -1
#define MinLength 10
typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialzie(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void DecreaseKey(int Position,ElementType key,PriorityQueue H);
void IncreaseKey(int Position,ElementType key,PriorityQueue H);
void Delete(int Position,PriorityQueue H);

#endif