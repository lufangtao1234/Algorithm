#include<stdio.h>
/*
ϣ������
����a�������������
length:���鳤��
*/
void ShellSort(int a[],int length)
{
	int gap=length/2;//��ʼ����Ϊ���鳤�ȵ�һ��
	int j,i,key,swap,k;
	for (;gap>0;gap/=2)
	{
		for (i= 0; i < gap; i++)
		{
			for(j=i+gap;j<length;j+=gap)
			{
				if(a[j]<a[j-gap])
				{
					key=a[j];
					k=j-gap;
					while(k>=0&&a[k]>key)
					{
						a[k+gap]=a[k];
						k-=gap;
					}
					a[k+gap]=key;
				}
			}
		}
	}
}