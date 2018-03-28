#include"LinkList.h"

int main()
{
	LinkList L; //指向LNode的指针型变量L
	int result = InitList_L(&L); //传L的地址过去
	ElemType_L e=-1,flag,ep=-1,pos;
	ElemType_L p_e, n_e;
	result = ListLength_L(L);
	printf("length:%d\n", result);
	//if (result == 1)
	//{
	//	printf("success\n");
	//}
	//else
	//{
	//	printf("error\n");
	//}
	//result = ListEmpty_L(L);
	//printf("empty:%d\n", result);
	ListInsert_L(L, 1, 1);
	ListInsert_L(L, 2, 2);
	ListInsert_L(L, 3, 3);
	ListInsert_L(L, 4, 4);
	ListInsert_L(L, 5, 5);
	ListInsert_L(L, 6, 15);
	ListInsert_L(L, 7, 7);
	ListInsert_L(L, 8, 24);
	//result = ListLength_L(L);
	//printf("length:%d\n", result);

	//GetElem_L(L, 10, &ep);
	//printf("GetElem: %d\n", ep);

	ListTraverse_L(L, Visit_Int);
	printf("\n");

	flag = ListDelete_L(L, 0, &e);
	if (flag)
	{
		printf("successfully delete iNode:%d\n", e);
	}
	else
	{
		printf("delete error\n");
	}

	pos = LocateElem_L(L, 0, Compare);
	printf("pos : %d\n", pos);

	PriorElem_L(L, 1, &p_e);
	printf("\np_e: %d\n\n", p_e);

	NextElem_L(L, 1, &n_e);
	printf("\nn_e: %d\n\n", n_e);

	ListTraverse_L(L, Visit_Int);
	getchar();
	ListDestory_L(&L);
	return 0;
}