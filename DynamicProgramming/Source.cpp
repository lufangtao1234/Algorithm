#include"AssemblyScheduling.h"
#include"MatrixChainMultiply.h"
#include"LongestCommonSubsequence.h"
void main()
{
	int wait;
	/*int e[2]={2,4};
	int x[2]={3,2};
	int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
	int t[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
	AssemblyScheduling(a,t,e,x,6);*/
	/*int a[7]={30,35,15,5,10,20,25};
	MatrixChainOrder(a,6);*/
	char X[]={'x','A','B','C','B','D','A','B'};
	char Y[]={'x','B','D','C','A','B','A'};
	LongestCommonSubsquence(X,Y,7,6);
	scanf("%d",&wait);
}