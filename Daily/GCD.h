#include<stdio.h>
/*
求出M和N的最大公约数
*/
int GCD(int M,int N)
{
	int gem;
	int temp;
	if(M<N)
	{
		temp=N;
		N=M;
		M=temp;
	}
	while (N>0)
	{
		gem=M/N;
		M=N;
		N=gem;
	}
	return M;
}