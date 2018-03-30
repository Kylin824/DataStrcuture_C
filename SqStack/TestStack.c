#include"SqStack.h"

int main()
{
	SqStack S;
	ElemType_S pop_e;
	int result;
	result = InitStack(&S);
	printf("result:%d\n", result);
	Push(&S, 22);
	Push(&S, 31);
	Push(&S, 14);
	Push(&S, 34);
	Push(&S, 44);
	Push(&S, 54);
	Push(&S, 64);
	Push(&S, 74);
	Push(&S, 84);
	Push(&S, 94);
	Push(&S, 25);
	Push(&S, 6);
	Push(&S, 67);
	Push(&S, 32);
	StackTraverse(S, Visit_Int);
	Pop(&S, &pop_e);
	printf("\npop : %d\n", pop_e);
	Pop(&S, &pop_e);
	printf("\npop : %d\n", pop_e);
	Pop(&S, &pop_e);
	printf("\npop : %d\n\n", pop_e);
	StackTraverse(S, Visit_Int);
	getchar();
	DestroyStack(&S);
	return 0;
}