#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//1. const 修饰变量
//const int num = 10
//num = 20//error

//2. const 修饰指针
//const int* p //const放在了*的左边，修饰的是*p，使得*p不能通过p来改变，但是p可以被改变
//int* const p //const放在了*的右边，修饰的是p，p不能被改变，但是*p可以被改变
//const int* const p //p和*p都不能被改变

//ctrl+g 跳到指定行

//模拟实现strlen
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}
//int main()
//{
//	char arr[] = "abcdef";
//
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//整数的二进制表示有3中表达形式：原码，反码，补码
//而内存中存储的是二进制的补码

//正整数：原码，反码补码相同

//负整数：
//原码： 按照一个数的正负直接写出来的二进制就是原码
//反码： 符号位不变，其他位，按位取反
//~ - 波浪号按位取反连符号位一起取反
//补码： 反码的二进制序列+1就是补码

//整数在内存中存储的是补码

//大端字节序存储：
//当一个数据的低字节的数据存放在高地址处，高字节序的内容放在低地址处

//小端字节序存储：
//当一个数据的低字节的数据存放在低地址处，高字节序的内容放在高地址处

//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//模拟库函数，实现strlen
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}

//模拟库函数，实现strcpy
//char my_strcpy(char* dst, const char* start)
//{
//	assert(dst && start);
//	while (*dst++ = *start++)
//	{
//		;
//	}
//	return dst;
//}
//
//
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	//printf("%d\n", len);
//	return 0;
//}


//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

void swap(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		//找奇数
		while (arr[left] % 2 == 1)
		{
			left++;
		}
		//找偶数
		while (arr[right] % 2 == 0)
		{
			right--;
		}
		//排序
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}

}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	swap(arr, sz);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}