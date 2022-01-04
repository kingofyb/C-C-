#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//函数判断是否是闰年
//int is_leapyear(int year)
//{
//	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (is_leapyear(year) == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//	return 0;
//}

//函数实现交换两个数的值
//void swap(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 5;
//	int b = 10;
//	printf("交换前: a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后: a=%d b=%d\n", a, b);
//	return 0;
//}

//函数实现打印99乘法表
//void table(int x)
//{
//	int i = 0;
//	for (i = 1; i <= x; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= x; j++)
//		{
//			printf("%d x %d = %d ", i, j, i * j);
//		}
//	}
//}
//int main()
//{
//	int x = 11;
//	table(x);
//	return 0;
//}