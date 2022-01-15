#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


//奇数变为1，偶数变为0
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 0;
//	int tmp = 0;
//	while (n)
//	{
//		tmp = n % 10;
//		if (tmp % 2 == 1)
//		{
//			tmp = 1;
//		}
//		else
//		{
//			tmp = 0;
//		}
//		sum += tmp * pow(10, i++);
//		n /= 10;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，
//则打印出 1、2、3 一直到最大的 3 位数 999。
//1. 用返回一个整数列表来代替打印
//2. n 为正整数

//static int arr[100010];
//int* printNumbers(int n, int* returnSize) {
//	// write code here
//	int num = 1;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		num *= 10;
//	}
//	for (i = 1; i < num; i++)
//	{
//		arr[i - 1] = i;
//	}
//	*returnSize = --i;
//	return arr;
//}