#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
415. �ַ������

https://leetcode.cn/problems/add-strings/description/

���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�

�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��



ʾ�� 1��

���룺num1 = "11", num2 = "123"
�����"134"

ʾ�� 2��

���룺num1 = "456", num2 = "77"
�����"533"


*/

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0; // ��λ
//        string strRet;
//        while (end1 >= 0 || end2 >= 0) // �����������˲Ž�����ֻҪ��һ�����ڵ���0�ͼ���
//        {
//            //int val1 = num1[end1]; // ֱ��ȡ�п��ܻ�Խ�磬����end2��û������end1�����ˣ���ʱ����ʾͻ�Խ��
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0; // ������ڵ���0���͸�ֵ�������0
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0; // ASCII��ֵ
//
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0; // ����9�ͽ�λ1����Ȼ��λ0
//
//            // ͷ�� -- ͷ���Ч�ʺܵ�
//            // strRet.insert(0, 1, (ret%10) + '0'); // 0���λ�ò���1���ַ��������ַ�0��3�ͱ���ַ�3��
//            // strRet.insert(strRet.begin(), (ret%10) + '0'); // Ҳ���Ը���һ��λ�õĵ�����
//
//            // β��Ч�ʸ�
//            strRet += ('0' + ret % 10);
//
//            --end1;
//            --end2;
//        }
//
//        if (next == 1)
//            strRet += '1';
//
//        // ͷ��
//        // if(next) // ����9+1���������һ��1
//        // {
//        //     strRet.insert(strRet.begin(), '1');
//        // }
//
//        // ����
//        reverse(strRet.begin(), strRet.end()); // �����������������ҿ�[)
//
//
//        return strRet;
//    }
//};

/*
21.�ϲ�������������

https://leetcode.cn/problems/merge-two-sorted-lists/description/

��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
���룺l1 = [1,2,4], l2 = [1,3,4]
�����[1,1,2,3,4,4]

ʾ�� 2��

���룺l1 = [], l2 = []
�����[]


*/


//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        else if (list2 == nullptr)
//        {
//            return list1;
//        }
//        else if (list1->val < list2->val)
//        {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else
//        {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
//        }
//
//    }
//};

/*
917. ������ת��ĸ

https://leetcode.cn/problems/reverse-only-letters/description/

����һ���ַ��� s ��������������ת�ַ�����

���з�Ӣ����ĸ������ԭ��λ�á�
����Ӣ����ĸ��Сд���д��λ�÷�ת��
���ط�ת��� s

ʾ�� 1��

���룺s = "ab-cd"
�����"dc-ba"

ʾ�� 2��

���룺s = "a-bC-dEf-ghIj"
�����"j-Ih-gfE-dCba"

ʾ�� 3��

���룺s = "Test1ng-Leet=code-Q!"
�����"Qedo1ct-eeLg=ntse-T!"


*/

//class Solution {
//public:
//    bool IsLetter(char ch)
//    {
//        if ((ch >= 'a' && ch <= 'z')
//            || (ch >= 'A' && ch <= 'Z'))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    string reverseOnlyLetters(string s) {
//        size_t begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isalpha(s[begin])) // Ҳ����ֱ����c++����ĺ���isalpha
//            {
//                // ������ĸ��++
//                ++begin;
//            }
//            while (begin < end && !isalpha(s[end]))
//            {
//                --end;
//            }
//            swap(s[begin], s[end]);
//            ++begin;
//            --end;
//        }
//        return s;
//    }
//};

/*
387.�ַ����еĵ�һ��Ψһ�ַ�

https://leetcode.cn/problems/first-unique-character-in-a-string/description/

����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��



ʾ�� 1��

����: s = "leetcode"
���: 0

ʾ�� 2:

����: s = "loveleetcode"
���: 2

ʾ�� 3:

����: s = "aabb"
���: -1




*/

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        // ���ȣ�����һ������洢
//        int count[256] = { 0 };
//        int n = s.size();
//        // ͳ��ÿ���ַ����ֵĴ���
//        for (int i = 0; i < n; ++i)
//        {
//            count[s[i]] += 1;
//        }
//        // �����ַ������ǰ������ֻ����һ�ε��ַ�
//        for (int i = 0; i < n; ++i)
//        {
//            if (count[s[i]] == 1)
//            {
//                return i;
//            }
//
//        }
//        return -1;
//    }
//};

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        unordered_map<int, int> frequency;
//        for (char ch : s) {
//            ++frequency[ch];
//        }
//        for (int i = 0; i < s.size(); ++i) {
//            if (frequency[s[i]] == 1) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
