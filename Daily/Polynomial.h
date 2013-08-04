#include<stdio.h>
#include<stdlib.h>
#define MAXDEGREE 50
typedef struct Polynomial
{
	int CoeffArray[MAXDEGREE+1];
	int MaxHighGree;
}*PtrToPolynomial;

typedef struct Node *PtrToNode;
struct Node
{
	int Cofficient;
	int Exponent;
	PtrToNode Next;
};
PtrToNode MergeSameEffecit(PtrToNode P)
{
	PtrToNode t=(PtrToNode)malloc(sizeof(Node));
	t->Next=NULL;
	PtrToNode x;
	PtrToNode TempCell=P->Next;
	PtrToNode tempT;
	int flag=0;
	P=P->Next;
	while (P!=NULL)
	{	
		tempT=t->Next;
		flag=0;
		while (tempT!=NULL)
		{
			if(tempT->Cofficient==P->Cofficient)
			{
				flag=1;
				tempT->Exponent+=P->Exponent;
			}
			tempT=tempT->Next;
		}
		if(flag==0)
		{
			x=(PtrToNode)malloc(sizeof(Node));
			x->Exponent=P->Exponent;
			x->Cofficient=P->Cofficient;
			x->Next=t->Next;
			t->Next=x;
		}
		P=P->Next;
	}

	return t;
}
PtrToNode PtrPolynomialMult(PtrToNode p1,PtrToNode p2)
{
	PtrToNode x,p=(PtrToNode)malloc(sizeof(Node));
	PtrToNode temp;
	p->Next=NULL;
	p1=p1->Next;
	temp=p2->Next;

	while(p1!=NULL)
	{
		temp=p2->Next;
		while (temp!=NULL)
		{
			x=(PtrToNode)malloc(sizeof(Node));
			x->Cofficient=p1->Cofficient+temp->Cofficient;
			x->Exponent=p1->Exponent*temp->Exponent;
			x->Next=p->Next;
			p->Next=x;
			temp=temp->Next;
		}
		p1=p1->Next;
	}
	return MergeSameEffecit(p);
}
PtrToNode PtrPolynomialAdd(PtrToNode p1,PtrToNode p2)
{
	PtrToNode p=(PtrToNode)malloc(sizeof(Node));

	p->Next=NULL;
	PtrToNode temp=p2->Next;
	p1=p1->Next;
	while (temp->Next!=NULL)
		temp=temp->Next;
	temp->Next=p1;
	p=MergeSameEffecit(p2);
	return p;
}

void PrintPtrPolynomial(PtrToNode P)
{
	P=P->Next;
	while(P!=NULL)
	{
		printf("ÏµÊý£º%d,ÃÝ´Î£º%d\n",P->Exponent,P->Cofficient);
		P=P->Next;
	}
}
void InsertNode(PtrToNode &P,int exponent,int cofficient)
{
	PtrToNode t=(PtrToNode)malloc(sizeof(Node));
	t->Cofficient=cofficient;
	t->Exponent=exponent;
	t->Next=P->Next;
	P->Next=t;
}
void EmptyPolynomial(PtrToPolynomial polynomial )
{
	int i;
	for ( i = 0; i < MAXDEGREE+1; i++)
		polynomial->CoeffArray[i]=0;
	polynomial->MaxHighGree=0;
}
Polynomial PolynomialAdd(PtrToPolynomial p1,PtrToPolynomial p2)
{
	int i;
	Polynomial P;
	P.MaxHighGree=p1->MaxHighGree>p2->MaxHighGree?p1->MaxHighGree:p2->MaxHighGree;
	for ( i = 0; i < MAXDEGREE+1; i++)
		P.CoeffArray[i]=p1->CoeffArray[i]+p2->CoeffArray[i];
	return P;
}
Polynomial PolynomialMult(PtrToPolynomial p1,PtrToPolynomial p2)
{
	int i,j;
	PtrToPolynomial P=(PtrToPolynomial)malloc(sizeof(Polynomial));
	EmptyPolynomial(P);
	P->MaxHighGree=p1->MaxHighGree+p2->MaxHighGree;
	if(P->MaxHighGree>MAXDEGREE)
		exit(-1);
	for ( i = 0; i < MAXDEGREE+1; i++)
		for ( j = 0; j < MAXDEGREE+1; j++)
			P->CoeffArray[i+j]+=p1->CoeffArray[i]*p2->CoeffArray[j];

	return *P;
}
void PrintPolynomial(Polynomial p)
{
	int i=0;
	for ( i = 0; i < MAXDEGREE+1; i++)
		printf("%5d",p.CoeffArray[i]);
}