#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//leetcode 138. ���ƴ����ָ�������

//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    //1�������ڵ�������ԭ�ڵ�ĺ���
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
//    //2�����¿����ڵ��random
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
//    //3�������ڵ��������������һ��
//    //copyβ�嵽�½ڵ�
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