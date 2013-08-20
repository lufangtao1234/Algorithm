#include<stdio.h>
#include<stdlib.h>
#include"Stack_A.h"
#define EmptyTop -1
#define MinStackSize 5
struct StackARecord
{
	int Capacity;
	int TopofStack;
	ElementType *Array;
};

AStack AStack_CreateStack(int MaxElement)
{
	AStack stack;
	if(MaxElement<MinStackSize)
	{
		printf("Create stack error!\n");
		return NULL;
	}
	stack=(AStack)malloc(sizeof(StackARecord));
	if(stack==NULL)
	{
		printf("stack malloc error!\n");
		return NULL;
	}
	stack->Capacity=MaxElement;
	stack->TopofStack=-1;
	stack->Array=(ElementType*)malloc(sizeof(ElementType)*MaxElement);
	if(stack->Array==NULL)
	{
		printf("stack array malloc error!\n");
		return NULL;
	}
}
int AStack_IsEmpty(AStack stack)
{
	return stack->TopofStack==-1;
}
int AStack_IsFull(AStack stack)
{
	return stack->TopofStack==stack->Capacity-1;
}

void AStack_DisposeStack(AStack stack)
{
	free(stack->Array);
	free(stack);
}
void AStack_MakeEmpty(AStack stack)
{
	stack->TopofStack=-1;
}
void AStack_Push(ElementType X,AStack stack)
{
	if(AStack_IsFull(stack))
	{
		printf("stack is full!\n");
		return ;
	}
	stack->Array[++(stack->TopofStack)]=X;
}
ElementType AStack_Top(AStack stack)
{
	ElementType e;
	if(AStack_IsEmpty(stack))
	{
		printf("stack is empty!\n");
		return e;
	}
	e=stack->Array[stack->TopofStack];
	return e;
}
void AStack_Pop(AStack stack)
{
	if(AStack_IsEmpty(stack))
	{
		printf("stack is empty!\n");
		return;
	}
	stack->TopofStack--;
}
ElementType AStack_TopAndPop(AStack stack)
{
	ElementType e=AStack_Top(stack);
	AStack_Pop(stack);
	return e;
}
