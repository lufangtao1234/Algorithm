#include<stdio.h>
#include<stdlib.h>
#include"Stack_L.h"
struct StackLNode
{
	StackLElementType Element;
	PtrToStackLNode Next;
};
LStack CreateStack()
{
	LStack stack=(LStack)malloc(sizeof(StackLNode));
	stack->Next=NULL;
	return stack;
}

int LStack_IsEmpty(LStack stack)
{
	return stack->Next==NULL;
}
void LStack_Push(StackLElementType X,LStack stack)
{
	PtrToStackLNode P=(PtrToStackLNode)malloc(sizeof(StackLNode));
	P->Element=X;
	P->Next=stack->Next;
	stack->Next=P;
}
StackLElementType LStack_GetTop(LStack stack)
{
	StackLElementType e;
	if(LStack_IsEmpty(stack))
	{
		printf("empty stack!");
		return e;
	}
	e=stack->Next->Element;
	return e;
}
StackLElementType LStack_Pop(LStack stack)
{
	StackLElementType e;
	PtrToStackLNode P;
	if(LStack_IsEmpty(stack))
	{
		printf("empty stack!");
		return e;
	}
	P=stack->Next;
	e=P->Element;
	stack->Next=P->Next;
	free(P);
	return e;
}

void LStack_Print(LStack stack)
{
	PtrToStackLNode P=stack->Next;
	while(P!=NULL)
	{
		printf("%d\n",P->Element);
		P=P->Next;
	}
}