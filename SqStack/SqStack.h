#include<stdio.h>
#include<stdlib.h>

/* 状态码 */
typedef int Status;

#define	TRUE		1			//真 
#define	FALSE		0			//假
#define	OK			1			//通过
#define	ERROR		0			//错误

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#endif

/* 栈元素类型定义 */
typedef int ElemType_S;

#define STACK_INIT_SIZE  10 //线性栈存储空间的初始分配量 
#define STACKINCREMENT  10 //线性栈存储空间的分配增量

typedef struct 
{
	int stacksize;
	ElemType_S *base;
	ElemType_S *top;
}SqStack;

Status InitStack(SqStack *S);
void DestroyStack(SqStack *S);
Status Push(SqStack *S, ElemType_S e);
Status Pop(SqStack *S, ElemType_S *e);
void Visit_Int(ElemType_S e);
void Visit_Char(ElemType_S e);
Status StackTraverse(SqStack S, void(*visit_ptr)(ElemType_S));
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, ElemType_S *e);