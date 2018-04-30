#include"MST.h"

int main()
{
	MGraph G;
	FILE *fp = NULL;
	errno_t err;
	GraphKind Gkind = UDN;
	err = fopen_s(&fp, "MiniSpanTree_UDN.txt", "r");
	CreateGraph_M(&G, fp, Gkind);
	//printf("\nDFS Traverse: \n");
	//DFS_Traverse_M(G);
	//printf("\n");
	//printf("\nBFS Traverse: \n");
	//BFS_Traverse_M(G);
	//printf("\n");
	printf("\nMiniSpanTree_Prim: \n");
	MiniSpanTree_Prim(G, 'D');

	printf("\nMiniSpanTree_Krusakal: \n");
	MiniSpanTree_Kruskal(G);
	getchar();
	fclose(fp);
	return 0;
}