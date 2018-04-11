#include"HeapString.h"
#include<string.h>

/*******************************************
操作结果: 初始化串S
*******************************************/
void InitString(HString *T)
{ 
	(*T).length = 0;
	(*T).ch = NULL;
}

/*******************************************
初始条件: chars是字符串常量
操作结果: 生成一个其值等于串常量chars的串T
*******************************************/
Status StrAssign(HString *T, char *chars)
{
	int i = 0;
	char *c = chars;
	if ((*T).ch)
		free((*T).ch);
	while (*c) //计算字符串长度
	{
		i++;
		c++;
	}
	(*T).ch = (char *)malloc(i * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	memcpy((*T).ch, chars, i); //将chars字符串复制到T.ch上
	(*T).length = i;
	return OK;
}

/*******************************************
初始条件: 串S存在
操作结果: 将S清为空串
*******************************************/
Status ClearString(HString *T)
{
	if ((*T).ch)
	{
		free((*T).ch);
		(*T).ch = NULL;
	}
	(*T).length = 0;
	return OK;
}

/*******************************************
初始条件: 串S存在
操作结果: 返回S的元素个数,称为串的长度
*******************************************/
int StrLength(HString S)
{
	return S.length;
}

/*******************************************
初始条件: 串S与T都存在
操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
*******************************************/
int StrCompare(HString S, HString T)
{
	int i;
	for (i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}
	//两个串相等
	return S.length - T.length;
}

/*******************************************
初始条件: 串S1与S2都存在
操作结果: 用T返回由S1和S2联接而成的新串
*******************************************/
Status Concat(HString *T, HString S1, HString S2)
{
	int i;
	if ((*T).ch) //释放旧空间
		free((*T).ch);
	(*T).ch = (char *)malloc((S1.length + S2.length) * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	for (i = 0; i < S1.length; i++)
	{
		(*T).ch[i] = S1.ch[i];
	}
	(*T).length = S1.length + S2.length;
	for (i = 0; i < S2.length; i++)
	{
		(*T).ch[i + S1.length] = S2.ch[i];
	}
	return OK;
}

/*******************************************
初始条件: 串S存在，1<= pos <= S.length && 0 <= len <= S.length - pos +1
操作结果: 用Sub返回串S的第pos个字符起长度为len的子串
*******************************************/
Status SubString(HString *Sub, HString S, int pos, int len)
{
	int i;
	if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos +1)
	{
		return ERROR;
	}
	if ((*Sub).ch)
		free((*Sub).ch); //清空旧字串
	if (!len) //len == 0
	{
		(*Sub).ch = NULL;
		(*Sub).length = 0;
	}
	else
	{
		(*Sub).ch = (char *)malloc(len * sizeof(char));
		for (i = 0; i < len; i++)
		{
			(*Sub).ch[i] = S.ch[pos - 1 + i];
		}
		(*Sub).length = len;
	}
	return OK;
}

/*******************************************
初始条件: 串S存在
操作结果: 输出T字符串
*******************************************/
void StrPrint(HString S)
{
	int i;
	for (i = 0; i < S.length; i++)
	{
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

/*******************************************
初始条件: 串S存在
操作结果: 若S为空串,则返回TRUE,否则返回FALSE 
*******************************************/
Status StrEmpty(HString S)
{
	return S.ch == NULL ? TRUE : FALSE;
}

/*******************************************
初始条件:串T存在
操作结果: 由串T复制得串S
*******************************************/
Status StrCopy(HString *T, HString S)
{
	int i;
	if (!S.ch)
	{
		return ERROR;
	}
	if ((*T).ch)
		free((*T).ch);
	(*T).ch = (char *)malloc(S.length * sizeof(char));
	if (!(*T).ch)
		exit(OVERFLOW);
	for (i = 0; i < S.length; i++)
	{
		(*T).ch[i] = S.ch[i];
	}
	(*T).length = S.length;
	return OK;
}

/*******************************************
初始条件:串T存在，1<= pos <= S.length && 0 <= len <= S.length - pos +1
操作结果: 从串T中删除第pos个字符起长度为len的子串
*******************************************/
Status StrDelete(HString *T, int pos, int len)
{
	int i;
	if (pos < 1 || pos > (*T).length || len < 0 || len > (*T).length - pos + 1)
	{
		return ERROR;
	}
	for (i = pos -1; i < (*T).length - len; i++)
	{
		(*T).ch[i] = (*T).ch[i + len];
	}
	(*T).length = (*T).length - len;
	(*T).ch = (char *)realloc((*T).ch, (*T).length * sizeof(char));
	return OK;
}

/*******************************************
初始条件:串T存在，1<= pos <= S.length
操作结果: 在串T中的第pos个字符之前插入串S
*******************************************/
Status StrInsert(HString *T, int pos, HString S)
{
	int i;
	if (pos < 1 || pos >(*T).length + 1)
	{
		return ERROR;
	}
	if (S.length)
	{
		(*T).ch = (char *)realloc((*T).ch, ((*T).length + S.length) * sizeof(char));
		if (!(*T).ch)
			exit(OVERFLOW);
		for (i = (*T).length - 1; i >= pos - 1; i--)
		{
			(*T).ch[S.length + i] = (*T).ch[i];
		}
		for (i = 0; i < S.length; i++)
		{
			(*T).ch[pos - 1 + i] = S.ch[i];
		}
		(*T).length += S.length;
	}
	return OK;
}

/*******************************************
初始条件:串S，T和V存在，T是非空串
操作结果:用V替换主串S中出现的所有与T相等的不重叠的子串
*******************************************/
Status Replace(HString *S, HString T, HString V)
{
	int pos;
	if (StrEmpty(T)) /* T是空串 */
		return ERROR;
	pos = Index(*S, T, 1);
	while (pos) //串S中存在串T 
	{
		StrDelete(S, pos, T.length);
		StrInsert(S, pos, V);
		pos += V.length;
		pos = Index(*S, T, pos);
	}
	return OK;
}

/*******************************************
初始条件:串S和T存在，T是非空串，1<= pos <= S.length
操作结果:若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次
		 出现的位置；否则函数值为0
注：普通模式匹配
*******************************************/
int Index(HString S, HString T, int pos)
{
	int i;
	HString tmp;
	InitString(&tmp);
	if (pos < 0 || pos > S.length)
	{
		return ERROR;
	}
	i = pos;
	while (i <= S.length + T.length - 1)
	{
		SubString(&tmp, S, i, T.length);
		if (StrCompare(tmp, T) != 0)
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	return 0;
}
/*******************************************
初始条件:子串非空
操作结果:计算返回子串T的next数组(部分匹配表)，用于KMP匹配
*******************************************/
void get_next(HString T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[i] = j; //第一个必为0
	while (i < T.length)
	{
		if (j == 0 || T.ch[i - 1] == T.ch[j - 1]) //j==0，第二个必为1，然后j=1 
												  //从第三个开始，若前缀T.ch[i-1]等于后缀T.ch[j-1]，则i与j都往后移
		{
			++i;
			++j;
			next[i - 1] = j;
		}
		else                      //否则j回溯
		{
			j = next[j - 1];
		}
	}
}

/*******************************************
初始条件:子串非空
操作结果:KMP匹配，不回溯i值，通过next[]数组来回溯j值，达到KMP匹配i不回溯
*******************************************/
int Index_KMP(HString S, HString T, int pos)
{
	int i = pos;
	int j = 0;
	int next[20] = { 0 };
	get_next(T, next);
	while (i <= S.length + T.length - 1 && j < T.length)
	{
		if (j == -1 || S.ch[i] == T.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j] - 1;
		}
	}
	if (j >= T.length)
	{
		return i - T.length + 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************
初始条件:子串非空
操作结果:get_next()算法的改进
*******************************************/
void get_nextval(HString T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[i] = j; //第一个必为0
	while (i < T.length)
	{
		if (j == 0 || T.ch[i - 1] == T.ch[j - 1]) //j==0，第二个必为1，然后j=1 
												  //从第三个开始，若前缀T.ch[i-1]等于后缀T.ch[j-1]，则i与j都往后移
		{
			++i;
			++j;
			if (T.ch[i - 1] != T.ch[j - 1])
			{
				nextval[i - 1] = j;
			}
			else
			{
				nextval[i - 1] = nextval[j - 1];
			}
		}
		else                      //否则j回溯
		{
			j = nextval[j - 1];
		}
	}
}