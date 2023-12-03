#include<iostream>
#include <cassert>
using namespace std;


// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
// O(N) -- N+1
//long long Fac(size_t N) // Fac(N), Fac(N-1), Fac(N-2), ..., Fac(0)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1) * N;
//}


// ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�
// ÿ�ε��ö��ǳ����Σ����ܹ��ж��ٴε���
// O(2^N)

// Fib(N) - 2^0��
// Fib(N-1) Fib(N-2) - 2^1��
// Fib(N-2) Fib(N-3) Fib(N-3) Fib(N-4) - 2^2��
// ...
// Fib(3) Fib(2) ...
// Fib(2) Fib(1) ... - 2^N-2�ε��� -- �ȱ����� ������ 2^(N-1) - 1

// 2^40 = 1024^4


//�ռ临�Ӷ��أ�
//ʱ�����ۼƵĶ��ռ䲻�ǣ��ռ�����ظ�����
// ��������
//O(N)
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}


// ����BubbleSort�Ŀռ临�Ӷȣ�
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



// ����Fibonacci�Ŀռ临�Ӷȣ�
// ����쳲��������е�ǰn��
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

// ����׳˵ݹ�Fac�Ŀռ临�Ӷȣ�
// �ݹ��Ҫ����ջ֡
// ������N+1��ջ֡��ÿ��ջ֡����1
// ���Կռ临�Ӷ���O(N)
// 
// �����ȴ���һ��ջ֡��Ȼ������֮����һ��ջ֡�����õ�ͬһ��ռ�
// 
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//
//	return Fac(N - 1) * N;
//}


// Leetcode 189. ��ת����
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
//	k %= numsSize; // ���k����N��ֱ��ȡģ������10�εĻ����൱��3��(����������7��Ԫ��)
//	reverse(nums, numsSize - k, numsSize - 1); //���ú����, N-K �� N-1
//	reverse(nums, 0, numsSize - k - 1); //����ǩ���ģ�0 �� ��Ϊ�����Ǹ���N-K�����������N-K-1
//	reverse(nums, 0, numsSize - 1); //������������
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