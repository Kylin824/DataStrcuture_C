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

/* 队列类型定义 */
typedef int ElemType_Q;

typedef struct QNode
{
	ElemType_Q data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, ElemType_Q e);
Status DeQueue(LinkQueue *Q, ElemType_Q *e);
void Visit_Int(ElemType_Q e);
void Visit_Char(ElemType_Q e);
Status QueueTraverse(LinkQueue Q, void(*visit_ptr)(ElemType_Q));
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, ElemType_Q *e);