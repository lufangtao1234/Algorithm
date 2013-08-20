#include<stdio.h>
#include<stdlib.h>
#include"Common.h"
#include"Error.h"
#include"HashSep.h"
struct  ListNode
{
	ElementType Element;
	Position Next;
};
typedef Position List;
struct HashTbl
{
	int TabeSize;
	List * TheLists;
};
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if(TableSize < MINTABLESIZE)
	{
		FateErrors("Table size to samll!");
		return NULL;
	}
	H=(HashTable) malloc(sizeof(HashTbl));
	if(H==NULL)
	{
		FateErrors("OUt of Space!");
	}
	H->TabeSize=NextPrime(TableSize);
	H->TheLists=(List*)malloc(H->TabeSize*sizeof(List));
	if(H->TheLists==NULL)
		FateErrors("Out of space!");
	for ( i = 0; i < H->TabeSize; i++)
	{
		H->TheLists[i]=(Position)malloc(sizeof(ListNode));
		if(H->TheLists[i]==NULL)
			FateErrors("Out of space!");
		else 
			H->TheLists[i]->Next=NULL;
	}
	return H;
}

//Hashº¯Êý
int Hash(ElementType key,int tableSize)
{
	return key%tableSize;
}

void Insert(ElementType key,HashTable H)
{
	Position node=(Position)malloc(sizeof(ListNode));
	int i;
	if(node==NULL)
		FateErrors("Out of space!");
	node->Next=NULL;
	node->Element=key;

	i=Hash(key,H->TabeSize);
	node->Next=H->TheLists[i];
	H->TheLists[i]=node;
}

Position Find(ElementType key ,HashTable H)
{
	int i;
	Position P=NULL;
	i=Hash(key,H->TabeSize);
	P=H->TheLists[i];
	while(P!=NULL&&P->Element!=key)
		P=P->Next;
	return P;
}

void Print(Position P)
{
	printf("%d",P->Element);
}