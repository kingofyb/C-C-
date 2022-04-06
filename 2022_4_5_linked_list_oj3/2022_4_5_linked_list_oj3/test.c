#define _CRT_SECURE_NO_WARNINGS 1


//牛客 OR36 链表的回文结构
//class PalindromeList {
//public:
//    //翻转
//    struct ListNode* reverseList(struct ListNode* head) {
//        if (head == NULL)
//        {
//            return NULL;
//        }
//        struct ListNode* n1, * n2, * n3;
//        n1 = NULL;
//        n2 = head;
//        n3 = n2->next;
//        while (n2)
//        {
//            n2->next = n1;
//            n1 = n2;
//            n2 = n3;
//            if (n3)
//                n3 = n3->next;
//        }
//        return n1;
//    }
//
//    //中间节点
//    struct ListNode* middleNode(struct ListNode* head) {
//        struct ListNode* slow, * fast;
//        slow = fast = head;
//        while (fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    bool chkPalindrome(ListNode* A) {
//        // write code here
//        struct ListNode* mid = middleNode(A);
//        struct ListNode* rhead = reverseList(mid);
//
//        while (A && rhead)
//        {
//            if (A->val == rhead->val)
//            {
//                A = A->next;
//                rhead = rhead->next;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};


//leetcode 160. 相交链表
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lenA = 1, lenB = 1;
//    //找尾
//    while (tailA->next)
//    {
//        tailA = tailA->next;
//        ++lenA;
//    }
//    while (tailB->next)
//    {
//        tailB = tailB->next;
//        ++lenB;
//    }
//    if (tailA != tailB)
//    {
//        return NULL;
//    }
//
//    //相交，求交点，长的先走差距走，再同时走找交点
//    struct ListNode* shortList = headA, * longList = headB;
//    if (lenA > lenB)
//    {
//        shortList = headB;
//        longList = headA;
//    }
//    int gap = abs(lenA - lenB);
//
//    while (gap--)
//    {
//        longList = longList->next;
//    }
//    while (shortList && longList)
//    {
//        if (shortList == longList)
//        {
//            return shortList;
//        }
//        shortList = shortList->next;
//        longList = longList->next;
//    }
//    return NULL;
//}

//leetcode 141. 环形链表
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//		  //如果fast能追上slow，就有环
//        if (slow == fast)
//        {
//            return true;
//        }
//    }
//    return false;
//}


//leetcode 142. 环形链表 II
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (slow == fast)
//        {
//            struct ListNode* meet = slow;
//            while (meet != head)
//            {
//                meet = meet->next;
//                head = head->next;
//            }
//            return meet;
//        }
//    }
//    return false;
//}
