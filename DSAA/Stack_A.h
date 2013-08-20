#ifndef _STACK_A_H
#define _STACK_A_H
typedef int ElementType;
struct StackARecord;
typedef struct StackARecord *AStack;
int AStack_IsEmpty(AStack stack);
int AStack_IsFull(AStack stack);
AStack AStack_CreateStack(int MaxElement);
void AStack_DisposeStack(AStack stack);
void AStack_MakeEmpty(AStack stack);
void AStack_Push(ElementType X,AStack stack);
ElementType AStack_Top(AStack stack);
void AStack_Pop(AStack stack);
ElementType AStack_TopAndPop(AStack stack);
#endif