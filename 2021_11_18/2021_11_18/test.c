#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}

//写一个函数，可以逆序一个字符串的内容。
//int main()
//{
//	char ch1[100] = { "there is a banana" };
//	char ch2[100];
//	int len = strlen(ch1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		ch2[i] = ch1[len - i - 1];
//		printf("%c", ch2[i]);
//	}
//	return 0;
//}

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int num = 3;
//	int len = 3;
//	int sum = 0;
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		tmp = tmp * 10 + num;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}


//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 100000; i++)
//	{
//		int n = 1;
//		int sum = 0;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp = tmp / 10;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}


//打印菱形
int main()
{
	int line = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &line);
	//上半部分
	for (i = 0; i < line; i++)
	{
		for (n = 0; n < line - i - 1; n++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//下半部分
	for (i = 0; i < line; i++)
	{
		for (n = 0; n < i + 1; n++)
		{
			printf(" ");
		}
		for (j = 0; j < (line - i - 1) * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}