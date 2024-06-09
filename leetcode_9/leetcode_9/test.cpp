#include<iostream>
using namespace std;

int main()
{

	return 0;
}

/*
1. 两数之和

https://leetcode.cn/problems/two-sum/

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
'
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

*/


/*
9. 回文数

https://leetcode.cn/problems/palindrome-number/description/

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数
是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。


示例 1：

输入：x = 121
输出：true

class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性

//        如果 x 小于 0，或者 x 是以 0 结尾但不等于 0，那么 x 不是回文数。
//        负数肯定不是回文数，因为它们的倒序数不是负数。
//        以 0 结尾的数（但不是 0 本身）也不是回文数，因为倒序会多出一个 0。

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // 定义变量 revertedNumber 来存储反转后的数字
        int revertedNumber = 0;
        // 当 x 大于 revertedNumber 时继续循环
        while (x > revertedNumber) {

        //在每次循环中，将 x 的最后一位数字加到 revertedNumber 的末尾。
        //然后将 x 去掉最后一位数字（通过整除 10）。
            revertedNumber = revertedNumber * 10 + x % 10;
            // 去掉 x 的最后一位数字
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。

//      当 x 的长度是偶数时，x 应该等于 revertedNumber。
//      当 x 的长度是奇数时，revertedNumber 会多一位，因此我们可以通过 revertedNumber / 10 去掉中间的数字再比较。
//      最终，如果 x 等于 revertedNumber 或 x 等于 revertedNumber 去掉最后一位的结果，那么 x 是回文数，返回 true；否则返回 false。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
*/


// --------------------------- 前缀和
/*
DP34 【模板】前缀和

https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=38960&ru=/exam/oj

输入：
3 2
1 2 4
1 2
2 3

输出：
3
6

第一行表示有3个数，2次询问
第二行是个数组：
a: [1,2,4]
i: [1,2,3] -> i = index

第三行，给1和2就是算1和2位置的和，1 + 2 = 3
第四行，给2和3就是算第二个和第三个数的和：2 + 4 = 6
如果是1 3，那就是 1+2+4 = 7
如果是2 2，那就是只算出2这个位置的和，就只有2

从a1开始访问的，所以数组大小得是n+1

例子：
arr: [1,4,7,2,5,8,3,6,9]

i:   [1,2,3,4,5,6,7,8,9]

解法一：暴力解法 -> 模拟
时间复杂度：O(N*q) -> 有多少次查询就要遍历数组多少次(q次查询)
超时

解法二：前缀和 -> 快速求出数组中某一个连续区间的和
时间复杂度：O(q) + O(N)

第一步：预处理出来一个前缀和数组(dp)
arr: [1,4,7,2,5,8,3,6,9]

dp:  [1,5,12,14,19,27,30,36,45]

i:   [1,2,3,4,5,6,7,8,9]

dp[i]：表示[1,i]区间内所有元素的和
比如dp[3]表示原始数组1+4+7

dp[i] = dp[i-1] + arr[i]


第二步：使用前缀和数组
想求出l到r之间的和时可以直接减去就行：
[l,r] = dp[r] - dp[l-1]

dp:  [1,5,12,14,19,27,30,36,45]
              l     r

细节问题：为什么下标要从1开始计数？
比如如果想算[0,2]，那l就要访问-1，-1这个位置访问不了，所以要处理边界问题

从1开始就可以处理边界情况
比如算[1,2] -> dp[2] - dp[0]，可以把dp[0] = 0



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 1. 读入数据
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    // 2. 预处理出来一个前缀和数组
    vector<long long> dp(n+1); // 防止溢出
    for(int i = 1; i <= n; i++) dp[i] = dp[i-1] + arr[i];

    // 3.使用前缀和数组
    int l = 0, r = 0;
    while(q--)
    {
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << endl;
    }
    return 0;
}
*/