#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
//union Un
//{
//	char c;//1
//	int i;//4
//};
//
//int main() 
//{
//	union Un u = {0};
//	u.c = 'w';
//	u.i = 0x11223344;
//	//printf("%d\n", sizeof(u));//4
//  ////联合体也叫共用体
//	//printf("%p\n", &u);//02E2F8A0
//	//printf("%p\n", &(u.c));//一样 - 02E2F8A0
//	//printf("%p\n", &(u.i));//一样 - 02E2F8A0
//
//	return 0;
//}

//判断大小端
//int cheak_sys()
//{
//	int a = 1;
//	//强转解引用低地址，如果为1则是小端，否则是大端
//	if (*(char*)&a == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int cheak_sys()
//{
//	int a = 1;
//	return (*(char*)&a);
//}

//int cheak_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}

//int cheak_sys()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}

//int main()
//{
//	int ret = cheak_sys();
//	if (1 == ret)
//		printf("小端\n");
//	else
//		printf("大端\n");
//
//	//如果返回1，表示小端
//	//如果返回0，表示大端
//	return 0;
//}

//union Un1
//{
//	char c[5];//5 1,8 - 1 (char)对齐数
//	int i;    //4 4,8 - 4 (int) 5不是4的倍数，所以浪费三个字节，8
//};
//
//union Un2
//{
//	short c[7];//14 2,8-2
//	int i;     //4  4,8-4 14不是4的倍数，16是
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));//8
//	printf("%d\n", sizeof(union Un2));//16
//
//	return 0;
//}

//int main()
//{
//	//开辟10个整型的空间
//	//int arr[10];
//	int* p = (int*)malloc(40);
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//释放
//	free(p);//当释放后，p就是野指针了
//	p = NULL;
//	
//	return 0;
//}

//int main()
//{
//	//开辟10个整型的空间
//	//int arr[10];
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用
//	int  i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//	//开辟10个整型的空间
//	//int arr[10];
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//需要增容 - 80
//	int*ptr = (int*)realloc(p, 80);
//	if (NULL != ptr)
//	{
//		p = ptr;
//		ptr = NULL;
//	}
//	//继续使用了
//	
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

int main()
{
	//开辟10个整型的空间
	//int arr[10];
	int* p = (int*)realloc(NULL, 40);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//使用
	int  i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	//释放
	free(p);
	p = NULL;

	return 0;
}