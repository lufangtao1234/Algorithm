#ifndef MGRAPH_H
#define MGRAPH_H
#include<stdio.h>
#include<stdlib.h>
#define INFINTY INT_MAX
#define MAX_VERTEX_NUM 5
 enum VertexColor
{
	White,//白色
	Gray,//灰色
	Black//黑色
};
//弧的类型
typedef struct VRType
{

};
//弧相关信息
typedef struct InfoType
{

};
//顶点向量
typedef struct VertexType
{
	char key;
	VertexColor color;
	int parent;
	int depth;
	int start;
	int finsh;
}VertexType;
typedef enum 
{
	DG,//有向图
	DN,//有向网
	UDG,//无向图
	UDN//无向网
}GraphKind;
//顶点颜色

typedef struct ArcCell
{
	VRType adj;
	InfoType * info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//图的邻接矩阵
typedef struct 
{
	VertexType verx[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}MGraph;
#endif