#include<iostream>
#include <cassert>
using namespace std;

// 请计算一下Func1中++count语句总共执行了多少次？
void Func1(int N)
{
int count = 0;
for (int i = 0; i < N; ++i)
{
	for (int j = 0; j < N; ++j)
	{
		++count;
	}
}

for (int k = 0; k < 2 * N; ++k)
{
	++count;
}
int M = 10;
while (M--)
{
	++count;
}
printf("%d\n", count);
//N*N + 2N + 10
}

//推导大O阶方法：时间复杂度估算就是算他是属于哪个量级的算法
//1、用常数1取代运行时间中的所有加法常数。
//2、在修改后的运行次数函数中，只保留最高阶项。
//3、如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶。


// 计算Func2的时间复杂度？
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);

//2N + 10 = O(N)
}



// 计算Func3的时间复杂度？
void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
//不知到N和M的大小
//O(N+M)
}
//N远大于M
//O(N)
//M远大于N
//O(M)
//一样大O(N)或O(M)都可以



// 计算Func4的时间复杂度？
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
//O(1)，O(1)表示常数次


//另外有些算法的时间复杂度存在最好、平均和最坏情况：
//最坏情况：任意输入规模的最大运行次数(上界)
//平均情况：任意输入规模的期望运行次数
//最好情况：任意输入规模的最小运行次数(下界)
//例如：在一个长度为N数组中搜索一个数据x
//最好情况：1次找到
//最坏情况：N次找到
//平均情况：N / 2次找到
//在实际中一般情况关注的是算法的最坏运行情况，所以数组中搜索数据时间复杂度为O(N)

// 计算strchr的时间复杂度？
//const char* strchr(const char* str, int character);
// strchr就是在字符串数组中查找一个字符
//所以最坏情况 O(N)




// 计算BubbleSort的时间复杂度？
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

//算时间复杂度不能去数循环，这个不一定准确，一定要看算法思想来进行计算
// 首项加尾项乘以系数/2
//准确的：F(N) = N-1 + N-2 + N-3 + ... + 2 + 1 = ((N-1+1)*(N-1))/2 = N*N/2
//所以O(N^2)
//最好的情况 O(N)，至少要走一遍


// 计算BinarySearch的时间复杂度？
int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	// [begin, end]：begin和end是左闭右闭区间，因此有=号
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

//纸折半了多少次就除了多少个2
//除了多少个2就找了多少次
//假设折半查找了x次
//2^x = N
//x = log N (log以2为底，N的对数)

//最好 O(1)
//最坏 找不到或者只剩一个 -- O(log2 N)

//时间复杂度是计算算法执行次数，一次执行次数不一定是一条语句，也可能是多条语句，但肯定是常数条。


int main()
{
	//Func1(1);
	Func4(1);
	return 0;
}

//面试题 17.04. 消失的数字
int missingNumber(int* nums, int numsSize) {
	int x = 0;
	//先异或数组
	//在第一个for循环中，变量 x 被初始化为0，并且用来与数组 nums 中的每一个元素进行异或操作。
	//根据异或操作的性质，如果数组中的某个数字出现两次，它们会相互抵消，结果为0。由于数组中的每个数字都是唯一的（除了缺失的那个数字）
	//这个循环结束后，x 的值将是数组中所有数字的异或结果。
	for (int i = 0; i < numsSize; ++i)
	{
		x ^= nums[i];
	}
	//再异或0-n之间的值
	//+1是因为数组本身缺了一个数字，所以要多加一位

	//第二个for循环从0到 numsSize（这应该是缺失数字的最大值，因为数组长度是 numsSize，而且是从0开始的，所以应该有 numsSize + 1 个数字）
	//进行异或操作。由于异或操作的性质，0到 numsSize 的异或将会给出一个临时的结果，如果所有数字都在的话，这个结果应该是0。
	//但是由于数组中缺失了一个数字，因此这个结果不为0。
	for (int j = 0; j < numsSize + 1; ++j)
	{
		x ^= j;
	}

	//经过两次循环后，x 的值是数组中所有数字异或的结果与0到n所有数字异或的结果的异或。
	//	由于除了缺失的数字外，其他数字都被异或了两次，根据异或操作的性质，它们相互抵消变成了0。
	//	唯一没有抵消的就是缺失的数字，因此最终的结果 x 就是缺失的数字。
	return x;

}