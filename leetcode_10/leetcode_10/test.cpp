#include<iostream>
#include <unordered_map>
using namespace std;

/*
14. 最长公共前缀

https://leetcode.cn/problems/longest-common-prefix/

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 如果输入字符串数组为空，则返回空字符串
        if(strs.empty()) return "";

        // 使用 minmax_element 来找到字符串数组中最小和最大的字符串
        // p 是一个 pair，p.first 指向最小字符串，p.second 指向最大字符串。
        const auto p = minmax_element(strs.begin(), strs.end());

        // 遍历最小字符串的每一个字符（从第一个字符到最后一个字符）。
        for(int i=0; i<p.first->size(); i++)
        {
            // 如果在某个位置，最小字符串和最大字符串的字符不相同，则返回最小字符串的从开始到当前位置的子串
            if(p.first->at(i) != p.second->at(i))
            {
                //  返回最小字符串从开始到第 i 个位置的子串
                return p.first->substr(0,i);
            }
        }

        // 如果循环结束，说明最小字符串本身就是最长公共前缀
        return *p.first;
    }
};

const -> 这是一个修饰符，表示变量 p 是常量，不能被修改。它确保了 p 的值在声明之后不能再被改变

auto -> 这是一个类型说明符，告诉编译器根据右侧的初始化表达式自动推断变量 p 的类型。
在这里，p 的类型是 std::pair<iterator, iterator>，其中 iterator 是 strs 向量的迭代器类型

p -> 这是变量的名称，它是一个 std::pair，包含两个迭代器，分别指向 strs 向量中最小和最大的字符串。

minmax_element -> 这是一个标准库函数，位于 <algorithm> 头文件中。它接受两个迭代器，返回一个 std::pair，
其中第一个元素是范围内的最小元素，第二个元素是范围内的最大元素。

strs.begin() -> 这是一个迭代器，指向 strs 向量的第一个元素。

strs.end() -> 这是一个迭代器，指向 strs 向量的最后一个元素之后的位置。

p.first -> 访问 p 这个 std::pair 的第一个元素，p.first 是指向 strs 中最小字符串的迭代器。

"->" -> 这是成员访问运算符，用于指向对象的成员。这里用于访问迭代器指向的字符串的成员函数 at()

at(i) -> 这是字符串类的成员函数，返回字符串中索引为 i 的字符。如果索引 i 超出范围，会抛出 out_of_range 异常

p.second -> 访问 p 这个 std::pair 的第二个元素，p.second 是指向 strs 中最大字符串的迭代器

substr(0, i) -> 字符串类的成员函数，返回一个子字符串，起始位置为 0，长度为 i

*p.first -> 解引用运算符，用于获取指针或迭代器指向的对象。在这里，*p.first 获取迭代器 p.first 指向的字符串

--------------------------------------------------------------------------
std::string substr (size_t pos = 0, size_t len = npos) const;
pos 是子字符串开始的位置。
len 是子字符串的长度。

当调用 p.first->substr(0, 0) 时：

p.first 是一个指向字符串的指针，假设它指向的是字符串 "dog"。
substr(0, 0) 表示从位置 0 开始，长度为 0。

这意味着从字符串的第一个字符开始，提取长度为 0 的子字符串。显然，这样的子字符串是一个空字符串。
*/



/*
20. 有效的括号

https://leetcode.cn/problems/valid-parentheses/description/

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


示例 1：

输入：s = "()"
输出：true

示例 2：

输入：s = "()[]{}"
输出：true

示例 3：

输入：s = "(]"
输出：false

栈是一种后进先出的数据结构，这意味着最后一个压入栈的元素最先弹出。
这种特性特别适合处理成对出现、嵌套结构的问题，比如括号匹配、函数调用栈等。

基本操作：

push：将元素压入栈顶。
pop：将栈顶元素弹出。
top：访问栈顶元素而不弹出。
empty：检查栈是否为空。


栈的后进先出 (LIFO) 特性：

栈是一种后进先出 (LIFO, Last In First Out) 的数据结构，适合处理括号匹配问题。
每当遇到一个左括号时，将其压入栈中；每当遇到一个右括号时，检查栈顶是否是对应的左括号，如果是，则弹出栈顶元素。



匹配括号对：

每个右括号都必须有一个对应的左括号，而且必须按正确的顺序嵌套。通过栈的数据结构，可以轻松实现这种匹配。

字符串遍历：

通过遍历字符串，逐个检查每一个字符是否是括号，并进行相应的处理。这个过程保证了字符串中的每一个括号都被检查和匹配。


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s)
        {
            // 如果c是 ([{ 就入栈
            if(c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            // 如果c是 )]} 并且栈不为空 则判断栈顶是否为与之对应的左括号 是则出栈，不是则返回false
            else if(c == ')' && !stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else if(c == '}' && !stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else if(c == ']' && !stk.empty() && stk.top() == '[')
            {
                stk.pop();
            }
            else
            {
                // 如果c是 )}] 栈为空 那么返回false
                // 如果c是 )}] 栈不为空， 但是 栈顶不是与c对应的左括号 那么返回false
                return false;
            }
        }
        // 例如"(){}[" ， 如果最后栈不为空，那么就是有多余的左括号了
        return stk.empty();
    }
};

优化：
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 定义一个字符栈

        for (char c : s) { // 使用范围 for 循环遍历字符串 s 中的每一个字符 c
            // 如果字符 c 是左括号 (，{ 或 [，则将其压入栈 stk
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            // 如果字符是右括号之一，则进行匹配检查
            else {
                // 检查栈是否为空，如果为空则返回 false，因为没有对应的左括号。
                // 使用辅助函数 isMatchingPair 检查栈顶元素是否与当前右括号匹配，如果不匹配则返回 false
                if (stk.empty() || !isMatchingPair(stk.top(), c)) {
                    return false;
                }
                // 匹配成功，弹出栈顶元素
                stk.pop();
            }
        }

        // 最后检查栈是否为空，如果为空则括号完全匹配，否则有未匹配的左括号
        return stk.empty();
    }

private:
    // 辅助函数，用于检查两个括号是否匹配
    bool isMatchingPair(char left, char right) {
        return (left == '(' && right == ')') ||
               (left == '{' && right == '}') ||
               (left == '[' && right == ']');
    }
};

辅助函数 isMatchingPair 用于检查两个括号是否匹配。
接受两个字符 left 和 right，如果它们是一对匹配的括号，则返回 true，否则返回 false

*/

/*
什么时候使用for (auto c : s)，什么时候使用for (int i = 0; i < s.size(); i++)

只读遍历且不需要索引：使用 for (auto c : s)。这可以使代码更简洁。
需要索引：使用 for (int i = 0; i < s.size(); i++)。
需要修改元素：使用 for (int i = 0; i < s.size(); i++) 或 for (auto& c : s)（如果不需要索引，但需要修改元素）。


只读遍历：
std::string s = "example";
for (auto c : s) {
    std::cout << c << " ";
}

需要索引：
std::string s = "example";
for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) { // 打印偶数索引的字符
        std::cout << s[i] << " ";
    }
}

修改元素：
std::string s = "example";
for (auto& c : s) {
    c = toupper(c); // 将每个字符转换为大写
}
std::cout << s; // 输出 "EXAMPLE"

需要索引且修改元素：
std::vector<int> nums = {1, 2, 3, 4, 5};
for (int i = 0; i < nums.size(); i++) {
    nums[i] *= 2; // 将每个元素乘以2
}
for (auto num : nums) {
    std::cout << num << " "; // 输出 "2 4 6 8 10"
}

*/

/*
HJ73 计算日期到天数转换

https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。
进阶：时间复杂度：O(n) ，空间复杂度：O(1)

输入描述：
输入一行，每行空格分割，分别是年，月，日

输出描述：
输出是这一年的第几天

2012 12 31
366

#include <iostream>
using namespace std;

int main()
{
    // 如果算的是5月，那前面四个月肯定是过完的，直接加上就可以
    int year, month, day;
    cin >> year >> month >> day;

    int monthDays1_N[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    // [1,month-1]
    int n = monthDays1_N[month-1] + day;

    // 四年一润，百年不润，四百年润一次
    if(month > 2 && ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)))
    {
        n += 1;
    }

    cout<<n<<endl;

    return 0;

}
*/

/*


*/




int main() {
    std::unordered_map<std::string, int> umap;

    // 插入元素
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["orange"] = 3;

    // 访问元素
    std::cout << "apple: " << umap["apple"] << std::endl;

    // 查找元素
    if (umap.find("banana") != umap.end()) {
        std::cout << "banana found" << std::endl;
    }

    // 遍历元素
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}