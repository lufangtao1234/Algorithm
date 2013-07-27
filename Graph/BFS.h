#include"ALGraph.h"
#include"GQueuq.h"
/*
以s为源点广度优先遍历图
*/
void BFS(ALGraph &graph,VertexType s)
{
	int i,j,sindex,index;
	GQueue q;
	VertexType temp;
	ArcNode *node;
	q.length=MAX_VERTEX_NUM;
	q.tail=0;
	q.head=0;

	for ( i = 0; i < MAX_VERTEX_NUM; i++)
	{
		if(graph.vertices[i].data.key==s.key)
		{
			sindex=i;
			graph.vertices[i].data.parent=-1;
			graph.vertices[i].data.depth=0;
			continue;
		}
		graph.vertices[i].data.color=White;
		graph.vertices[i].data.depth=INFINTY;
		graph.vertices[i].data.parent=-1;
	}
	graph.vertices[sindex].data.color=Gray;
	ENQUEUE(q,graph.vertices[sindex].data);
	while (!IsEmpty(q))
	{
		temp=DEQUEUE(q);
		for ( j = 0; j < MAX_VERTEX_NUM; j++)
		{
			if(graph.vertices[j].data.key==temp.key)
			{
				index=j;
				break;
			}
		}
		node=graph.vertices[index].firstarc;
		while(node!=NULL)
		{
			if(graph.vertices[(*node).adjvex].data.color==White)
			{
				graph.vertices[(*node).adjvex].data.color=Gray;
				graph.vertices[(*node).adjvex].data.depth=graph.vertices[index].data.depth+1;
				graph.vertices[(*node).adjvex].data.parent=index;
				ENQUEUE(q,graph.vertices[(*node).adjvex].data);
			}
			node=(*node).nextarc;
		}
		graph.vertices[index].data.color=Black;
	}
}

void printPath(ALGraph graph,VertexType s,VertexType v)
{
	if(s.key==v.key)
		printf("%c",s.key);
	else if(s.parent==-1)
		printf("no path from%c to %c exists",s.key,v.key);
	else 
	{
		printPath(graph,s,graph.vertices[v.parent].data);
		printf("%c",v.key);
	}
}