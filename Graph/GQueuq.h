#include"MGraph.h"
//定义图所使用到的队列
typedef struct GQueue
{
	VertexType vertex[MAX_VERTEX_NUM];
	int head;
	int tail;
	int length;
} GQueue;
/*
把元素x插入到队列q中
*/
void ENQUEUE(GQueue &q,VertexType x)
{
	if(q.head==q.tail+1)
	{
		printf("overflow!");
		return ;
	}
	q.vertex[q.tail]=x;
	if(q.tail==q.length)
		q.tail=0;
	else 
		q.tail++;
}
/*
出队列
*/
VertexType  DEQUEUE(GQueue &q)
{
	VertexType temp;
	if(q.head==q.tail)
	{
		printf("underflow!");
		return temp ;
	}
	temp=q.vertex[q.head];
	if(q.head==q.length)
		q.head=0;
	else
		q.head++;
	return temp;
}
//队列是否为空
bool IsEmpty(GQueue q)
{
	if(q.head==q.tail)
		return true;
	else 
		return false;
}