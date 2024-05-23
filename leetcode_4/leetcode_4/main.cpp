#include<iostream>
using namespace std;

/*
1658. 将 x 减到 0 的最小操作数

https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/

给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。
请注意，需要修改数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0

示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1

示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。

正难则反
找到两个区域，a在左边，b在右边是的a + b = x。
[[    ]        [     ]]
    a             b
创建一个sum，sum是整个数组的和
这时可以考虑中间的这个区域，使得sum - x，使中间这块连续的区域最长

转化：找出最长的子数组的长度，所有元素的和正好等于sum - x
                        len                        target
n - len

解法一：暴力枚举

target = sum - x
  [ < target   ] R(>=target)
[              ] ]             ]
  L

sum1 来标记L和R所指的区域的和
让R依次向后移动找那个最佳的位置

如果R找到一个元素使得前面的和 >= target，那么那个元素之前的元素之和肯定 < target

暴力解法的话，就让L右移一步，然后R回到L这里
但是R还有必要向左移动吗？
其实没有必要，本身前面的区域就小于target了，这时删除了第一个元素肯定还是小于target
所以R没有必要回去，所以让R要么原地不动，要么向后移动

解法二：滑动窗口
1.left = 0，right = 0

2.进窗口 -> sum1 += nums[right]

3.判断 -> 当这段区域的和 > target 就出窗口
出窗口 -> sum1 -= nums[left]

更新结果 -> 如果这段区域的和 = target 再更新结果

最后再用n减一下，得出最后结果

时间复杂度：O(N)
空间复杂度：O(1)
*/

//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int sum = 0; // 整个数组的和
//
//        for (int a : nums) sum += a; // 把里面每个数都拿出来然后+=
//        int target = sum - x;
//
//        // 细节问题
//        if (target < 0) return -1;
//
//        int ret = -1; // 如果没有找到结果，返回-1，所以直接赋值-1
//        for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++)
//        {
//            // 进窗口
//            tmp += nums[right];
//
//            while (tmp > target) // 判断
//            {
//                tmp -= nums[left++]; // 出窗口
//            }
//            if (tmp == target) // 更新结果
//            {
//                ret = max(ret, right - left + 1);
//            }
//        }
//        if (ret == -1) return ret;
//        else return nums.size() - ret;
//    }
//};


/*
904. 水果成篮

https://leetcode.cn/problems/fruit-into-baskets/description/

你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。



示例 1：

输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。
示例 2：

输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

等于是连续摘

转化：找出一个最长的子数组长度，子数组中不超过两种类型的水果

fruits = [1,2,3,2,2]

解法一：暴力枚举 + 哈希表
[1,2,3,2,2]

比如固定1，那就只能找到1,2
如果固定2，可以采摘到2,3,2,2
...
找出所有可能性，然后选择最长的

可以借助哈希表储存水果类型，统计水果一共出现多少种

解法二：滑动窗口
比如：
     R
f = [1, 2, 1, 2, 3, 2, 3, 3]
     L
hash<int,int> 不仅要存入水果的种类，还要存入水果的数量


1. left = 0，right = 9

2. 进窗口 -> hash[f[Right]]++

3. 判断 -> hash.size > 2
出窗口 -> hash[f[Left]]--，要判断一下，如果对应的位置的元素变成0，要从哈希表中删除

更新结果


*/

//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        unordered_map<int, int> hash; // 统计窗口内出现了多少种水果
//
//        int ret = 0;
//        for (int left = 0, right = 0; right < fruits.size(); right++)
//        {
//            hash[fruits[right]]++; // 进窗口
//
//            while (hash.size() > 2) // 判断
//            {
//                hash[fruits[left]]--; // 出窗口
//                if (hash[fruits[left]] == 0)
//                {
//                    hash.erase(fruits[left]); // 变成0就从哈希表中删除
//                }
//                left++;
//            }
//            ret = max(ret, right - left + 1); // 结果应该是left和right所指区间的长度
//        }
//        return ret;
//    }
//};
// 时间复杂度比较耗时，所以可以对哈希表做一个优化
//
//
// 优化后：
// 因为
//1 <= fruits.length <= 10^5
//0 <= fruits[i] < fruits.length
//所以可以使用一个数组来代表哈希表

// int hash[100001] = {0};
//
// for (int left = 0, right = 0, kinds = 0; right < fruits.size(); right++)
// if(hash[fruits[right]] == 0) kinds++; // 维护水果的种类
// while (kinds > 2)
// hash.erase(fruits[left]); -> if(hash[fruits[left]] == 0) kinds--;

// 如果数据范围是有限的，可以使用数组来替代哈希表，比直接使用容器效率的提升很大


/*
438. 找到字符串中所有字母异位词

https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。


1. 暴力解法

1. 如何快速判断两个字符串是否是“异位词”
s1 = "aabca"
s2 = "abaca"

用排序然后再一一比较的方法太耗时了

所以可以利用哈希表
遍历s1的字符，把字符依次丢到hash1
遍历s2的字符，把字符依次丢到hash2
然后比较两个哈希表中对应位置字符出现的个数是否相等，相等就是异位词

2.解决问题
比如：
s = "cbaebabacd" 
以c为起点，找一个长度为m的子串，
把子串里面每个字符出现的个数丢到另一个哈希表hash2里面
然后遍历完这个子串之后，比较一下这两个哈希表是否相等就可以
然后以b为起点...

p = "abc"，长度为m，hash1

hash1统计p里面的个数
hash2统计滑动窗口里面每个字符出现的个数

如何优化呢

每次枚举的时候，只需要把第一个字符删除，然后添加下一个字符就可以了
所以没有必要重新从头开始统计信息

s = "c b a e b a b a c d"
     L   R
s = "c b a e b a b a c d"
       L   R

可以使用滑动窗口
解法：滑动窗口 + 哈希表
1. left = 0, right = 0

2. 进窗口 -> hash2[in]++

3. 判断 -> right - left + 1 > m，就移动
出窗口 -> hash2[out]--

更新结果 -> check(hash2, hash1)

优化：可以对更新结果的判断条件(check)进行优化
利用变量count来统计窗口中“有效字符”的个数

s = "ccbaebabacd"，hash2

p = "abc"，hash1: a -> 1, b -> 1, c -> 1

进窗口：进入后 -> 判断此时hash2[in]是否小于等于hash1[in]
如果小于等于，就是添加的有效字符，count++
如果是其余情况，就是无效字符，count不变

出窗口：出去前 -> hash2[out] <= hash1[out] -> count--
其余情况count不变

更新结果：count == m
*/

//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> ret;
//        int hash1[26] = { 0 }; // 统计字符串p中每个字符出现的个数
//
//        for (auto ch : p) hash1[ch - 'a']++; // ch - 'a'对应位置的下标
//
//        int hash2[26] = { 0 }; // 统计窗口里面每一个字符出现的个数
//        int m = p.size();
//        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
//        {
//            char in = s[right];
//            //hash2[in - 'a']++; // 进窗口
//            // 维护一下count，可以在hash2前面添加++
//            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++; // 进窗口+维护
//
//            if (right - left + 1 > m) // 判断
//            {
//                char out = s[left++]; // 元素搞出去之后，left向右移动一步
//                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--; // 出窗口 + 出去前维护count
//                //hash2[out - 'a']--; // 出窗口
//            }
//            // 更新结果
//            if (count == m) ret.push_back(left);
//        }
//        return ret;
//    }
//};


/*
30. 串联所有单词的子串

https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/

给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 
"acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。

示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。

s = "barfoothefoobarman", words = ["foo","bar"] words里面的字符串长度都为3

s = "[bar][foo][the][foo][bar][man]"
       b    a    c    a    b    d

跟438. 找出所有字母的异位词 很像

滑动窗口 + 哈希表

不同之处：
1. 哈希表
hash<string, int> -> string对应字符，int对应字符串出现的次数

2. left与right指针的移动
移动的步长，是给定字符串里面每个单词的长度(len)

3. 滑动窗口执行的次数
len

*/

//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        unordered_map<string, int> hash1; // 保存words 里面所有单词的频次
//
//        for (auto& s : words) hash1[s]++; // 遍历字符串数组
//
//        vector<int> ret;
//        int len = words[0].size(), m = words.size();
//        for (int i = 0; i < len; i++) // 执行len次
//        {
//            // 这个哈希表维护滑动窗口内面单词的频次
//            unordered_map<string, int> hash2;
//            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len) // 因为是要把后面的字符串放到滑动窗口里面，如果right太靠后，后面根本就没有长度为len的字符串
//            {
//                // 进窗口 + 维护count
//                string in = s.substr(right, len);
//                hash2[in]++;
//                // 第一个哈希表不一定有这个单词，这样的话就会重新创建一个in，丢到哈希表
//                // 所以会有时间消耗
//                // 如果in出现在第一个哈希表里面的时候才接下来再判断
//                // 因为此时判断的时候这个in一定是在里面了，所以就不用重新再创建一个in在哈希表里面了
//                if (hash1.count(in) && hash2[in] <= hash1[in]) count++; // 可以提前判断一下，节省时间
//                // 判断
//                if (right - left + 1 > len * m) // len * m 窗口里面所有字符串的长度
//                {
//                    // 出窗口 + 维护count
//                    string out = s.substr(left, len);
//                    if (hash1.count(out) && hash2[out] <= hash1[out]) count--; // 有效单词
//                    hash2[out]--;
//                    // 出窗口后，left向后移动len步
//                    left += len;
//                }
//
//                // 更新结果，当有效字符的个数正好等于字典里面单词的个数时
//                if (count == m) ret.push_back(left);
//            }
//        }
//        return ret;
//    }
//};