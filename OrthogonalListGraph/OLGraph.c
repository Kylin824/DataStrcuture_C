#include"OLGraph.h"

Status CreateGraph_OL(OLGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_OL(fp, G);
		return result;
	case DN:
		result = CreateDN_OL(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(OLGraph G, VertexType_OL v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.xlist[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_OL(FILE *fp, OLGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_OL vhead, vtail;
	ArcBox *arc;
	ArcBox **pout, **pin;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).xlist[i].data));							//顶点值存入顶点数组
		(*G).xlist[i].firstin = NULL;									//入边表置为空表
		(*G).xlist[i].firstout = NULL;									//出边表置为空表
	}

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcBox *)malloc(sizeof(ArcBox));		//生成边结点
		if (!arc)
			exit(OVERFLOW);

		arc->headvex = vj;
		arc->tailvex = vi;
		arc->weight = 1;
		arc->taillink = NULL;
		arc->headlink = NULL;

		pout = &((*G).xlist[vi].firstout);		//p是指向firstarc的二重指针 firstarc中有adjvex,weight,nextarc参数
		while ((*pout) != NULL)					//若不为NULL，说明firstarc有值，将p指向firstarc的nextarc
		{
			pout = &((*pout)->taillink);
		}
		*pout = arc;

		pin = &((*G).xlist[vj].firstin);		//
		while ((*pin) != NULL)
		{
			pin = &((*pin)->headlink);
		}
		*pin = arc;
	}

	return OK;
}

void Print_DG_order(OLGraph G)
{
	int i;
	ArcBox *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.xlist[i].data);
		p = G.xlist[i].firstout;
		while (p)
		{
			printf("-> %d ", p->headvex);
			p = p->taillink;
		}
		printf("\n");
	}
}

void Print_DG_re_order(OLGraph G)
{
	int i;
	ArcBox *p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.xlist[i].data);
		p = G.xlist[i].firstin;
		while (p)
		{
			printf("<- %d ", p->tailvex);
			p = p->headlink;
		}
		printf("\n");
	}
}

Status CreateDN_AL(FILE *fp, OLGraph *G)
{
	char tmp;
	int i, k, vi, vj, weight;
	VertexType_OL vhead, vtail;
	ArcBox *arc;
	ArcBox **pout, **pin;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).xlist[i].data));							//顶点值存入顶点数组
		(*G).xlist[i].firstin = NULL;									//入边表置为空表
		(*G).xlist[i].firstout = NULL;									//出边表置为空表
	}

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj == -1 || vi == -1)
			return ERROR;
		arc = (ArcBox *)malloc(sizeof(ArcBox));		//生成边结点
		if (!arc)
			exit(OVERFLOW);

		arc->headvex = vj;
		arc->tailvex = vi;
		arc->weight = weight;
		arc->taillink = NULL;
		arc->headlink = NULL;

		pout = &((*G).xlist[vi].firstout);		//p是指向firstarc的二重指针 firstarc中有adjvex,weight,nextarc参数
		while ((*pout) != NULL)					//若不为NULL，说明firstarc有值，将p指向firstarc的nextarc
		{
			pout = &((*pout)->taillink);
		}
		*pout = arc;

		pin = &((*G).xlist[vj].firstin);		//
		while ((*pin) != NULL)
		{
			pin = &((*pin)->headlink);
		}
		*pin = arc;
	}

	return OK;
}