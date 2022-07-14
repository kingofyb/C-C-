#define _CRT_SECURE_NO_WARNINGS 1
//// ���Ķ���6
//struct TreeNode
//{
//	int data;
//	struct TreeNode* child1;
//	struct TreeNode* child2;
//	struct TreeNode* child3;
//	struct TreeNode* child4;
//	struct TreeNode* child5;
//	struct TreeNode* child6;
//	// ...
//};
//
//// ��ȷ�����Ķ�
//typedef struct TreeNode* SLDataType;
//struct TreeNode
//{
//	int data;
//
//	// ˳���溢�ӵ�ָ��
//	SeqList _childs;
//	// ...
//	// vector<struct TreeNode*> vChild;
//};
//
//// �������ֵ�
//typedef int DataType;
//struct TreeNode
//{
//	struct TreeNode* firstChild1;    // ��һ�����ӽ��
//	struct TreeNode* pNextBrother;   // ָ������һ���ֵܽ��
//	DataType data;               // ����е�������
//};

#include "Heap.h"

void TestHeap()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}

//  1�������дһ��Hp���ݽṹ����������
//  2����O(N)�ռ临�Ӷ�
//void HeapSort(int* a, int n)
//{
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < n; ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		a[i++] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}

// ���� -- �����
// ���� -- ��С��
void HeapSort(int* a, int n)
{
	//// ���ѷ�ʽ1��O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

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

void TestHeapSort()
{
	// �����ӡ -- С��
	// �����ӡ -- ���
	/*HP hp;
	HeapInit(&hp);
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
	HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
	printf("%d ", HeapTop(&hp));
	HeapPop(&hp);
	}
	printf("\n");*/

	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	//TestHeap();
	TestHeapSort();

	return 0;
}