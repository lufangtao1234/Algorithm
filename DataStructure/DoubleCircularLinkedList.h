#include<stdio.h>
/*
双向循环列表结构
*/
struct  DCLList
{
	int e;
	DCLList*p;
	DCLList*n;
} *g;

/*
DCLList * guard 为链表哨兵
int k为要找的元素
如果链表中存在k值，返回其地址，如果不存在则返回null。
*/
DCLList * DCLL_LIST_SEARCH(DCLList * guard,int k)
{
	if(guard==NULL||(*guard).p==(*guard).n)
		return NULL;
	DCLList *temp=(*guard).n;
	while((temp!=guard)&&((*temp).e!=k))
		temp=(*temp).n;
	return temp;
}

/*
把元素x插入到双向链表中
*/
void DCLL_LIST_INSERT(DCLList*guard,DCLList*x)
{
	if(guard==NULL)
		return ;
	if((*guard).n==NULL||(*guard).p==NULL)
	{
		(*x).n=guard;
		(*x).p=guard;
		(*guard).n=x;
		(*guard).p=x;
		return ;
	}
	(*x).n=(*guard).n;
	(*(*guard).n).p=x;
	(*x).p=guard;
	(*guard).n=x;
}
/*
把元素x从双向链表中删除
*/
void DCLL_LIST_DELETE(DCLList*guard,DCLList *x)
{
	if(guard==NULL)
		return ;
	(*(*x).p).n=(*x).n;
	(*(*x).n).p=(*x).p;
}

/*
打印双向列表
*/
void DCLL_LIST_SHOW(DCLList *guard)
{
	if(guard==NULL)
		return ;
	DCLList *temp=(*guard).n;
	while(temp!=guard)
	{
		printf("%d\n",(*temp).e);
		temp=(*temp).n;
	}
}

