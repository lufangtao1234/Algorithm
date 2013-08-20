#ifndef _STACK_L_H
#define _STACK_L_H
#include"BiTree.h"
typedef BiTree  StackLElementType;
struct StackLNode;
typedef struct  StackLNode *PtrToStackLNode;
typedef  PtrToStackLNode LStack;

int LStack_IsEmpty(LStack stack);
void LStack_Push(StackLElementType X,LStack stack);
StackLElementType LStack_GetTop(LStack stack);
StackLElementType LStack_Pop(LStack stack);
void LStack_Print(LStack stack);
LStack CreateStack();
#endif