#include"MGraph.h"
//����ͼ��ʹ�õ��Ķ���
typedef struct GQueue
{
	VertexType vertex[MAX_VERTEX_NUM];
	int head;
	int tail;
	int length;
} GQueue;
/*
��Ԫ��x���뵽����q��
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
������
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
//�����Ƿ�Ϊ��
bool IsEmpty(GQueue q)
{
	if(q.head==q.tail)
		return true;
	else 
		return false;
}