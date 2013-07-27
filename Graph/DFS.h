#include"ALGraph.h"
void DFS_Visit(ALGraph &graph,VertexType v);
int time;
/*������ȱ���ͼ*/
void DFS(ALGraph &graph)
{
	int i,j;
	for ( i = 0; i < MAX_VERTEX_NUM; i++)
	{
		graph.vertices[i].data.color=White;
		graph.vertices[i].data.parent=-1;
	}
	time=0;
	for ( i = 0; i < MAX_VERTEX_NUM; i++)
	{
		if(graph.vertices[i].data.color==White)
			DFS_Visit(graph,graph.vertices[i].data);
	}
}
/*
�������λ��
*/
int indexof(ALGraph graph,VertexType v)
{
	int i=-1;
	for ( i = 0; i < MAX_VERTEX_NUM; i++)
	{
		if(graph.vertices[i].data.key==v.key)
			break;
	}
	return i;
}
/*
�������
*/
void DFS_Visit(ALGraph &graph,VertexType v)
{
	int index=indexof(graph,v);
	ArcNode *node;
	time++;
	graph.vertices[index].data.color=Gray;
	graph.vertices[index].data.start=time;
	node=graph.vertices[index].firstarc;
	while(node!=NULL)
	{
	
			if(graph.vertices[(*node).adjvex].data.color==White)
			{
				graph.vertices[(*node).adjvex].data.color=Gray;
				graph.vertices[(*node).adjvex].data.parent=index;
				DFS_Visit(graph,graph.vertices[(*node).adjvex].data);
			}
			node=(*node).nextarc;
	}
	time++;
	graph.vertices[index].data.finsh=time;
}