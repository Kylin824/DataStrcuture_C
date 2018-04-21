#include"ALGraph.h"

Status CreateGraph_AL(ALGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_AL(fp, G);
		return result;
	case DN:
		result = CreateDN_AL(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(ALGraph G, VertexType_AL v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_AL(FILE *fp, ALGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_AL vhead, vtail;
	ArcNode *arc;
	ArcNode **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));							//顶点值存入顶点数组
		(*G).vertices[i].firstarc = NULL;									//边表置为空表
	}

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcNode *)malloc(sizeof(ArcNode));		//生成边结点
		if (!arc)
			exit(OVERFLOW);
		arc->adjvex = vj;
		arc->weight = 1;
		arc->nextarc = NULL;

		p = &((*G).vertices[vi].firstarc);		//p是指向firstarc的二重指针 firstarc中有adjvex,weight,nextarc参数
		while ((*p) != NULL)					//若不为NULL，说明firstarc有值，将p指向firstarc的nextarc
		{
			p = &((*p)->nextarc);				
		}
		*p = arc;
	}

	return OK;
}

void Print_DG(ALGraph G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("-> %d ", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}

Status CreateDN_AL(FILE *fp, ALGraph *G)
{
	char tmp;
	int i, k, vi, vj, weight;
	VertexType_AL vhead, vtail;
	ArcNode *arc;
	ArcNode **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).vertices[i].data));							//顶点值存入顶点数组
		(*G).vertices[i].firstarc = NULL;									//边表置为空表
	}

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcNode *)malloc(sizeof(ArcNode));		//生成边结点
		if (!arc)
			exit(OVERFLOW);
		arc->adjvex = vj;
		arc->weight = weight;
		arc->nextarc = NULL;

		p = &((*G).vertices[vi].firstarc);		//p是指向firstarc的二重指针 firstarc中有adjvex,weight,nextarc参数
		while ((*p) != NULL)					//若不为NULL，说明firstarc有值，将p指向firstarc的nextarc
		{
			p = &((*p)->nextarc);
		}
		*p = arc;
	}

	return OK;
}

void Print_DN(ALGraph G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("-> %d ", p->adjvex);
			printf("%d ", p->weight);
			p = p->nextarc;
		}
		printf("\n");
	}
}