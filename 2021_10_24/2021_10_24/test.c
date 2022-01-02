#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int num = 10;
//	&num;//取出num的地址
//	//注：这里num的4个字节，每个字节都有地址，取出的是第一个字节的地址（较小的地址）
//	printf("%p\n", &num);//打印地址，%p是以地址的形式打印
//	return 0;
//}
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;//pc是用来存放地址的，所以我们把p成为指针变量
//	*pc = 'q';//*的解引用操作符，*pc的意思就是通过p中的值，找到pc所指向的对象，也就是说*pc就是ch
//	printf("%c\n", ch);
//	return 0;
//}

//int main()
//{
//	//32位环境下指针大小是4个字节
//	//64位环境下指针大小是8个字节
//	printf("%d\n", sizeof(char*));//4
//	printf("%d\n", sizeof(short*));//4
//	printf("%d\n", sizeof(int*));//4
//	printf("%d\n", sizeof(long*));//4
//	printf("%d\n", sizeof(float*));//4
//	printf("%d\n", sizeof(double*));//4
//	
//	return 0;
//}

//结构体
//struct Stu
//{
//	//结构体成员
//	char name[20];
//	int age;
//	char sex[10];
//};
//int main()
//{
//	//创建结构体变量，并且初始化
//	struct Stu zhangsan = { "张三",30,"男" };
//	struct Stu lisi = { "李四",24,"保密" };
//	//printf("%s %d %s\n", zhangsan.name, zhangsan.age, zhangsan.sex);
//	//->这个操作符
//	struct Stu* p1 = &lisi;
//	printf("%s %d %s\n", (*p1).name, (*p1).age, (*p1).sex);
//	printf("%s %d %s", p1->name, p1->age, p1->sex);
//	return 0;
//}

//从大到小排列
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int c = 1;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a=%d b=%d c=%d", a, b, c);
//	return 0;
//}

//100以内3的倍数
//int main()
//{
//	for (int i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//20 40最大公约数
//int main()
//{
//	int a = 50;
//	int b = 1500;
//	int c = 0;
//	if (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}

//打印1000年到2000年之间的闰年
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//写一个代码：打印100~200之间的素数
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int j = 2;
//		for (j = 2;j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}