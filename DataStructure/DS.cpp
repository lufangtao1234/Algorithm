#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"
//#include"RedBlackTree.h"
void main()
{
	int wait;
	//printData(DesData);
	///*PUSH(DesData,1);
	//PUSH(DesData,2);
	//PUSH(DesData,3);
	//PUSH(DesData,4);
	//printData(DesData);
	//POP(DesData);*/
	///*Qlength=7;
	//ENQUEUE(DesData,1);
	//ENQUEUE(DesData,2);
	//ENQUEUE(DesData,3);
	//ENQUEUE(DesData,4);
	//printData(DesData);
	//printf_s("%d\n",DEQUEUE(DesData));
	//printf_s("%d\n",DEQUEUE(DesData));
	//printf_s("%d\n",DEQUEUE(DesData));*/

	//DCLList *gurard= (DCLList*) malloc(sizeof(DCLList));
	//(*gurard).n=NULL;
	//(*gurard).p=NULL;
	//DCLList *x1= (DCLList*) malloc(sizeof(DCLList));
	//DCLList *x2= (DCLList*) malloc(sizeof(DCLList));
	//DCLList *x3= (DCLList*) malloc(sizeof(DCLList));
	//(*x1).e=1;
	//(*x2).e=2;
	//(*x3).e=3;
	//DCLL_LIST_INSERT(gurard,x1);
	//DCLL_LIST_INSERT(gurard,x2);
	//DCLL_LIST_INSERT(gurard,x3);
	//DCLL_LIST_SHOW(gurard);
	//DCLL_LIST_DELETE(gurard,x2);
	//DCLL_LIST_SHOW(gurard);
	/*BSTree *root=NULL;
	BSTree *e1=(BSTree*)malloc(sizeof(BSTree));
	BSTree *e2=(BSTree*)malloc(sizeof(BSTree));
	BSTree *e3=(BSTree*)malloc(sizeof(BSTree));
	BSTree *e4=(BSTree*)malloc(sizeof(BSTree));
	(*e1).key=3;
	(*e1).L=NULL;
	(*e1).R=NULL;
	(*e2).key=1;
	(*e2).L=NULL;
	(*e2).R=NULL;
	(*e3).key=4;
	(*e3).L=NULL;
	(*e3).R=NULL;
	(*e4).key=5;
	(*e4).L=NULL;
	(*e4).R=NULL;
	BINARYSEARCHTREE_INSERT(root,e1);
	BINARYSEARCHTREE_INSERT(root,e2);
	BINARYSEARCHTREE_INSERT(root,e3);
	BINARYSEARCHTREE_INSERT(root,e4);
	BINARYSEARCHTREE_PRINT(root);
	printf("%d\n",(*BINARYSEARCHTREE_SEARCH(root,e1)).key);
	printf("%d\n",(*BINARYSEARCHTREE_MAX(root)).key);
	printf("%d\n",(*BINARYSEARCHTREE_MIN(root)).key);
	printf("%d\n",(*BINARYSEARCHTREE_SUCCESSOR(e2)).key);
	BINARYSEARCHTREE_DELETE(root,e1);
	BINARYSEARCHTREE_PRINT(root);*/
	/*RB_Tree *NIL=(RB_Tree*)malloc(sizeof(RB_Tree));
	(*NIL).Parent=NIL;
	(*NIL).Left=NIL;
	(*NIL).Right=NIL;
	RB_Tree *root=NIL;
	RB_Tree *e1=(RB_Tree*)malloc(sizeof(RB_Tree));
	RB_Tree *e2=(RB_Tree*)malloc(sizeof(RB_Tree));
	RB_Tree *e3=(RB_Tree*)malloc(sizeof(RB_Tree));
	RB_Tree *e4=(RB_Tree*)malloc(sizeof(RB_Tree));
	(*e1).key=3;
	(*e2).key=1;
	(*e3).key=2;
	(*e4).key=5;
	RB_INSERT(root,e1,NIL);
	RB_INSERT(root,e2,NIL);
	RB_INSERT(root,e3,NIL);
	RB_INSERT(root,e4,NIL);
	RB_PRINT(root,NIL);*/
	BiTree T;
	char s[]={'A','B','C','-','-','D','E','-','G','-','-','F','-','-','-'};
	T=CreateBiTree(s);
	InOrderTraverseRecursion(T);
	scanf_s("%d",&wait);
}