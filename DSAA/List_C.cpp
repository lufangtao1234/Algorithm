#include<stdio.h>
#include<stdlib.h>
#include"List_C.h"
struct Node
{
	ElementType Element;
	Position Next;
};

struct  Node CursorSpace[SPACESIZE];
void InitializeCursorSpace()
{
	int i;
	for ( i = 0; i < SPACESIZE-1; i++)
	{
		CursorSpace[i].Next=i+1;
	}
	CursorSpace[SPACESIZE-1].Next=0;
}
int IsEmpty(List L)
{
	return CursorSpace[L].Next==0;
}

int IsLast(Position P,List L)
{
	return CursorSpace[P].Next==0;
}

Position Find(ElementType X,List L)
{
	Position P;
	P=CursorSpace[L].Next;
	while(P!=0&&CursorSpace[P].Element!=X)
		P=CursorSpace[P].Next;
	return P;
}
Position CursorAlloc()
{
	Position P;
	P=CursorSpace[0].Next;
	CursorSpace[0].Next=CursorSpace[P].Next;
	return P;
}

void CursorFree(Position P)
{
	CursorSpace[P].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=P;
}
Position FindPrevious(ElementType X,List L)
{
	Position P=L;
	while (CursorSpace[P].Next!=0&&CursorSpace[CursorSpace[P].Next].Element!=X)
		P=CursorSpace[P].Next;
	return P;
}
void Delete(ElementType X,List L)
{
	Position P,TmpCell;
	P=FindPrevious(X,L);
	if(!IsLast(P,L))
	{
		TmpCell=CursorSpace[P].Next;
		CursorSpace[P].Next=CursorSpace[TmpCell].Next;
		CursorFree(TmpCell);
	}
}
void Insert(ElementType X,List L,Position P)
{
	Position TmpCell;
	TmpCell=CursorAlloc();
	if(TmpCell==0)
	{
		printf("malloc is error!\n");
		return ;
	}
	CursorSpace[TmpCell].Element=X;
	CursorSpace[TmpCell].Next=CursorSpace[P].Next;
	CursorSpace[P].Next=TmpCell;
}
void PrintList(List L)
{
	while (L!=0)
	{
		printf("%5d",CursorSpace[L].Element);
		L=CursorSpace[L].Next;
	}
}
