#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//goto语句
//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//	return 0;
//}

//写一个关机程序
//只要程序启动了，就倒计时69秒关机，如果60秒内，你输入: 我是猪，就取消关机，如果不输入，时间到关机

//windows提供的关机命令 - shutdown
//shutdown -s -t 60 --> 60秒后关机
//shutdown -a 取消关机
//system() - 库函数-执行系统命令
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shut down -s -t 60");
//again:
//	printf("请注意你的电脑在1分钟内关机，如果输入：我属猪，就取消关机\n");
//	scanf("$s", input);
//	//判断
//	if (strcmp(input, "我是猪") == 0)
//	{
//		//取消关机
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

 //函数
//int main()
//{
//	char arr[] = "hello world";
//	//把前五个字符改成x
//	memset(arr, 'x', 5);
//	printf("%s", arr);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	int z = 0;
//	z = (x > y ? x : y);
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_max(a, b);
//	printf("%d", m);
//	return 0;
//}

//写一个函数可以交换两个整型变量的内容
//void swap(int* pa, int* pb)//定义函数时，形式参数
//{
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前:a=%d b=%d\n", a, b);
//	//交换
//	swap(&a,&b);//实际参数
//	printf("交换后:a=%d b=%d\n", a, b);
//	return 0;
//}

//写一个函数判断是不是素数
//int is_prime(int n)
//{
//	//2~n-1的数字试除
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//函数实现整形有序数组二分查找
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
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
			return mid;
		}
	}
	return - 1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k, sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是%d\n", ret);
	}

	return 0;
}