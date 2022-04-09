#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//leetcode 138. 复制带随机指针的链表

//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    //1、拷贝节点链接在原节点的后面
//    while (cur)
//    {
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//
//        copy->next = cur->next;
//        cur->next = copy;
//
//        cur = cur->next->next;
//    }
//
//    //2、更新拷贝节点的random
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = cur->next->next;
//    }
//
//    //3、拷贝节点解下来，链接在一起
//    //copy尾插到新节点
//    cur = head;
//    struct Node* copyHead = NULL;
//    struct Node* copyTail = NULL;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//
//        cur->next = next;
//
//        if (copyTail == NULL)
//        {
//            copyHead = copyTail = copy;
//        }
//        else
//        {
//            copyTail->next = copy;
//            copyTail = copyTail->next;
//        }
//        cur = next;
//    }
//
//    return copyHead;
//}


void TestList1()
{
	//LTNode* pList = NULL;
	//ListInit(&pList);
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	ListPopFront(pList);
	//ListPopBack(pList);
	//ListPopBack(pList);
	//ListPopBack(pList);
	//ListPopBack(pList);
	//ListPopBack(pList);
	//ListPopBack(pList);
	ListPrint(pList);
}

void TestList2()
{
	//LTNode* pList = NULL;
	//ListInit(&pList);
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	LTNode* pos = ListFind(pList, 3);
	if (pos)
	{
		ListInsert(pos, 30);
	}
	ListPrint(pList);

}

int main()
{
	TestList1();

	return 0;
}