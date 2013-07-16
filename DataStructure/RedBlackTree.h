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

/*�������������
�������裺
1.��e��R[e]֮�����Ϊ��֧�ᡱ���С�
2.ʹ��R[e]��Ϊ�������µĸ���e��ΪR[e]�����ӣ���R[e]���������Ϊx���Һ��ӡ�
*/
void LEFT_ROTATE(RB_Tree * &root,RB_Tree *e,RB_Tree *NIL)
{
	if(root==NIL||e==NIL)
		return ;
	//�õ��������ӽ��
	RB_Tree * RightChild=(*e).Right; 
	//�����ӽ������ӽ�㸳ֵ��������ӽ��
	(*e).Right=(*RightChild).Left;  
	//������ӽ������ӽ�㲻Ϊ�գ�����ָ��˽��
	if((*RightChild).Left!=NIL)    
		(*((*RightChild).Left)).Parent=e;
	//�˽������ӽ��ĸ��ڵ�ָ��˽ڵ�ĸ��ڵ�
	(*RightChild).Parent=(*e).Parent; 
	if((*e).Parent==NIL)
		root=RightChild;
	else  if(e==(*((*e).Parent)).Left)
		(*((*e).Parent)).Left=RightChild;
	else
		(*((*e).Parent)).Right=RightChild;
	//�Ѵ˽ڵ�ŵ����ҽ���������
	(*RightChild).Left=e;
	//�Ѵ˽ڵ�ĸ��ڵ�ָ�����ҽ��
	(*e).Parent=RightChild;
}

/*
���������������
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
���ֺ����������
*/
void RB_INSERT_FIXUP(RB_Tree *&root,RB_Tree *e,RB_Tree *NIL)
{
	RB_Tree * uncle=NIL;
	while ((*((*e).Parent)).Color==RED)
	{
		//������ĸ��ڵ�Ϊ�����Ƚ�������
		if((*e).Parent==(*(*((*e).Parent)).Parent).Left)
			uncle=(*(*((*e).Parent)).Parent).Right; //������常���
		else 			
			uncle=(*((*e).Parent)).Left;
		//������常���Ϊ��ɫ
		if((*uncle).Color==RED)
		{
			(*((*e).Parent)).Color=BLACK;
			(*uncle).Color=BLACK;
			(*(*((*e).Parent)).Parent).Color=RED;
			e=(*((*e).Parent)).Parent;
		}
		//���常Ϊ��ɫ��
		else 
		{
			//�˽��Ϊ�丸�ڵ�����ӽ��
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
�������в���Ԫ��
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
�����ӡ�����
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