#include"ALGraph.h"
int main()
{
	ALGraph G;
	FILE *fp = NULL;
	errno_t err;
	GraphKind Gkind = DG;
	switch (Gkind)
	{
	case DG:
		err = fopen_s(&fp, "DG.txt", "r");
		break;
	case DN:
		err = fopen_s(&fp, "DN.txt", "r");
		break;
	default:
		break;
	}
	CreateGraph_AL(&G, fp, Gkind);
	Print_DG(G);
	printf("DFS Traverse: \n");
	DFS_Traverse_AL(G);
	printf("\nBFS Traverse: \n");
	BFS_Traverse_AL(G);

	//Print_DN(G);
	getchar();
	fclose(fp);
	return 0;
}