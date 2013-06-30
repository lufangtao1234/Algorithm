#include<stdio.h>
#include<stdlib.h>
void Merge(int a[],int p,int q, int r)
{
	int ln=q-p+1;
	int rn=r-q;
	int k=p,i,j;
	int *L=(int *)calloc(ln,sizeof(int));
	int *R=(int *)calloc(rn,sizeof(int));
	if(!L||!R)
	{
		printf("calloc Error!");
		return ;
	}
	for (i = 0; i < ln; i++)
		*(L+i)=a[p+i];
	for (j = 0; j < rn; j++)
		*(R+j)=a[q+1+j];
	i=p;
	j=q+1;
	while(k<r)
	{
		if(i==q+1)
			while(j<r&&k<r)
			{
				a[k++]=*(R+j-q-1);
				j++;
			}
			if(j==r)
				while(i<=q&&k<r)
				{
					a[k++]=*(L+i-p);
					i++;
				}
				if(*(R+j-q-1)<*(L+i-p))
				{
					a[k++]=*(L+i-p);
					i++;
				}
				else
				{
					a[k++]=*(R+j-q-1);
					j++;
				}			
	}

}

void MergeSort(int a[],int p,int r)
{
	if(p>=r)
		return;
	int q=(p+r)/2;
	MergeSort(a,p,q);
	MergeSort(a,q+1,r);
	Merge(a,p,q,r);

}