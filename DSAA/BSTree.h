#ifndef _BSTREE_H
#define _BSTREE_H
typedef int BSTreeElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *BSTree;

BSTree BSTree_MakeEmpty(BSTree T);
Position BSTree_Find(BSTreeElementType X,BSTree T);
Position BSTree_FindMin(BSTree T);
Position BSTree_FinMax(BSTree T);
Position BSTree_FindParent(BSTreeElementType X,BSTree);
BSTree BSTree_Insert(BSTreeElementType X,BSTree T);
BSTree BSTree_Delete(BSTreeElementType X,BSTree T);
BSTreeElementType BSTree_Retrieve(Position P);
void BSTree_InfixOrder(BSTree T);

#endif