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

/* 顺序表类型定义 */
typedef char ElemType_Sq;

/* 宏定义 */
#define LIST_INIT_SIZE 10				//顺序表存储空间的初始分配量 
#define LISTINCREMENT  10				//顺序表存储空间的分配增量

/*线性表存储结构*/
typedef struct
{
	int length;			//当前长度
	int listsize;       //当前分配的存储容量
	ElemType_Sq *elem;			//存储空间基地址
}SqList;

Status InitList_Sq(SqList *L);
void DestroyList_Sq(SqList *L);
void ClearList_Sq(SqList *L);
Status ListEmpty_Sq(SqList L);
int ListLength_Sq(SqList L);
Status GetElem_Sq(SqList L, int i, ElemType_Sq *e);
Status Compare(ElemType_Sq l, ElemType_Sq e);
int LocateElem_Sq(SqList L, ElemType_Sq e, Status (*compare_ptr)(ElemType_Sq, ElemType_Sq));
Status PriorElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *pri_e);
Status NextElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *next_e);
Status ListInsert_Sq(SqList *L, int i, ElemType_Sq e);
Status ListDelete_Sq(SqList *L, int i, ElemType_Sq *e);
void Visit_Int(ElemType_Sq i);
void Visit_Char(ElemType_Sq i);
Status ListTraverse_Sq(SqList L, void (*Visit_ptr)(ElemType_Sq));