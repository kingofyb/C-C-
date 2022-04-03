#define _CRT_SECURE_NO_WARNINGS 1


//leetcode 876. ������м���
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}


//ţ�� JZ22 �����е�����k�����
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    struct ListNode* slow, * fast;
//    slow = fast = pListHead;
//    //fast����k��
//    while (k--)
//    {
//        //k��������ĳ���
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//
//}


//leetcode 21. �ϲ�������������
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    struct ListNode* head = NULL, * tail = NULL;
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            if (tail == NULL)
//                head = tail = list1;
//
//            else
//            {
//                tail->next = list1;
//                tail = list1;
//            }
//            list1 = list1->next;
//        }
//        else
//        {
//            if (tail == NULL)
//            {
//                head = tail = list2;
//            }
//            else
//            {
//                tail->next = list2;
//                tail = list2;
//            }
//            list2 = list2->next;
//        }
//
//    }
//    if (list1)
//    {
//        tail->next = list1;
//    }
//    if (list2)
//    {
//        tail->next = list2;
//    }
//    return head;
//
//}

//ţ�� CM11 ����ָ�

//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
//        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//        lessTail->next = greaterTail->next = NULL;
//
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//
//        struct ListNode* list = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//
//        return list;
//    }
//};