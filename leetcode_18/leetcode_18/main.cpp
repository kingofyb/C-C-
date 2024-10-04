// 面试题 17.19. 消失的两个数字

/*
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可。

示例 1:
输入: [1]
输出: [2,3]

示例 2:
输入: [2,3]
输出: [1,4]

算法原理：
其实就是 丢失的数字 + 只出现一次的数字III(有两个数出现一次，其余都出现两次)

解法：位运算
1. 将所有数异或在一起, tmp = a^b(缺失的这两个数)

2. 找到tmp中比特位为1的那一位，因为a和b不一样，所以最终结果可能不等于0，所以
tmp中肯定有一个bit位的结果是1，比如x位肯定不同，一个是0一个是1

3. 根据x位的不同，划分成两类异或

现在可以分为两大类，一个是x位是0，一个是x位是1
此时把左边结果异或在一起，结果就是a
把右边异或结果就是b
*/

/*
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        int tmp = 0;
        // 将所有的数异或在一起
        // 异或原数组
        for(auto x : nums) tmp ^= x;
        // 异或1~n
        for(int i = 1; i <= nums.size() + 2; i++)
        {
            tmp ^= i; // 现在tmp存的是a和b异或的结果
        }

        // 找出a和b中比特位不同(为1)的那一位
        int diff = 0;
        while(1)
        {
            if(((tmp >> diff) & 1) == 1) // 一定会跳出这个循环
            {
                break;
            }
            else
            {
                diff++;
            }
        }

        // 根据diff位的不同，将所有的数划分为两类异或
        int a = 0, b = 0;
        for(int x : nums)
        {
            if(((x >> diff) & 1) == 1)
            {
                b ^= x;
            }
            else
            {
                a ^= x;
            }
        }
        for(int i = 1; i <= nums.size() + 2; i++)
        {
            if(((i >> diff) & 1) == 1)
                {
                    b ^= i;
                }
            else
                {
                    a ^= i;
                }
        }
        return {a,b};
    }
};


*/

/*
模拟算法 - 比葫芦画瓢

1. 模拟算法流程

2. 把流程转化成代码
*/

// 1576. 替换所有的问号

/*
https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/

给你一个仅包含小写英文字母和 ? 字符的字符串 s，请你将所有的 ? 转换为若干小写字母，
使最终的字符串不包含任何 连续重复 的字符。

注意：你 不能 修改非 ? 字符。
题目测试用例保证 除 ? 字符 之外，不存在连续重复的字符。

在完成所有转换（可能无需转换）后返回最终的字符串。
如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。

示例 1：
输入：s = "?zs"
输出："azs"
解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。
只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。

示例 2：
输入：s = "ubv?w"
输出："ubvaw"
解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。
因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
*/

/*

class Solution {
public:
    string modifyString(string s)
    {
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == '?') // 替换
            {
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    // i == 0 || ch != [s[i]-1] 如果当前是0的话不用判断前面是否相等，如果不是0就要判断
                    // i == n-1 || ch != s[i+1] 如果当前是最后一个位置就不用判断，否则要跟后一位判断，不相等就替换
                    if((i == 0 || ch != s[i-1]) && (i == n-1 || ch != s[i+1]))
                    {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        return s;
    }
};

*/

// 495. 提莫攻击

/*
https://leetcode.cn/problems/teemo-attacking/description/


在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄。他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。

当提莫攻击艾希，艾希的中毒状态正好持续 duration 秒。

正式地讲，提莫在 t 发起攻击意味着艾希在时间区间 [t, t + duration - 1]（含 t 和 t + duration - 1）处于中毒状态。如果提莫在中毒影响结束 前 再次攻击，中毒状态计时器将会 重置 ，在新的攻击之后，中毒影响将会在 duration 秒后结束。

给你一个 非递减 的整数数组 timeSeries ，其中 timeSeries[i] 表示提莫在 timeSeries[i] 秒时对艾希发起攻击，以及一个表示中毒持续时间的整数 duration 。

返回艾希处于中毒状态的 总 秒数。

示例 1：
输入：timeSeries = [1,4], duration = 2
输出：4
解释：提莫攻击对艾希的影响如下：
- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
- 第 4 秒，提莫再次攻击艾希，艾希中毒状态又持续 2 秒，即第 4 秒和第 5 秒。
艾希在第 1、2、4、5 秒处于中毒状态，所以总中毒秒数是 4 。

示例 2：
输入：timeSeries = [1,2], duration = 2
输出：3
解释：提莫攻击对艾希的影响如下：
- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
- 第 2 秒，提莫再次攻击艾希，并重置中毒计时器，艾希中毒状态需要持续 2 秒，即第 2 秒和第 3 秒。
艾希在第 1、2、3 秒处于中毒状态，所以总中毒秒数是 3 。


假设a和b是连续的两秒，d为持续时间
x = b - a
如果x >= d的话，这里面的时间都要加上, ret += d
如果x < d, ret += x,因为这样的话再b点又要受到一次攻击，中毒时间是重置的
*/

//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration)
//    {
//        int ret = 0;
//        for (int i = 1; i < timeSeries.size(); i++) // i要从1开始，因为要计算和前一位的差
//        {
//            // 同时，代码逻辑上不需要比较第一个时间点，因为中毒持续时间是从第一次攻击后开始计算的，
//            // 所以直接从第二次攻击开始检查两个攻击之间的间隔是否会影响中毒时间的累计。
//            int x = timeSeries[i] - timeSeries[i - 1];
//            if (x >= duration) ret += duration;
//            else ret += x;
//        }
//        return ret + duration;
//    }
//};