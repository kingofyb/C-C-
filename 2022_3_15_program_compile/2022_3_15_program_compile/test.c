#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//************************** 翻译环境
//1.源文件

//2.编译
//在编译器下(预编译/预处理 - 编译 - 汇编)
//Linux环境下目标文件的后缀是.o
//在Windows环境下目标文件的后缀是.obj

//预编译/预处理 gcc -E test.c -o test.i
//1.头文件的包含 #include
//2.删除注释
//3.#define 定义符号的替换 
//文本操作

//编译 gcc -S test.i 生成test.s
//把C语言代码转换成汇编代码
//1.语法分析
//2.词法分析
//3.语义分析
//4.符号汇总

//汇编 gcc -c test.s 生成test.o elf
//readelf 工具可以解析elf格式的文件
//把汇编代码转换成二进制的指令
//1.形成符号表

//test.c生成test.obj

//3.链接
//obj和链接库一起通过链接器生成可执行文件 .exe
//1.合并段表
//2.符号表的合并和重定位
//多个目标文件进行链接的时候会通过符号表查看来自外部的符号是否真实存在

//4.可执行程序 test.exe

//********************* 运行环境
//程序载入内存
//程序开始执行，调用main函数
//执行代码，使用一个运行时堆栈（函数栈帧）
//终止程序

//int main()
//{
//	//printf("%s\n", __FILE__);//文件路径
//	//printf("%d\n",__LINE__);//这一行的行号
//	//printf("%s\n", __DATE__);//日期
//	//printf("%s\n", __TIME__);//时间
//
//	int i = 0;
//	//记录日志
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "%s %s %s %d %d\n", __DATE__, __TIME__, __FILE__, __LINE__, i);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//VS2022 是不遵循 ANSI C

#define M 1000
#define reg register
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PRINT(n) printf("the value of " #n " is %d\n",n);
#define CAT(C, num) Class##num

int main()
{
	//register int num = 10;
	//reg int num = 20;
	//int a = 10;
	//PRINT(a);

	//int b = 20;
	//PRINT(b);
	//int c = MAX(a, b);
	//printf("%d\n", c);

	int Class104 = 10000;
	printf("%d\n", CAT(C, 104));//Class104


	return 0;
}