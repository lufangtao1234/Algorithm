#ifndef _BITREE_H_
#define _BITREE_H_

typedef char ElementType;
struct BiTreeNode;
typedef struct BiTreeNode *BiTree;

BiTree CreateBiTree(char s[]);
void InOrderTraverseRecursion(BiTree tree);
void InOrderTraverseNoRecursion(BiTree tree);

#endif