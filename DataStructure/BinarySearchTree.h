#include<stdio.h>
struct  BSTree
{
	int key;
	BSTree *L;
	BSTree *R;
	BSTree *P;
};
BSTree *BINARYSEARCHTREE_SUCCESSOR(BSTree * e);
/*
ɾ������������е�Ԫ��
*/
void BINARYSEARCHTREE_DELETE(BSTree *&root,BSTree *e)
{
	if(root==NULL||e==NULL)
		return ;
	BSTree *y=NULL;
	BSTree *x=NULL;
	if(((*e).L==NULL)||((*e).L==NULL))
		y=e;
	else
		y=BINARYSEARCHTREE_SUCCESSOR(e);
	//���ĺ��û������Ů
	if((*y).L!=NULL)
		x=(*y).L;
	else 
		x=(*y).R;
	if(x!=NULL)
		(*x).P=(*y).P;

	if((*y).P==NULL)
		root=x;
	else if(y==(*((*y).P)).L)
		(*((*y).P)).L=x;
	else 
		(*((*y).P)).R=x;
	if(y!=e)
		(*e).key=(*y).key;
	return ;
}
/*
Ԫ�ز�������������
root:�����������
e:Ҫ�����Ԫ��
*/
void BINARYSEARCHTREE_INSERT(BSTree *& root,BSTree * e)
{
	if(e==NULL)
		return ;
	if(root==NULL)
	{
		root=e;
		return ;
	}
	BSTree *x=root;
	BSTree *y=root;
	while (x!=NULL)
	{
		y=x;
		if((*x).key<=(*e).key)
			x=(*x).R;
		else
			x=(*x).L;
	}
	if((*y).key<=(*e).key)
		(*y).R=e;
	else 
		(*y).L=e;
	(*e).P=y;
}

/*
�����ӡ���������
*/
void BINARYSEARCHTREE_PRINT(BSTree * root)
{
	if(root!=NULL)
	{
		BINARYSEARCHTREE_PRINT((*root).L);
		printf("%d\n",(*root).key);
		BINARYSEARCHTREE_PRINT((*root).R);
	}

}
/*
���Ҷ���������е�Ԫ��
*/
BSTree* BINARYSEARCHTREE_SEARCH(BSTree *root,BSTree *e)
{
	if(root==NULL||e==NULL)
		return NULL;
	BSTree * x=root;
	while(x!=NULL)
	{
		if((*x).key==(*e).key)
			return x;
		else if((*x).key<(*e).key)
			x=(*x).R;
		else
			x=(*x).L;
	}
	return NULL;
}
/*�Ҷ���������жԴ�Ԫ��*/
BSTree * BINARYSEARCHTREE_MAX(BSTree *root)
{
	if(root==NULL)
		return NULL;
	BSTree *x=root;
	while ((*x).R!=NULL)
		x=(*x).R;
	return x;
}

/*�Ҷ���������ж�СԪ��*/
BSTree * BINARYSEARCHTREE_MIN(BSTree *root)
{
	if(root==NULL)
		return NULL;
	BSTree *x=root;
	while ((*x).L!=NULL)
		x=(*x).L;
	return x;
}
/*�ҵ�Ԫ�صĺ��*/
BSTree * BINARYSEARCHTREE_SUCCESSOR(BSTree * root)
{
	if(root==NULL)
		return NULL;
	if((*root).R!=NULL)
		return BINARYSEARCHTREE_MIN((*root).R);
	BSTree *c=root;
	BSTree *p=(*c).P;
	while ((p!=NULL)&&(c==(*p).R))
	{
		c=p;
		p=(*c).P;
	}
	return p;


}