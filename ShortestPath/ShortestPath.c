#include"ShortestPath.h"

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
				printf("-- ");
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
	
	printf("  A B C D E F G H I \n");

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

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
	int v, min, w, k;
	int final[MAX_VEXTEX_NUM];

	for (v = 0; v < G.vexnum; v++)		//初始化
	{
		final[v] = 0;					//final数组代表对应下标的顶点是否已加入最短路径
		(*D)[v] = G.arcs[v0][v];		//D数组指示选定的顶点到对应下标各顶点的距离，final[]每加入一个顶点，都要更新一次D数组
		(*P)[v] = 0;					//P数组指示对应下标顶点的前驱
	}

	(*D)[v0] = 0;						//v0到v0路径为0
	final[v0] = 1;						//v0顶点加入最短路径

	//开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集中
	for (v = 1; v < G.vexnum; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; w++)		//寻找离v0最近的顶点
		{
			if (!final[w] && (*D)[w] < min)	//w顶点在非S集中且w顶点有邻边，找出最短的邻边
			{
				k = w;
				min = (*D)[w];				//w顶点离v0最近
			}
		}
		
		final[k] = 1;					//将找到的w顶点加入S集

		//更新当前最短路径和距离

		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] &&  (min + G.arcs[k][w] < (*D)[w]))
			{
				//找到新路径，修改D[w]和P[w]
				(*D)[w] = min + G.arcs[k][w];
				(*P)[w] = k;
			}
		}
	}
}

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable_F *D)
{
	int v, w, k;

	for (v = 0; v < G.vexnum; v++)		//初始化
	{									
		for (w = 0; w < G.vexnum; w++)
		{
			if (v != w)
			{
				(*D)[v][w] = G.arcs[v][w];		//D初始化与邻接矩阵相同
				(*P)[v][w] = w;					//P初始化为0-w
			}
			else
			{
				(*D)[v][w] = 0;
			}

		}
	}

	for (k = 0; k < G.vexnum; k++)
	{
		for (v = 0; v < G.vexnum; v++)
		{
			for (w = 0; w < G.vexnum; w++)
			{
				if ( (*D)[v][w] > (*D)[v][k] + (*D)[k][w] )
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}

	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			if ((*D)[v][w] != INFINITY)
			{
				printf("%2d ", (*D)[v][w]);
			}
			else
			{
				printf("-- ");
			}
		}
		printf("\n");
	}
}