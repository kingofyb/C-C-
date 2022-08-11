#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"Stack.h"

int callCount = 0;

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
		// ѡ�����Һ�����С/����Ǹ�
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// ���Ӹ����ױȽ�
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
//void QuickSort(int* a, int begin, int end)
//{
//	// ���䲻���ڣ�����ֻ��һ��ֵ����Ҫ�ڴ���
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		// �ұ����ߣ���С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//
//		// ������ߣ��Ҵ�
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[keyi], &a[left]);
//	keyi = left;
//
//	// [begin, keyi-1] keyi [keyi+1, end]
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi+1, end);
//}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else // (a[begin] >= a[mid])
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

// Hoare
int PartSort1(int* a, int begin, int end)
{
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

	return keyi;
}

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	while (begin < end)
	{
		// �ұ���С�����ߵĿ�����ȥ�����λ���γ��µĿ�
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end];
		piti = end;

		// ����Ҵ���ұߵĿ�����ȥ�����λ���γ��µĿ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[piti] = a[begin];
		piti = begin;
	}

	a[piti] = key;
	return piti;
}

// ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	// ��������ȡ�е��Ż�
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[keyi], &a[midi]);

	while (cur <= end)
	{
		// curλ�õ�֮С��keyiλ��ֵ
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}


void QuickSort(int* a, int begin, int end)
{
	//callCount++;
	//printf("%p\n", &callCount);

	// ���䲻���ڣ�����ֻ��һ��ֵ����Ҫ�ڴ���
	if (begin >= end)
	{
		return;
	}

	if (end - begin > 10)
	{
		int keyi = PartSort3(a, begin, end);
		// [begin, keyi-1] keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}
}

// Ҫ�����գ��ݹ�ķǵݹ�
// �ݹ�����⣬���˳������棬������̫������ջ���
// 1��ֱ�Ӹ�ѭ�� -- ����쳲��������С��鲢����
// 2�������ݽṹջģ��ݹ����
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi[keyi+1, right]

		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}