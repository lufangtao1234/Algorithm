#include"Stack.h"

/*
判断是为正确的括号形式，只有{[(三种括号形式
*/
int isRightBracket(char b[],int length)
{
	int i;
	char t;
	PtrToAStck p=CreateAStack();
	for ( i = 0; i < length; i++)
	{
		if(b[i]=='{'||b[i]=='['||b[i]=='(')
			PUSH(p,b[i]);
		else if(b[i]=='}'||b[i]==']'||b[i]==')')
		{
			t=POP(p);
			if(b[i]=='}'&&t!='{')
				return 0;
			else if(b[i]==']'&&t!='[')
				return 0;
			else if(b[i]==')'&&t!='(')
				return 0;
		}
	}
	if(isAStackEmpty(p))
		return 1;
	else return 0;
}

/*A的优先级是否比B的优先级低*/
int IsLowerPriority(char A,char B)
{
	if(A=='(')
		return -1;
	if(B==')')
		return 1;
	if((A==B)||(A=='+'&&B=='-')||(A=='-'&&B=='+')||(A=='*'&&B=='/')||(A=='/'&&B=='*'))
		return 0;
	if(A=='+'||A=='-')
		return -1;
	if(A=='*'||A=='/')
		return 1;
}

int IsNumber(char A)
{
	if(A>='0'&&A<='9')
		return 1;
	else 
		return 0;
}
/*中缀算式转换为后缀算式*/
char*InfixToSuffix(char A[] ,int length)
{
	char *result=(char *)malloc((length+1)*sizeof(char));
	int bracketCount=0;//栈中左括号的个数
	int index=0,i;
	char t;
	PtrToAStck p=CreateAStack();
	for ( i = 0; i < length; i++)
	{
		if(IsNumber(A[i]))
		{
			result[index++]=A[i];
		}
		else
		{
			if(A[i]=='(')
			{
				PUSH(p,A[i]);
			}
			else if(A[i]==')')
			{
				t=POP(p);
				while(t!='(')
				{
					result[index++]=t;
					t=POP(p);				
				}

			} else 
			{
				if(isAStackEmpty(p))
					PUSH(p,A[i]);
				else
				{
					t=POP(p);
					if(t=='(')
					{
						PUSH(p,t);
						PUSH(p,A[i]);
					}else if(IsLowerPriority(t,A[i])==1)
					{
						PUSH(p,t);
						PUSH(p,A[i]);
					}
					else 
					{
						while(IsLowerPriority(t,A[i])!=1)
						{
							result[index++]=t;
							if(isAStackEmpty(p))
								break;
							t=POP(p);
						}
						if(!isAStackEmpty(p))
							PUSH(p,t);
						PUSH(p,A[i]);
					}
				}
			}
		}
	}

	return result;
}


