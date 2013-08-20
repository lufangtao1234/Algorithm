#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"

struct BiTreeNode
{
	ElementType Element;
	BiTree LChild;
	BiTree RChild;
};

BiTree InitBiTree(char s[],int &index)
{
	BiTree T=NULL;
	if(s[index]=='-')
		return T;
	T=(BiTree)malloc(sizeof(BiTreeNode));
	T->Element=s[index];
	index++;
	T->LChild=InitBiTree(s,index);
	index++;
	T->RChild=InitBiTree(s,index);
	return T;
}
/*
利用输入字符数组构造一棵二叉树
*/
BiTree CreateBiTree(char s[])
{
	int i=0;
	BiTree T=InitBiTree(s,i);
	return T;
}

void InOrderTraverseRecursion(BiTree tree)
{
	if(tree==NULL)
		return ;
	printf("%c",tree->Element);
	InOrderTraverseRecursion(tree->LChild);
	InOrderTraverseRecursion(tree->RChild);
}

void InOrderTraverseNoRecursioｎ(BiTree tree)
{
	
}

