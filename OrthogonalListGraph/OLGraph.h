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

typedef char VertexType_OL;		//顶点类型
typedef enum { DG, DN, UDG, UDN } GraphKind; //图类型：有向图、有向网、无向图、无向网

typedef struct ArcBox						//边表结点
{
	int tailvex, headvex;					//尾和头顶点下标
	int weight;								//权值
	struct ArcBox *headlink, *taillink;		//
}ArcBox;

typedef struct VertexNode					//顶点表结点
{
	VertexType_OL data;						//顶点信息
	ArcBox *firstin, *firstout;				//入/出边表头指针
}VertexNode;

typedef VertexNode OList[MAX_VEXTEX_NUM];

typedef struct
{
	OList xlist;							//顶点表数组
	int vexnum, arcnum;						//顶点数、弧数
	int kind;								//图类型：DG或DN
}OLGraph;

int Scanf(FILE *fp, char *format, ...);

Status CreateGraph_OL(OLGraph *G, FILE *fp, GraphKind Gkind);
Status CreateDG_OL(FILE *fp, OLGraph *G);
void Print_DG_order(OLGraph G);
void Print_DG_re_order(OLGraph G);
Status CreateDN_AL(FILE *fp, OLGraph *G);
//void Print_DN(OLGraph G);


