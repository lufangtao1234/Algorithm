#include<stdio.h>
#include<stdlib.h>
#include"List.h"

/*implementtation List */
struct  Node
{
	ElementType Element;
	Position Next;
};
/*Empty the List*/
List MakeEmpty(List L)
{
	if(L==NULL)
		return NULL;
	PtrToNode t, ptr=L->Next;

	while(ptr!=NULL)
	{
		t=ptr;
		ptr=ptr->Next;
		free(t);
	}
	return L;
}

int IsEmpty(List L)
{
	return L->Next==NULL;
}

int IsLast(Position P,List L)
{
	return P->Next==NULL;
}
/*Find the first element equal X*/
Position Find(ElementType X,List L)
{
	Position t;
	t=L->Next;
	while(t!=NULL&&t->Element!=X)
		t=t->Next;
	return t;
}
/*Find the first  Previous Element equal X*/
Position FindPrevious(ElementType X,List L)
{
	Position P,t;
	t=L;
	while(t->Next!=NULL&&t->Next->Element!=X)
		t=t->Next;
	return t;
}
/*Delte the First Element equal X*/
void Delete(ElementType X,List L)
{
	Position t, P=FindPrevious(X,L);
	if(P==NULL)
	{
		printf("No Element !\n");
		return ;
	}
	if(!IsLast(P,L))
	{
		t=P->Next;
		P->Next=P->Next->Next;
		free(t);
	}

}
/*Insert the Element after the positon p*/
void Insert(ElementType X,List L,Position P)
{
	Position t=(PtrToNode)malloc(sizeof(Node));
	if(t==NULL)
	{
		printf("malloc is error! Insert fail!");
		return ;
	}
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}
/*Delte List */
void DeleteList(List L)
{
	L=MakeEmpty(L);
	free(L);
}
