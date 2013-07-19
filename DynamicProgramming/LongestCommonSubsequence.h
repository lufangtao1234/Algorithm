#include<stdio.h>
#include<stdlib.h>

/*
求A与B的最长公共子序列
lengthA为数组A的长度
lengthB为数组B的长度
*/
void LCS(char *A,char *B,int lengthA,int lengthB,int **&m,int **&s)
{
	int i,j,k;
	for ( i = 1; i < lengthA+1; i++)
	{
		for ( j = 1; j < lengthB+1; j++)
		{
			if(A[i]==B[j])
			{
				m[i][j]=m[i-1][j-1]+1;
				s[i][j]=2;
			}
			else if(m[i-1][j]>=m[i][j-1])
			{
				m[i][j]=m[i-1][j];
				s[i][j]=-1;
			}
			else
			{
				m[i][j]=m[i][j-1];
				s[i][j]=1;
			}
		}
	}
}
void PrintLCS(int **s,char *A,int i,int j)
{
	if(i==0||j==0)
		return ;
	if(s[i][j]==2)
	{
		PrintLCS(s,A,i-1,j-1);
		printf("%c",A[i]);
	}
	else if(s[i][j]==1)
		PrintLCS(s,A,i,j-1);
	else
		PrintLCS(s,A,i-1,j);

}
void LongestCommonSubsquence(char *A,char *B,int lengthA,int lengthB)
{
	int **m,**s;
	int i,j,k;
	m=(int**)malloc((lengthA+1)*sizeof(int**));
	s=(int**)malloc((lengthA+1)*sizeof(int**));
	for (i = 0; i < lengthA+1; i++)
	{
		m[i]=(int*)malloc((lengthB+1)*sizeof(int*));
		s[i]=(int*)malloc((lengthB+1)*sizeof(int*));
	}
	for ( i = 0; i < lengthA+1; i++)
		for ( j = 0; j < lengthB+1; j++)
			s[i][j]=0;

	for ( i = 0; i < lengthA+1; i++)
		m[i][0]=0;
	for ( j = 0; j < lengthB+1; j++)
		m[0][j]=0;
	LCS(A,B,lengthA,lengthB,m,s);
	for ( i = 0; i < lengthA+1; i++)
	{
		for ( j = 0; j < lengthB+1; j++)
		{
			printf("%5d",s[i][j]);
		}
		printf("\n");
	}
	PrintLCS(s,A,lengthA,lengthB);
}