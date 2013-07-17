#include<stdio.h>
#include<stdlib.h>
void PrintStations(int *l,int s,int i,int n);
/*
����װ���ߵĵ���
a[i][j]Ϊ��i��װ���ߵ�j��װ��վװ��ʱ��
t[i][j]Ϊ�ӵ�i��װ���ߵ�j��װ��վ�ƶ���һ��װ�����õ�ʱ��
e[i]�����i��װ�����õ�ʱ��
x[i]�뿪��i��װ�����õ�ʱ��
nװ������װ��վ�ĸ���
*/
void AssemblyScheduling(int a[2][6],int t[2][5],int *e,int *x,int n)
{
	int *f1=(int*)malloc(n*sizeof(int));
	int *f2=(int*)malloc(n*sizeof(int));
	int *l1=(int*)malloc(n*sizeof(int));
	int *l2=(int*)malloc(n*sizeof(int));
	int j;
	f1[0]=e[0]+a[0][0];
	f2[0]=e[1]+a[1][0];

	for (j = 1; j < n; j++)
	{
		if(f1[j-1]+a[0][j]<f2[j-1]+t[1][j-1]+a[0][j])
		{
			f1[j]=f1[j-1]+a[0][j];
			l1[j]=1;
		}
		else
		{
			f1[j]=f2[j-1]+t[1][j-1]+a[0][j];
			l1[j]=2;
		}
		if(f2[j-1]+a[1][j]<f1[j-1]+t[0][j-1]+a[1][j])
		{
			f2[j]=f2[j-1]+a[1][j];
			l2[j]=2;
		}
		else
		{
			f2[j]=f1[j-1]+t[0][j-1]+a[1][j];
			l2[j]=1;
		}
	}
	if(f1[n-1]+x[0]<f2[n-1]+x[1])
	{
		printf("Min %d\n",f1[n-1]+x[0]);

		PrintStations(l1,1,n,n);
	}
	else
	{
		printf("Min %d\n",f2[n-1]+x[1]);
		PrintStations(l2,2,n,n);
	}

}

void PrintStations(int *l,int s,int i,int n)
{
	if(i==1)
	{
		printf("Line %d,Station %d\n",l[i],i);
		return ;
	}

	PrintStations(l, s,i-1,n);
	if(i==n)
		printf("Line %d,Station %d\n",s,n);
	else
		printf("Line %d,Station %d\n",l[i],i);
}