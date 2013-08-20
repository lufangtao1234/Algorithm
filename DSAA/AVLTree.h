#ifndef _AVLTREE_H_
#define _AVLTREE_H_

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindParent(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
ElementType Retrieve(Position P);
void PrintAVLTree(AvlTree T);
AvlTree FindInsertParent(ElementType X,AvlTree T);
AvlTree InsertNoRecursion(ElementType X,AvlTree);

#endif