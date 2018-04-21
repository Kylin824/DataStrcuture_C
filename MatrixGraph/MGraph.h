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

typedef char VertexType_M;		//顶点类型
typedef int EdgeType;			//边类型

typedef enum { DG, DN, UDG, UDN } GraphKind; //图类型：有向图、有向网、无向图、无向网

typedef struct
{
	VertexType_M vexs[MAX_VEXTEX_NUM];		//顶点数组
	EdgeType arcs[MAX_VEXTEX_NUM][MAX_VEXTEX_NUM];  //边/弧-邻接矩阵
	int vexnum, arcnum;						//当前顶点数、边/弧数
	GraphKind kind;
}MGraph;

int Scanf(FILE *fp, char *format, ...);
Status CreateGraph_M(MGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_M(FILE *fp, MGraph *G);
Status CreateDN_M(FILE *fp, MGraph *G);
Status CreateUDG_M(FILE *fp, MGraph *G);
Status CreateUDN_M(FILE *fp, MGraph *G);


