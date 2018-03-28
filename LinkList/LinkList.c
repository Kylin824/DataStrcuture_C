#include"LinkList.h"

/*************************************************
函数功能	：创建空链表，即创建头节点L
输入参数	：头节点结构体地址&L
输出参数	：无
函数返回值	：Status
*************************************************/
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;
	(*L)->test = 255;
	return OK;
}

/*************************************************
函数功能	：在链表L中第i个位置之前插入元素e
输入参数	：头节点L，元素位置i，元素值e
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListInsert_L(LinkList L, int i, ElemType_L e)
{
	LinkList p = L;
	LinkList new_node;
	int j = 0;//从头节点开始找到第i-1个节点

	while (p && j < i -1)
	{
		p = p->next;
		j++;
	}
	//p已指向i-1节点，开始创建新节点

	new_node = (LinkList)malloc(sizeof(LNode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->data = e;
	new_node->next = p->next;
	p->next = new_node;

	return OK;
}

void Visit_Int(ElemType_L i)
{
	printf("%d  ", i);
}

void Visit_Char(ElemType_L i)
{
	printf("%c  ", i);
}

/*************************************************
函数功能	：遍历并输出链表元素
输入参数	：头节点L，函数Visit()指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListTraverse_L(LinkList L, void(*Visit_ptr)(ElemType_L))
{
	LinkList p = L->next;

	while (p != NULL)
	{
		Visit_ptr(p->data);
		p = p->next;
	}

	return OK;
}

/*************************************************
函数功能	：销毁所有节点
输入参数	：头节点结构体地址&L
输出参数	：无
函数返回值	：void
*************************************************/
void ListDestory_L(LinkList *L)
{
	LinkList p = *L;
	while (p)
	{
		p = (*L)->next;
		free(*L);
		*L = p;

	}
}

/*************************************************
函数功能	：清空链表，保留头节点
输入参数	：头节点L
输出参数	：无
函数返回值	：void
*************************************************/
Status ClearList_L(LinkList L)
{
	if (!L)
		return ERROR;

	LinkList pre,p; //pre为前驱节点

	pre = L->next;

	while (pre)
	{
		p = pre->next;
		free(pre);
		pre = p;
	}
	L->next = NULL;

	return OK;
}

/*************************************************
函数功能	：删除指定位置i的节点并用返回该节点值e
输入参数	：头节点L，删除位置i,节点data值
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListDelete_L(LinkList L, int i, ElemType_L *e)
{
	LinkList pre,p; //pre:第i个节点的前驱
	pre = L;
	int j = 1;
	//找到i-1个点
	while (pre->next && j < i)
	{
		pre = pre->next;
		j++;
	}

	if (!pre->next || j > i) //!pre-next是j>=表长的情况，j>i是j<=0的情况
	{
		return ERROR;
	}
	//否则则位置正确
	p = pre->next;
	pre->next = p->next;
	*e = p->data;
	free(p);

	return OK;
}

/*************************************************
函数功能	：判断链表L是否为空表
输入参数	：头节点L
输出参数	：无
函数返回值	：Status
*************************************************/
Status ListEmpty_L(LinkList L)
{
	if (L != NULL && L->next == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/*************************************************
函数功能	：查看链表长度
输入参数	：头节点L
输出参数	：无
函数返回值	：int
*************************************************/
int ListLength_L(LinkList L)
{
	LinkList p;
	int j=0;
	p = L;
	while (p->next)
	{
		p = p->next;
		j++;
	}
	return j;
}

/*************************************************
函数功能	：用e返回链表L中第i个元素的值
输入参数	：头节点L，元素位置i，接受返回值的指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status GetElem_L(LinkList L, int i, ElemType_L *e)
{
	LinkList pre, p; //pre:第i个节点的前驱
	pre = L;
	int j = 1;
	//找到i-1个点
	while (pre->next && j < i)
	{
		pre = pre->next;
		j++;
	}

	if (!pre->next || j > i) //!pre-next是j>=表长的情况，j>i是j<=0的情况
	{
		return ERROR;
	}
	//否则则位置正确
	p = pre->next;
	*e = p->data;
	return OK;
}

Status Compare(ElemType_L l, ElemType_L e)
{
	return e == l ? TRUE : FALSE;
}

/*************************************************
函数功能	：返回L中第一个与e满足compare()的元素的位置j，若不存在该元素则返回0
输入参数	：头节点L，判定的元素e， compare()函数指针
输出参数	：无
函数返回值	：int
*************************************************/
int LocateElem_L(LinkList L, ElemType_L e, Status(*compare_ptr)(ElemType_L, ElemType_L))
{
	LinkList p = L->next;
	int j=1;
	while (p && !compare_ptr(p->data, e))
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		return j;
	}
	else
	{
		return FALSE;
	}
	
}

/*************************************************
函数功能	：若cur_e是L的元素且不是第一个，则用pri_e返回它的前驱，否则返回ERROR，pre_e为-1
输入参数	：头节点L，当前元素cur_e，前驱元素&pri_e
输出参数	：无
函数返回值	：Status
*************************************************/
Status PriorElem_L(LinkList L, ElemType_L cur_e, ElemType_L *pri_e)
{
	LinkList p, pre;
	pre = L;
	p = L->next;
	while (p && p->data != cur_e)
	{
		pre = p;
		p = p->next;
	}
	if (p != NULL && p != L->next) //cur_e不存在或cur_e为头节点
	{
		*pri_e = pre->data;
		return OK;
	}
	*pri_e = -1; //cur_e不存在，pri_e返回-1
	return ERROR;
}

/*************************************************
函数功能	：若cur_e是L的元素且不是第一个，则用next_e返回它的后继，否则返回ERROR，next_e为-1
输入参数	：头节点L，当前元素cur_e，前驱元素&next_e
输出参数	：无
函数返回值	：Status
*************************************************/
Status NextElem_L(LinkList L, ElemType_L cur_e, ElemType_L *next_e)
{
	LinkList p;
	p = L->next;
	while (p && p->data != cur_e)
	{
		p = p->next;
	}
	if (p && p->next != NULL) //cur_e不存在 && cur_e为尾节点
	{
		*next_e = p->next->data;
		return OK;
	}
	*next_e = -1; //cur_e不存在，pri_e返回-1
	return ERROR;
}