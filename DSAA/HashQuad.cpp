#include<stdio.h>
#include<stdlib.h>
#include"Error.h"
#include"HashQuad.h"

enum KindOfEntry
{
	Legitimate,Empty,Deleted
};
struct HastEntry
{
	ElementType Element;
	enum  KindOfEntry Info;
};
typedef struct HastEntry Cell;
struct HastTbl
{
	int TableSize;
	Cell *TheCells;
};
//Hashº¯Êý
int Hash_Linear(ElementType key,HashTable H)
{
	int result=key%H->TableSize;
	while(H->TheCells[result].Info!=Empty&&H->TheCells[result].Element!=key)
		result=(result+1)%H->TableSize;
	return result;
}
int Hash_Square(ElementType key,HashTable H)
{
	int result=key%H->TableSize;
	int j=1;
	while(H->TheCells[result].Info!=Empty&&H->TheCells[result].Element!=key)
	{
		result=(result+j*j)%H->TableSize;
		j++;
	}
	return result;
}
HashTable InitilizeTable(int TableSize)
{
	HashTable H=(HashTable)malloc(sizeof(HastTbl));
	int i=0;
	if(!H)
		FateErrors("malloc Error!");
	H->TableSize=TableSize;
	H->TheCells=(Cell*)malloc(TableSize*sizeof(Cell));
	if(!(H->TheCells))
		FateErrors("H->TheCells Error!");
	for ( i = 0; i < TableSize; i++)
		H->TheCells[i].Info=Empty;
	return H;
}

void DestroyTable(HashTable H)
{
	free(H->TheCells);
	free(H);
}

void Insert_Q(ElementType Key,HashTable H)
{
	int i=Hash_Square(Key,H);
	H->TheCells[i].Element=Key;
	H->TheCells[i].Info=Legitimate;
}
Position Find_Q(ElementType Key,HashTable H)
{
	int i=Hash_Square(Key,H);
	return i;

}