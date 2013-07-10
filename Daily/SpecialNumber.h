#include<stdio.h>
#define DECIMALS 5 //位数
#define SPECIAL_NUMBER 7 //特殊的数字
int SpecialNumberCount(int number);
/*
包含特殊数字7，但不能被7整除的5位数的个数和总和，以及包含两个7的的个数和总和
*/
void SpecialNumber()
{
	double oneSum=0;
	int oneCount=0;
	double twoSum=0;
	int twoCount=0;
	int specailCount=0;
	for (int i = 10000; i < 100000; i++)
	{
		specailCount=SpecialNumberCount(i);
		if((specailCount!=0)&&(i%SPECIAL_NUMBER!=0))
		{
			oneSum+=i;
			oneCount++;
		}
		if((specailCount==2)&&(i%SPECIAL_NUMBER!=0))
		{
			twoSum+=i;
			twoCount++;
		}
	}
	printf("包含特殊数字7，但不能被7整除的5位数的个数为%d和总和为%f",oneCount,oneSum);
	printf("包含特殊数字两个7，5位数的个数为%d和总和为%f",twoCount,twoSum);

}

int SpecialNumberCount(int number)
{
	int ex=number;
	int count=0;
	while(ex!=0)
	{
		if(ex%10==SPECIAL_NUMBER)
			count++;
		ex=ex/10;
	}
	return count;
}