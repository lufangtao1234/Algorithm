#include<stdio.h>
/*
˫��ѭ���б�ṹ
*/
struct  DCLList
{
	int e;
	DCLList*p;
	DCLList*n;
} *g;

/*
DCLList * guard Ϊ�����ڱ�
int kΪҪ�ҵ�Ԫ��
��������д���kֵ���������ַ������������򷵻�null��
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
��Ԫ��x���뵽˫��������
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
��Ԫ��x��˫��������ɾ��
*/
void DCLL_LIST_DELETE(DCLList*guard,DCLList *x)
{
	if(guard==NULL)
		return ;
	(*(*x).p).n=(*x).n;
	(*(*x).n).p=(*x).p;
}

/*
��ӡ˫���б�
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

