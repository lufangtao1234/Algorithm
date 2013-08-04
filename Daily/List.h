#ifndef __LIST__
#define __LIST__
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
List CreateList();
void PrintList(List L);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
void Delete(int x,List L);
Position FindPrevious(int x,List L);
void Insert(int x,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);
#endif