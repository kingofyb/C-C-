#include<iostream>
using namespace std;

/*
76. 最小覆盖子串

https://leetcode.cn/problems/minimum-window-substring/description/

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。


示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。


示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串

解法一： 暴力枚举 + 哈希表

先定义left和right，可以在随机位置
枚举一个位置向后找，找到一个位置之后，发现这段区间是一个最小的区间之后，让left移动一格
然后right继续从left开始向后找

输入：s = "ADOBECODEBANC", t = "ABC"
hash1:
在t中A出现1次，B出现1次，C出现1次

hash2：
在s中，记录ABC出现几次
只要在hash2中，字符统计出现的次数大于等于hash1，那么就是一个有效的枚举

优化：
          符合要求
s = "-----------------------------"
        [L       R]

当left向左移动一步时，会有两种情况
1：依旧符合要求
right不动

2：不符合要求
right向右移动，找符合要求的位置

两个指针是同向运动的，所以单调性，所以可以使用滑动窗口

解法二：滑动窗口 + 哈希表
s = "A D O B E C O D E B A N C", t = "ABC"
     L
       R




1. left = 0, right = 0

2. 进窗口 -> hash2[in]++

3. 判断，当窗口刚好合法时出窗口 -> check(hash1, hash2)

更新结果 -> 起始位置、最终的最短长度

出窗口 -> hash2(out)--

判断成立先更新结果，再出窗口然后继续判断

优化：判断条件
使用变量count标记有效字符的“种类”

1. 进窗口 -> 进之后，当hash2(in) == hash1(in), count++
只要hash2里面A的个数与hash1里面A的个数相等时统计

2. 出窗口 -> 出之前，当hash2(out) == hash1(out), count--
比如出窗口后，hash2里面A的个数从0变成了1，然后hash1里面A为1，成为了无效字符，那么count--

3. 判断条件 -> count == hash1.szie()
*/

//class Solution {
//public:
//    string minWindow(string s, string t)
//    {
//        // 数组模拟哈希表，因为全是英文字符
//        int hash1[128] = { 0 }; // 统计字符串t中每个字符的频次
//        int hash2[128] = { 0 }; // 统计窗口内每个字符的频次
//        int kinds = 0; // 统计有效字符有多少种
//        for (auto ch : t)
//        {
//            // if(hash[ch] == 0) kinds++;
//            // hash[ch]++;
//            // 同上
//            if (hash1[ch]++ == 0) kinds++; // 加之前如果等于0，说明找到一个有效字符，所以kinds++
//        }
//
//
//
//        int minlen = INT_MAX, begin = -1; // minlen是最小覆盖子串长度，begin存的是起始位置
//        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
//        {
//            char in = s[right];
//            //     hash2[in]++;
//            //     if(hash2[in] == hash1[in])
//            //     {
//            //         count++;
//            //     }
//            // 同上
//            if (++hash2[in] == hash1[in]) count++; // 进窗口+维护count变量
//
//            while (count == kinds) // 判断条件
//            {
//                // 只要窗口长度小于minlen
//                if (right - left + 1 < minlen) // 更新结果
//                {
//                    minlen = right - left + 1;
//                    begin = left;
//                }
//                // 出窗口
//                char out = s[left++];
//
//                // if(hash2[out] == hash1[out]) count--;
//                // hash2[out]--;
//
//                // 同上
//                if (hash2[out]-- == hash1[out]) count--; // 说明此时有效字符的种类要减少
//            }
//        }
//        if (begin == -1) return ""; // 如果等于-1说明没有找到一个子串，返回空串
//        else return s.substr(begin, minlen); // 找到了就把它裁出来
//    }
//};

/*
二分查找算法：朴素模版

1. 特点
最容易死循环的算法

704. 二分查找

https://leetcode.cn/problems/binary-search/description/

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4


示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

原理：
[1, 2, 3, 4, 5, 6, 7, 8], t = 5

解法一：暴力解法 -> O(N)
从左往右依次用t跟数组的元素对比

比如选择4，那么在升序数组中，4和4左边区间的元素肯定比5小

解法二：二分查找算法“二段性”
当数组有二段性的时候就可以用二分查找算法

二段性：
当我们发现一个规律，然后根据这个规律选取某一个点后，能把这个数组分成两部分
然后根据规律可以有选择性的舍去一部分，然后根据这个规律在另一个部分里面继续查找的时候就可以用二分查找

选择中间点，时间复杂度最优

                 M
[                x                 ], t
 L                                R

L = left, R = right, M = mid

朴素版本二分查找算法的核心：

第一种情况：x < t，删除左区间 -> left = mid + 1 -> 然后再在更新之后的[left, right]区间寻找结果

第二种情况：x > t，删除右区间 -> right = mid - 1 -> 然后再在更新之后的[left, right]区间寻找结果

第三种情况：x = t，直接返回结果

细节问题：
1. 循环结束的条件 -> left > right

2. 为什么是正确的

3. 时间复杂度
循环1次：n/2
2次：n/4
3次：n/8
...
x次：1 -> 2^x/n -> 2^x = n -> x = logN
*/

//class Solution {
//public:
//    int search(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            // int mid = (left + right) / 2; // 有溢出风险
//            int mid = left + (right - left) / 2; // 防止溢出
//            if (nums[mid] < target) left = mid + 1;
//            else if (nums[mid] > target) right = mid - 1;
//            else return mid;
//        }
//        return -1;
//    }
//};

// 朴素二分模版
// 
// 
// 
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2; 
//            if (......) 
//                  left = mid + 1;
//            else if (......) 
//                  right = mid - 1;
//            else 
//                  return ......;
//        }