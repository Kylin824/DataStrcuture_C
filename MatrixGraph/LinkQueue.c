#include"LinkQueue.h"

/*************************************************
函数功能	：初始化队列，队列的头指针(伪)和尾指针存放在LinkQueue结构体中
输入参数	：结构体LinkQueue指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	//(*Q).front->data = 65535;
	return OK;	
}

/*************************************************
函数功能	：插入元素e为队列Q新的队尾元素
输入参数	：结构体LinkQueue指针，元素值e
输出参数	：无
函数返回值	：Status
*************************************************/
Status EnQueue(LinkQueue *Q, ElemType_Q e)
{
	QueuePtr new_node;
	new_node = (QueuePtr)malloc(sizeof(QNode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->next = NULL;
	new_node->data = e;
	(*Q).rear->next = new_node;
	(*Q).rear = new_node;
	return OK;
}

/*************************************************
函数功能	：若队列非空，则删除队头元素并返回其值e，否则返回error
输入参数	：结构体LinkQueue指针，返回元素值e指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status DeQueue(LinkQueue *Q, ElemType_Q *e)
{
	QueuePtr real_front;
	if ((*Q).front == (*Q).rear) //队列为空
		return ERROR;
	real_front = (*Q).front->next;
	*e = real_front->data;
	(*Q).front->next = real_front->next;
	if (real_front == (*Q).rear) //若头节点为尾节点
	{
		(*Q).rear = (*Q).front;
	}
	free(real_front);
	return OK;
}

void Visit_Int(ElemType_Q e)
{
	printf("%d  ", e);
}

void Visit_Char(ElemType_Q e)
{
	printf("%c  ", e);
}

/*************************************************
函数功能	：若队列非空，遍历所有元素并调用visit_ptr指针的函数访问其值
输入参数	：结构体LinkQueue，函数指针*visit_ptr
输出参数	：无
函数返回值	：Status
*************************************************/
Status QueueTraverse(LinkQueue Q, void(*visit_ptr)(ElemType_Q))
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	while (p != NULL)
	{
		visit_ptr(p->data);
		p = p->next;
	}
	return OK;
}

/*************************************************
函数功能	：销毁队列
输入参数	：结构体LinkQueue指针
输出参数	：无
函数返回值	：无
*************************************************/
void DestroyQueue(LinkQueue *Q)
{
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
}

/*************************************************
函数功能	：清空队列
输入参数	：结构体LinkQueue指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status ClearQueue(LinkQueue *Q)
{
	while ((*Q).front->next)
	{
		(*Q).rear = (*Q).front->next;
		(*Q).front->next = (*Q).rear->next;
		free((*Q).rear);
	}
	(*Q).rear = (*Q).front;
	return OK;
}

/*************************************************
函数功能	：判断队列是否为空，若空则返回TRUE，否则返回FALSE
输入参数	：结构体LinkQueue
输出参数	：无
函数返回值	：Status
*************************************************/
Status QueueEmpty(LinkQueue Q)
{
	return Q.front->next == NULL ? TRUE : FALSE;
}

/*************************************************
函数功能	：返回队列长度
输入参数	：结构体LinkQueue
输出参数	：无
函数返回值	：int
*************************************************/
int QueueLength(LinkQueue Q)
{
	QueuePtr p = Q.front->next;
	int j = 0;
	if (p == NULL)
		return 0;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}

/*************************************************
函数功能	：若队列非空，返回队头元素e
输入参数	：结构体LinkQueue，返回元素值*e
输出参数	：无
函数返回值	：Status
*************************************************/
Status GetHead(LinkQueue Q, ElemType_Q *e)
{
	if (Q.front == Q.rear) //队列为空
	{
		return ERROR;
	}
	*e = Q.front->next->data;
	return OK;
}
