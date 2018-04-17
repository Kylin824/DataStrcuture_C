#include"BiThrTree.h"

Status InitBiThrTree(BiThrTree *T)
{
	*T = NULL;
	return OK;
}

Status CreateBiThrTree(BiThrTree *T, FILE *fp)
{
	char ch;
	fscanf_s(fp, "%c", &ch, 1);
	if (ch == '^')
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiThrTree(&(*T)->lchild, fp);
		if ((*T)->lchild) /* 有左孩子 */
			(*T)->LTag = Link;
		CreateBiThrTree(&(*T)->rchild, fp);
		if ((*T)->rchild) /* 有右孩子 */
			(*T)->RTag = Link;
	}
	return OK;
}

void ClearBiThrTree(BiThrTree *T)
{
	if (*T) //二叉树不为空
	{
		if ((*T)->lchild)
			if ((*T)->LTag != Thread)
				ClearBiThrTree(&(*T)->lchild);
		if ((*T)->rchild)
			if ((*T)->RTag != Thread)
				ClearBiThrTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

void Visit_Char(ElemType_Thr i)
{
	printf("%c ", i);
}

void InOrderTraverse(BiThrTree T, void(*Visit_ptr)(ElemType_Thr))
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild, Visit_Char);
	Visit_ptr(T->data);
	InOrderTraverse(T->rchild, Visit_Char);
}

BiThrTree pre;

void InThreading(BiThrTree T)
{
	if (T) // 线索二叉树不为空
	{
		InThreading(T->lchild);
		if (!T->lchild) //无左孩子
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild) //前驱无右孩子
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T; // 保持pre指向前驱
		InThreading(T->rchild);
	}
}

Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	//中序遍历二叉树T，并将其线索化，Thrt指向头结点
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*Thrt)
		exit(OVERFLOW);
	(*Thrt)->LTag = Link; /* 建头结点 */
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt); /* 右指针回指 */
	if (!T) /* 若二叉树空,则左指针回指 */
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T; // 头结点指向根结点
		pre = (*Thrt);
		InThreading(T); /* 中序遍历进行中序线索化 */
		pre->rchild = *Thrt; //InThreading结束后，pre为最后一个结点，将其右孩子指向头节点Thrt
		pre->RTag = Thread; /* 最后一个结点线索化 */
		(*Thrt)->rchild = pre;  //Thrt的右孩子指向最后一个结点
	}
	return OK;
}