#include<iostream>
using namespace std;

int main()
{

	return 0;
}

/*
34. 在排序数组中查找元素的第一个和最后一个位置

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：

输入：nums = [], target = 0
输出：[-1,-1]


解法一：暴力查找
[1, 2, 3, 3, 3, 4, 5] t = 3
从前往后扫描暴力查找，最坏情况下O(N)

优化
利用数组有序的特性

解法二：朴素二分
[1, 2, 3, 3, 3, 4, 5] t = 3
 L        M        R
在极端情况下时间复杂度会降低，比如如果数组内的元素都一样

优化
[1, 2, 3, 3, 3, 4, 5] t = 3
[    ] [            ]
左边区间小于t，右边区间大于等于t

当发现问题中有二段线的规律时就可以用二分查找

 L             M             R
[-----------------------------] t
               x
-------------------------------------------------------- 查找区间左端点

1. x < t -> left = mid + 1 -> [left,right]

2. x >= t -> right = mid -> [left, right] 

因为 mid有可能是最终结果，所以不能更新到 mid + 1

细节处理：

1. 循环条件
left < right

a. 当 left = right的时候就是最终结果，无需判断
b. 如果判断，就会死循环

第一种情况：[left, right]中有结果
 L                           R
[-----------------------------] t
[       ][                    ]         
           t
因为 left = mid + 1，所以 left是想跳出左边这个区域的
当left和right相遇的位置就是最终结果

第二种情况：全大于t
 L                           R
[-----------------------------] t
只会命中第二个条件，right只会像左移动
直接判断左端点的值是否是t

第三种情况：全小于t
只会命中第一个条件，left只会像右移动
直接判断右端点的值是否是t

2. 求中点的操作
a. left + (right - left) / 2
b. left + (right - left + 1) / 2
当数组的个数是偶数时，用a求中点是靠左，用b是靠右

用b会陷入死循环，因为是右端点

当a。求的是左端点，当命中第一个条件时left会右移，此时相等的话就终止循环
当命中第二个条件时，right会更新到mid，此时两个又相遇了，又终止循环了
所以求中点的操作只能用a才能终止循环

-------------------------------------------------------- 查找区间右端点
[1, 2, 3, 3, 3, 4, 5] t = 3
[             ][    ]

左边区间全部小于等于t，右边全部大于t

 L             M             R
[-----------------------------] t
               x
1. x <= t，mid此时在左边区域，所以更新left -> left = mid -> [left, right] left和right中继续寻找结果

2. x > t，mid此时在右边区域，更新right -> right = mid - 1 -> [left, right]

处理细节：
1. 循环条件
left < right

2. 求中点的方式
a. left + (right - left) / 2
b. left + (right - left + 1) / 2

b求的是右端点
当最后元素剩2个时
[* *]
 L R

如果使用a，那么mid现在落在L，那么对于第一个条件，left会在这里不动，然后mid又落在这个位置，就会陷入死循环
使用b，mid就在R，当命中第一个条件时，left会移动到right，终止循环
命中第二个条件，right移动到left，也会终止循环


*/

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        // 处理边界情况
//        if (nums.size() == 0) return { -1, -1 };
//        int begin = 0;
//        // 1. 二分左端点
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2; // 中点下标
//            if (nums[mid] < target) left = mid + 1;
//            else right = mid;
//
//        }
//        // 结束循环后，left和right相遇
//        // 判断是否有结果
//        if (nums[left] != target) return { -1, -1 };
//        else begin = left; // 等于left或right都一样，标记左端点
//
//        // 2. 二分右端点
//        // 其实left不需要重置，但是为了保持代码的独立性
//        left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2; // 中点下标
//            if (nums[mid] <= target) left = mid;
//            else right = mid - 1;
//        }
//        return { begin, right }; // 此时left或者right都存的右端点
//    }
//};


// 当下面出现 -1 的时候，上面就 +1
// 分类讨论的代码，就题论题即可
// 查找区间左端点的模版
//while (left < right)
//{
//    int mid = left + (right - left) / 2;
//    if (...) left = mid + 1;
//    else right = mid;
//}

// 查找区间右端点的模版
//while (left < right)
//{
//    int mid = left + (right - left + 1) / 2;
//    if (...) left = mid;
//    else right = mid - 1;
//}