#include"SCC.h"

int main()
{
	OLGraph G;
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "TestData_DG_OL.txt", "r");
	CreateDG_OL(fp, &G);
	fclose(fp);
	Print_DG_order(G);
	printf("\nKosaraju £º \n");
	Kosaraju(G);
	getchar();
	return 0;
}