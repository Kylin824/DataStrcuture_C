//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//
//	FILE *fp;
//	char a[80];
//	char ch;
//	char ch1;
//	errno_t err;
//	if ((err = fopen_s(&fp, "MyOrderData.txt", "r")) != 0)    //不同点2
//	{
//		printf("无法打开此文件\n");            //如果打不开，就输出打不开
//		return 0;                            //终止程序
//	}
//	fscanf_s(fp, "%c", &ch, 1);
//	printf("%c\n", ch);
//	fscanf_s(fp, "%c", &ch1, 1);
//	printf("%c", ch1);
//	//fscanf_s(fp, "%s", a, 80);
//	//printf("%s", a);
//	getchar();
//	fclose(fp);
//	return 0;
////
////	FILE *fp;
////	errno_t err;
////	char   s[] = "ABDG^^^EH^^I^^CF^J^^^";
////	char   c = '\n';
////	if ((err = fopen_s(&fp, "MyOrderData.txt", "w")) != 0)    //不同点2
////	{
////		printf("无法打开此文件\n");            //如果打不开，就输出打不开
////		exit(0);                               //终止程序
////	}
////	fprintf(fp, "%s%c", s, c);
////	fclose(fp);
////	getchar();
////	return 0;
//}