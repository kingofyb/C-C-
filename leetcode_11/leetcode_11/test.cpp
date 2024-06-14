#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
415. 字符串相加

https://leetcode.cn/problems/add-strings/description/

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。



示例 1：

输入：num1 = "11", num2 = "123"
输出："134"

示例 2：

输入：num1 = "456", num2 = "77"
输出："533"


*/

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        int next = 0; // 进位
//        string strRet;
//        while (end1 >= 0 || end2 >= 0) // 两个都结束了才结束，只要有一个大于等于0就继续
//        {
//            //int val1 = num1[end1]; // 直接取有可能会越界，比如end2还没结束，end1结束了，这时候访问就会越界
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0; // 如果大于等于0，就给值，否则给0
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0; // ASCII码值
//
//            int ret = val1 + val2 + next;
//            next = ret > 9 ? 1 : 0; // 大于9就进位1，不然进位0
//
//            // 头插 -- 头插的效率很低
//            // strRet.insert(0, 1, (ret%10) + '0'); // 0这个位置插入1个字符，比如字符0加3就变成字符3了
//            // strRet.insert(strRet.begin(), (ret%10) + '0'); // 也可以给第一个位置的迭代器
//
//            // 尾插效率高
//            strRet += ('0' + ret % 10);
//
//            --end1;
//            --end2;
//        }
//
//        if (next == 1)
//            strRet += '1';
//
//        // 头插
//        // if(next) // 比如9+1，如果还有一个1
//        // {
//        //     strRet.insert(strRet.begin(), '1');
//        // }
//
//        // 逆置
//        reverse(strRet.begin(), strRet.end()); // 逆置区间必须是左闭右开[)
//
//
//        return strRet;
//    }
//};

/*
21.合并两个有序链表

https://leetcode.cn/problems/merge-two-sorted-lists/description/

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：

输入：l1 = [], l2 = []
输出：[]


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
917. 仅仅反转字母

https://leetcode.cn/problems/reverse-only-letters/description/

给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s

示例 1：

输入：s = "ab-cd"
输出："dc-ba"

示例 2：

输入：s = "a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：

输入：s = "Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"


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
//            while (begin < end && !isalpha(s[begin])) // 也可以直接用c++里面的函数isalpha
//            {
//                // 不是字母就++
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
387.字符串中的第一个唯一字符

https://leetcode.cn/problems/first-unique-character-in-a-string/description/

给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。



示例 1：

输入: s = "leetcode"
输出: 0

示例 2:

输入: s = "loveleetcode"
输出: 2

示例 3:

输入: s = "aabb"
输出: -1




*/

//class Solution {
//public:
//    int firstUniqChar(string s) {
//        // 首先，创建一个数组存储
//        int count[256] = { 0 };
//        int n = s.size();
//        // 统计每个字符出现的次数
//        for (int i = 0; i < n; ++i)
//        {
//            count[s[i]] += 1;
//        }
//        // 按照字符次序从前往后找只出现一次的字符
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
