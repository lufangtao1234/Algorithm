#include"BTree.h"
void main()
{
	int wait;
	BTree*root=AllocateNode();
	(*root).keyNmuber=1;
	(*root).keys[0]=4;
	BTree*left=AllocateNode();
	(*left).keyNmuber=2;
	(*left).keys[0]=2;
	(*left).keys[1]=3;
	BTree*right=AllocateNode();
	(*right).keyNmuber=2;
	(*right).keys[0]=6;
	(*right).keys[1]=7;
	(*root).childrens[0]=left;
	(*root).childrens[1]=right;
	BTreeMerge(root,0);
	BTreePrint(root,1);
	BTreeSplitChild(root,1,(*root).childrens[0]);
	BTreePrint(root,1);
	scanf("%d",&wait);
}