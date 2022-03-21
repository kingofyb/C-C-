#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

// ����BinarySearch��ʱ�临�Ӷȣ�
////O(logN)
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	//����ҿ�
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
//	//����ұ�
//	int begin = 0;
//	int end = n - 1;
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);//����һλ����/2�������
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

//// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�
////O(N^2)
////�ݹ��㷨ʱ�临�Ӷȼ��㣺
////1.ÿ�κ���������O(1)����ô�Ϳ����ĵݹ����
////1.ÿ�κ������ò���O(1)����ô�Ϳ����ĵݹ��д������ۼ�
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


//// ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�
////�ȱ�����
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