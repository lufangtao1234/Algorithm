#include<stdio.h>
/*
���M��N�����Լ��
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