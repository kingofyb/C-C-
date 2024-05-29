#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
69. x 的平方根

https://leetcode.cn/problems/sqrtx/description/

给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。


示例 1：

输入：x = 4
输出：2

示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

假设求17的平方根

解法一：暴力解法

从1开始依次尝试
比如1的平方是1，2的平方是4...直到5的平方，25>17，所以一定是4点几的平方，所以等于4

1  2  3  4  5  6  7
1  4  9  16 25 36 49

寻找二段性

可以把这些数抽象成一段横线

           ret
------------*--------------

ret左边的区域的平方后全是小于等于x，从这个位置开始右边的区域平方后全大于x

解法二：二分查找

先定义一个L(从1开始)，一个R(x)
查找区间应该是从1到x

1. mid*mid <= x -> 落在左边区间，更新left指针，left = mid

2. mid*mid > x -> 落在右边区间，更新right指针，right = mid - 1 

*/

//class Solution {
//public:
//    int mySqrt(int x)
//    {
//        // x 有可能小于1
//        if (x < 1) return 0; // 处理边界情况
//        int left = 1, right = x;
//        while (left < right)
//        {
//            long long mid = left + (right - left + 1) / 2; // long long防溢出
//            if (mid * mid <= x) left = mid;
//            else right = mid - 1; // 根据模版，这里出现减法，就把求mid那里加1即可
//        }
//        return left;
//    }
//};

/*
35. 搜索插入位置

https://leetcode.cn/problems/search-insert-position/description/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4

寻找二段性

第一种情况：直接找到target

第二种情况：找不到target，要找插入位置
插入的位置应该是第一次比它大的这个数前面，或者最后
最终找到位置的这个值应该是大于等于target的
左边的区域全都小于target

[小于t][大于等于t             ]
-------------------------------
         ret

1. x < t -> left = mid + 1

2. x >= t -> right = mid
*/

//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target) left = mid + 1;
//            else right = mid;
//        }
//        // 如果target插入位置在数组最后
//        if (nums[left] < target) return left + 1; // right + 1也是对的，因为left和right已经相遇了
//        return left;
//    }
//};

/*
852. 山脉数组的峰顶索引

https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/

符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3

存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]

给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

示例 1：

输入：arr = [0,1,0]
输出：1

示例 2：

输入：arr = [0,2,1,0]
输出：1

示例 3：

输入：arr = [0,10,5,2]
输出：1

先上升，到山顶，然后再下降

解法一：暴力枚举
定义一个指针从开始如果前一个数后一个数就不会是峰值，直接到下一个位置
当扫描到第一次数是大于后面的数的时候就是峰顶

时间复杂度：O(N)

优化：
山顶左边区间所有数都是大于前一个数，右边区间所有数都是小于前一个数

解法二：二分查找
二段性 - 能把数组分成两部分
中间值的下标为mid

1. 如果落在左边区间，mid包含在了最终结果里面，接下来去右边区间找
arr[mid] > arr[mid - 1] -> left = mid

2. 落在右边区间，要到左边区域找
arr[mid] < arr[mid - 1] -> right = mid - 1
*/

//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int left = 1, right = arr.size() - 2; // 抛开第一个和最后一个位置
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (arr[mid] > arr[mid - 1]) left = mid;
//            else right = mid - 1;
//        }
//        return left;
//    }
//};