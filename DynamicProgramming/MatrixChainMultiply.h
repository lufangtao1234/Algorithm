#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

struct  Matrix
{
	int rows;//行数
	int columns;//列数
	int **element;//矩阵

};
/*
矩阵A和矩阵B相乘
*/
Matrix MatrixMultiply(Matrix A,Matrix B)
{
	Matrix C;
	int i,j,k;
	C.columns=A.rows;
	C.rows=B.columns;
	C.element=(int**)malloc(A.rows*sizeof(int*));
	for ( k = 0; k < A.rows; k++)
		C.element[k]=(int*)malloc(B.columns*sizeof(int));

	if(A.columns!=B.rows)
	{
		printf("A Columns Not Equal B Rows!");
		exit(0) ;
	}
	for (i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < B.columns; j++)
		{
			C.element[i][j]=0;
			for ( k = 0; k < A.columns; k++)
				C.element[i][j]=C.element[i][j]+A.element[i][k]*B.element[k][j];
		}
	}
}
/*
打印矩阵相乘加括号
*/
void PrintOptimalParens(int **s,int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		PrintOptimalParens(s,i,s[i][j]);
		PrintOptimalParens(s,s[i][j]+1,j);
		printf(")");
	}
}
/*
数组p长度为n+1,矩阵个数为n
*/
void MatrixChainOrder(int *p,int n)
{
	int i,j,k,l,q;
	int **m,**s;
	m=(int**)malloc(n*sizeof(int*));
	s=(int**)malloc(n*sizeof(int*));
	for ( k = 0; k < n; k++)
	{
		m[k]=(int*)malloc(sizeof(int*));
		s[k]=(int*)malloc(sizeof(int*));
	}
	for ( k = 0; k < n; k++)
		m[k][k]=0;

	for(l=2;l<=n;l++)
	{
		for (i = 0; i < n-l+1; i++)
		{
			j=i+l-1;
			m[i][j]=MAX;
			for ( k = i; k <=j-1; k++)
			{
				q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
			printf("%8d",m[i][j]);
		printf("\n");
	}
	PrintOptimalParens(s,0,n-1);
}
