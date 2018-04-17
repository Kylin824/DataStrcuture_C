#include"BiThrTree.h"

int main()
{
	BiThrTree T;
	BiThrTree Thrt;
	FILE *fp;
	errno_t err;
	InitBiThrTree(&T);
	if ((err = fopen_s(&fp, "MyOrderData.txt", "r")) != 0)    //不同点2
	{
		printf("无法打开此文件\n");            //如果打不开，就输出打不开
		return 0;                            //终止程序
	}
	CreateBiThrTree(&T, fp);
	printf("Inorder: ");
	InOrderTraverse(T, Visit_Char);
	InOrderThreading(&Thrt, T);
	//getchar();
	fclose(fp);
	ClearBiThrTree(&Thrt);
	return 0;
}