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
#define UNDERFLOW	-3			//堆栈下溢CreateBiTree
#endif

/* 二叉链表树类型定义 */
typedef char ElemType_T;

/* 二叉链表树结构定义 */
typedef struct BiTNode
{
	ElemType_T data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//typedef BiTNode* BitTree; //等价于上面的*BiTree

Status InitBiTree(BiTree *T);
Status CreateBiTree(BiTree *T, FILE *fp);
Status ClearBiTree(BiTree *T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
ElemType_T Root(BiTree T);
ElemType_T Value(BiTree T, BiTree p);
Status Assign(BiTree T, BiTree *p, ElemType_T value);
void Visit_Int(ElemType_T i);
void Visit_Char(ElemType_T i);
void PreOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
void InOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
void PostOrderTraverse(BiTree T, void(*Visit_ptr)(ElemType_T));
