#include"AMLGraph.h"

Status CreateGraph_AML(AMLGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case UDG:
		result = CreateUDG_AML(fp, G);
		return result;
	case UDN:
		result = CreateUDN_AML(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex(AMLGraph G, VertexType_AML v)
{
	int i;
	for (i = 0; i < G.edgenum; i++)
	{
		if (G.adjmulist[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateUDG_AML(FILE *fp, AMLGraph *G)
{
	char tmp;
	int i, k, vi, vj;
	VertexType_AML vhead, vtail;
	EdgeBox *edge;
	//EdgeBox **p;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).edgenum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
	{
		Scanf(fp, "%c", &((*G).adjmulist[i].data));							//顶点值存入顶点数组
		(*G).adjmulist[i].firstedge = NULL;									//边表置为空表
	}

	Scanf(fp, "%c", &tmp);													//跳过换行符

	for (k = 0; k < (*G).edgenum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex(*G, vhead);
		vj = LocateVex(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj == -1 || vi == -1)
			return ERROR;
		edge = (EdgeBox *)malloc(sizeof(EdgeBox));		//生成边
		if (!edge)
			exit(OVERFLOW);
		edge->ivex = vi;
		edge->jvex = vj;
		edge->ilink = NULL;
		edge->jlink = NULL;

		edge->ilink = (*G).adjmulist[vi].firstedge;
		(*G).adjmulist[vi].firstedge = edge;

		edge->jlink = (*G).adjmulist[vj].firstedge;
		(*G).adjmulist[vj].firstedge = edge;

		//p = &((*G).adjmulist[vi].firstedge);		//p是指向firstedge的二重指针 firstedge中有ivex,jvex,*ilink,*jlink参数
		//while ((*p) != NULL)					//若不为NULL，说明firstedge有值，将p指向firstedge的ilink
		//{
		//	p = &((*p)->ilink);
		//}
		//*p = edge;
	}

	return OK;
}

Status CreateUDN_AML(FILE *fp, AMLGraph *G)
{
	return OK;
}