#include<iostream>
#include<string>
using namespace std;

//(1)istream& getline(istream& is, string& str, char delim);
//(2)istream& getline(istream& is, string& str);

// Get line from stream into string
//int main()
//{
//	string name;
//
//	// extract to string
//	cout << "Please, enter your full name: ";
//	getline(cin, name);
//	cout << "Hello, " << name << "!\n";
//
//	return 0;
//}

// rfind
// Searches the string for the last occurrence of the sequence specified by its arguments.
// string(1)size_t rfind(const string& str, size_t pos = npos) const;
//int main()
//{
//    string str("The sixth sick sheik's sixth sheep's sick.");
//    string key("sixth");
//
//    size_t found = str.rfind(key);
//    if (found != std::string::npos)
//        str.replace(found, key.length(), "seventh");
//
//    cout << found << endl;
//    cout << str << '\n';
//
//    return 0;
//}


/*
HJ1 字符串最后一个单词的长度

https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking

计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）

输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。

输入：
hello nowcoder

输出：
8

说明：
最后一个单词为nowcoder，长度为8

*/

/*
getline 的作用是从标准输入（cin）中读取一行文本，
并将其存储到 word 字符串中。getline 读取操作在遇到换行符（\n）时结束，但换行符本身不会被存储到 word 中


*/



//#include <iostream>
//using namespace std;
//
//int main() {
//
//    string word;
//    // getline 的作用是从标准输入（cin）中读取一行文本，并将其存储到 word 字符串中。
//    // getline 读取操作在遇到换行符（\n）时结束，但换行符本身不会被存储到 word 中
//    while (getline(cin, word))
//    {
//        size_t pos = word.rfind(" ");
//        cout << word.size() - pos - 1 << endl;
//    }
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//
//    string str;
//    // cin>>str;
//    getline(cin, str);
//    size_t pos = str.rfind(' ');
//    // size是最后一个字符的下一个位置
//    // cin输入多个字符串的时候是空格或者换行来间隔的
//    // 输入的这一行里面本身就有空格，cin就会认为这个空格是多个值之间的分割
//    // 比如hello nowcoder，cin里面就只有hello，nowcoder在缓冲区
//
//    if (pos != string::npos)
//    {
//        cout << str.size() - pos - 1 << endl;
//    }
//    // 如果找不到空格，那长度就是size
//    else
//    {
//        cout << str.size() << endl;
//    }
//
//    return 0;
//}





// ----------------------------------------- tried, not the answer 
//int main()
//{
//	string s = "abcdefg";
//	int k = 2;
//
//    string r1;
//    for (int i = 0; i < k; i++)
//    {
//        r1 += s[i];
//    }
//    reverse(r1.begin(), r1.end());
//    
//    int n = s.size();
//    string r2 = s.substr(k, n - 1);
//
//    string r3 = r1 + r2;
//    cout << r1 << endl;
//    cout << r2 << endl;
//    cout << r3 << endl;
//	return 0;
//}
// -------------------------------------------------------------------------




/*
541. 反转字符串 II

https://leetcode.cn/problems/reverse-string-ii/description/

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。


示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：

输入：s = "abcd", k = 2
输出："bacd"

详情见博客图解：
*/

//class Solution {
//public:
//    string reverseStr(string s, int k)
//    {
//        int n = s.size();
//        // 每次都是2k个2k个进行处理，所以+=2k
//        for (int i = 0; i < n; i += 2 * k)
//        {
//            // reverse(s.begin() + i, s.begin() + min(i+k,n));
//            // 每隔2k个字符的前k个字符进行反转
//            // 剩余字符小于2k个但大于等于k个，则反转前k个字符
//            if (i + k <= s.size())
//            {
//                reverse(s.begin() + i, s.begin() + i + k);
//                continue;
//            }
//            // 剩余字符少于k个，则将剩余字符串全部反转
//            reverse(s.begin() + i, s.begin() + s.size());
//        }
//        return s;
//    }
//};

/*
557. 反转字符串中的单词 III

https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/

给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。



示例 1：

输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

示例 2:

输入： s = "Mr Ding"
输出："rM gniD"

解法一：双指针
使用一个 while 循环遍历整个字符串，直到 left 超过字符串长度。
在内部，使用另一个 while 循环找到当前单词的右边界，即找到下一个空格或者字符串的结尾


*/

// 双指针
//class Solution {
//public:
//    string reverseWords(string s) {
//        int left = 0;
//        int n = s.size();
//        while (left < n)
//        {
//            // 找到单词右边界
//            int right = left;
//            while (right < n && s[right] != ' ')
//            {
//                right++;
//            }
//            // 反转
//            reverse(s.begin() + left, s.begin() + right);
//
//            // 移动left到下一个单词的开头
//            left = right + 1;
//        }
//        return s;
//
//    }
//};

/*
125. 验证回文串

https://leetcode.cn/problems/valid-palindrome/description/

如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。


示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。

示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串


*/

//class Solution {
//public:
//    // 判断是不是字母和数字
//    bool isLetterOrNumber(char ch)
//    {
//        return (ch >= '0' && ch <= '9')
//            || (ch >= 'a' && ch <= 'z');
//    }
//    bool isPalindrome(string s) {
//
//        // 加了引用，所以可以把大写字符转小写
//        for (auto& ch : s)
//        {
//            if (ch >= 'A' && ch <= 'Z')
//            {
//                ch += 32; // ASCII中，大写字母+32就是对应的小写字母
//            }
//        }
//
//        int begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isLetterOrNumber(s[begin])) // 如果是字母数字就停下来
//            {
//                // 如果不是字母数字就跳过
//                ++begin;
//            }
//            while (begin < end && !isLetterOrNumber(s[end])) // 如果是字母数字就停下来
//            {
//                // 如果不是字母数字就跳过
//                --end;
//            }
//            if (s[begin] == s[end])
//            {
//                // 相等就继续比较
//                ++begin;
//                --end;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//
//};