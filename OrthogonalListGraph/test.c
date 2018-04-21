#include"OLGraph.h"
int main()
{
	OLGraph G;
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
	CreateGraph_OL(&G, fp, Gkind);
	Print_DG_order(G);
	printf("\n");
	Print_DG_re_order(G);
	//Print_DN(G);
	getchar();
	fclose(fp);
	return 0;
}