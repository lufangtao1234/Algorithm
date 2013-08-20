#ifndef _PATTERN_MATCHING_H
#define _PATTERN_MATCHING_H
/*
��������T��posλ�ÿ�ʼ���Ƿ��к��Ӵ�Sƥ��,����з���ƥ�俪ʼλ�ã����û�У�����-1
T:����
S:�Ӵ�
tlength:��������
slength:�Ӵ�����
pos:������ʼλ��
*/
int Index (char T[],char S[],int tlength,int slength,int pos)
{
	int j=0,i=pos;
	while(i<tlength&&j<slength)
	{
		if(T[i]==S[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	return j==slength?i-slength:-1;

}
void KMP_Next(char s[],int *next,int slength)
{
	int i=-1,j=-2;
	next[0]=-1;
	while (i<slength)
	{
		if(j==-1||s[i]==s[j])
		{
			++i;
			++j;
			next[i]=j;
		}else
			j=next[j];
	}

}
void KMP_Nextal(char s[] ,int *nextal,int slength)
{
	int i=-1,j=-2;
	nextal[0]=-1;
	while (i<slength)
	{
		if(j==-1||s[i]==s[j])
		{
			++i;
			++j;
			if(s[i]!=s[j])
				nextal[i]=j;
			else 
				nextal[i]=nextal[j];
		}else
			j=nextal[j];
	}
}
int KMP_Index(char T[],char S[],int tlength,int slength,int pos)
{
	int *next=(int*)malloc(slength*sizeof(int));
	KMP_Next(S,next,slength);

	int j=-1,i=pos-1;
	while(i<tlength&&j<slength)
	{
		if(j==-1||T[i]==S[j])
		{
			i++;
			j++;
		}
		else
			j=next[j];
	}
	return j==slength?i-slength:-1;


}

#endif