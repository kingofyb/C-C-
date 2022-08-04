#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		// [0,end]���򣬰�end+1λ�õ�ֵ���룬��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// ƽ����O(N^1.3��
//void ShellSort(int* a, int n)
//{
//	/*int gap = 3;*/
//
//	/*for (int j = 0; j < gap; ++j)
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}*/
//
//	// gap > 1ʱ��Ԥ����
//	// gap ���һ�ε���1����ֱ�Ӳ�������
//	//PrintArray(a, n);
//
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		//gap = gap / 2;
//
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//
//		//printf("gap:%d->", gap);
//		//PrintArray(a, n);
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap = gap / 2;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}



void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustDwon(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{

		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ���� -- ��С��
// ���� -- �����
void HeapSort(int* a, int n)
{
	// ���ѷ�ʽ2��O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// ʱ�临�Ӷȣ�O��N^2�� ��õ������O(N^2)
// �Ա� ��������˭���ã�-- ����
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[mini])
				mini = i;

			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);

		// ���begin��maxi�ص�����ôҪ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// ʱ�临�Ӷ�:O��N^2��  ��õ������O(N)
// �Ա� ��������˭���ã�-- ����
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int j = 0; j < n - 1; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}

// [begin, end]
void QuickSort(int* a, int begin, int end)
{
	// ���䲻���ڣ�����ֻ��һ��ֵ����Ҫ�ڴ���
	if (begin >= end)
	{
		return;
	}

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		// �ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// ������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	// [begin, keyi-1] keyi [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}