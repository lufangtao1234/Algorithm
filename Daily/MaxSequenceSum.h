#include<stdio.h>
#include<math.h>
/*
最大子集和
a:输入集合
length:数组长度
start:最大和开始位置
end:最大和结束位置
运行时间为：O(N*N*N)
*/
int MaxSequenceSumN3(int a[],int length,int &start,int &end)
{
	int thisSum=0,maxSum=0,i,j,k;

	for ( i = 0; i < length; i++)
	{
		for ( j = i; j < length; j++)
		{
			thisSum=0;

			for ( k = i; k <= j; k++)
			{
				thisSum+=a[k];
				if(thisSum>maxSum)
				{
					start=i;
					maxSum=thisSum;
					end=k;
				}
			}
		}
	}
	return maxSum;
}
/*
最大子集和
a:输入集合
length:数组长度
start:最大和开始位置
end:最大和结束位置
运行时间为：O(N*N)
*/
int MaxSequenceSumN2(int a[],int length,int &start,int &end)
{
	int thisSum=0,maxSum=0,i,j,k;

	for ( i = 0; i < length; i++)
	{
		thisSum=0;
		for ( j = i; j < length; j++)
		{

			thisSum+=a[j];
			if(thisSum>maxSum)
			{
				start=i;
				maxSum=thisSum;
				end=j;
			}
		}
	}
	return maxSum;
}
/*
最大子集和
a:输入集合
length:数组长度
start:最大和开始位置
end:最大和结束位置
运行时间为：O(N*logN)
*/
int MaxSequenceSumNlogN(int a[],int length,int &start,int &end,int left,int right)
{
	int leftMaxSum,rightMaxSum;
	int leftBorderSum=0,rightBorderSum=0;
	int leftMaxBorderSum=0,rightMaxBorderSum=0;
	int max;
	int center,i;
	int leftstart,leftend,rightstart,rightend;
	start=end=left;
	if(left==right)
		if(a[left]>0)		
			return a[left];
		else return 0;
		center=(left+right)/2;
		leftMaxSum=MaxSequenceSumNlogN(a,length,leftstart,leftend,left,center);
		rightMaxSum=MaxSequenceSumNlogN(a,length,rightstart,rightend,center+1,right);

		for ( i = center; i >= left; i--)
		{
			leftBorderSum+=a[i];
			if(leftBorderSum>leftMaxBorderSum)
				leftMaxBorderSum=leftBorderSum;
		}
		for ( i = center+1; i < right; i++)
		{
			rightBorderSum+=a[i];
			if(rightBorderSum>rightMaxBorderSum)
				rightMaxBorderSum=rightBorderSum;
		}
		if(leftMaxSum>rightMaxSum)
		{
			start=leftstart;
			end=leftend;
			max=leftMaxSum;
		}
		else 
		{
			start=rightstart;
			end=rightend;
			max =rightMaxSum;
		}
		if(max <(rightMaxBorderSum+leftMaxBorderSum))
		{
			start=leftstart;
			end=rightend;
			max=rightMaxBorderSum+leftMaxBorderSum;
		}
		return max;
}

/*
最大子集和
a:输入集合
length:数组长度
start:最大和开始位置
end:最大和结束位置
运行时间为：O(N)
*/
int MaxSequenceSumN(int a[],int length,int &start,int &end)
{
	int thisSum=0,maxSum=0,i,j,k;

	for ( i = 0; i < length; i++)
	{
		thisSum+=a[i];
		if(thisSum>maxSum)
		{
			maxSum=thisSum;
			end=i;
		}
		else if(thisSum<0)
		{
			thisSum=0;
			start=i+1;
		}
	}
	return maxSum;
}