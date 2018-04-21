#include<stdio.h>
#include<stdlib.h>

/* 状态码 */
typedef int Status;

#define	TRUE		1			//真 
#define	FALSE		0			//假
#define	OK			1			//通过
#define	ERROR		0			//错误

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢CreateBiTree
#endif

#define MAX_VEXTEX_NUM 20		//最大顶点个数
#define INFINITY 65535			//最大值∞

typedef char VertexType_AL;		//顶点类型
typedef int EdgeType;			//边类型
typedef enum { DG, DN, UDG, UDN } GraphKind; //图类型：有向图、有向网、无向图、无向网

typedef struct ArcNode			//边表结点
{
	int adjvex;					//边指向的结点的下标
	EdgeType weight;			//权值
	struct ArcNode *nextarc;	//指向下一个边结点
}ArcNode;

typedef struct VertexNode		//顶点表结点
{
	VertexType_AL data;			//顶点信息
	ArcNode *firstarc;			//边表头指针
}VertexNode;

typedef VertexNode AdjList[MAX_VEXTEX_NUM];


typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_AL(ALGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_AL(FILE *fp, ALGraph *G);
void Print_DG(ALGraph G);
Status CreateDN_AL(FILE *fp, ALGraph *G);
void Print_DN(ALGraph G);


