#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//输入两个整数，求两个整数二进制格式有多少个位不同
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int count = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;
//	while (c)
//	{
//		count++;
//		c = c & (c - 1);
//	}
//	printf("%d\n", count);
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	for (i = 0; i <= 31; i += 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	for (i = 1; i <= 31; i += 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	return 0;
//}

//写一个函数返回参数二进制中 1 的个数
//int Numberof1(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	return count;
//}
//int main()
//{
//	int n = 15;
//	int count = Numberof1(n);
//	printf("%d",count);
//	return 0;
//}

//不允许创建临时变量，交换两个整数的内容
int main()
{
	int a = 5;
	int b = 10;
	printf("交换前 a=%d b=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换后 a=%d b=%d\n", a, b);
	return 0;
}