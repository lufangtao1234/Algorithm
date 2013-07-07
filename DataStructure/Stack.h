#include<stdio.h>
//栈顶游标
int top=-1;
/*
判断栈是否为空
*/
bool STACK_EMPTY(int s[])
{
	if(top==-1)
		return true;
	else 
		return false;
}

/*
把元素x压入到栈s中
*/
void PUSH(int s[],int x)
{
	top++;
	s[top]=x;
}

/*出栈*/
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