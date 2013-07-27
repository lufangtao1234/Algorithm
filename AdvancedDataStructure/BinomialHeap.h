#include<stdio.h>
#include<stdlib.h>
#define MIN -1
#define MAX 10000
struct BinomialHeap
{
	int key;//�ؼ���
	BinomialHeap * parent;//ָ�򸸽ڵ�
	BinomialHeap *child;//�ӽڵ�
	BinomialHeap *sibling;//�ֵܽڵ�
	int degree;//�ڵ���Ů����
};
/*
��ӡ����� (right)
*/
void BinomialHeapPrint(BinomialHeap *head)
{
	if(head==NULL)
		return ;
	printf("Key is :%d",(*head).key);
	if((*head).sibling!=NULL){
		printf("The Slibling :\n");
	}
	BinomialHeapPrint((*head).sibling);
	if((*head).child!=NULL){
		printf("The Child :\n");
		BinomialHeapPrint((*head).child);
	}
}
/*
����һ���յĶ����
*/
BinomialHeap * BinomialHeapMake()
{
	BinomialHeap *head=(BinomialHeap*)malloc(sizeof(BinomialHeap));
	(*head).parent=NULL;
	(*head).child=NULL;
	(*head).sibling=NULL;
	(*head).degree=0;
	return head;
}

/*
��linked��link��������linkΪ���ڵ�
*/
void BinomialHeapLink(BinomialHeap*&linked,BinomialHeap*&link)
{
	(*linked).parent=link;
	(*linked).sibling=(*link).child;
	(*link).child=linked;
	(*link).degree++;
}
/*���ض������С��㣬��ɾ���˽��*/
BinomialHeap *BinomialHeapMinExtr(BinomialHeap *&head)
{
	BinomialHeap *t=head;
	BinomialHeap *min=NULL;
	BinomialHeap *minParent=head;
	int minDegree;
	if(head==NULL)
		return NULL;
	min=t;
	minDegree=(*min).degree;
	while ((*t).sibling!=NULL)
	{
		if((*((*t).sibling)).degree<minDegree)
		{
			minParent=t;
			min=(*t).sibling;
			minDegree=(*((*t).sibling)).degree;
		}
		t=(*t).sibling;
	}
	//ɾ�����
	if(min==head)
		head=(*min).sibling;
	else
		(*minParent).sibling=(*min).sibling;
	(*min).sibling=NULL;
	return min;
}
/*
���ն���ѵĶȵ�������
*/
BinomialHeap * BinomialHeapDegreeASCSort(BinomialHeap *head)
{
	BinomialHeap *temp=head;
	BinomialHeap *r=BinomialHeapMinExtr(head);
	BinomialHeap *min=r;
	while (r!=NULL)
	{
		temp=BinomialHeapMinExtr(head);
		(*r).sibling=temp;
		r=temp;
	}
	return 	min;
;
}
/*
�������heap1�Ͷ����heap2�ĸ���ϳ�һ���������ĵ��������������е�����
*/
BinomialHeap * BinomialHeapMerge(BinomialHeap *heap1,BinomialHeap*heap2)
{
	BinomialHeap *head=BinomialHeapMake();
	BinomialHeap *temp=heap1;
	//��������heap1��heap2
	while((*temp).sibling!=NULL)
		temp=(*temp).sibling;
	(*temp).sibling=heap2;

	head=BinomialHeapDegreeASCSort(temp);
	return head;
}
/*
�ϲ������heap1�Ͷ����heap2�����غϲ���Ķ����
*/
BinomialHeap *BinomialHeapUnion(BinomialHeap *heap1,BinomialHeap*heap2)
{
	BinomialHeap *head=BinomialHeapMake();

	return head;
}