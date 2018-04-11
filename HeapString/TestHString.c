#include"HeapString.h"

int main()
{
	//HString T1, T2, S, Sub, V;

	//int pkmp, pos;
	//HString S,T;
	//InitString(&T);
	//StrAssign(&T, "ababaaaba");
	//InitString(&S);
	//StrAssign(&S, "absababaaabaabbsbshaijsababaaaba");
	//pkmp = Index_KMP(S, T, 3);
	//pos = Index(S, T, 3);
	//printf("pkmp : %d\n", pkmp);
	//printf("pos : %d\n", pos);
	//getchar();

	//ClearString(&S);
	//ClearString(&T);
	int i;
	HString T;
	int next[20] = {0};
	int nextval[20] = {0};
	InitString(&T);
	StrAssign(&T, "ababaaaba");
	get_next(T, next);
	get_nextval(T, nextval);
	printf("next: ");
	for (i = 0; i < 12; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\nnextval: ");
	for (i = 0; i < 12; i++)
	{
		printf("%d ", nextval[i]);
	}
	printf("\n");
	getchar();
	ClearString(&T);
	////int result;
	//InitString(&T1);
	//InitString(&T2);
	//InitString(&S);
	//InitString(&Sub);
	//InitString(&V);
	//StrAssign(&T1, "123");
	//StrAssign(&T2, "abc123ius123iok123");
	//StrAssign(&S, "abc123def123ghi123jkl123mn");
	//StrAssign(&V, "llllky");
	////result = Concat(&S, T1, T2);
	//StrPrint(T1);
	//StrPrint(T2);
	//printf("s result :");
	//StrPrint(S);
	////StrDelete(&S, 0, 9);
	////printf("delete result :");
	////StrPrint(S);
	////StrInsert(&S, 2, T1);
	////printf("insert result :");
	////StrPrint(S);
	//Replace(&S, T1, V);
	//printf("replace result :");
	//StrPrint(S);
	////SubString(&Sub, S, 3, 10);
	////printf("substring result :");
	////StrPrint(Sub);
	////printf("´®³¤Îª%d ´®¿Õ·ñ£¿%d(1:¿Õ 0:·ñ)\n", StrLength(T1), StrEmpty(T1));
	//ClearString(&T1);
	////printf("´®³¤Îª%d ´®¿Õ·ñ£¿%d(1:¿Õ 0:·ñ)\n", StrLength(T1), StrEmpty(T1));
	//ClearString(&T2);
	//getchar();
	//ClearString(&S);
	//ClearString(&Sub);
	//ClearString(&V);
	return 0;
}