#include"SCC.h"
//逆置有向图
void InverseGraph(OLGraph *G)
{
	int i, t;
	ArcBox *tmp, *q;
	ArcBox *p = NULL;
	VertexNode *h;
	for (i = 0; i < (*G).vexnum; i++)
	{
		h = &((*G).xlist[i]);			//对顶点表的顶点依次操作
		if (h->firstout)				
			p = h->firstout;

			tmp = h->firstout;			//将顶点的firstout 与 firstin互换
			h->firstout = h->firstin;
			h->firstin = tmp;

			while (p)					//对顶点指向的出边表操作（出边表与入边表操作一个就行,因为都包含在边表中）
			{
				q = p;
				p = p->taillink;		//p指向下个顶点

				t = q->headvex;			//vex值互换
				q->headvex = q->tailvex;
				q->tailvex = t;

				tmp = q->headlink;		//link值互换
				q->headlink = q->taillink;
				q->taillink = tmp;
			}

	}
}

void DFS_Traverse_SCC(OLGraph G)
{
	int i;

	for (i = 0; i < G.vexnum; i++)		//初始化访问标记数组
		visited[i] = FALSE;

	count = 0;

	for (i = 2; i < G.vexnum; i++)		//顶点可随机选择，若是连通图，则只执行一次
		if (!visited[i])
			DFS_SCC_1(G, i);
}

//第一次DFS
void DFS_SCC_1(OLGraph G, int i)
{
	ArcBox *p;
	visited[i] = TRUE;					//标记该顶点已访问
	printf("%c ", G.xlist[i].data);		//打印该顶点
	p = G.xlist[i].firstout;
	while (p)
	{
		if (!visited[p->headvex])
			DFS_SCC_1(G, p->headvex);
		p = p->taillink;
	}
	finished[count++] = i;
}

void DFS_SCC_2(OLGraph G, int i)
{
	ArcBox *p;
	visited[i] = TRUE;					//标记该顶点已访问
	printf("%c ", G.xlist[i].data);		//打印该顶点
	p = G.xlist[i].firstout;
	while (p)
	{
		if (!visited[p->headvex])
			DFS_SCC_2(G, p->headvex);
		p = p->taillink;
	}
}

void Kosaraju(OLGraph G)
{
	int i, j;

	//第一次DFS
	printf("\nfirst DFS: ------\n");
	DFS_Traverse_SCC(G);
	printf("\n--------first DFS\n");

	printf("\nfinished[count]: ------\n");
	for (j = 0; j < G.vexnum; j++)
	{
		printf("%d ", finished[j]);
	}
	printf("\n--------finished[count]\n");

	//逆置有向图
	InverseGraph(&G);

	printf("\nInverseGraph: ------\n");
	Print_DG_order(G);
	printf("--------InverseGraph\n");


	//第二次DFS遍历
	for (i = 0; i < G.vexnum; i++)
		visited[i] = FALSE;

	printf("\n强连通分量为： \n");
	for (i = G.vexnum - 1; i >= 0; i--)
	{
		if (!visited[finished[i]])
		{
			DFS_SCC_2(G, finished[i]);
			printf("\n");
		}
	}
}
