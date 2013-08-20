#ifndef _HashQuad_H
#define _HashQuad_H

typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;
struct HastTbl;
typedef struct HastTbl *HashTable;

HashTable InitilizeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find_Q(ElementType Key,HashTable H);
void Insert_Q(ElementType Key,HashTable H);
ElementType Retrieve(Position P,HashTable H);
HashTable Rehash(HashTable H);

#endif