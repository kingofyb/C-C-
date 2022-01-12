#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//指针是内存中一个最小的单元编号，也就是地址
//平时口语中说的指针，通常指的是指针变量，是用来存放内存地址的变量
//地址 - 内存单元的标号
//高电频 - 1      低电频 - 0
//32位 - 32跟地址线 - 物理的电线 - 通电 - 1/0

//1 . 指针类型决定了在解引用的是一次能访问几个字节（指针的权限）
//int* --> 4
//float* --> 4
//char* --> 1
//double* --> 8

//2 . 指针类型决定了指针向前后者向后走一步，走多大距离（单位是字节）

//int main()
//{
//	//用指针初始化
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//倒着打印
//	int* q = &arr[9];
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *q);
//		q--;
//	}
//
//	return 0;
//}

//一个字符一个字符
//int main()
//{
//	int arr[10] = { 0 };
//	char* p = (char*)arr;
//
//	return 0;
//}

//野指针
//int main()
//{
//	//int* p;//野指针
//
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		//数组越界
//		*p = i;
//		p++;
//	}
//	return 0;
//}

//                             指针运算
//指针 +/- 整数
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//倒着打印
	//int* q = arr + sz - 1;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", *(q - i));
	//}
//
//	return 0;
//}

//指针 - 指针 = 两个指针之间的元素个数


// 计数器方法
//int my_strlen(char* s)
//{
//	int count = 0;
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}

//指针 - 指针 的方法
//int my_strlen(char* s)
//{
//	char* start = s;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return s - start;
//}
////求字符串长度
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//二级指针
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;//ppa就是一个二级指针

	return 0;
}