#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//leetcode 203. �Ƴ�����Ԫ��
//����һ�������ͷ�ڵ� head ��һ������ val ��
//����ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val != val)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//        else
//        {
//            struct ListNode* next = cur->next;
//            if (prev == NULL)
//            {
//                free(cur);
//                head = next;
//                cur = next;
//            }
//            else
//            {
//                free(cur);
//                prev->next = next;
//                cur = next;
//            }
//        }
//    }
//    return head;
//}


//leetcode 206 ��ת����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//    return n1;
//}

//ͷ��ķ���
//struct Listnode* reverselist(struct Listnode* head) {
//    struct Listnode* newhead = NULL;
//    struct Listnode* cur = head;
//    while (cur)
//    {
//        struct Listnode* next = cur->next;
//        //ͷ��
//        cur->next = newhead;
//        newhead = cur;
//
//        cur = next;
//        
//    }
//    return newhead;
//}