#include"BinomialHeap.h"
void main()
{
	int wait;
	BinomialHeap *head=BinomialHeapMake();
	BinomialHeap *slibling=BinomialHeapMake();
	BinomialHeap *slibling3=BinomialHeapMake();
	BinomialHeap *temp=NULL;
	(*slibling).key=4;
	(*slibling).degree=0;
	(*slibling3).key=3;
	(*slibling3).degree=0;
	BinomialHeap *slibing2=BinomialHeapMake();
	BinomialHeap *child2=BinomialHeapMake();
	BinomialHeap  *head1,*head2;
	(*slibing2).key=2;
	(*slibing2).degree=1;
	(*child2).key=5;
	(*slibing2).child=child2;
	//(*slibing2).sibling=slibling;
	head=slibing2;
	head1=slibling;
	//BinomialHeapPrint(head);
	//BinomialHeapPrint(head1);
	/*temp=BinomialHeapMinExtr(head);
	printf("\nThe Delte\n");
	BinomialHeapPrint(temp);
	printf("\nThe BinomialHeap\n");*/
	/*printf("\nSorted\n");
	head=BinomialHeapDegreeASCSort(head);*/
	/*printf("\nMerged\n");
	head=BinomialHeapMerge(head,head1);*/
	printf("\nLinked\n");
	BinomialHeapLink(slibling,slibling3);
	BinomialHeapPrint(slibling3);
	scanf("%d",&wait);
}
