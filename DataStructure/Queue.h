#include<stdio.h>
int Qhead=0;
int Qtail=0;
int Qlength;
/*
��Ԫ��x���뵽����q��
*/
void ENQUEUE(int q[],int x)
{
	if(Qhead==Qtail+1)
	{
		printf("overflow!");
		return ;
	}
	q[Qtail]=x;
	if(Qtail==Qlength)
		Qtail=0;
	else 
		Qtail++;
}
/*
������
*/
int  DEQUEUE(int q[])
{
	int temp;
	if(Qhead==Qtail)
	{
		printf("underflow!");
		return -1;
	}
	temp=q[Qhead];
	if(Qhead==Qlength)
		Qhead=0;
	else
		Qhead++;
	return temp;

}