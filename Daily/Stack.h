#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct SNode
{
	ElementType e;
	SNode* Next;
} *PtrNode;
typedef PtrNode Stack;


Stack CreateStack()
{
	Stack stack=(Stack)malloc(sizeof(SNode));
	if(stack==NULL)
		exit(-1);
	stack->Next=NULL;
	return stack;
}
int isStackEmpty(Stack stack)
{
	return stack->Next==NULL;
}
ElementType POP(Stack stack)
{
	ElementType t;
	if(isStackEmpty(stack))
		exit(-1);
	t=stack->Next->e;
	stack->Next=stack->Next->Next;
	return t;

}
void EmptyStarck(Stack stack)
{
	if(stack==NULL)
		exit(-1);
	else 
		while(!isStackEmpty(stack))
			POP(stack);
}
void PUSH(Stack stack,ElementType e)
{
	PtrNode P=(PtrNode)malloc(sizeof(SNode));
	if(P==NULL)
		exit(-1);
	P->e=e;
	P->Next=stack->Next;
	stack->Next=P;
}
