#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
//int main()
//{
//	char input[20] = { 0 };
//	printf("请输入密码;>");
//	scanf("%s", input);
//	//getcahr();//拿走\n
//	//清理缓冲区
//	int tmp = 0;
//	while ((tmp = getchar()) != '\n')
//	{
//		;//空语句
//	}
//
//	printf("请确认密码(Y/N):>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//	return 0;
//}

//int main()
//{
//	//char ch = '\0';
//	//while ((ch = getchar()) != EOF)//EOF = -1
//	//{
//	//	if (ch < '0' || ch > '9')
//	//		continue;
//	//	putchar(ch);
//	//}
//
//	//代码3
//	int i = 0;
//	int j = 0;
//	//如果省略掉初始化部分，这里打印多少个hehe?
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//
//}


//计算阶乘
//1.输入n
//2.产生1-n的数字，并乘
//int  main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		sum += ret;
//		
//	}
//	printf("%d\n", ret);
//	printf("%d\n", sum);
//	return 0;
//}

//二分查找 binary search
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//有序数组（递增）
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	        //40         /  4 = 10
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了,下标是%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到了\n");
//	}
//	return 0;
//}

//hello bit!!!!!!!
//################
//h##############!
//hh############!!
//...
//hello bit!!!!!!!
int main()
{
	char arr1[] = "hello bit!!!!!!!";
	char arr2[] = "################";

	int left = 0;
	int right = strlen(arr1) - 1;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//睡眠函数-单位是毫秒
		system("cls");//执行系统命令的
		left++;
		right--;
	}
	printf("%s\n", arr2);
	return 0;
}