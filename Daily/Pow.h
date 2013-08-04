#include<stdio.h>
/*
¼ÆËãMµÄN´ÎÃİ
*/
int Pow(int M,int N)
{
	if(N==0)
		return 1;
	if(N==1)
		return M;
	if(N%2==0)
		return Pow(M,N/2)*Pow(M,N/2);
	else
		return Pow(M,(N-1)/2)*Pow(M,(N-1)/2)*M;
}