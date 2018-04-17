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

/* 类型定义 */
typedef char ElemType_Thr;

typedef enum { Link, Thread } PointerTag;// 0(Link)为指针，1(Thread)为线索

/* 二叉线索树结构定义 */
typedef struct BiThrNode
{
	ElemType_Thr data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag,RTag;
}BiThrNode, *BiThrTree;

//typedef BiThrNode* BiThrTree;
Status InitBiThrTree(BiThrTree *T);
Status CreateBiThrTree(BiThrTree *T, FILE *fp);
void ClearBiThrTree(BiThrTree *T);
void Visit_Char(ElemType_Thr i);
void InOrderTraverse(BiThrTree T, void(*Visit_ptr)(ElemType_Thr));
void InThreading(BiThrTree T);
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T);




