#include"SqStack.h"

/*************************************************
函数功能	：构造一个空栈
输入参数	：栈结构体指针&S
输出参数	：无
函数返回值	：Status
*************************************************/
Status InitStack(SqStack *S)
{
	(*S).base = (ElemType_S *)malloc(STACK_INIT_SIZE * sizeof(ElemType_S));
	if (!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base; //空栈，栈顶指针与栈底指针相同
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

/*************************************************
函数功能	：销毁栈
输入参数	：栈结构体指针&S
输出参数	：无
函数返回值	：void
*************************************************/
void DestroyStack(SqStack *S)
{
	free((*S).base);
	(*S).top = NULL;
	(*S).base = NULL;
	(*S).stacksize = 0;
}

/*************************************************
函数功能	：Push元素e入栈
输入参数	：栈结构体指针&S,元素e
输出参数	：无
函数返回值	：Status
*************************************************/
Status Push(SqStack *S, ElemType_S e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (ElemType_S *)realloc((*S).base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(ElemType_S));
		if (!(*S).base)
			exit(OVERFLOW);
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	//容量足够，开始压栈
	*((*S).top) = e;
	(*S).top = (*S).top + 1;
	return OK;
}

/*************************************************
函数功能	：Pop元素e出栈，并将其值返回
输入参数	：栈结构体指针&S,返回值元素&e
输出参数	：无
函数返回值	：Status
*************************************************/
Status Pop(SqStack *S, ElemType_S *e)
{
	if ((*S).base == (*S).top) //栈为空，出栈失败
	{
		return ERROR;
	}
	*e = *((*S).top - 1);
	(*S).top = (*S).top - 1;
	return OK;
}

void Visit_Int(ElemType_S e)
{
	printf("%d \n", e);
}
void Visit_Char(ElemType_S e)
{
	printf("%c \n", e);
}

/*************************************************
函数功能	：从栈底到栈顶对栈元素调用Visit()方法遍历栈
输入参数	：栈S,Visit()函数指针
输出参数	：无
函数返回值	：Status
*************************************************/
Status StackTraverse(SqStack S, void(*visit_ptr)(ElemType_S))
{
	ElemType_S* p = S.base;
	if (S.base == S.top) //栈为空
	{
		return ERROR;
	}
	while (p != S.top)
	{
		visit_ptr(*p);
		p++;
	}
	return OK;
}

/*************************************************
函数功能	：若栈为空返回TRUE，否则返回FALSE
输入参数	：栈S
输出参数	：无
函数返回值	：Status
*************************************************/
Status StackEmpty(SqStack S)
{
	return S.base == S.top ? TRUE : FALSE;
}

/*************************************************
函数功能	：返回栈元素个数，即栈长度
输入参数	：栈S
输出参数	：无
函数返回值	：int 
*************************************************/
int StackLength(SqStack S)
{
	int i = 0;
	ElemType_S *p = S.top;
	if (S.base == S.top)
	{
		return 0;
	}
	while (p != S.base)
	{
		i++;
		p--;
	}
	return i;
}

/*************************************************
函数功能	：获得栈顶元素
输入参数	：栈S 返回值元素&e
输出参数	：无
函数返回值	：Status
*************************************************/
Status GetTop(SqStack S, ElemType_S *e)
{
	if(S.base == S.top)
	{
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
}