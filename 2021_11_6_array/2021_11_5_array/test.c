#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//C99标准之前是不支持使用变量 eg int arr[n]， 只能是常量 int arr[10]
//C99之后增加了长数组的概念，允许数组的大小是变量
//而且要求编译器支持C99标准

//strlen是一个库函数，计算的是字符串的长度，并且只能针对字符串
//关注的是字符串中是否有\n，计算的是\0之前的字符个数

//sizeof是一个操作符（运算符）
//sizeof是用来计算变量所占内存空间大小的，任何类型都是可以使用
//只关注空间大小，不在乎内存中是否存在\0

//一维数组在内存中是连续存放的

//冒泡排序
//void bubble_sort(int arr[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,5,6,9,8,7,6 };
//	bubble_sort(arr, 7);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////实现函数init() 初始化数组为全0
//void inti(int arr[], int sz, int n)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = n;
//	}
//}
//
//实现Print()  打印数组的每个元素
void Print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

////实现reverse()  函数完成数组元素的逆置。
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = 0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("最初数组为: \n");
//	Print(arr, 10);
//	printf("\n");
//	printf("反转数组\n");
//	reverse(arr, 10);
//	Print(arr, 10);
//	printf("\n");
//	printf("初始化数组\n");
//	inti(arr, 10, 1);
//	Print(arr, 10);
//
//	return 0;
//}

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void swap(int arr1[], int arr2[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 5,4,3,2,1 };
	printf("原数组arr1为：\n");
	Print(arr1, 5);
	printf("\n");
	printf("原数组arr2为：\n");
	Print(arr2, 5);
	printf("\n");
	swap(arr1, arr2, 5);
	printf("转换后arr1为：\n");
	Print(arr1, 5);
	printf("\n");
	printf("转换后arr2为：\n");
	Print(arr2, 5);
	return 0;
}