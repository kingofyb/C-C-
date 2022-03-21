#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

// 计算BinarySearch的时间复杂度？
////O(logN)
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	//左闭右开
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}


//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	//左闭右闭
//	int begin = 0;
//	int end = n - 1;
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);//右移一位就是/2，防溢出
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

//// 计算阶乘递归Fac的时间复杂度？
////O(N^2)
////递归算法时间复杂度计算：
////1.每次函数调用是O(1)，那么就看他的递归次数
////1.每次函数调用不是O(1)，那么就看他的递归中次数的累加
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	for (size_t i = 0; i < N; ++i)
//	{
//		printf("%d", i);
//	}
//	printf("\n");
//
//	return Fac(N - 1) * N;
//}
//


//// 计算斐波那契递归Fib的时间复杂度？
////等比数列
////O(2^N)
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}
//
//int main()
//{
//	/*int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
//	{
//		printf("%d\n", BinarySearch(a, 10, i));
//	}*/
//
//	printf("%lld\n", Fib(50));
//
//	return 0;
//}