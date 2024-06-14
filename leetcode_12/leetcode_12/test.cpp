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
HJ1 �ַ������һ�����ʵĳ���

https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking

�����ַ������һ�����ʵĳ��ȣ������Կո�������ַ�������С��5000����ע���ַ���ĩβ���Կո�Ϊ��β��

����������
����һ�У�����Ҫ������ַ������ǿգ�����С��5000��

���������
���һ����������ʾ�����ַ������һ�����ʵĳ��ȡ�

���룺
hello nowcoder

�����
8

˵����
���һ������Ϊnowcoder������Ϊ8

*/

/*
getline �������Ǵӱ�׼���루cin���ж�ȡһ���ı���
������洢�� word �ַ����С�getline ��ȡ�������������з���\n��ʱ�����������з������ᱻ�洢�� word ��


*/



//#include <iostream>
//using namespace std;
//
//int main() {
//
//    string word;
//    // getline �������Ǵӱ�׼���루cin���ж�ȡһ���ı���������洢�� word �ַ����С�
//    // getline ��ȡ�������������з���\n��ʱ�����������з������ᱻ�洢�� word ��
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
//    // size�����һ���ַ�����һ��λ��
//    // cin�������ַ�����ʱ���ǿո���߻����������
//    // �������һ�����汾����пո�cin�ͻ���Ϊ����ո��Ƕ��ֵ֮��ķָ�
//    // ����hello nowcoder��cin�����ֻ��hello��nowcoder�ڻ�����
//
//    if (pos != string::npos)
//    {
//        cout << str.size() - pos - 1 << endl;
//    }
//    // ����Ҳ����ո��ǳ��Ⱦ���size
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
541. ��ת�ַ��� II

https://leetcode.cn/problems/reverse-string-ii/description/

����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���

���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����


ʾ�� 1��

���룺s = "abcdefg", k = 2
�����"bacdfeg"

ʾ�� 2��

���룺s = "abcd", k = 2
�����"bacd"

���������ͼ�⣺
*/

//class Solution {
//public:
//    string reverseStr(string s, int k)
//    {
//        int n = s.size();
//        // ÿ�ζ���2k��2k�����д�������+=2k
//        for (int i = 0; i < n; i += 2 * k)
//        {
//            // reverse(s.begin() + i, s.begin() + min(i+k,n));
//            // ÿ��2k���ַ���ǰk���ַ����з�ת
//            // ʣ���ַ�С��2k�������ڵ���k������תǰk���ַ�
//            if (i + k <= s.size())
//            {
//                reverse(s.begin() + i, s.begin() + i + k);
//                continue;
//            }
//            // ʣ���ַ�����k������ʣ���ַ���ȫ����ת
//            reverse(s.begin() + i, s.begin() + s.size());
//        }
//        return s;
//    }
//};

/*
557. ��ת�ַ����еĵ��� III

https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/

����һ���ַ��� s ������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��



ʾ�� 1��

���룺s = "Let's take LeetCode contest"
�����"s'teL ekat edoCteeL tsetnoc"

ʾ�� 2:

���룺 s = "Mr Ding"
�����"rM gniD"

�ⷨһ��˫ָ��
ʹ��һ�� while ѭ�����������ַ�����ֱ�� left �����ַ������ȡ�
���ڲ���ʹ����һ�� while ѭ���ҵ���ǰ���ʵ��ұ߽磬���ҵ���һ���ո�����ַ����Ľ�β


*/

// ˫ָ��
//class Solution {
//public:
//    string reverseWords(string s) {
//        int left = 0;
//        int n = s.size();
//        while (left < n)
//        {
//            // �ҵ������ұ߽�
//            int right = left;
//            while (right < n && s[right] != ' ')
//            {
//                right++;
//            }
//            // ��ת
//            reverse(s.begin() + left, s.begin() + right);
//
//            // �ƶ�left����һ�����ʵĿ�ͷ
//            left = right + 1;
//        }
//        return s;
//
//    }
//};

/*
125. ��֤���Ĵ�

https://leetcode.cn/problems/valid-palindrome/description/

����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��

��ĸ�����ֶ�������ĸ�����ַ���

����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��


ʾ�� 1��

����: s = "A man, a plan, a canal: Panama"
�����true
���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���

ʾ�� 2��

���룺s = "race a car"
�����false
���ͣ�"raceacar" ���ǻ��Ĵ�


*/

//class Solution {
//public:
//    // �ж��ǲ�����ĸ������
//    bool isLetterOrNumber(char ch)
//    {
//        return (ch >= '0' && ch <= '9')
//            || (ch >= 'a' && ch <= 'z');
//    }
//    bool isPalindrome(string s) {
//
//        // �������ã����Կ��԰Ѵ�д�ַ�תСд
//        for (auto& ch : s)
//        {
//            if (ch >= 'A' && ch <= 'Z')
//            {
//                ch += 32; // ASCII�У���д��ĸ+32���Ƕ�Ӧ��Сд��ĸ
//            }
//        }
//
//        int begin = 0, end = s.size() - 1;
//        while (begin < end)
//        {
//            while (begin < end && !isLetterOrNumber(s[begin])) // �������ĸ���־�ͣ����
//            {
//                // ���������ĸ���־�����
//                ++begin;
//            }
//            while (begin < end && !isLetterOrNumber(s[end])) // �������ĸ���־�ͣ����
//            {
//                // ���������ĸ���־�����
//                --end;
//            }
//            if (s[begin] == s[end])
//            {
//                // ��Ⱦͼ����Ƚ�
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