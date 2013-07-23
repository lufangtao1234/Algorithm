#include<stdio.h>
#include<stdlib.h>
#define DEGREE 3 //B树的度
struct  BTree
{
	int keyNmuber;//关键字的个数
	int *keys;//关键字集合，这里以整数位例
	bool isLeaf;//是否为叶子结点
	BTree ** childrens;//keyNumber+1个指向孩子结点的指针
	int limit;//B树的度
	int other;//其他
	BTree *parent;//父节点
};

/*
分配一个B树的结点
*/
BTree * AllocateNode()
{
	BTree *bTree=(BTree*)malloc(sizeof(BTree));
	int i;
	(*bTree).isLeaf=true;
	(*bTree).keyNmuber=0;
	(*bTree).keys=(int*)malloc((2*DEGREE-1)*sizeof(int));
	(*bTree).childrens=(BTree**)malloc(2*DEGREE*sizeof(BTree*));
	for (int i = 0; i < 2*DEGREE; i++)
		(*bTree).childrens[i]=NULL;
	return bTree;
}
/*
分裂一个满结点
fcTree是bTree第postion（从0开始）个子节点，fcTree为满结点
*/
void BTreeSplitChild(BTree * &bTree,int postion,BTree *&fcTree)
{
	int i,j,k;
	BTree *newBTree=AllocateNode();
	(*newBTree).isLeaf=(*fcTree).isLeaf;
	(*newBTree).keyNmuber=DEGREE-1;

	for ( i = 0; i < DEGREE-1; i++)
		(*newBTree).keys[i]=(*fcTree).keys[DEGREE+i];

	if((*fcTree).isLeaf==false)
	{
		for (j = 0; j < DEGREE; j++)
			(*newBTree).childrens[j]=(*fcTree).childrens[DEGREE+j];

	}
	(*fcTree).keyNmuber=DEGREE-1;
	for ( j = (*bTree).keyNmuber; j >postion; j--)
		(*bTree).childrens[j+1]=(*bTree).childrens[j];
	(*bTree).childrens[postion]=newBTree;
	for ( j = (*bTree).keyNmuber-1; j >=postion; j)
		(*bTree).keys[j+1]=(*bTree).keys[j];
	(*bTree).keys[postion-1]=(*fcTree).keys[DEGREE-1];
	(*bTree).keyNmuber++;

}
/*
合并结点bTree在index位置的左右子树
*/
void BTreeMerge(BTree *&bTree,int index)
{
	BTree*leftChild=(*bTree).childrens[index];
	BTree*rigthChild=(*bTree).childrens[index+1];
	int key=(*bTree).keys[index];
	int i,j;
	for ( i = index; i <(*bTree).keyNmuber-1; i++)
	{
		(*bTree).keys[i]=(*bTree).keys[i+1];
		(*bTree).childrens[i+1]=(*bTree).childrens[i+2];
	}
	(*bTree).keyNmuber--;
	(*bTree).childrens[index]=leftChild;
	(*leftChild).keys[(*leftChild).keyNmuber++]=key;
	for ( j = 0; j < (*rigthChild).keyNmuber; j++)
		(*leftChild).keys[(*leftChild).keyNmuber++]=(*rigthChild).keys[j];
}

/*
把关键字k插入到未满结点中
*/
void BTreeInsertNoNFull(BTree * bTree,int k)
{
	int n=(*bTree).keyNmuber-1;
	if((*bTree).isLeaf==true)
	{
		while(n>=0&&k<(*bTree).keys[n])
		{
			(*bTree).keys[n+1]=(*bTree).keys[n];
			n--;
		}
		(*bTree).keys[n+1]=k;
		(*bTree).keyNmuber++;
	}
	else 
	{
		while (n>=0&&k<(*bTree).keys[n])
		{
			n--;
		}
		n++;
		if((*(*bTree).childrens[n]).keyNmuber==2*DEGREE-1)
		{
			BTreeSplitChild(bTree,n,(*bTree).childrens[n]);
			if(k>(*bTree).keys[n])
				n++;
		}
		BTreeInsertNoNFull((*bTree).childrens[n],k);
	}
}
/*
把结点k插入到B树中
*/
void BTreeInsert(BTree *&root,int k)
{
	BTree *temp=root;
	BTree *newBTree=AllocateNode();
	if((*root).keyNmuber==2*DEGREE-1)
	{
		root=newBTree;
		(*newBTree).isLeaf=false;
		(*newBTree).keyNmuber=0;
		(*newBTree).childrens[0]=temp;
		BTreeSplitChild(newBTree,1,temp);
		BTreeInsertNoNFull(newBTree,k);
	}
	else
		BTreeInsertNoNFull(root,k);
}

void BTreePrint(BTree *bTree,int level)
{
	int i,j;
	if(bTree==NULL)
		return ;
	printf("Level:%d\n",level);
	for ( i = 0; i < (*bTree).keyNmuber; i++)
		printf("%12d",(*bTree).keys[i]);
	printf("\n");
	if((*bTree).childrens==NULL)
		return ;
	level++;
	for ( i = 0; i < (*bTree).keyNmuber+1; i++)
		BTreePrint((*bTree).childrens[i], level);
}
/*
在B树种搜索关键字k，是否存在，如果存在，则返回此结点，并把关键字位置存储在other字段
*/
BTree* BTreeSearch(BTree *root,int k,BTree *parent)
{
	int i=0,j;
	while((i<(*root).keyNmuber)&&(k>(*root).keys[i]))
		i++;
	if((i<(*root).keyNmuber)&&(k==(*root).keys[i]))
	{
		(*root).other=i;
		(*root).parent=parent;
		return root;
	}
	if((*root).isLeaf)
		return NULL;
	else 
		return BTreeSearch((*root).childrens[i],k,root);
}
/*
关键字key在结点position中，删除此关键字key
*/
void BTreeDelte(BTree *&position,int key,int index)
{
	BTree *leftChild=(*position).childrens[index];
	BTree *rightChild=(*position).childrens[index+1];
	//如果删除关键左子树存在，并且数目大于Degree-1，
	//则用做左子树最大关键字替换要删除的关键字，递归删除此最大关键字
	if((leftChild!=NULL)&&((*leftChild).keyNmuber>=DEGREE))
	{
		(*position).keys[index]=(*leftChild).keys[(*leftChild).keyNmuber-1];
		BTreeDelte((*position).childrens[index],(*leftChild).keys[(*leftChild).keyNmuber-1],(*leftChild).keyNmuber-1);
	}
	else if((rightChild!=NULL)&&((*rightChild).keyNmuber>=DEGREE))//向右子树借结点
	{
		(*position).keys[index]=(*rightChild).keys[(*rightChild).keyNmuber-1];
		BTreeDelte((*position).childrens[index+1],(*rightChild).keys[(*rightChild).keyNmuber-1],(*rightChild).keyNmuber-1);
	}
	/*
	如果左右子树个数恰好为Degree-1
	*/
	else if((leftChild!=NULL)||(rightChild!=NULL))
	{

	}
}
