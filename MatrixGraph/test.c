#include"MGraph.h"

int main()
{
	MGraph G;
	FILE *fp = NULL;
	errno_t err;
	GraphKind Gkind = UDG;
	switch (Gkind)
	{
	case DG:
		err = fopen_s(&fp, "DG.txt", "r"); 
		break;
	case DN:
		err = fopen_s(&fp, "DN.txt", "r");
		break;
	case UDG:
		err = fopen_s(&fp, "UDG.txt", "r");
		break;
	case UDN:
		err = fopen_s(&fp, "UDN.txt", "r");
		break;
	default:
		break;
	}
	CreateGraph_M(&G, fp, Gkind);
	printf("\nDFS Traverse: \n");
	DFS_Traverse_M(G);
	printf("\n");
	printf("\nBFS Traverse: \n");
	BFS_Traverse_M(G);
	getchar();
	fclose(fp);
	return 0;
}