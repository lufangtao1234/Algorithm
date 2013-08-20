#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include"Stack_L.h"
#include"Common.h"

//Tree CreateExpressionTreeBySuffix(char sunffix[],int length)
//{
//	Tree T,TmpCell,left,right;
//	int i;
//	LStack stack=CreateStack();;
//
//	for ( i = 0; i < length; i++)
//	{
//		if(IsChar(sunffix[i]))
//		{
//			TmpCell =(Tree)malloc(sizeof(TreeNode));
//			TmpCell->Left=NULL;
//			TmpCell->Right=NULL;
//			TmpCell->Element=sunffix[i];
//			LStack_Push(TmpCell,stack);
//		}
//		else
//		{
//			right=LStack_Pop(stack);
//			left=LStack_Pop(stack);
//			TmpCell =(Tree)malloc(sizeof(TreeNode));
//			TmpCell->Left=left;
//			TmpCell->Right=right;
//			TmpCell->Element=sunffix[i];
//			LStack_Push(TmpCell,stack);
//		}
//	}
//	T=LStack_GetTop(stack);
//	return T;
//}
void InfixOrderTraversal(Tree t)
{
	if(t==NULL)
		return ;
	InfixOrderTraversal(t->Left);
	printf("%c",t->Element);
	InfixOrderTraversal(t->Right);
}