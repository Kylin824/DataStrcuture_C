#include"ShortestPath.h"

int main()
{
	MGraph G;
	int i, j;
	FILE *fp = NULL;

	Patharc P;		  /* 表示该顶点的前驱 */
	ShortPathTable D; /* 求某点到其余各点的最短路径之和 */

	Pathmatrix Pf;
	ShortPathTable_F Df;

	int v0 = 0;
	errno_t err;
	GraphKind Gkind = DN;
	err = fopen_s(&fp, "TestData_DN_M_DIJ.txt", "r");
	CreateGraph_M(&G, fp, Gkind);

	ShortestPath_Dijkstra(G, v0, &P, &D);

	printf("\n");

	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c - %c : %c", v0 + 65, i + 65, i + 65);
		j = i;
		while (P[j] != 0)
		{
			printf(" <- %c", P[j] + 65);
			j = P[j];
		}
		printf(" <- %c ", v0 + 65);
		printf("\n");
	}

	printf("\n源点到各顶点的最短路径长度为:\n");
	for (i = 0; i < G.vexnum; ++i)
		printf("%c - %c : %d \n", G.vexs[v0], G.vexs[i], D[i]);


	printf("\nFloyd: \n");
	ShortestPath_Floyd(G, &Pf, &Df);
	getchar();
	fclose(fp);
	return 0;
}