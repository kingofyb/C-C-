#define _CRT_SECURE_NO_WARNINGS 1
//// 树的度是6
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
//// 不确定树的度
//typedef struct TreeNode* SLDataType;
//struct TreeNode
//{
//	int data;
//
//	// 顺序表存孩子的指针
//	SeqList _childs;
//	// ...
//	// vector<struct TreeNode*> vChild;
//};
//
//// 左孩子右兄弟
//typedef int DataType;
//struct TreeNode
//{
//	struct TreeNode* firstChild1;    // 第一个孩子结点
//	struct TreeNode* pNextBrother;   // 指向其下一个兄弟结点
//	DataType data;               // 结点中的数据域
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

//  1、你得先写一个Hp数据结构，反而复杂
//  2、有O(N)空间复杂度
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

// 升序 -- 建大堆
// 降序 -- 建小堆
void HeapSort(int* a, int n)
{
	//// 建堆方式1：O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	// 建堆方式2：O(N)
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
	// 升序打印 -- 小堆
	// 降序打印 -- 大堆
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