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

/* 链表类型定义 */
typedef int ElemType_L;

/*链表数据结构*/
typedef struct LNode
{
	ElemType_L data;
	struct LNode *next;
	int test;
}LNode, *LinkList;

//typedef LNode* LinkList; //等价于上面的*ListList

Status InitList_L(LinkList *L);
Status ListInsert_L(LinkList L, int i, ElemType_L e);
Status ListDelete_L(LinkList L, int i, ElemType_L *e);
void Visit_Int(ElemType_L i);
void Visit_Char(ElemType_L i);
Status ListTraverse_L(LinkList L, void(*Visit_ptr)(ElemType_L));
void ListDestory_L(LinkList *L); //头节点要删
Status ClearList_L(LinkList L); //头节点不删
Status ListEmpty_L(LinkList L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L, int i, ElemType_L *e);
Status Compare(ElemType_L l, ElemType_L e);
int LocateElem_L(LinkList L, ElemType_L e, Status(*compare_ptr)(ElemType_L, ElemType_L));
Status PriorElem_L(LinkList L, ElemType_L cur_e, ElemType_L *pri_e);
Status NextElem_L(LinkList L, ElemType_L cur_e, ElemType_L *next_e);