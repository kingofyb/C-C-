#include<iostream>
using namespace std;

int main()
{
	return 0;
}

// 模版 - 二维前缀和
/*
DP35 【模板】二维前缀和

https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=38962&ru=/exam/oj

给你一个 n 行 m 列的矩阵 A ，下标从1开始。

接下来有 q 次查询，每次查询输入 4 个参数 x1 , y1 , x2 , y2

请输出以 (x1, y1) 为左上角 , (x2,y2) 为右下角的子矩阵的和，
输入描述：
第一行包含三个整数n,m,q.

接下来n行，每行m个整数，代表矩阵的元素

接下来q行，每行4个整数x1, y1, x2, y2，分别代表这次查询的参数

输入：
3 4 3
1 2 3 4
3 2 1 0
1 5 7 8
1 1 2 2
1 1 3 3
1 2 3 4

输出：
8
25
32

解法一：暴力解法 -> 模拟
直接算区间里面的和

每次询问都要遍历数组一遍

时间复杂度：O(n*m*q)

解法二：前缀和

1. 预处理出来一个前缀和矩阵
dp[i][j]表示：从[1,1]位置到[i,j]位置，这段区间里面所有元素的和
dp[i][j] = A + B + C + D = (A + B) + (A + C) + D - A

A + B = dp[i-1][j]
A + C = dp[i][j-1]
D = arr[i][j]
A = dp[i-1][j-1]


直接遍历dp一遍就能全部得出来

2. 使用前缀和矩阵

求的是[x1,y1] ~ [x2,y2]

先算出整个区域的面积，再减去
D = A + B + C + D - (A+B) - (A+C) + A 

A + B + C + D = dp[x2][y2]

A + B = dp[x1-1][y2]

A + C = dp[x2][y1-1]

A = dp[x1-1][y1-1]


时间复杂度：O(m*n) + O(q)
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // 1. 读入数据
//    int n = 0, m = 0, q = 0;
//    cin >> n >> m >> q;
//
//    // 因为下标是从1开始计数的，所以m和n要+1才能访问到[m][n]这个位置
//    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//
//    // 2. 预处理前缀和矩阵，longlong防止溢出
//    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
//        }
//    }
//
//    // 3. 使用前缀和矩阵，一共q次，所以q--
//    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//    while (q--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//
//    }
//
//    return 0;
//}

/*
13. 罗马数字转整数

https://leetcode.cn/problems/roman-to-integer/description/

示例 1:
输入: s = "III"
输出: 3

示例 2:
输入: s = "IV"
输出: 4

示例 3:
输入: s = "IX"
输出: 9


*/


//class Solution {
//public:
//    int romanToInt(string s)
//    {
//        // 建立罗马数字到整数的映射
//        unordered_map<char, int> roman_map = {
//            {'I', 1},
//            {'V', 5},
//            {'X', 10},
//            {'L', 50},
//            {'C', 100},
//            {'D', 500},
//            {'M', 1000}
//        };
//
//        int result = 0;
//        int n = s.size();
//
//        for (int i = 0; i < n; i++)
//        {
//            // 如果当前字符不是最后一个字符，并且当前字符表示的数值小于下一个字符表示的数值
//            if (i < n - 1 && roman_map[s[i]] < roman_map[s[i + 1]])
//            {
//                // 减去当前字符表示的数值
//                result -= roman_map[s[i]];
//            }
//            else
//            {
//                result += roman_map[s[i]];
//            }
//        }
//        return result;
//    }
//};

/*
28. 找出字符串中第一个匹配项的下标

https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。

示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。


时间复杂度：O(n * m)，其中 n 是 haystack 的长度，m 是 needle 的长度。最坏情况下，每个字符都需要进行比较。
空间复杂度：O(1)，因为只使用了常数空间。
*/

//class Solution {
//public:
//    int strStr(string haystack, string needle)
//    {
//        int n = haystack.size(), m = needle.size();
//        // 外循环遍历 haystack 的每一个可能的起始位置 i（范围为 0 到 n - m）。
//        for (int i = 0; i + m <= n; i++)
//        {
//            bool flag = true;
//            // 内循环遍历 needle 的每一个字符，检查 haystack 从 i 位置开始的子串是否与 needle 匹配。
//            for (int j = 0; j < m; j++)
//            {
//                if (haystack[i + j] != needle[j])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            // 如果发现匹配子串，返回其起始位置 i
//            if (flag)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

/*
66. 加一

https://leetcode.cn/problems/plus-one/description/

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
*/

//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        int n = digits.size(); // 获取数组的长度
//
//        // 从数组的最后一个元素开始遍历
//        for (int i = n - 1; i >= 0; --i) {
//            if (digits[i] < 9) { // 如果当前元素小于9
//                digits[i] += 1; // 将当前元素加一
//                return digits; // 直接返回结果
//            }
//            digits[i] = 0; // 如果当前元素等于9，将其置为0
//        }
//
//        // 如果所有元素都是9，则在数组的开头插入1
//        digits.insert(digits.begin(), 1);
//        return digits; // 返回结果
//    }
//};