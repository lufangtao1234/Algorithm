#include<stdio.h>
#define DECIMALS 5 //λ��
#define SPECIAL_NUMBER 7 //���������
int SpecialNumberCount(int number);
/*
������������7�������ܱ�7������5λ���ĸ������ܺͣ��Լ���������7�ĵĸ������ܺ�
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
	printf("������������7�������ܱ�7������5λ���ĸ���Ϊ%d���ܺ�Ϊ%f",oneCount,oneSum);
	printf("����������������7��5λ���ĸ���Ϊ%d���ܺ�Ϊ%f",twoCount,twoSum);

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