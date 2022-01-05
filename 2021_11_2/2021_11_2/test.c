#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//每调用一次函数，num就增加1
//void add(int* p)
//{
//	*p += 1;
//}
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//	return 0;
//}

//函数嵌套调用
//函数不能嵌套定义但是可以嵌套调用

//链式访问
//把一个函数的返回值作为另外一个函数的参数
//int main()
//{
//	int len = strlen("abc");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abc"));
//	return 0;
//}


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));//4321
//	return 0;
//}
#include"add.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret = add(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//接受一个整型值（无符号），按照顺序打印它的每一位。
//void Print(unsigned int n)//n=1234
//{
//	if (n > 9)
//	{
//		Print(n / 10);//Print(123) 1 2 3
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//1234
//	Print(num);
//	return 0;
//}

//编写函数不允许创建临时变量，求字符串的长度
//int my_strlen(char* s)
//{
//	int count = 0;//临时变量
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}

//int my_strlen(char* s)
//{
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(s + 1);
//	}
//}
//int main()
//{
//	//求字符串长度
//	char arr[] = "abc";//a b c \0
//	//arr是数组名，数组名是数组首元素的地址
//	int len = my_strlen(arr);//char*
//
//	printf("%d\n", len);
//	return 0;
//}

//求阶乘
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	//循环产生1~n的数字
//	printf("%d\n", ret);
//	return 0;
//}


//求第n个斐波那契数
int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 2) + fib(n - 1);
	}
}
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n>2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d\n", ret);
	return 0;
}