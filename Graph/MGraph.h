#ifndef MGRAPH_H
#define MGRAPH_H
#include<stdio.h>
#include<stdlib.h>
#define INFINTY INT_MAX
#define MAX_VERTEX_NUM 5
 enum VertexColor
{
	White,//��ɫ
	Gray,//��ɫ
	Black//��ɫ
};
//��������
typedef struct VRType
{

};
//�������Ϣ
typedef struct InfoType
{

};
//��������
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
	DG,//����ͼ
	DN,//������
	UDG,//����ͼ
	UDN//������
}GraphKind;
//������ɫ

typedef struct ArcCell
{
	VRType adj;
	InfoType * info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//ͼ���ڽӾ���
typedef struct 
{
	VertexType verx[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}MGraph;
#endif