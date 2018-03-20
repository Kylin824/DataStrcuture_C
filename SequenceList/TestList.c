#include<stdio.h>
#include"SqList.h"

int main()
{
	SqList L;
	ElemType_Sq e;
	int loc;
	ElemType_Sq pe = 0;
	ElemType_Sq ne = 0;
	int result = InitList_Sq(&L);
	if (result == 1)
	{
		printf("success\n");
	}
	else
	{
		printf("error");
	}
	ListInsert_Sq(&L, 1, 'a');
	ListInsert_Sq(&L, 2, 'b');
	ListInsert_Sq(&L, 3, 'c');
	ListInsert_Sq(&L, 4, 'd');
	printf("list:\n");
	ListTraverse_Sq(L, Visit_Char);
	ListDelete_Sq(&L, 3, &e);
	ListTraverse_Sq(L, Visit_Char);
	//printf("e:%d\n", e);
	//GetElem_Sq(L, 2, &e);
	//printf("\ne:%d\n", e);
	//loc = LocateElem_Sq(L, 7, Compare);
	//printf("loc:%d\n", loc);
	//PriorElem_Sq(L, 5, &pe);
	//printf("pe:%d\n", pe);

	//NextElem_Sq(L, 5, &ne);
	//printf("ne:%d\n", ne);

	printf("e:%c\n", e);
	GetElem_Sq(L, 2, &e);
	printf("\ne:%c\n", e);
	loc = LocateElem_Sq(L, 'c', Compare);
	printf("loc:%c\n", loc);
	PriorElem_Sq(L, 'c', &pe);
	printf("pe:%c\n", pe);

	NextElem_Sq(L, 'c', &ne);
	printf("ne:%c\n", ne);

	getchar();
	free(L.elem);
	return 0;
}