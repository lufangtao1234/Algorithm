#include<stdio.h>
#include<stdlib.h>
#include"BSTree.h"

struct TreeNode
{
	BSTreeElementType Element;
	BSTree Left;
	BSTree Right;
};
BSTree BSTree_MakeEmpty(BSTree T)
{
	if(T->Left==NULL&&T->Right==NULL)
	{
		free(T);
		return NULL;
	}
	T->Left=BSTree_MakeEmpty(T->Left);
	T->Right=BSTree_MakeEmpty(T->Right);
	free(T);
	return T;
}
Position BSTree_Find(BSTreeElementType X,BSTree T)
{
	BSTree TmpCell=T;
	while (TmpCell!=NULL&&TmpCell->Element!=X)
	{
		if(TmpCell->Element>X)
			TmpCell=TmpCell->Left;
		else 
			TmpCell=TmpCell->Right;
	}
	return TmpCell;
}
Position BSTree_FindMin(BSTree T)
{
	while(T->Left!=NULL)
		T=T->Left;
	return T;
}
Position BSTree_FinMax(BSTree T)
{
	while(T->Right!=NULL)
		T=T->Right;
	return T;
}
BSTree BSTree_Insert(BSTreeElementType X,BSTree T)
{
	BSTree node=(BSTree)malloc(sizeof(TreeNode));
	BSTree parent=T,current=T;
	node->Element=X;
	node->Left=NULL;
	node->Right=NULL;
	if(T==NULL)
		T=node;
	else
	{
		while(current!=NULL)
		{
			parent=current;
			if(current->Element>X)
				current=current->Left;
			else 
				current=current->Right;
		}
		if(parent->Element>X)
			parent->Left=node;
		else 
			parent->Right=node;
	}
	return T;
}
Position BSTree_FindParent(BSTreeElementType X,BSTree T)
{
	BSTree parent=NULL,current=T;
	while(current!=NULL&&current->Element!=X)
	{
		parent=current;
		if(current->Element>X)
			current=current->Left;
		else 
			current=current->Right;
	}
	return parent;
}
BSTree BSTree_Delete(BSTreeElementType X,BSTree T)
{
	Position P=BSTree_Find(X,T);
	Position parent=BSTree_FindParent(X,T);
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
		TmpCell=BSTree_FindMin(P->Right);
		T=BSTree_Delete(TmpCell->Element,T);
		P->Element=TmpCell->Element;
	}
	return T;
}
void BSTree_InfixOrder(BSTree T)
{
	if(T==NULL)
		return ;
	BSTree_InfixOrder(T->Left);
	printf("%d",T->Element);
	BSTree_InfixOrder(T->Right);
}

BSTreeElementType BSTree_Retrieve(Position P)
{

	if(P!=NULL)
		return P->Element;
	return -1;
}