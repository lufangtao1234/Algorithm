#include<stdio.h>
//ջ���α�
int top=-1;
/*
�ж�ջ�Ƿ�Ϊ��
*/
bool STACK_EMPTY(int s[])
{
	if(top==-1)
		return true;
	else 
		return false;
}

/*
��Ԫ��xѹ�뵽ջs��
*/
void PUSH(int s[],int x)
{
	top++;
	s[top]=x;
}

/*��ջ*/
int POP(int s[])
{
	if(STACK_EMPTY(s))
	{
		printf("underflow!");
		return -1;
	}
	else top--;
	return s[top+1];
}