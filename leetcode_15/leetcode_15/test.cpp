#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
724. 寻找数组的中心下标

https://leetcode.cn/problems/find-pivot-index/description/

给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。
这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。


示例1：
输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。


示例 2：
输入：nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心下标。


示例 3：
输入：nums = [2, 1, -1]
输出：0
解释：
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。


解法一：暴力解法

解法二：前缀和
1.
dp[i] = dp[i-1] + arr[i]

dp[i] -> 0到i位置所有元素的和
dp[i-1] -> 0到i-1所有元素的和
arr[i] -> 当前位置的元素


f表示前缀和数组：
f[i]表示：[0,i-1]区间，所有元素的和
f[i-1]表示[0,i-2]区间，所有元素的和

f[i] = f[i-1] + nums[i-1]

g表示后缀和数组：
g[i]表示：[i+1,n-1]区间，所有元素的和

g[i] = g[i+1] + nums[i+1]


2.
0~n-1：枚举所有元素的中心下标
然后判断是否相等：f[i] == g[i]

3. 细节问题
处理越界：
f[0] = 0
g[n-1] = 0

填表顺序：
f: 从左向右
g: 从右向左
*/

//class Solution {
//public:
//    int pivotIndex(vector<int>& nums)
//    {
//        int n = nums.size();
//        vector<int> f(n), g(n); // 大小为n
//
//        // 1. 预处理前缀和和后缀和数组
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = f[i - 1] + nums[i - 1];
//        }
//        for (int i = n - 2; i >= 0; i--)
//        {
//            g[i] = g[i + 1] + nums[i + 1];
//        }
//
//        // 2. 使用
//        // 枚举所有下标
//        for (int i = 0; i < n; i++)
//        {
//            if (f[i] == g[i]) // 找到中心下标
//            {
//                return i;
//            }
//        }
//
//        return -1; // 没有中心下标
//    }
//};

/*
238. 除自身以外数组的乘积

https://leetcode.cn/problems/product-of-array-except-self/description/

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据保证数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。


示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]

示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]


解法一：暴力解法

解法二：前缀和（前缀积）
1. 预处理前缀积以及后缀积
f表示前缀积：
f[i]表示：[0,i-1]区间内所有元素的乘积
f[i] = f[i-1] * nums[i-1]


g表示后缀积：
g[i]表示：[i+1,n-1]区间内所有元素的乘积
g[i] = g[i+1] * nums[i+1]

2. 使用
i -> f[i] * g[i]

3. 细节问题
f[0] = 1
g[n-1] = 1 
*/

//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums)
//    {
//        int n = nums.size();
//        vector<int> f(n), g(n); // 不需要考虑溢出
//
//        // 1. 预处理
//        f[0] = g[n - 1] = 1; // 细节问题
//        for (int i = 1; i < n; i++)
//        {
//            f[i] = f[i - 1] * nums[i - 1];
//        }
//        for (int i = n - 2; i >= 0; i--)
//        {
//            g[i] = g[i + 1] * nums[i + 1];
//        }
//
//        // 2. 使用
//        vector<int> ret(n);
//        for (int i = 0; i < n; i++)
//        {
//            ret[i] = f[i] * g[i];
//        }
//
//        return ret;
//    }
//};

/*
560. 和为 K 的子数组

https://leetcode.cn/problems/subarray-sum-equals-k/description/

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2

解法一：暴力解法 -> 枚举
时间复杂度：O(N^2)
不能用双指针来做优化（存在0和负数）

解法二：前缀和 + 哈希表
以i位置为结尾的所有子数组
本质上就是：在[0,i-1]区间内，有多少个前缀和等于 sum[i] - k

哈希表：<int,int>
第一个int存前缀和，第二个int存前缀和出现的次数

细节问题：
1. 前缀和加入哈希表的时机？
在计算i位置之前，哈希表里面只保存[0,i-1]位置的前缀和

2. 不用真的创建一个前缀和数组
用一个变量sum，来标记前一个位置的前缀和即可

3. 如果整个前缀和等于k呢？
先把hash[0] = 1 丢到哈希表里面，相当于默认有一个前缀和等于0
*/

//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash; // 统计前缀和出现的次数
//        hash[0] = 1;
//
//        int sum = 0, ret = 0;
//        for (auto x : nums)
//        {
//            sum += x; // 计算当前位置的前缀和
//            if (hash.count(sum - k))
//            {
//                ret += hash[sum - k]; // 统计个数
//            }
//            hash[sum]++;
//
//        }
//        return ret;
//    }
//};


/*
974. 和可被 K 整除的子数组

https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/

给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。

子数组 是数组中 连续 的部分。

示例 1：
输入：nums = [4,5,0,-2,-3,1], k = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 k = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


示例 2:
输入: nums = [5], k = 9
输出: 0


解法一：暴力枚举



补充知识：
1. 同余定理
(a-b) / p = k ... 0，如果a-b的差能被p整除，那么 a%p = b%p。

比如
(26 - 12) / 7 = 2 -> 26 % 7 = 12 % 7 = 5

(1 + 2*3) % 2 = 1
(a + p*k) % p = a % p

2. c++ [负数 % 正数] 的结果以及修正	
负数取模：
负 % 正 = 负 --> 修正：a % p + p --> 正负统一: (a%p + p) % p


解法二：前缀和 + 哈希表
在[0,i-1]区间内，找到有多少个前缀和的余数等于 (sum % k + k) % k

哈希表<int,int>
第一个int表示前缀和余数，第二个int表示出现的次数
*/

//class Solution {
//public:
//    int subarraysDivByK(vector<int>& nums, int k)
//    {
//        unordered_map<int, int> hash;
//        hash[0 % k] = 1; // 存的是0这个数的余数
//
//        int sum = 0, ret = 0;
//        for (auto x : nums)
//        {
//            sum += x; // 算出当前位置的前缀和
//            int r = (sum % k + k) % k; // 修正后的余数
//            if (hash.count(r))
//            {
//                ret += hash[r]; // 统计结果
//            }
//            hash[r]++;
//        }
//        return ret;
//    }
//};