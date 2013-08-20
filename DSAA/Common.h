#ifndef _COMMON_H
#define _COMMON_H
static int IsNumber(char s)
{
	return s>='0'&&s<='9'?1:0;
}
static int IsChar(char s)
{
	return (s>='a'&&s<='z')||(s>='A'&&s<='Z')?1:0;
}
static int Max(int a,int b)
{
	return a>b?a:b;
}

static int IsPrime(int number)
{
	int rihgt=1;
	int i=1;
	for (; i < number/2; i++)
	{
		if(number%i==0)
		{
			rihgt=false;
			break;
		}
	}
	return rihgt;
}
static int NextPrime(int number)
{
	int i=number;
	while (true)
	{
		if(IsPrime(i))
			break;
		i++;
	}
	return i;
}
#endif