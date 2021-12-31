#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//if判断语句
//int main()
//{
//	int input = 0;
//	printf("你要好好学习吗?(1\0)\n");
//	//输入
//	scanf("%d", &input);
//	//判断
//	if (input == 1)
//	{
//		printf("好offer\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//	return 0;
//}

//循环
//int main()
//{
//	int line = 0;
//	
//	while (line < 20000)
//	{
//		printf("敲代码\n");
//		line += 1;
//	}
//	if (line >= 20000)
//	{
//		printf("好offer");
//	}
//	else
//	{
//		printf("继续努力");
//	}
//	return 0;
//}

//函数
//定义函数
//int add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum = 0;
//	//输入
//	scanf("%d %d", &num1, &num2);
//	//sum = num1 + num2
//	sum = add(num1, num2);
//	//打印
//	printf("和为: %d\n", sum);
//	return 0;
//}

//数组
//int main()
//{
//	//整型数组
//	//int arr[10] = {0};
//	
//	//存字符 - 字符数组
//	//char ch[5] = {'a'};
//	//char ch[6] = "hello";
//
//	return 0;
//}

int main()
{
	//% -- 取余操作符
	// >> << -- 移位操作符(移动二进制位)
	//int - 4byte - 32bit
	//int a = 3;
	//0000000000000000000000000000011
	//int b = a << 1;
	//0000000000000000000000000000110
	//printf("%d\n", b);

	//& 按位与 -- 这里的位指的也是二进制位
	//^ 按位异或
	//| 按位或

	//int a = 3;
	//int b = 5;
	//int c = a ^ b; //按位异或，相同为0，相异为1

	//c语言中0表示假，非0表示真

	//int a = 10;
	//sizeof 计算的是变量或者类型所创建变量占据内存的大小-单位是字节
	//printf("%d\n", sizeof(a));//4
	//printf("%d\n", sizeof(int));//4

	//~ - 按位取反
	//按位取反是对内存中的补码进行取反
	//int a = -1;
	//-1 是负整数
	//负整数的二进制有源码、反码、补码、
	//内存中存储的是二进制的补码
	//1000000000000000000000000000001 - -1的源码
	//1111111111111111111111111111110 - 反码
	//补码 = 反码 + 1
	//1111111111111111111111111111111 - 补码
	//0000000000000000000000000000000
	//int b = ~a;
	//printf("%d", b);
	//int a = 10;
	//int b = ++a;//前置++，先++，后使用 ++a 11 11
	//int b = a++;//后置++，先使用，后++ 11 10
	//int b = --a;//前置--，先--，后使用 9 9
	//int b = a--;//后置--，先使用，后--  9 10
	
	//printf("a=%d,b=%d", a, b);

	//条件操作符
	//num1 ? num2 : num3
	//简化if语句
	//int a = 0;
	//int b = 0;
	//int max = 0;
	//scanf("%d %d", &a, &b);
	/*if (a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}*/
	//max = (a > b ? a : b);
	//printf("%d\n", max);

	//int a = 3;
	//int b = 5;
	//int c = 10;
	//逗号表达式会从左向右依次计算
	//整个逗号表达式的结果是最后一个表达式的结果
	//int d = (a + 2, b = a - 3, c = b + 4);
	//				b = 0		   c = 0 + 4
	//d = 4
	//printf("%d\n", d);



	return 0;
}