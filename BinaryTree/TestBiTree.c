#include"BinaryTree.h"

int main()
{
	BiTree T;
	FILE *fp;
	errno_t err;
	Status result;
	int depth;
	InitBiTree(&T);
	if ((err = fopen_s(&fp, "MyOrderData.txt", "r")) != 0)    //不同点2
	{
		printf("无法打开此文件\n");            //如果打不开，就输出打不开
		return 0;                            //终止程序
	}
	result = CreateBiTree(&T, fp);
	depth = BiTreeDepth(T);
	printf("BiTree Depth: %d\n", depth);
	printf("Preoder: ");
	PreOrderTraverse(T, Visit_Char);
	printf("\nInorder: ");
	InOrderTraverse(T, Visit_Char);
	printf("\nPostorder: ");
	PostOrderTraverse(T, Visit_Char);
	getchar();
	fclose(fp);
	ClearBiTree(&T);
	return 0;
}