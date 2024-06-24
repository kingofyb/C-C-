#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
136. 只出现一次的数字

https://leetcode.cn/problems/single-number/description/

给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。



示例 1 ：
输入：nums = [2,2,1]
输出：1

示例 2 ：
输入：nums = [4,1,2,1,2]
输出：4

示例 3 ：
输入：nums = [1]
输出：1

核心思想
利用按位异或运算的性质来解决这个问题：

异或运算的性质：
a ^ a = 0：相同的数异或结果为0。
a ^ 0 = a：任意数与0异或结果为该数本身。
交换律和结合律：a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b。
由于数组中除了一个数只出现一次，其他数都出现两次，根据异或运算的性质，这些成对出现的数会互相抵消变成0，
最后剩下的就是那个只出现一次的数。

示例运行
假设 nums = [2, 2, 1]，我们来看看代码如何运行：

初始 value = 0。
遍历数组：
value ^= 2：value = 0 ^ 2 = 2
value ^= 2：value = 2 ^ 2 = 0
value ^= 1：value = 0 ^ 1 = 1
最终 value 的值为1，返回1。
这个结果符合预期，证明代码是正确的。

通过异或运算，可以在线性时间内（O(n)）找到唯一只出现一次的数字，
并且只使用常量级别的额外空间（O(1)）。这个方法既高效又简洁。
*/

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int value = 0;
//        for (auto e : nums) { value ^= e; }
//        return value;
//    }
//};

/*
118. 杨辉三角

https://leetcode.cn/problems/pascals-triangle/description/

杨辉三角的特点是每个数是它上方两个数之和。

这种方法时间复杂度为 O(N^2)，空间复杂度也是 O(N^2)
*/

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1, 0); // 第0行开一个0，第1行开2个0...
//            // 第一个和最后一个是1
//            vv[i].front() = 1;
//            vv[i].back() = 1;
//        }
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            for (size_t j = 0; j < vv[i].size(); ++j)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//                }
//            }
//        }
//        return vv;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;  // 声明一个二维向量vv，存储杨辉三角的每一行
//        vv.resize(numRows);  // 调整vv的大小为numRows行
//        for (size_t i = 0; i < vv.size(); ++i) {  // 遍历每一行
//            vv[i].resize(i + 1, 0);  // 每一行有i+1个元素，初始化为0
//            vv[i].front() = 1;  // 每一行的第一个元素为1
//            vv[i].back() = 1;  // 每一行的最后一个元素为1
//        }
//        for (size_t i = 0; i < vv.size(); ++i) {  // 再次遍历每一行
//            for (size_t j = 0; j < vv[i].size(); ++j) {  // 遍历每一行的每个元素
//                if (vv[i][j] == 0) {  // 如果当前元素是0，表示它需要计算
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];  // 当前元素是它左上和右上的元素之和
//                }
//            }
//        }
//        return vv;  // 返回生成的杨辉三角
//    }
//};



/*
26. 删除有序数组中的重复项

https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
不需要考虑数组中超出新长度后面的元素。



示例 2：
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。
不需要考虑数组中超出新长度后面的元素。

*/

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int src = 0;
//        int dst = 0;
//        while (src < nums.size())
//        {
//            if (nums[src] == nums[dst])
//            {
//                ++src;
//            }
//            else
//            {
//                nums[++dst] = nums[src++];
//            }
//        }
//
//        nums.resize(dst + 1);
//        return dst + 1;
//    }
//};


/*
17. 电话号码的字母组合

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]

*/


//class Solution {
//    char* numToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    // string numToStr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//public:
//    void Combine(string digits, int di, vector<string>& retV, string combineStr)
//    {
//        if (di == digits.size())
//        {
//            retV.push_back(combineStr);
//            return;
//        }
//        // 递归
//        // 取数字字符映射的字符串
//        int num = digits[di] - '0';
//        string str = numToStr[num];
//        for (auto ch : str)
//        {
//            // di+1就会往下一层走
//            Combine(digits, di + 1, retV, combineStr + ch);
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> v;
//        if (digits.empty())
//        {
//            return v;
//        }
//        string str;
//        Combine(digits, 0, v, str);
//
//        return v;
//    }
//};