#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		//算个位
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		//算十位
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//分数求和
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
//int main()
//{
//	int odd = 1;
//	double total = 0.0;
//	for (int i = 1; i <= 100; i++)
//	{
//		total += odd * 1.0 / i;
//		total *= -1;
//	}
//	printf("%1f\n", total);
//	return 0;
//}

//求十个整数中的最大值
//int main()
//{
//	int arr[10] = {0};
//
//	printf("请输入是个数字,用空格隔开:");
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}

//在屏幕上输出9*9乘法口诀表
//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			printf("%d * %d = %d\n", i, j, i * j);
//		}
//	}
//	return 0;
//}

//二分查找
//编写代码在一个整形有序数组中查找具体的某个数
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标是%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}