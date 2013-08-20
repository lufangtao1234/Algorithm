#include<stdio.h>
#include<stdlib.h>
#include"BiThrTree.h"
#include"Error.h"

struct BiThrTreeNode
{
	ElementType Element;
	PtrToBiThrTreeNode LChild;
	PtrToBiThrTreeNode RChild;
	PointerTag LTag;
	PointerTag RTag;
};
BiThrTree InitBiThrTree(char s[],int &index)
{
	BiThrTree T=NULL;
	if(s[index]=='-')
		return T;
	T=(BiThrTree)malloc(sizeof(BiThrTreeNode));
	T->Element=s[index];
	index++;
	T->LChild=InitBiThrTree(s,index);
	index++;
	T->RChild=InitBiThrTree(s,index);
	return T;
}
BiThrTree CreateBiThrTree(char s[])
{
	int i=0;
	BiThrTree T=InitBiThrTree(s,i);
	return T;
}

void PreOrderTraverseRecursion(BiThrTree tree)
{
	if(tree==NULL)
		return ;
	printf("%c",tree->Element);
	PreOrderTraverseRecursion(tree->LChild);
	PreOrderTraverseRecursion(tree->RChild);
}
void InThreading(BiThrTree T,BiThrTree pre)
{
	BiThrTree t;
	if(T)
	{
		InThreading(T->LChild,pre);
		if(!T->LChild){T->LTag=THREAD;T->LChild=pre;}
		if(!pre->RChild){pre->RTag=THREAD;pre->RChild=T;}
		pre=T;
		InThreading(T->RChild,pre);
	}

}
BiThrTree InOrderThread(BiThrTree tree)
{
	BiThrTree pre, T=(BiThrTree)malloc(sizeof(BiThrTreeNode));
	if(T==NULL)
		FateErrors("Overflow!");
	T->LTag=LINK;
	T->RTag=THREAD;
	T->RChild=tree;
	if(!tree) T->LChild=T;
	else
	{
		T->LChild=T;
		pre=T;
		InThreading(T,pre);
		pre->RChild=T;
		pre->RTag=THREAD;
		T->RChild=pre;
	}
	return T;
}
void InorderTraverse_Thr(BiThrTree tree)
{
	
}