#include<stdio.h>
#include<stdlib.h>
enum RB_Color
{
	RED,
	BLACK
};

struct  RB_Tree
{
	int key;
	RB_Tree *Left;
	RB_Tree *Right;
	RB_Tree *Parent;
	RB_Color Color;
};

/*红黑树左旋操作
操作步骤：
1.以e与R[e]之间的链为“支轴”进行。
2.使得R[e]成为该子树新的根，e成为R[e]的左孩子，而R[e]的左孩子则成为x的右孩子。
*/
void LEFT_ROTATE(RB_Tree * &root,RB_Tree *e,RB_Tree *NIL)
{
	if(root==NIL||e==NIL)
		return ;
	//得到结点的右子结点
	RB_Tree * RightChild=(*e).Right; 
	//把右子结点的左子结点赋值给结点右子结点
	(*e).Right=(*RightChild).Left;  
	//如果右子结点的左子结点不为空，把其指向此结点
	if((*RightChild).Left!=NIL)    
		(*((*RightChild).Left)).Parent=e;
	//此结点的右子结点的父节点指向此节点的父节点
	(*RightChild).Parent=(*e).Parent; 
	if((*e).Parent==NIL)
		root=RightChild;
	else  if(e==(*((*e).Parent)).Left)
		(*((*e).Parent)).Left=RightChild;
	else
		(*((*e).Parent)).Right=RightChild;
	//把此节点放到其右结点的左结点上
	(*RightChild).Left=e;
	//把此节点的父节点指向其右结点
	(*e).Parent=RightChild;
}

/*
红黑树的右旋操作
*/
void RIGHT_ROTATE(RB_Tree * &root,RB_Tree *e,RB_Tree *NIL)
{
	if(root==NIL||e==NIL)
		return ;
	RB_Tree * LeftChild=(*e).Left;
	(*e).Left=(*LeftChild).Right;
	if((*LeftChild).Right!=NIL)
		(*((*LeftChild).Right)).Parent=e;
	(*LeftChild).Parent=(*e).Parent;
	if((*e).Parent==NIL)
		root=LeftChild;
	else  if(e==(*((*e).Parent)).Left)
		(*((*e).Parent)).Left=LeftChild;
	else
		(*((*e).Parent)).Right=LeftChild;
	(*LeftChild).Right=e;
	(*e).Parent=LeftChild;
}

/*
保持红黑树的性质
*/
void RB_INSERT_FIXUP(RB_Tree *&root,RB_Tree *e,RB_Tree *NIL)
{
	RB_Tree * uncle=NIL;
	while ((*((*e).Parent)).Color==RED)
	{
		//如果结点的父节点为其祖先结点的左孩子
		if((*e).Parent==(*(*((*e).Parent)).Parent).Left)
			uncle=(*(*((*e).Parent)).Parent).Right; //获得其叔父结点
		else 			
			uncle=(*((*e).Parent)).Left;
		//如果其叔父结点为红色
		if((*uncle).Color==RED)
		{
			(*((*e).Parent)).Color=BLACK;
			(*uncle).Color=BLACK;
			(*(*((*e).Parent)).Parent).Color=RED;
			e=(*((*e).Parent)).Parent;
		}
		//其叔父为黑色，
		else 
		{
			//此结点为其父节点的右子结点
			if(e==(*((*e).Parent)).Right)
			{
				e=(*e).Parent;
				LEFT_ROTATE(root,e,NIL);
			}
			(*((*e).Parent)).Color=BLACK;
			(*(*((*e).Parent)).Parent).Color=RED;
			RIGHT_ROTATE(root,(*((*e).Parent)).Parent,NIL);
		}
	}
	(*root).Color=BLACK;
}

/*
向红黑树中插入元素
*/
void RB_INSERT(RB_Tree *&root,RB_Tree *e,RB_Tree *NIL)
{
	if(e==NIL)
		return ;
	RB_Tree * parent=NIL;
	RB_Tree *current=root;
	while (current!=NIL)
	{
		parent=current;
		if((*current).key<(*e).key)
			current=(*current).Right;
		else
			current=(*current).Left;
	}
	(*e).Parent=parent;
	if(parent==NIL)
		root=e;
	else
	{
		if((*e).key<(*parent).key)
			(*parent).Left=e;
		else 
			(*parent).Right=e;
	}
	(*e).Left=NIL;
	(*e).Right=NIL;
	(*e).Color=RED;
	RB_INSERT_FIXUP(root,e,NIL);

}

/*
中序打印红黑树
*/
void RB_PRINT(RB_Tree * root,RB_Tree *NIL)
{
	if(root!=NIL)
	{
		RB_PRINT((*root).Left,NIL);
		printf("%d Color:%s\n",(*root).key,(*root).Color==RED?"RED":"BLACK");
		RB_PRINT((*root).Right,NIL);
	}

}