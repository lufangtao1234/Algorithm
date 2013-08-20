#include<stdio.h>
#include<stdlib.h>
//#include"Stack_L.h"
//#include"Queue_A.h"
//#include"Queue_L.h"
//#include"Tree.h"
//#include"BSTree.h"
//#include"AVLTree.h"
//#include"Stack_L.h"
//#include"BiTree.h"
//#include"BiThrTree.h"
#include"Common.h"
#include"Error.h"
//#include"HashSep.h"
//#include"HashQuad.h"
#include"BinHeap.h"

void main()
{
	int wait;
	/*LStack stack=CreateStack();
	StackLElementType X1=1;
	LStack_Push(X1,stack);
	X1=2;
	LStack_Push(X1,stack);
	X1=3;
	LStack_Push(X1,stack);
	X1=4;
	LStack_Push(X1,stack);
	LStack_Print(stack);
	LStack_Pop(stack);
	LStack_Print(stack);
	LStack_Pop(stack);
	LStack_Print(stack);
	LStack_Pop(stack);*/
	/*Queue q=AQueue_CreateQueue(10);
	AQueue_Enqueue(1,q);
	AQueue_Enqueue(2,q);
	AQueue_Enqueue(3,q);
	AQueue_Enqueue(4,q);
	AQueue_Enqueue(5,q);
	AQueue_Enqueue(6,q);
	printf("%d\n",AQueue_Front(q));
	AQueue_Dequeue(q);
	printf("%d\n",AQueue_Front(q));
	AQueue_Dequeue(q);
	printf("%d\n",AQueue_Front(q));
	AQueue_Dequeue(q);
	printf("%d\n",AQueue_Front(q));
	AQueue_Dequeue(q);
	printf("%d\n",AQueue_Front(q));
	AQueue_Dequeue(q);*/
	//LQueue q=LQueue_CreateQueue();
	//LQueue_Enqueue(1,q);
	//LQueue_Enqueue(2,q);
	//LQueue_Enqueue(3,q);
	//LQueue_Enqueue(4,q);
	//LQueue_Enqueue(5,q);
	//printf("%d\n",LQueue_Front(q));
	//LQueue_Dequeue(q);
	//printf("%d\n",LQueue_Front(q));
	//LQueue_Dequeue(q);
	//printf("%d\n",LQueue_Front(q));
	//LQueue_Dequeue(q);
	//printf("%d\n",LQueue_Front(q));
	//LQueue_Dequeue(q);
	//printf("%d\n",LQueue_Front(q));
	//LQueue_Dequeue(q);
	/*char s[9]={'a','b','+','c','d','e','+','*','*'};
	Tree t=CreateExpressionTreeBySuffix(s,9);
	InfixOrderTraversal(t);*/

	/*BSTree T=NULL;
	T=BSTree_Insert(4,T);
	T=BSTree_Insert(5,T);
	T=BSTree_Insert(2,T);
	T=BSTree_Insert(3,T);
	T=BSTree_Insert(1,T);
	BSTree_InfixOrder(T);
	T=BSTree_Delete(2,T);
	printf("\n");
	BSTree_InfixOrder(T);*/

	/*AvlTree T=NULL;
	T=Insert(5,T);
	T=Insert(8,T);
	T=Insert(7,T);
	T=Insert(1,T);
	T=Insert(3,T);
	PrintAVLTree(T);
	T=Delete(3,T);
	printf("\n");
	PrintAVLTree(T);*/
	//	BiTree T;
	//BiThrTree T;
	char s[]={'A','B','C','-','-','D','E','-','G','-','-','F','-','-','-'};
	//T=CreateBiTree(s);
	//T=CreateBiTreeNoRecursion(s);
	/*T=CreateBiTreeNoRecursion_1(s);
	PreOrderTraverseRecursion(T);
	printf("\n");
	PreOrderTraverseNoRecursion(T);
	printf("\n");
	InOrderTraverseRecursion(T);
	printf("\n");
	InOrderTraverseNoRecursion(T);
	printf("\n");
	PostOrderTraverseRecursion(T);
	printf("\n");
	PostOrderTraverseNRecursion(T);*/

	//T=CreateBiThrTree(s);
	//PreOrderTraverseRecursion(T);

	//HashTable H=InitializeTable(100);
	//HashTable H=InitilizeTable(100);
	//Insert_Q(20,H);
	//Insert_Q(26,H);
	//Insert_Q(30,H);
	//Insert_Q(23,H);
	//Insert_Q(12,H);
	////Print(Find(12,H));
	//printf("%d\n",Find_Q(12,H));

	PriorityQueue H=Initialzie(100);
	Insert(4,H);
	Insert(2,H);
	Insert(5,H);
	Insert(65,H);
	Insert(1,H);
	Insert(3,H);
	Insert(7,H);
	printf("%d\n",DeleteMin(H));
	//DecreaseKey(2,2,H);
	printf("%d\n",DeleteMin(H));
	printf("%d\n",DeleteMin(H));
	scanf("%d",&wait);
}

