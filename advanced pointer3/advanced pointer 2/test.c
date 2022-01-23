#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void test(char** p)
//{
//
//}
//
//int main()
//{
//	char ch = 'W';
//	char* p = &ch;
//	char* pp = &p;
//	char* arr[5];
//
//	test(&p);
//	test(pp);
//	test(arr);
//
//	return 0;
//}

//函数指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//void test(char* str)
//{
//
//}
//int main()
//{
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);
//	int (*pf)(int, int) = &Add;//pf是函数指针
//
//	//void (*pt)(char*) = test;
//	//第二个括号 -> 函数调用操作符
//	//int sum = (*pf)(2, 3);
//	int sum = (pf)(2, 3);
//	return 0;
//}

//int main()
//{
//	//1. 把0强制类型转换为void(*)()类型的函数指针
//	//2. 再去调用0地址处这个参数为无参，返回类型是void的函数
//	//(*(void(*)())0)();//这是一次函数调用，调用0地址处的函数
//	//0 -> 0x0012ff44就是个数字
//
//	void(*signal(int, void(*)(int)))(int);
//	//首先signal肯定先和后面的括号结合，表明siganl是个函数。但是并没有传参，所以是函数声明
//	//参数有2个： int -> 整型，void(*)(int) -> 函数指针类型
//	//剩下的void(*)(int)就是个函数指针类型的返回值，该指针指向的函数参数int，返回类型是void
//	return 0;
//}


//函数指针数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int (*pfArr[4])(int, int) = { Add,Sub,Mul,Div };//函数指针数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int ret = pfArr[i](8, 4);
//		printf("%d\n", ret);//12,4,32,2
//	}
//	return 0;
//}