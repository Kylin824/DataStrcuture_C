#include"MST.h"

Status CreateGraph_M(MGraph *G, FILE *fp, GraphKind Gkind)
{
	Status result;
	switch (Gkind)
	{
	case DG:
		result = CreateDG_M(fp, G);
		return result;
	case DN:
		result = CreateDN_M(fp, G);
		return result;
	case UDG:
		result = CreateUDG_M(fp, G);
		return result;
	case UDN:
		result = CreateUDN_M(fp, G);
		return result;
	default:
		result = ERROR;
		return result;
		break;
	}
	/*printf("kind: %d", Gkind);*/
	return OK;
}

int LocateVex_M(MGraph G, VertexType_M v)
{
	int i;
	for (i = 0; i < G.arcnum; i++)
	{
		if (G.vexs[i] == v)
		{
			return i;
		}
	}
	return -1;
}

Status CreateDG_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = 1;
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateDN_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj, weight;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
			(*G).arcs[vi][vj] = weight;
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateUDG_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c", &vhead, &vtail);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = 1;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
	{
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}
Status CreateUDN_M(FILE *fp, MGraph *G)
{
	char tmp;
	int i, j, k, vi, vj, weight;
	VertexType_M vhead, vtail;
	Scanf(fp, "%d%d%d", &((*G).kind), &((*G).vexnum), &((*G).arcnum));		//读入图类型、顶点数、边数

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		Scanf(fp, "%c", &((*G).vexs[i]));				//顶点值存入顶点数组

	Scanf(fp, "%c", &tmp);								//跳过换行符

	for (i = 0; i < (*G).vexnum; i++)
		for (j = 0; j < (*G).vexnum; j++)
			(*G).arcs[i][j] = INFINITY;					//初始化邻接矩阵

	for (k = 0; k < (*G).arcnum; k++)
	{
		Scanf(fp, "%c%c%d", &vhead, &vtail, &weight);				//读入边的信息
		vi = LocateVex_M(*G, vhead);
		vj = LocateVex_M(*G, vtail);					//vi与vj对应于邻接矩阵中边的头与尾
		if (vj != -1 && vi != -1)
		{
			(*G).arcs[vi][vj] = weight;
			(*G).arcs[vj][vi] = (*G).arcs[vi][vj];
		}
	}
	printf("  A B C D E F \n");
	for (i = 0; i < (*G).vexnum; i++)					//打印邻接矩阵
	{
		printf("%c ", (*G).vexs[i]);
		for (j = 0; j < (*G).vexnum; j++)
			if ((*G).arcs[i][j] == 65535)
				printf("- ");
			else
				printf("%d ", (*G).arcs[i][j]);
		printf("\n");
	}
	return OK;
}

//For UDN
void MiniSpanTree_Prim(MGraph G, VertexType_M u)
{
	int i, j, min, k, a;
	int adjvex[MAX_VEXTEX_NUM];		//存储lowcost对应的最小权值来自的边的顶点值
	int lowcost[MAX_VEXTEX_NUM];	//存储该边上的权值

	a = LocateVex_M(G, u);			//由任一顶点va开始生成

	for (i = 0; i < G.vexnum; i++)
	{
		lowcost[i] = G.arcs[a][i];	//va顶点的邻边加入lowcost
		adjvex[i] = a;				//一开始lowcost全都来自va顶点
	}

	lowcost[a] = 0;						//lowcost[k] = 0代表va已加入生成树中

										//开始根据lowcost[]里面最小权值找到下一个顶点k的坐标,并将k的邻边加入lowcost

	for (i = 1; i < G.vexnum; i++)		//选择其余G.vexnum - 1个顶点
	{
		min = INFINITY;
		j = 0;
		k = 0;
		while (j < G.vexnum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)	//找到顶点最小权值边对应的另一顶点的下标k
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//已找到下一顶点k,将其加入

		printf("{%c-- %d --%c}\n", adjvex[k] + 65, min, k + 65);

		lowcost[k] = 0;			//顶点k加入生成树中

								//对lowcost[]处理，增加k的邻边进入lowcost[]中
		for (j = 0; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;				//新加入lowcost的邻边来自于顶点vk
			}
		}
	}
}

//可视为寻找顶点所在树的根结点
int Find(int *parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, m, n;
	int s = 0;
	Edge edges[MAX_EDGE_NUM];
	Edge tmp;
	int parent[MAX_VEXTEX_NUM];		//判断边与边是否形成环路

									//printf("begin  end  weight \n");
									//将邻接矩阵转化为边集数组edges[]
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = i; j < G.vexnum; j++)
		{
			if (G.arcs[i][j] != INFINITY)
			{
				edges[s].begin = i;
				edges[s].end = j;
				edges[s].weight = G.arcs[i][j];
				//printf("%c  %c  %d  \n", edges[n].begin + 65, edges[n].end + 65, edges[n].weight);
				s++;
			}
		}
	}

	//对edges[]由小到大排序 冒泡排序
	for (j = 0; j < G.arcnum; j++)
		for (i = 0; i < G.arcnum - 1 - j; i++)
		{
			if (edges[i].weight > edges[i + 1].weight)
			{
				tmp = edges[i];
				edges[i] = edges[i + 1];
				edges[i + 1] = tmp;
			}
		}

	//初始化
	for (i = 0; i < G.vexnum; i++)
	{
		parent[i] = 0;					//parent数组初始化置0	
	}

	for (i = 0; i < G.arcnum; i++)		//从最小权值边开始添加进生成树中
	{
		n = Find(parent, edges[i].begin);	//Find函数寻找顶点在parent数组中的根节点
		m = Find(parent, edges[i].end);		//根据根节点是否相同得出两者是否在同一连通分量中
		if (n != m)
		{
			parent[n] = m;				//end顶点作为begin顶点的parent结点，在parent数组中构建一个树
			printf("{%c %d %c} \n", edges[i].begin + 65, edges[i].weight, edges[i].end + 65);
		}
	}
}

