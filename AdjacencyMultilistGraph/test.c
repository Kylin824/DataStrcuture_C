#include"AMLGraph.h"

int main()
{
	AMLGraph G;
	FILE *fp = NULL;
	errno_t err;
	GraphKind Gkind = UDG;
	switch (Gkind)
	{
	case UDG:
		err = fopen_s(&fp, "UDG.txt", "r");
		break;
	case UDN:
		err = fopen_s(&fp, "UDN.txt", "r");
		break;
	default:
		break;
	}
	CreateGraph_AML(&G, fp, Gkind);
	printf("\n");
	getchar();
	fclose(fp);
	return 0;
}