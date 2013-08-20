#ifndef _HASHSEP_H_
#define _HASHSEP_H_H
#define MINTABLESIZE 10
typedef int ElementType ;
struct  ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType key,HashTable H);
void Insert(ElementType key,HashTable H);
ElementType Retrieve(Position P);
void Print(Position P);
#endif