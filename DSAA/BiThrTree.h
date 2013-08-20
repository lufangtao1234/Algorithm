#ifndef _BITHRTREE_H_
#define _BITHRTREE_H_

typedef int ElementType;
typedef enum PointerTag{LINK,THREAD};
struct BiThrTreeNode;
typedef struct BiThrTreeNode *PtrToBiThrTreeNode;
typedef PtrToBiThrTreeNode BiThrTree;

BiThrTree CreateBiThrTree(char s[]);
void PreOrderTraverseRecursion(BiThrTree tree);
BiThrTree InOrderThread(BiThrTree tree);
void InorderTraverse_Thr(BiThrTree tree);
#endif