#include<iostream>
using namespace std;

/*
11. 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

https://leetcode.cn/problems/container-with-most-water/
1. 题目解析
[1,8,6,2,5,4,8,3,7]

解法1：
暴力枚举 - 2层for循环
每两个数字都组合看哪个大
会超时
时间复杂度：O(N^2)

解法2：
v      =        h      x      w
1. 如果h和w都减小，那么结果一定是小的
2. 如果h不变，w减小，那么结果也是减小的

比如
[1,8,6,2,5,4,8,3,7]
 L               R
先计算1和7，得出v1
这时候可以把左侧指针L移动到8，然后计算8和7得到v2
然后把右侧指针R移动到3，得到v3，然后移动R到8得到v4 。。。
把这一堆v使用max得到最大值


利用单调性，使用双指针解决问题
时间复杂度：O(N)

c版本在网站有，下面是c++版本的答案
*/

//int maxArea(vector<int>& height) {
//    int left = 0, right = height.size() - 1, ret = 0;
//    while (left < right)
//    {
//        int v = min(height[left], height[right]) * (right - left);
//        ret = max(ret, v);
//
//        //移动指针，谁小移动谁
//        if (height[left] < height[right]) left++;
//        else right--;
//    }
//    return  ret;
//}

// ---------------------------------------------------------------------------------
/*
611. 有效三角形的个数
https://leetcode.cn/problems/valid-triangle-number/

给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
任意两边之和大于第三边 - 这个规则需要判断三次才能知道三条边能否构成三角形
如果我们知道大小顺序，那么仅需判断较小的两个数是否大于最大的数即可 - 这个规则只需要判断一次

示例 1:

输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是:
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
优化：先对整个数组排序


解法1：暴力枚举解法
for(i=0; i<n; i++)
  for(j=i+1; j<n; j++)
    for(k=j+1; k<n; k++)
      check(i,j,k)
时间复杂度：三层循环，所以是O(3 * N^3)

解法2：利用单调性，使用双指针算法来解决问题
给定数组 [2,2,3,4,5,9,10]
已经有序，因为已经排过序
[2,2,3,4,5,9,10]
 L         R

a代表L指的数，b代表R指的数，c代表数组中最大数
所以只有两种情况：
a + b > c
和
a + b <= c

a+b就大于c了，那么b加上a和b之间的所有数相加都大于c
2+9 > 10, 3+9 > 10 ...

所以

a + b > c 变成 right - left, right-- 去下一个区间判断

a + b <= c 这个情况，如果a+b就已经小于c了，那么a加上小于等于b的所有数相结合都小于等于c
a + b <= c 变成 left++

第一步 - 先固定最大的数（最右边的数）- O(N)
第二步 - 在最大数的左区间内，使用双指针算法，快速统计出符合要求的三元组的个数 - O(N)

时间复杂度：O(N^2)
*/

//int triangleNumber(vector<int>& nums) {
//    //优化，排序
//    sort(nums.begin(), nums.end());
//
//    //利用双指针解决问题
//    int ret = 0, n = nums.size();
//    for (int i = n - 1; i >= 2; i--) //先固定最大的数
//    {
//        int left = 0, right = i - 1;
//        while (left < right)
//        {
//            if (nums[left] + nums[right] > nums[i])
//            {
//                ret += right - left;
//                right--;
//            }
//            else
//            {
//                left++;
//            }
//        }
//    }
//    return ret;
//
//}

// ---------------------------------------------------------------------------
/*
LeetCode——剑指 Offer 57. 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

【输入】nums = [2,7,11,15], target = 9
【输出】[2,7] 或者 [7,2]

解法1：暴力枚举
例子：
nums = [2,7,11,15,19,21], target = 30
从2开始和所有数相结合看看等不不等于t，然后从7开始 ...
for(i=0; i<n; i++)
  for(j=i+1; j<n; j++)
    check(nums[i] + nums[k] == t)
时间复杂度：O(N^2)

解法2：利用数组有序特性，双指针算法（也可以二分）
利用单调性，使用双指针算法

[2,7,11,15,19,21], t= 30
 L            R

1. sum > t - right--
如果L+R相加都大于t了，所以要舍弃R，直接让right向左移动一位

2. sum < t - left++
如果L+R都已经小于t了，那么在有序数组中，就没有必要计算了，因为数组是从小到大排序，直接换个区间
只需要计算一次就可以舍弃这个区间，所以很高效

3. sum = t - return 结果

时间复杂度: O(N)
*/

//vector<int> twoSum(vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int sum = nums[left] + nums[right];
//        if (sum > target) right--;
//        else if (sum < target) left++;
//        //如果返回值是vector，并且返回值只需返回两个变量，则可以直接使用大括号返回
//        else return {nums[left], nums[right]};
//    }
//    //如果没有最终结果(照顾编译器)
//    return {-1,-1};
//}

// ------------------------------------------------------------------------------------------
/*
15. 三数之和
https://leetcode.cn/problems/3sum/description/

给定一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

因为要去重，可以先把数组排序
[-4, -1, -1, 0, 1, 2]

解法一：先排序 + 暴力枚举 + 利用set去重
把数组都扔到set里面，然后去重

时间复杂度：O(N^3)，因为要三个for循环


解法二：排序 + 双指针
如果数组有序，就往双指针这方面靠

举例：
[-4, -4, -1 ,0, 0, 0, 1, 1，4, 4, 5, 6]
    [                                 ] 在这个有序区间里找到和t = 4，这样-4 + 4 = 0，这个可以看怎么用双指针计算两数之和（上个问题）
  i  L                               R
1. 排序
2. 固定一个数a - 当a大于0之后，后面情况就不用考虑了
3. 在该数后面的区间里，利用双指针算法快速找到两个数的和等于-a即可

然后处理细节问题：
1. 去重（不用set）
找到一种结果之后left和right指针要跳过重复元素
比如0+4计算之后，后面left++，到下一个0之后，可以直接跳过这个0，到下一个元素

当使用完一次双指针算法之后，i也需要跳过重复元素
如果i++之后i+1的值等于i，也要去重

还要避免指针越界


2. 不漏
找到一种结果之后，不要“停”，缩小区间，继续寻找

时间复杂度：O(N^2)
空间复杂度：O(logN)
*/

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ret;
//        //1. 排序
//        sort(nums.begin(), nums.end());
//
//        //2.双指针
//        int n = nums.size();
//        for (int i = 0; i < n;) // 固定数a
//        {
//            if (nums[i] > 0) break;
//            int left = i + 1, right = n - 1, target = -nums[i];
//            while (left < right)
//            {
//                int sum = nums[left] + nums[right];
//                if (sum > target) right--;
//                else if (sum < target) left++;
//                else
//                {
//                    // 这里pushback要pushback vector的一个数组           
//                    ret.push_back({ nums[i],nums[left],nums[right] });
//                    // 不漏
//                    left++, right--;
//
//                    // 去重left和right，并且避免越界
//                    while (left < right && nums[left] == nums[left - 1]) left++;
//                    while (right > left && nums[right] == nums[right + 1]) right--;
//                }
//            }
//            // 去重 i，并移动i
//            i++;
//            while (i < n && nums[i] == nums[i - 1]) i++;
//        }
//        return ret;
//    }
//};