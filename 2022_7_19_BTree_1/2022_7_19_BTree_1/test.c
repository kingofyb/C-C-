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
#include <time.h>

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

void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建堆
	int* kMinHeap = (int*)malloc(sizeof(int) * k);
	assert(kMinHeap);
	for (int i = 0; i < k; ++i)
	{
		kMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(kMinHeap, k, i);
	}

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (int j = k; j < n; ++j)
	{
		if (a[j] > kMinHeap[0])
		{
			kMinHeap[0] = a[j];
			AdjustDwon(kMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[120] = 1000000 + 5;
	a[99] = 1000000 + 6;
	a[0] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

//int main()
//{
//	//TestHeap();
//	//TestHeapSort();
//	TestTopk();
//
//	return 0;
//}

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int count = 0;
void TreeSize1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	++count;
	TreeSize1(root->left);
	TreeSize1(root->right);
}

int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize2(root->left) + TreeSize2(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return TreeKLevel(root->left, k - 1)
		+ TreeKLevel(root->right, k - 1);
}

// 求二叉树深度
int TreeDepth(BTNode* root);

// 二叉树查找值为x的结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	count = 0;
	TreeSize1(root);
	printf("TreeSize:%d\n", count);

	count = 0;
	TreeSize1(root);
	printf("TreeSize:%d\n", count);

	printf("TreeSize:%d\n", TreeSize2(root));
	printf("TreeSize:%d\n", TreeSize2(root));

	printf("LeafSize:%d\n", TreeLeafSize(root));
	printf("KLevelSize:%d\n", TreeKLevel(root, 2));
	printf("KLevelSize:%d\n", TreeKLevel(root, 3));
	printf("KLevelSize:%d\n", TreeKLevel(root, 4));

	return 0;
}