#include"SpecialNumber.h"
#include"PascalTriangle.h"
#include"MaxSequenceSum.h"
#include"GCD.h"
#include"Pow.h"
#include"List.h"
#include"Polynomial.h"
//#include"Stack.h"
#include"StackEx.h"
void main()
{
	int wait,i;

	//int a[]={-6,12,-1,-15,6,-1,9};
	//int maxSum,start,end;
	////maxSum=MaxSequenceSumN3(a,7,start,end);
	////maxSum=MaxSequenceSumN2(a,7,start,end);
	////maxSum=MaxSequenceSumNlogN(a,7,start,end,0,7);
	//maxSum=MaxSequenceSumN(a,7,start,end);
	//for ( i = start; i <= end; i++)
	//{
	//	printf("%6d",a[i]);
	//}
	//printf("\nThe MaxSequenceSum is %d\n",maxSum);


	//PascalTriangle(10);
	//SpecialNumber();

	/*printf("%d\n",GCD(15,50));
	printf("%d\n",GCD(50,15));
	printf("%d\n",Pow(2,20));*/
	/*PtrToNode L;
	L=CreateList();
	Insert(1,L,L);
	Insert(2,L,L);
	Insert(3,L,L);
	Insert(4,L,L);
	PrintList(L);
	Delete(4,L);
	PrintList(L);*/
	//PtrToPolynomial P1=(PtrToPolynomial)malloc(sizeof(Polynomial)),P2=(PtrToPolynomial)malloc(sizeof(Polynomial));
	//EmptyPolynomial(P1);
	//EmptyPolynomial(P2);
	//P1->CoeffArray[0]=1;
	//P1->CoeffArray[14]=5;
	//P1->CoeffArray[20]=-10;
	//P1->MaxHighGree=20;
	//P2->CoeffArray[0]=5;
	//P2->CoeffArray[1]=11;
	//P2->CoeffArray[10]=-2;
	//P2->CoeffArray[12]=3;
	//P2->MaxHighGree=12;
	//PrintPolynomial(*P1);
	//PrintPolynomial(*P2);
	//printf("\n Add\n");
	//PrintPolynomial(PolynomialAdd(P1,P2));
	//printf("\n Mult\n");
	//PrintPolynomial(PolynomialMult(P1,P2));
	//PtrToNode P=(PtrToNode)malloc(sizeof(Node));
	//P->Next=NULL;
	//PtrToNode P2=(PtrToNode)malloc(sizeof(Node));
	//P2->Next=NULL;
	//InsertNode(P,-1,10);
	//InsertNode(P,34,3);
	//printf("\n");
	//InsertNode(P2,-1,12);
	//InsertNode(P2,66,3);
	//PrintPtrPolynomial(P2);
	//printf("\n");
	////PrintPtrPolynomial(PtrPolynomialAdd(P,P2));
	//printf("\n");
	//PrintPtrPolynomial(PtrPolynomialMult(P,P2));
	//Stack s=CreateStack();
	/*PtrToAStck s=CreateAStack();
	ElementType e1=1;
	ElementType e2=2;
	ElementType e3=3;
	ElementType e4=4;
	PUSH(s,e1);
	PUSH(s,e2);
	PUSH(s,e3);
	PUSH(s,e4);
	printf("%d\n",POP(s));
	printf("%d\n",POP(s));
	printf("%d\n",POP(s));
	printf("%d\n",POP(s));*/
	//	char s1[]={'{','}','{','{','[','(',')',')','}','}'};
	//printf("{}{{[()]}}是否为正确：%s",isRightBracket(s1,10)==1?"是":"不是");
	char s1[]={'1','+','2','*','3','+','(','4','*','5','+','6',')','*','7'};
	char *s2=InfixToSuffix(s1,15);
	for ( i = 0; i < 15; i++)
	{
		printf("%c",s2[i]);
	}
	scanf("%d",&wait);
}