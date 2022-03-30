#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void TestSList1()
{
	/*SListNode* slist = NULL;
	SListNode* n1 = malloc(sizeof(SListNode));
	SListNode* n2 = malloc(sizeof(SListNode));
	SListNode* n3 = malloc(sizeof(SListNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n1->next = n3;
	n3->next = n2;
	n2->next = NULL;
	slist = n1;*/

	SListNode* slist = NULL;
	SListNode* n1 = malloc(sizeof(SListNode));
	SListNode* n2 = malloc(sizeof(SListNode));
	SListNode* n3 = malloc(sizeof(SListNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	slist = n1;

	SListPrint(slist);
}

void SwapInt(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SwapPInt(int** pp1, int** pp2)
{
	int* tmp = *pp1;
	*pp1 = *pp2;
	*pp2 = tmp;
}

void TestSList2()
{
	SListNode* slist = NULL; //空链表
	//SListPushBack(slist, 1);
	//SListPushBack(slist, 2);
	//SListPushBack(slist, 3);
	//SListPushBack(slist, 4);
	for (int i = 0; i < 4; ++i)
	{
		SListPushBack(&slist, i);
	}
	SListPrint(slist);

	// 函数中想改变实参int变量，要传int*
	int a = 0, b = 1;
	SwapInt(&a, &b);

	// 函数中想改变实参int*变量，要传int**  
	int* pa = &a, * pb = &b;
	//SwapInt(pa, pb);
	SwapPInt(&pa, &pb);
}

void TestSList3()
{
	SListNode* slist = NULL; //空链表
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);

	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPrint(slist);
}

void TestSList4()
{
	SListNode* slist = NULL; //空链表
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);

	SListPopFront(&slist);

	SListNode* pos = SListFind(slist, 3);
	if (pos)
	{
		printf("找到了:%p\n", pos);
		// 修改
		pos->data *= 10;
	}

	SListPrint(slist);
}

void TestSList5()
{
	SListNode* slist = NULL; //空链表
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPrint(slist);

	SListNode* pos = SListFind(slist, 3);
	if (pos)
	{
		SListInsert(&slist, pos, 30);
	}
	SListPrint(slist);

	pos = SListFind(slist, 1);
	if (pos)
	{
		SListInsert(&slist, pos, 30);
	}
	SListPrint(slist);
}

void TestSList6()
{
	SListNode* slist = NULL; //空链表
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	SListPrint(slist);

	SListNode* pos = SListFind(slist, 3);
	if (pos)
	{
		SListErase(&slist, pos);
	}
	SListPrint(slist);

	pos = SListFind(slist, 1);
	if (pos)
	{
		SListErase(&slist, pos);
	}
	SListPrint(slist);
}

//int main()
//{
//	TestSList6();
//
//	return 0;
//}


struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while (cur)
	{
		if (cur->val != val)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			struct ListNode* next = cur->next;
			free(cur);
			prev->next = next;
			cur = next;
		}
	}

	return head;
}

int main()
{
	struct ListNode* node1 = malloc(sizeof(struct ListNode));
	struct ListNode* node2 = malloc(sizeof(struct ListNode));
	struct ListNode* node3 = malloc(sizeof(struct ListNode));
	struct ListNode* node4 = malloc(sizeof(struct ListNode));
	node1->val = 7;
	node2->val = 7;
	node3->val = 7;
	node4->val = 7;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	node1 = removeElements(node1, 7);

	return 0;
}