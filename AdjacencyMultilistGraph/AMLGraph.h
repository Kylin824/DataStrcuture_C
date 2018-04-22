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

typedef char VertexType_AML;		//顶点类型

typedef enum { DG, DN, UDG, UDN } GraphKind; //图类型：有向图、有向网、无向图、无向网

typedef struct EdgeBox						//边表结点
{
	int ivex, jvex;
	struct EdgeBox *ilink, *jlink;
}EdgeBox;

typedef struct VertexBox					//顶点表结点
{
	VertexType_AML data;					//顶点信息
	EdgeBox *firstedge;						//首边指针
}VertexBox;

typedef struct
{
	VertexBox adjmulist[MAX_VEXTEX_NUM];							//顶点表数组
	int vexnum, edgenum;						//顶点数、弧数
	int kind;								//图类型：UDG或UDN
}AMLGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_AML(AMLGraph *G, FILE *fp, GraphKind Gkind);
Status CreateUDG_AML(FILE *fp, AMLGraph *G);
Status CreateUDN_AML(FILE *fp, AMLGraph *G);


