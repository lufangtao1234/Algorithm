#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"
#include"Stack_L.h"
struct BiTreeNode
{
	ElementType Element;
	BiTree LChild;
	BiTree RChild;
};
/*

*/
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
BiTree CreateBiTreeNoRecursion_1(char s[])
{
	bool isCreateR = false;
	LStack stack=CreateStack();
	BiTree t, tree  = (BiTree)malloc(sizeof(BiTreeNode));
	tree->Element=s[0];
	tree->LChild=NULL;
	tree->RChild=NULL;
	LStack_Push(tree,stack);
	t=tree;
	int i=1;
	while(1)
	{
		if(s[i++]!='-')
		{
			if (!isCreateR){
				BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
				temp->Element = s[i-1];
				tree->LChild = temp;
				temp->LChild=NULL;
				temp->RChild=NULL;
				tree = temp;
				LStack_Push(tree,stack);
				
			}
			else
			{
				BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
				temp->Element = s[i-1];
				temp->LChild=NULL;
				temp->RChild=NULL;
				tree->RChild = temp;

				tree = temp;
				LStack_Push(tree,stack);
				isCreateR = false;
			}
		}
		else
		{
			if(!isCreateR)
			{
				isCreateR=true;
			}
			if(LStack_IsEmpty(stack))
				break;
			else 
				tree=LStack_Pop(stack);

		}
	}
	return t;
}
BiTree CreateBiTreeNoRecursion(char s[])
{
	BiTree TmpCell, tree=(BiTree)malloc(sizeof(BiTreeNode)),NoVisited=(BiTree)malloc(sizeof(BiTreeNode));
	tree->Element=s[0];
	tree->LChild=NoVisited;
	tree->RChild=NoVisited;
	LStack stack=CreateStack();
	int isRight=0;
	LStack_Push(tree,stack);
	int i=1;
	while (1)
	{
		TmpCell=LStack_Pop(stack);
		while(TmpCell->LChild!=NoVisited&&TmpCell->RChild!=NoVisited)
			TmpCell=LStack_Pop(stack);
		if(s[i++]!='-')
		{
			tree=(BiTree)malloc(sizeof(BiTreeNode));
			tree->Element=s[i-1];
			tree->LChild=NoVisited;
			tree->RChild=NoVisited;

			if(TmpCell->LChild==NoVisited)
				TmpCell->LChild=tree;
			else
				TmpCell->RChild=tree;
			LStack_Push(TmpCell,stack);
			LStack_Push(tree,stack);
		}
		else
		{
			if(TmpCell->LChild==NoVisited)
			{
				TmpCell->LChild=NULL;
				LStack_Push(TmpCell,stack);
			}
			else 
			{
				TmpCell->RChild=NULL;
				if(LStack_IsEmpty(stack))
					break;
			}

		}

		if(LStack_IsEmpty(stack))
			break;
	}
	return TmpCell;
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

void PreOrderTraverseRecursion(BiTree tree)
{
	if(tree==NULL)
		return ;
	printf("%c",tree->Element);
	PreOrderTraverseRecursion(tree->LChild);
	PreOrderTraverseRecursion(tree->RChild);
}

void  PreOrderTraverseNoRecursion(BiTree tree)
{
	LStack stack=CreateStack();
	LStack_Push(tree,stack);
	BiTree TmpCell=tree;
	while(!LStack_IsEmpty(stack))
	{
		TmpCell=LStack_Pop(stack);
		printf("%c",TmpCell->Element);
		if(TmpCell->RChild!=NULL)
			LStack_Push(TmpCell->RChild,stack);
		if(TmpCell->LChild!=NULL)
			LStack_Push(TmpCell->LChild,stack);

	}
}

void InOrderTraverseRecursion(BiTree tree)
{
	if(tree==NULL)
		return ;
	InOrderTraverseRecursion(tree->LChild);
	printf("%c",tree->Element);
	InOrderTraverseRecursion(tree->RChild);
}

void InOrderTraverseNoRecursion(BiTree tree)
{
	LStack stack=CreateStack();
	BiTree TmpCell;
	int returnRight=0;
	LStack_Push(tree,stack);
	while(!LStack_IsEmpty(stack))
	{
		if(!returnRight)
		{
			TmpCell=LStack_GetTop(stack);
			while(TmpCell->LChild!=NULL)
			{
				LStack_Push(TmpCell->LChild,stack);
				TmpCell=TmpCell->LChild;
			}
			returnRight=1;
		}
		TmpCell=LStack_Pop(stack);
		printf("%c",TmpCell->Element);
		if(TmpCell->RChild!=NULL)
		{
			returnRight=0;
			LStack_Push(TmpCell->RChild,stack);
		}
	}
}

void PostOrderTraverseRecursion(BiTree tree)
{
	if(tree==NULL)
		return ;
	PostOrderTraverseRecursion(tree->LChild);
	PostOrderTraverseRecursion(tree->RChild);
	printf("%c",tree->Element);
}

void PostOrderTraverseNRecursion(BiTree tree)
{
	LStack stack=CreateStack();
	BiTree TmpCell=tree,last=NULL;//last记录上一次访问的结点
	while(TmpCell!=NULL||!LStack_IsEmpty(stack))
	{
		while(TmpCell!=NULL)
		{
			LStack_Push(TmpCell,stack);
			TmpCell=TmpCell->LChild;
		}
		TmpCell=LStack_GetTop(stack);
		if(TmpCell->RChild==NULL||TmpCell->RChild==last)//如果TmpCell没有右结点，或其右结点刚刚访问过
		{
			printf("%c",TmpCell->Element);
			LStack_Pop(stack);
			last=TmpCell;
			TmpCell=NULL;
		}else
		{
			TmpCell=TmpCell->RChild;
		}

	}
}