#ifndef ALGRAPH_H
#define ALGRAPH_H
#include<stdio.h>
#include<stdlib.h>
#include"MGraph.h"
#define MAX_VERTEX_NUM 5

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	InfoType * info;
}ArcNode;
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct 
{
	AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;

void PrintGraph(ALGraph graph)
{
	int i;
	for ( i = 0; i < graph.vexnum; i++)
	{
		printf("The key: %c\n",graph.vertices[i].data.key);
		printf("The depth: %d\n",graph.vertices[i].data.depth);
		printf("The parent: %d\n",graph.vertices[i].data.parent);
		printf("The start: %d\n",graph.vertices[i].data.start);
		printf("The finsh: %d\n",graph.vertices[i].data.finsh);
	}
}
#endif