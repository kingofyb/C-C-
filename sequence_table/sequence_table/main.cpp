#include<iostream>
#include <cassert>
using namespace std;


// 计算阶乘递归Fac的时间复杂度？
// O(N) -- N+1
//long long Fac(size_t N) // Fac(N), Fac(N-1), Fac(N-2), ..., Fac(0)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}


// 计算斐波那契递归Fib的时间复杂度？
// 每次调用都是常数次，看总共有多少次调用
// O(2^N)

// Fib(N) - 2^0次
// Fib(N-1) Fib(N-2) - 2^1次
// Fib(N-2) Fib(N-3) Fib(N-3) Fib(N-4) - 2^2次
// ...
// Fib(3) Fib(2) ...
// Fib(2) Fib(1) ... - 2^N-2次调用 -- 等比数列 最后等于 2^(N-1) - 1

// 2^40 = 1024^4


//空间复杂度呢？
//时间是累计的而空间不是，空间可以重复利用
// 函数回来
//O(N)
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}


// 计算BubbleSort的空间复杂度？
// O(1)
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}



// 计算Fibonacci的空间复杂度？
// 返回斐波那契数列的前n项
// O(N)
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}

// 计算阶乘递归Fac的空间复杂度？
// 递归就要建立栈帧
// 建立了N+1个栈帧，每个栈帧都是1
// 所以空间复杂度是O(N)
// 
// 比如先创建一个栈帧，然后销毁之后下一个栈帧还是用的同一块空间
// 
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//
//	return Fac(N - 1) * N;
//}


// Leetcode 189. 轮转数组
//void reverse(int* a, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = a[left];
//		a[left] = a[right];
//		a[right] = tmp;
//		++left;
//		--right;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k) {
//	k %= numsSize; // 如果k大于N，直接取模，比如10次的话就相当于3次(假设数组有7个元素)
//	reverse(nums, numsSize - k, numsSize - 1); //逆置后面的, N-K 到 N-1
//	reverse(nums, 0, numsSize - k - 1); //逆置签名的，0 到 因为后面那个是N-K，所以这个是N-K-1
//	reverse(nums, 0, numsSize - 1); //逆置整个数组
//}


#include"SeqList.h"

void TestSeqList1()
{
	SL s1;
	SLInit(&s1);
}

int main()
{
	TestSeqList1();
	return 0;
}