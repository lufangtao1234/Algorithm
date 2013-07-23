#include<stdio.h>
#include<stdlib.h>
#define DEGREE 3 //B���Ķ�
struct  BTree
{
	int keyNmuber;//�ؼ��ֵĸ���
	int *keys;//�ؼ��ּ��ϣ�����������λ��
	bool isLeaf;//�Ƿ�ΪҶ�ӽ��
	BTree ** childrens;//keyNumber+1��ָ���ӽ���ָ��
	int limit;//B���Ķ�
	int other;//����
	BTree *parent;//���ڵ�
};

/*
����һ��B���Ľ��
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
����һ�������
fcTree��bTree��postion����0��ʼ�����ӽڵ㣬fcTreeΪ�����
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
�ϲ����bTree��indexλ�õ���������
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
�ѹؼ���k���뵽δ�������
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
�ѽ��k���뵽B����
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
��B���������ؼ���k���Ƿ���ڣ�������ڣ��򷵻ش˽�㣬���ѹؼ���λ�ô洢��other�ֶ�
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
�ؼ���key�ڽ��position�У�ɾ���˹ؼ���key
*/
void BTreeDelte(BTree *&position,int key,int index)
{
	BTree *leftChild=(*position).childrens[index];
	BTree *rightChild=(*position).childrens[index+1];
	//���ɾ���ؼ����������ڣ�������Ŀ����Degree-1��
	//���������������ؼ����滻Ҫɾ���Ĺؼ��֣��ݹ�ɾ�������ؼ���
	if((leftChild!=NULL)&&((*leftChild).keyNmuber>=DEGREE))
	{
		(*position).keys[index]=(*leftChild).keys[(*leftChild).keyNmuber-1];
		BTreeDelte((*position).childrens[index],(*leftChild).keys[(*leftChild).keyNmuber-1],(*leftChild).keyNmuber-1);
	}
	else if((rightChild!=NULL)&&((*rightChild).keyNmuber>=DEGREE))//������������
	{
		(*position).keys[index]=(*rightChild).keys[(*rightChild).keyNmuber-1];
		BTreeDelte((*position).childrens[index+1],(*rightChild).keys[(*rightChild).keyNmuber-1],(*rightChild).keyNmuber-1);
	}
	/*
	���������������ǡ��ΪDegree-1
	*/
	else if((leftChild!=NULL)||(rightChild!=NULL))
	{

	}
}
