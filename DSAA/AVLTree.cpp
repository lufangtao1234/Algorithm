#include<stdio.h>
#include<stdlib.h>
#include"Common.h"
#include"Error.h"
#include"AVLTree.h"

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Height(Position P)
{
	if(P==NULL)
		return -1;
	else 
		return P->Height;
}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;

	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K2->Right))+1;
	return K1;
}
static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;

	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K2->Right))+1;
	return K1;
}

static Position DoubleRotateWithLeft(Position K3)
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right=SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}
AvlTree FindInsertParent(ElementType X,AvlTree T)
{
	Position current=T,parent=NULL;
	while(current!=NULL)
	{
		parent=current;
		if(current->Element>X)
			current=current->Left;
		else 
			current=current->Right;
	}
	return parent;
}
AvlTree InsertNoRecursion(ElementType X,AvlTree T)
{
	Position insertParent,insertPP;
	Position insert=(AvlTree)malloc(sizeof(struct AvlNode));
	if(insert==NULL)
		FateErrors("Out of space!");
	insert->Element=X;
	insert->Height=0;
	insert->Left=insert->Right=NULL;
	//Ê÷Îª¿Õ
	if(T==NULL)
	{
		T=insert;
	}
	else 
	{
		insertParent=FindInsertParent(X,T);
		insertPP=FindParent(insertParent->Element,T);

	}
	return T;
}
AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		T=(AvlTree)malloc(sizeof(struct AvlNode));
		if(T==NULL)
			FateErrors("Out of space!");
		else
		{
			T->Element=X;
			T->Height=0;
			T->Left=T->Right=NULL;
		}

	}else if(X<T->Element)
	{
		T->Left=Insert(X,T->Left);
		if(Height(T->Left)-Height(T->Right)==2)
			if(X<T->Left->Element)
				T=SingleRotateWithLeft(T);
			else
				T=DoubleRotateWithLeft(T);
	}else if(X>T->Element)
	{
		T->Right=Insert(X,T->Right);
		if(Height(T->Right)-Height(T->Left)==2)
			if(X>T->Right->Element)
				T=SingleRotateWithRight(T);
			else 
				T=DoubleRotateWithRight(T);
	}
	T->Height=Max(Height(T->Left),Height(T->Right))+1;

	return T;
}
Position FindParent(ElementType X,AvlTree T)
{
	Position current=T,parent=NULL;
	while((current!=NULL)&&(current->Element!=X))
	{
		parent=current;
		if(current->Element>X)
			current=current->Left;
		else 
			current=current->Right;
	}
	return parent;

}
Position Find(ElementType X,AvlTree T)
{
	Position current=T;
	while(current!=NULL&&current->Element!=X)
		if(current->Element>X)
			current=current->Left;
		else 
			current=current->Right;
	return current;
}

Position FindMin(AvlTree T)
{
	Position current=T,parent=NULL;
	while(current!=NULL)
	{
		parent=current;
		current=current->Left;
	}
	return parent;
}
AvlTree Delete(ElementType X,AvlTree T)
{
	Position P=Find(X,T);
	Position parent=FindParent(X,T);
	Position TmpCell;
	if(P==NULL)
		return T;
	if(P->Left==NULL||P->Right==NULL)
	{
		TmpCell=P->Left!=NULL?P->Left:P->Right;
		if(P==parent->Left)
			parent->Left=TmpCell;
		else
			parent->Right=TmpCell;
	}
	else
	{
		TmpCell=FindMin(P->Right);
		T=Delete(TmpCell->Element,T);
		P->Element=TmpCell->Element;
	}
	return T;

}

void PrintAVLTree(AvlTree T)
{
	if(T==NULL)
		return ;
	PrintAVLTree(T->Left);
	printf("%d",T->Element);
	PrintAVLTree(T->Right);
}