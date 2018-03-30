#include"SqList.h"

/*************************************************
函数功能	：构造一个空的顺序线性表L
输入参数	：线性表L指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status InitList_Sq(SqList *L)
{
	(*L).elem = (ElemType_Sq *)malloc(LIST_INIT_SIZE * sizeof(ElemType_Sq));
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}
/*************************************************
函数功能	：销毁线性表L
输入参数	：线性表L指针
输出参数	：无
函数返回值	：无
*************************************************/
void DestroyList_Sq(SqList *L)
{
	free((*L).elem);

	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}

/*************************************************
函数功能	：清空线性表L
输入参数	：线性表L指针
输出参数	：无
函数返回值	：无
*************************************************/
void ClearList_Sq(SqList *L)
{
	(*L).length = 0;
}

/*************************************************
函数功能	：判断线性表L是否为空表
输入参数	：线性表L的结构体值，只读不写，传值即可
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListEmpty_Sq(SqList L)
{
	return 	L.length == 0 ? TRUE : FALSE;
}

/*************************************************
函数功能	：查看线性表L长度
输入参数	：线性表L的结构体值，只读不写，传值即可
输出参数	：无
函数返回值	：int
*************************************************/
int ListLength_Sq(SqList L)
{
	return 	L.length;
}

/*************************************************
函数功能	：用e返回线性表L中第i个元素的值
输入参数	：线性表L的结构体值，元素位置i，接受返回值的指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status GetElem_Sq(SqList L, int i, ElemType_Sq *e)
{
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	else
	{
		*e = L.elem[i - 1];
		//*e = *(L.elem + i - 1);  两条语句等价
	}
	return OK;
}

/*************************************************
函数功能	：数据元素判定函数
输入参数	：表中元素l，判定的元素e
输出参数	：无
函数返回值	：Status
*************************************************/
Status Compare(ElemType_Sq l, ElemType_Sq e)
{
	return e == l ? TRUE : FALSE;
}

/*************************************************
函数功能	：返回L中第一个与e满足compare()的元素的位置i，若不存在该元素则返回0
输入参数	：线性表L，判定的元素e， compare()函数指针
输出参数	：无
函数返回值	：int
*************************************************/
int LocateElem_Sq(SqList L, ElemType_Sq e, Status(*compare_ptr)(ElemType_Sq, ElemType_Sq))
{
	int i = 1;
	//不确定循环多少次，使用while循环
	while (i <= L.length && !compare_ptr(L.elem[i-1], e))
	{
		i++;
	}
	if (i <= L.length)
	{
		return i;
	}
	else
	{
		return FALSE;
	}
}

/*************************************************
函数功能	：若cur_e是L的元素且不是第一个，则用pri_e返回它的前驱，否则返回ERROR，pre_e无定义
输入参数	：线性表L，当前元素cur_e，前驱元素pri_e
输出参数	：无
函数返回值	：Status
*************************************************/
Status PriorElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *pri_e)
{
	int i = 0;

	while (i <= L.length && L.elem[i] != cur_e)
	{
		i++;
	}
	if (i < L.length && i != 0)//表中存在cur_e值且cur_e不是第一个元素
	{
		//将cur_e的前驱赋给pri_e
		*pri_e = L.elem[i - 1];
		return OK;
	}
	return ERROR;
}

/*************************************************
函数功能	：若cur_e是L的元素且不是最后一个，则用next_e返回它的后继，否则返回ERROR，next_e无定义
输入参数	：线性表L，当前元素cur_e，后继元素next_e
输出参数	：无
函数返回值	：Status
*************************************************/
Status NextElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *next_e)
{
	int i = 0;

	while (i <= L.length && L.elem[i] != cur_e)
	{
		i++;
	}

	if (i < L.length && i != L.length - 1)//表中存在cur_e值且cur_e不是最后一个元素
	{
		*next_e = L.elem[i + 1];
		return OK;
	}
	return ERROR;
}

/*************************************************
函数功能	：在顺序线性表L中第i个位置之前插入元素e，L长度加1
输入参数	：线性表L指针，元素位置i，元素值e
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListInsert_Sq(SqList *L, int i, ElemType_Sq e)
{
	ElemType_Sq *newbase;
	ElemType_Sq *q, *tail;
	//位置i不合法，返回错误
	if (i < 1 || i > (*L).length + 1)
	{
		return ERROR;
	}
	if ((*L).length > (*L).listsize)
	{
		//表已满，增加分配
		newbase = (ElemType_Sq *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType_Sq));
		if (!newbase)
		{
			//分配失败，返回
			exit(OVERFLOW);
		}
		(*L).elem = newbase;
		(*L).listsize = (*L).listsize + LISTINCREMENT;
		//分配成功，接下来添加该元素
	}

	q = &((*L).elem[i - 1]);//q为插入位置
	tail = &((*L).elem[(*L).length - 1]); //tail为表尾元素位置
	//tail = (*L).elem + (*L).length - 1; 	//两条语句等价
	for (; tail >= q; tail--)
	{
		*(tail + 1) = *tail; //将i到n的元素依次向后移动一位
	}
	*q = e; //将e赋给第i个元素，完成插入
	(*L).length++;
	return OK;
}


/*************************************************
函数功能	：删除线性表第i个元素，并用e返回其值，L长度减1
输入参数	：线性表L指针，元素位置i，元素值e
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListDelete_Sq(SqList *L, int i, ElemType_Sq *e)
{
	ElemType_Sq *q, *tail;
	//位置i不合法，返回错误
	if (i < 1 || i >(*L).length + 1)
	{
		return ERROR;
	}
	q = &((*L).elem[i - 1]);				//q为插入位置
	*e = *q;								//取得第i个元素的值
	tail = &((*L).elem[(*L).length - 1]);	//tail为表尾元素位置
	//tail = (*L).elem + (*L).length - 1; 	//两条语句等价
	for (++q; q <= tail; q++)
	{
		//由第q+1个元素起，依次覆盖前一个元素
		*(q - 1) = *q;
	}
	(*L).length--;
	return OK;
}

/*************************************************
函数功能	：访问元素
输入参数	：元素指针i
输出参数	：元素值
函数返回值	：无
*************************************************/
void Visit_Int(ElemType_Sq i)
{
	printf("%d  ", i);
}

void Visit_Char(ElemType_Sq i)
{
	printf("%c  ", i);
}

/*************************************************
函数功能	：遍历并输出线性表元素
输入参数	：线性表L指针，函数Visit()指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListTraverse_Sq(SqList L, void(*Visit_ptr)(ElemType_Sq))
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		Visit_ptr(L.elem[i]);
	}
	return OK;
}



