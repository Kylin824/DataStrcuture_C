#include"LinkQueue.h"

int main()
{
	LinkQueue Q;
	int result;
	char head;
	ElemType_Q re;
	result = InitQueue(&Q);
	printf("result: %d\n", result);

	EnQueue(&Q, 'a');
	EnQueue(&Q, 's');
	EnQueue(&Q, 'd');
	EnQueue(&Q, 'f');

	QueueTraverse(Q, Visit_Char);

	printf("\nlength: %d\n", QueueLength(Q));
	GetHead(Q, &head);
	printf("\n head : %c\n", head);

	DeQueue(&Q, &re);
	printf("\nout : %c\n", re);

	DeQueue(&Q, &re);
	printf("out : %c\n", re);

	GetHead(Q, &head);
	printf("\n head : %c\n", head);

	DeQueue(&Q, &re);
	printf("out : %c\n", re);

	QueueTraverse(Q, Visit_Char);

	printf("\nlength: %d\n", QueueLength(Q));

	ClearQueue(&Q);

	printf("\nlength: %d\n", QueueLength(Q));

	QueueTraverse(Q, Visit_Char);

	getchar();
	DestroyQueue(&Q);
	return 0;
}