#include<stdio.h>
#include<stdlib.h>
#include"List.h"
struct Node
{
	int Element;
	Position Next;
	Position Prev;
};
List CreateList()
{
	List L=(PtrToNode)malloc(sizeof(Node));
	L->Next=L;
	L->Prev=L;
	return L;
}
/*Return true if L is empty*/
int IsEmpty(List L)
{
	return L->Next==L;
}
/*Return true if P is the last position in list L */
/*Parameter L is unused in this implementation*/
int IsLast(Position P,List L)
{
	return P->Next==L;
}
/*Return Position of X in L;NULL if not found*/
Position Find(int x,List L)
{
	Position P;
	P=L->Next;
	while(P!=L&&P->Element!=x)
		P=P->Next;

	return P;
}
/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
void Delete(int x,List L)
{
	Position p ,TmpCell;
	p=Find(x,L);
	if(!IsLast(p,L))
	{
		TmpCell=p->Prev;
		p->Next->Prev=TmpCell;
		TmpCell->Next=p->Next;
		free(p);
	}
}

Position FindPrevious(int x,List L)
{
	Position P;
	P=L;
	while (P->Next!=L&&P->Next->Element!=x)
		P=P->Next;
	return P;
}
/*Insert (after legal position P)*/
/*Header implementation assumed*/
/*Parameter L is unused in this implementation*/
void Insert(int x,List L,Position P)
{
	Position TmpCell;
	TmpCell=(PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell==NULL)
		exit(-1);
	TmpCell->Element=x;
	TmpCell->Next=P->Next;
	P->Next->Prev=TmpCell;
	TmpCell->Prev=P;
	P->Next=TmpCell;
}
void DeleteListt(List L)
{
	Position P,Tmp;
	P=L->Next;
	L->Next=L;
	while(P!=L)
	{
		Tmp=P->Next;
		free(P);
		P=Tmp;
	}
}
void PrintList(List L)
{
	List P=L->Next;
	while(P!=L)
	{
		printf("%6d",P->Element);
		P=P->Next;
	}
}