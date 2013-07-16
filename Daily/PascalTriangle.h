#include<stdio.h>
#include<stdlib.h>
/*
 ‰»ÎN––—Óª‘»˝Ω«
*/
void PascalTriangle(int n)
{
	int i,j,k;
	int **a=(int **)malloc(sizeof(int*)*n);
	for ( i = 0; i < n; i++)
		a[i]=(int*)malloc(n*sizeof(int));
	for ( i = 0; i < n; i++)
		for ( j = 0; j < n; j++)
			if(j==0||j==i)
				a[i][j]=1;
			else 
				a[i][j]=0;
	for ( i = 1; i < n; i++)
		for ( j = 1; j < n; j++)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
			printf("%3d",a[i][j]);

		printf("\n");
	}
}