#ifndef _TREE_H
#define _TREE_H
typedef char TreeElementType; 

typedef struct TreeNode
{
	TreeElementType Element;
	struct TreeNode * Left;
	struct TreeNode * Right;
} *PtrToNode, *Tree;
Tree CreateExpressionTreeBySuffix(char sunffix[],int length);
void InfixOrderTraversal(Tree t);
#endif