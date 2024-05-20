#include<iostream>
using namespace std;

/*
18. 四数之和

https://leetcode.cn/problems/4sum/description/

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
（若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]

解法一：排序 + 暴力枚举 + 理由set去重
超时

解法二：排序 + 双指针
[-2, -1, 0, 0, 1, 2] target
     [             ] target - a
  a
     b [         ] target - a - b
        left  right
1. 先依次固定一个a;
2. 在a后面的区间内，利用“三数之和”找到三个数，使这三个数的和等于target - a即可

三数之和的大体思路：
1. 依次固定一个b;
2. 在b后面的区间内，利用“双指针”找到两个数，使这两个数的和等于target - a - b即可

处理细节问题：
1. 不重
去重a,b,left,right

2. 不漏

时间复杂度：O(N^3)
*/

//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>> ret;
//        // 排序
//        sort(nums.begin(), nums.end());
//        // 利用双指针解决问题
//        int n = nums.size();
//        for (int i = 0; i < n; ) //固定a
//        {
//            // 利用三数之和
//            for (int j = i + 1; j < n; ) //固定b
//            {
//                // 双指针
//                int left = j + 1, right = n - 1;
//                long long aim = (long long)target - nums[i] - nums[j];
//                while (left < right)
//                {
//                    int sum = nums[left] + nums[right];
//                    if (sum < aim) left++;
//                    else if (sum > aim) right--;
//                    else
//                    {
//                        ret.push_back({ nums[i], nums[j], nums[left++], nums[right--] });
//                        // 去重1
//                        while (left < right && nums[left] == nums[left - 1]) left++; //当left右移完之后和左边这个数相比，如果相同，说明重复元素，需要跳过
//                        while (left < right && nums[right] == nums[right + 1]) right--;
//                    }
//                }
//                // 去重2
//                j++;
//                while (j < n && nums[j] == nums[j - 1]) j++;
//            }
//            // 去重3
//            i++;
//            while (i < n && nums[i] == nums[i - 1]) i++;
//        }
//        return ret;
//    }
//};

// --------------------------------------------------------------------------------
// 滑动窗口
/*
209. 长度最小的子数组

https://leetcode.cn/problems/minimum-size-subarray-sum/description/

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组
 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

target = 7, nums = [2,3,1,2,4,3]

解法一：暴力枚举出所有子数组的和
时间复杂度：O(N^3)

 R 
[2, 3, 1, 2, 4, 3]
 L
先定义一个sum，计算左区间的和
比如：sum + 2 + 3 + ...
这样可以省去再遍历一遍数组

    R
[2, 3, 1, 2, 4, 3]
 L
sum = 5

       R
[2, 3, 1, 2, 4, 3]
 L
sum = 6
len 2 -> 3

...

             R
[2, 3, 1, 2, 4, 3]
 L
sum = 12
len = 5

这个len是一直增长的，所以肯定不是最短的结果

接下来让L向左移动一位，然后继续让R从左开始移动
那这个时候从3开始的区间可以在上一个结果中找到

解法二：利用单调性，使用“同向双指针”来优化
                         也就是 滑动窗口
非常像一个窗口在平移
当使用暴力解法时。两个指针都可以做到不回退，都是向一个方向移动时就可以使用滑动窗口

1. 初始化；left = 0, right = 0

2. 进窗口

3. 判断是否是结果，然后更新结果（长度），再出窗口，判断len

2和3一直循环

滑动窗口的正确性：在单调性里面体现

          R
[2, 3, 1, 2, 4, 3]
 L

此时sum = 8
4. 为什么不往后枚举呢？因为已经知道接下来的情况再枚举也是白枚举，因为是正整数数组
利用单调性，规避了很多没有必要的枚举行为

5. 时间复杂度
进窗口要一个循环，判断也是一个循环，等于是两层循环套在一起
但是总的操作次数只是2n次
所以最终的时间复杂度是一个O(N)
*/

//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size();
//        int sum = 0, len = INT_MAX; //如果定义0，那最终的求min结果就是0，所以定义一个大的变量，不干扰最终结果
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            // 进入窗口
//            sum += nums[right];
//
//            //判断要不要缩小窗口
//            while (sum >= target)
//            {
//                len = min(len, right - left + 1); // 更新结果
//                sum -= nums[left++]; // 出窗口
//            }
//            // 一直更新到窗口不符合要求位置，然后right++
//        }
//        return len == INT_MAX ? 0 : len; // 如果没有最终结果就返回0，不然就返回len
//    }
//};

// ------------------------------------------------------------------------------------------------------
/*
3. 无重复字符的最长子串

https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

子串和字数组都是连续的一段


解法一：暴力枚举 + 哈希表(判断字符是否重复出现)

可以借助哈希表来判断是否有重复字符
遍历的时候把字符保存到哈希表里，当遍历到重复元素时，停止这个操作

 R
[d, e, a, b, c, a, b, c, a]
 L

                R
[d, e, a, b, c, a, b, c, a]
 L

当a重复时，停止这个操作，然后移动L，

                R
[d, e, a, b, c, a, b, c, a]
    L


时间复杂度：O(N^2)


解法二：利用规律，使用“滑动窗口”来解决问题

 R
[d, e, a, b, c, a, b, c, a]
 L

                  R
[[d, e, a, b, c], a, b, c, a]
  L

当a重复时，停止这个操作，然后移动L，

                R
[[d, e, a, b, c], a, b, c, a]
           L

当发现区间里面有重复字符时，可以让L先跳过这个重复字符
R也不用回到L的位置，让R继续移动即可
此时就可以使用滑动窗口解决问题

1. 先定义L = 0和R = 0

2. 进窗口 -> 让字符进入哈希表

3. 判断
根据判断结果判定是否出窗口（窗口内出现重复字符时才出窗口）

判断和出窗口是一个循环，一直到没有重复字符为止

出窗口就是从哈希表中删除该字符

然后更新结果（更新结果的过程要根据题目决定在哪）
本题中，在整个判断之后，更新结果

为什么要用滑动窗口，因为两个指针都不会回退

时间复杂度：O（N）
空间复杂度：O（1）
因为哈希表只有128位，所以可以忽略不计
*/

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        // 下标表示字符，让里面的数来表示是否重复出现，出现一次为1，两次为2...
//        int hash[128] = { 0 }; // 使用数组表示哈希表
//
//        int left = 0, right = 0, n = s.size();
//        int ret = 0;
//        while (right < n)
//        {
//            hash[s[right]]++; // 字符对应的下标，进入窗口
//
//            while (hash[s[right]] > 1) // 判断
//            {
//                hash[s[left++]]--; // 先把哈希表里面的对应的值--，表示它从哈希表删除，然后++完成出窗口的操作
//            }
//            ret = max(ret, right - left + 1); // 更新结果，区间的长度是right - left + 1
//            right++; // 让下一个元素进入窗口
//        }
//        return ret;
//    }
//};

// --------------------------------------------------------------------------------------------------------------------
/*
1004. 最大连续1的个数 III

https://leetcode.cn/problems/max-consecutive-ones-iii/description/

给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回数组中连续 1 的最大个数

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1*,1,1,1,1,1*]
粗体数字1*从 0 翻转到 1，最长的子数组长度为 6。

最多k个0说明可以翻转0,1,2，...，一直到k个为止
比如下方这个例子中，k最多可以翻转100个0，但其实不需要翻转100次
[1,1,0,0,1,1,0], k = 100

[1,1,1,0,0,0,1,1,1,1,0], K = 2
          [           ]，最长为6

可以等价处理，在数组中满足0的个数不超过k次即可，只要这个区域的0不超过k，那么这个区域是一定可以翻转成功的
把原始问题转换成：
找出最长的子数组，0的个数不超过k个
[1,1,1,0,0,0,1,1,1,1,0], K = 2

解法一：暴力枚举 + zero计数器(int类型变量，统计0出现多少次)

 R
[1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], K = 2
 L
zero = 0
          R
[1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], K = 2
 L
zero = 1

                  R
[[1, 1, 1, 0, 0], 0, 1, 1, 1, 1, 0], K = 2 固定第一个位置的最优解
 L
zero = 2

然后R继续从数组最开始的位置开始移动


解法二：滑动窗口
所以可以让R越过这段区域，不用重新遍历，可以移动L
                R
[1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], K = 2 
             L

当在暴力枚举中L和R都只往一个方向移动时，可以使用滑动窗口

1. left = 0, right = 0

2. 进窗口 -> 如果是1，无视；如果是0，计数器+1
当R向后移动时就相当于进窗口了
当进入窗口时无视，当碰到0时，计数器加一

3. 判断 -> 当zero大于k，出窗口
出窗口
让L一直右移，直到窗口合法为止

当判断结束之后，更新结果，当R移动到最后位置就会得到最终结果

时间复杂度：O(N)
空间复杂度：O(1)
*/

//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k)
//    {
//        int ret = 0;
//        for (int left = 0, right = 0, zero = 0; right < nums.size(); right++)
//        {
//
//            if (nums[right] == 0) zero++; // 进窗口
//            while (zero > k) // 判断窗口是否合法
//            {
//                if (nums[left++] == 0) zero--; // 出窗口，left向后移动
//            }
//            // 左闭右闭的区间
//            ret = max(ret, right - left + 1); // 更新结果
//        }
//        return ret;
//    }
//};