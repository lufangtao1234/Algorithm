#include<stdio.h>
#include<stdlib.h>
#define MIN -1
#define MAX 10000
struct BinomialHeap
{
	int key;//关键字
	BinomialHeap * parent;//指向父节点
	BinomialHeap *child;//子节点
	BinomialHeap *sibling;//兄弟节点
	int degree;//节点子女个数
};
/*
打印二项堆 (right)
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
构造一个空的二项堆
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
将linked与link相连，以link为父节点
*/
void BinomialHeapLink(BinomialHeap*&linked,BinomialHeap*&link)
{
	(*linked).parent=link;
	(*linked).sibling=(*link).child;
	(*link).child=linked;
	(*link).degree++;
}
/*返回二项堆最小结点，并删除此结点*/
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
	//删除结点
	if(min==head)
		head=(*min).sibling;
	else
		(*minParent).sibling=(*min).sibling;
	(*min).sibling=NULL;
	return min;
}
/*
按照二项堆的度递增排序
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
将二项堆heap1和二项堆heap2的根表合成一个按度数的单调递增次序排列的链表
*/
BinomialHeap * BinomialHeapMerge(BinomialHeap *heap1,BinomialHeap*heap2)
{
	BinomialHeap *head=BinomialHeapMake();
	BinomialHeap *temp=heap1;
	//首先连接heap1和heap2
	while((*temp).sibling!=NULL)
		temp=(*temp).sibling;
	(*temp).sibling=heap2;

	head=BinomialHeapDegreeASCSort(temp);
	return head;
}
/*
合并二项堆heap1和二项堆heap2，返回合并后的二项堆
*/
BinomialHeap *BinomialHeapUnion(BinomialHeap *heap1,BinomialHeap*heap2)
{
	BinomialHeap *head=BinomialHeapMake();

	return head;
}