#ifndef _BITREE_H_
#define _BITREE_H_
typedef char ElementType;
struct BiTreeNode;
typedef struct BiTreeNode *BiTree;

BiTree CreateBiTree(char s[]);
BiTree CreateBiTreeNoRecursion(char s[]);
BiTree CreateBiTreeNoRecursion_1(char s[]);
void InOrderTraverseRecursion(BiTree tree);
void InOrderTraverseNoRecursion(BiTree tree);
void PreOrderTraverseRecursion(BiTree tree);
void PreOrderTraverseNoRecursion(BiTree tree);
void PostOrderTraverseRecursion(BiTree tree);
void PostOrderTraverseNRecursion(BiTree tree);
#endif