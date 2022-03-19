#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//宏名全部大写
//函数名不要全部大写
//#undef 移除宏定义

//命令行定义
//可以在编译指令的地方指定符号的值

//选择性编译
//条件编译
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//#if 0
//		printf("%d\n", i);		
//#endif
//		//业务处理
//	}
//	return 0;
//}

//#define M 150
//
//int main()
//{
//#if M<100
//	printf("less\n");
//#elif M==100
//	printf("==\n");
//#elif M>100&&M<200
//	printf("more\n");
//#else
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//#define M 0
//
//int main()
//{
////#if defined(M)//只要定义过，不管值是什么，都会执行
////	printf("hehe\n");
////#endif
////
////#ifdef M
////	printf("haha\n");
////#endif
//
//
////#if !defined(M)
////	printf("hehe\n");
////#endif
////
////#ifndef M
////	printf("haha\n");
////#endif
//
//	return 0;
//}

//#include "test.h"
//#include "test.h"
//#include "test.h"
//#include "test.h"

//#include "test.h"
////#include <stdio.h>
//
//#include "stdio.h"
////1.当前工程目录查找
////2.库目录下查找
//
//int main()
//{
//
//	return 0;
//}

//模拟实现atoi
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

//int my_atoi(char* str)
//{
//	int n = 0;
//	assert(str);
//
//	while (*str)
//	{
//		n = n * 10 + (*str - '0');
//		str++;
//	}
//	return n;
//}
//1. 空指针
//2. 空字符串
//3. 空白字符
//4. +-
//5. 非数字字符
//6. 超大数字


//
//enum State
//{
//	INVALID,//非法
//	VALID   //合法
//};
//
//enum State status = INVALID;
//
//int my_atoi(const char* str)
//{
//	assert(str);
//	//空字符串
//	if (*str == '\0')
//		return 0;
//
//	//空白字符（跳过）
//	while (isspace(*str))
//	{
//		str++;
//	}
//	int flag = 1;
//	
//	//+-
//	if (*str == '+')
//	{
//		str++;
//		flag = 1;
//	}
//	else if (*str == '-')
//	{
//		str++;
//		flag = -1;
//	}
//
//	long long n = 0;
//	while (isdigit(*str))
//	{
//		n = n * 10 + flag*(*str - '0');
//		//越界的值
//		if (n > INT_MAX || n < INT_MIN)
//		{
//			return 0;
//		}
//		str++;
//	}
//	if (*str == '\0')
//	{
//		//合法返回
//		status = VALID;
//		return (int)n;
//	}
//
//	return (int)n;
//}

//int main()
//{
//	int ret = my_atoi("");//"0"
//	if (status == VALID)
//		printf("%d\n", ret);
//	else
//		printf("非法返回\n");
//
//	return 0;
//}