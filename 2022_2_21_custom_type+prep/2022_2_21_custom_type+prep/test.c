#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//修改默认对齐数
//#pragma pack(1)
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	return 0;
//}

//#pragma pack(4)
//struct S
//{
//	char c1;//0
//	//1~3
//	double d;//8 4 4 4~11
//	char c2;//12
//	//13~15
//};
//#pragma pack()