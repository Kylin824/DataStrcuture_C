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

typedef struct
{
	char *ch;
	int length;
}HString;

void InitString(HString *T);
Status StrAssign(HString *T, char *chars);
Status ClearString(HString *T);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status Concat(HString *T, HString S1, HString S2);
Status SubString(HString *Sub, HString S, int pos, int len);
void StrPrint(HString S);
Status StrEmpty(HString S);
Status StrCopy(HString *T, HString S);
Status StrDelete(HString *T, int pos, int len);
Status StrInsert(HString *T, int pos, HString S);
Status Replace(HString *T, HString S, HString V);
int Index(HString S, HString T, int pos);
void get_next(HString T, int *next);
void get_nextval(HString T, int *nextval);
int Index_KMP(HString S, HString T, int pos);
