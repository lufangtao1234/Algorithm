#ifndef _LIST_C__H
#define _LIST_C_H
#define SPACESIZE 100
typedef int ElementType;
struct  Node;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace();
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P,const List L);
Position Find(ElementType X,const List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,const List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L );
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);
Position CursorAlloc();
void CursorFree(Position P);
void PrintList(List L);
#endif