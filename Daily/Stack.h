#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef char ElementType;
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

typedef struct AStack
{
	int stackTop;
	ElementType S[MAX];

}*PtrToAStck;

PtrToAStck CreateAStack()
{
	PtrToAStck a=(PtrToAStck)malloc(sizeof(AStack));
	a->stackTop=-1;
	return a;
}

int isAStackEmpty(PtrToAStck p)
{
	return p->stackTop==-1;
}
void PUSH(PtrToAStck p,ElementType e)
{
	if(p==NULL)
		return ;
	if(p->stackTop>=MAX)
	{
		printf("Stack Overflow!");
		return ;
	}
	p->stackTop++;
	p->S[p->stackTop]=e;
}

ElementType POP(PtrToAStck p)
{
	ElementType e;
	if(p==NULL)
		return e;
	if(isAStackEmpty(p))
	{
		printf("Stack Underflow!");
		return  e;
	}
	e=p->S[p->stackTop--];
	return e;
}

typedef struct  StackRecord
{
	int capcity;
	int top;
	ElementType *array;
} *PtrToStackRecord;

PtrToStackRecord CreateStackRecord(int max)
{
	PtrToStackRecord s=(PtrToStackRecord)malloc(sizeof(StackRecord));
	if(s==NULL)
		exit(-1);
	s->array=(ElementType*)malloc(sizeof(ElementType)*max);
	s->top=-1;
	s->capcity=max;
	return s;
}

int IsStackRecordEmpty(PtrToStackRecord p)
{
	return p->top==-1;
}

int IsStackRecordFull(PtrToStackRecord p)
{
	return p->top==p->capcity-1;
}
void PUSH(PtrToStackRecord p,ElementType e)
{
	if(IsStackRecordFull(p))
		exit(-1) ;
	p->array[++p->top]=e;

}

ElementType POP(PtrToStackRecord p)
{
	ElementType e;
	if(IsStackRecordEmpty(p))
		return e;
	return p->array[p->top--];
}