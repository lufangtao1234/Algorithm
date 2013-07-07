#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include"Data.h"
#include"Queue.h"
#include"DoubleCircularLinkedList.h"
void main()
{
	int wait;
	printData(DesData);
	/*PUSH(DesData,1);
	PUSH(DesData,2);
	PUSH(DesData,3);
	PUSH(DesData,4);
	printData(DesData);
	POP(DesData);*/
	/*Qlength=7;
	ENQUEUE(DesData,1);
	ENQUEUE(DesData,2);
	ENQUEUE(DesData,3);
	ENQUEUE(DesData,4);
	printData(DesData);
	printf_s("%d\n",DEQUEUE(DesData));
	printf_s("%d\n",DEQUEUE(DesData));
	printf_s("%d\n",DEQUEUE(DesData));*/

	DCLList *gurard= (DCLList*) malloc(sizeof(DCLList));
	(*gurard).n=NULL;
	(*gurard).p=NULL;
	DCLList *x1= (DCLList*) malloc(sizeof(DCLList));
	DCLList *x2= (DCLList*) malloc(sizeof(DCLList));
	DCLList *x3= (DCLList*) malloc(sizeof(DCLList));
	(*x1).e=1;
	(*x2).e=2;
	(*x3).e=3;
	DCLL_LIST_INSERT(gurard,x1);
	DCLL_LIST_INSERT(gurard,x2);
	DCLL_LIST_INSERT(gurard,x3);
	DCLL_LIST_SHOW(gurard);
	DCLL_LIST_DELETE(gurard,x2);
	DCLL_LIST_SHOW(gurard);
	scanf_s("%d",&wait);
}