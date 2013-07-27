#include"BFS.h"
#include"DFS.h"
void main()
{
	int wait;
	ALGraph graph;
	VNode vNode1,vNode2,vNode3,vNode4,vNode5;
	ArcNode *arcNode1;
	ArcNode *arcNode2;
	ArcNode *arcNode3;
	ArcNode *arcNode4;

	int i;
	graph.vexnum=MAX_VERTEX_NUM;
	VertexType type1;
	type1.key='B';
	VertexType type2;
	type2.key='D';
	VertexType type3;
	type3.key='C';
	VertexType type4;
	type4.key='A';
	VertexType type5;
	type5.key='E';

	arcNode1=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode1).adjvex=1;
	arcNode4=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode4).adjvex=4;
	(*arcNode1).nextarc=arcNode4;
	(*arcNode4).nextarc=NULL;
	vNode1.data.key='B';
	vNode1.firstarc=arcNode1;
	graph.vertices[0]=vNode1;

	arcNode1=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode1).adjvex=0;
	arcNode2=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode2).adjvex=2;
	arcNode3=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode3).adjvex=3;
	arcNode4=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode4).adjvex=4;
	(*arcNode1).nextarc=arcNode2;
	(*arcNode2).nextarc=arcNode3;
	(*arcNode3).nextarc=arcNode4;
	(*arcNode4).nextarc=NULL;
	vNode2.data.key='C';
	vNode2.firstarc=arcNode1;
	graph.vertices[1]=vNode2;

	arcNode1=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode1).adjvex=1;
	arcNode4=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode4).adjvex=3;
	(*arcNode1).nextarc=arcNode4;
	(*arcNode4).nextarc=NULL;
	vNode3.data.key='A';
	vNode3.firstarc=arcNode1;
	graph.vertices[2]=vNode3;

	arcNode1=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode1).adjvex=1;
	arcNode4=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode4).adjvex=4;
	arcNode2=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode2).adjvex=2;
	(*arcNode1).nextarc=arcNode4;
	(*arcNode4).nextarc=arcNode2;
	(*arcNode2).nextarc=NULL;
	vNode4.data.key='D';
	vNode4.firstarc=arcNode1;
	graph.vertices[3]=vNode4;

	arcNode1=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode1).adjvex=1;
	arcNode4=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode4).adjvex=0;
	arcNode2=(ArcNode*)malloc(sizeof(ArcNode));
	(*arcNode2).adjvex=3;
	(*arcNode1).nextarc=arcNode4;
	(*arcNode4).nextarc=arcNode2;
	(*arcNode2).nextarc=NULL;
	vNode5.data.key='E';
	vNode5.firstarc=arcNode1;
	graph.vertices[4]=vNode5;

	PrintGraph(graph);
	//BFS(graph,type1);
	//printf("BFS:\n");
	DFS(graph);
	printf("DFS:\n");
	PrintGraph(graph);

	//printPath(graph,type1,type2);
	scanf("%d",&wait);

}