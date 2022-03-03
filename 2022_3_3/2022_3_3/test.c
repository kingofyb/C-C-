#define _CRT_SECURE_NO_WARNINGS 1
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//  //忘记释放
//	free(str);
//	str = NULL;
//
//	if (str != NULL)
//	{
//		//因为之前对str指向的空间已经释放，不能再次使用
//      //形成非法访问
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//柔性数组

//struct S1
//{
//	int n;
//	int arr[0];//大小是未指定
//};
//
//struct S2
//{
//	int n;
//	int arr[];//
//};
////flexible array
////结构中的柔性数组成员前面必须至少一个其他成员
////sizeof返回的这种结构大小不包括柔性数组的内存
////包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小
////以适应柔性数组的预期大小
//int main()
//{
//	//printf("%d\n", sizeof(struct S1));
//	struct S2* ps = (struct S2*)malloc(sizeof(struct S2) + 40);//40是给arr的
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//增容
//	struct S2* ptr = (struct S2*)realloc(ps, sizeof(struct S2)+80);
//	if (ptr == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		ps = ptr;
//	}
//	//释放
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
//
//struct S
//{
//	int n;
//	int* arr;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->n = 100;
//	ps->arr = (int*)malloc(40);
//	//使用
//	//增容
//
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
//