#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;




//string(1)
//string& insert(size_t pos, const string& str);
//
//c - string(3)
//string & insert(size_t pos, const char* s);
//
//single character(6)
//iterator insert(iterator p, char c);

//void test_string8()
//{
//	string str("wo lai le");
//	// 空格的地方插入'20%'
//	//for (size_t i = 0; i < str.size();)
//	//{
//	//	if (str[i] == ' ')
//	//	{
//	//		str.insert(i, "20%"); // 一直在第一个空格的地方插20%，
//	//		i += 4;
//	//	}
//	// else
//	// {
//	//		++i;
//	// }
//	//}
//	//cout << str << endl;
//
//
//	// 效率不好 O(N^2)
//	// ----------------------------------------------------------------
//	//for (size_t i = 0; i < str.size(); ++i)
//	//{
//	//	if (str[i] == ' ')
//	//	{
//	//		str.insert(i, "20%"); // 一直在第一个空格的地方插20%，
//	//		i += 3;
//	//	}
//	//}
//	//cout << str << endl;
//
//	//// 把空格替换成%20
//	//for (size_t i = 0; i < str.size(); ++i)
//	//{
//	//	if (str[i] == ' ')
//	//	{
//	//		str.erase(i, 1);
//	//	}
//	//}
//	//cout << str << endl;
//	// ------------------------------------------------------------
//
//	// 以空间换时间 O(N)
//	string newstr;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		if (str[i] != ' ')
//		{
//			newstr += str[i];
//		}
//		else
//		{
//			newstr += "%20";
//		}
//	}
//	cout << newstr << endl;
//}
//
//void test_string9()
//{
//	// 兼容c，有些接口不支持 string
//	string filename("test.cpp");
//
//	cout << filename << endl; // 走的string的流插入
//	cout << filename.c_str() << endl; // 返回的const char* 的字符串
//
//	// 比如现在要求用c读这个文件的内容
//	// 
//	// c_str()返回c的字符串
//	FILE* fout = fopen(filename.c_str(), "r");
//	assert(fout);
//	char ch = fgetc(fout);
//	while (ch != EOF)
//	{
//		cout << ch;
//		ch = fgetc(fout);
//	}
//
//
//}
//
//void test_string10()
//{
//	// 平时这两种是一样的，但有些时候不一样
//	string filename("test.cpp");
//	cout << filename << endl; // 走的string的流插入
//	cout << filename.c_str() << endl; // 返回的const char* 的字符串
//
//	filename += '\0';
//	filename += "string.cpp";
//
//	// 现在输出的结果就不一样了
//	cout << filename << endl; // string 对象的size为准
//	cout << filename.c_str() << endl; // 常量字符串的\0为准，有\0就停止
//	/*
//	test.cppstring.cpp
//	test.cpp
//	*/
//	cout << filename.size() << endl;
//	string copy = filename;
//	cout << copy << endl << endl;
//
//	// 打印ASCII码
//	//for (unsigned char ch = 0; ch < 128; ++ch)
//	//{
//	//	cout << ch << "";
//	//}
//
//
//}
//
//void DealUrl(const string& url)
//{
//	// 第一部分是用://分开的
//	// 第二部分用/
//
//	size_t pos1 = url.find("://");
//	if (pos1 == string::npos) // 如果没找到://
//	{
//		cout << "非法url" << endl;
//		return;
//	}
//	string protocol = url.substr(0, pos1); // 比如:在索引5的位置，因为索引从0开始，那么就是pos1 - 0，前面的长度就是5
//	cout << protocol << endl;
//
//	// 域名
//	size_t pos2 = url.find('/', pos1 + 3); // 从pos1+3开始找/，对于c++官网的url来说就是从c开始找
//	if (pos2 == string::npos) // 如果没找到/
//	{
//		cout << "非法url" << endl;
//		return;
//	}
//	// 开始位置就是:位置的+3，结束位置就是下一个/
//	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3); // 域名的长度
//	cout << domain << endl;
//
//	// uri，资源定位
//	string uri = url.substr(pos2 + 1);
//	cout << uri << endl;
//
//	cout << endl;
//}
//
//
//void test_string11()
//{
//	string filename("test.cpp.tar.zip");
//
//	// 找后缀 - 可以直接找 .
//	// size_t pos = filename.find('.'); // 默认从0开始找
//
//	// 但是如果有很多.zip.cpp什么的，如果要取最后一个后缀呢？
//	// 用rfind，reverse find
//	size_t pos = filename.rfind('.');
//
//	if (pos != string::npos) // 如果没有找到.，npos属于类的静态成员变量，是公有的，属于这个类域，属于这个类的所有对象
//	{
//		// string suff = filename.substr(pos, filename.size() - pos); // 这样可以
//
//		string suff = filename.substr(pos); // 默认取到结束，这样也可以
//		
//
//		cout << suff << endl;
//	}
//
//	string url1 = "https://cplusplus.com/search";
//	string url2 = "https://moodle.ucl.ac.uk/enrol/index.php?id=36510";
//
//	// 主要由三个部分构成：
//	/*
//	1.、协议名
//	比如 https
//	2、域名
//	比如 cplusplus.com
//	3、路径，请求等
//	比如 search
//	*/
//
//	// 如何把url分割成三个部分
//	DealUrl(url1);
//	DealUrl(url2);
//
//
//	// https://cplusplus.com/reference/string/string/find_first_of/
//	string word = "I need to ate some apple";
//	size_t found = word.find_first_of("a");
//	while (found != string::npos)
//	{
//		word[found] = '*';
//		found = word.find_first_of("a", found + 1);
//	}
//
//	cout << word << endl;
//}
//
//void test_string12()
//{
//	int ival;
//	double dval;
//	cin >> ival >> dval;
//	string istr = to_string(ival);
//	string dstr = to_string(dval);
//
//	cout << istr << endl;
//	cout << dstr << endl;
//
//	istr = "9999";
//	dstr = "9999.99";
//
//	ival = stoi(istr);
//	dval = stod(dstr);
//
//	cout << ival << endl;
//	cout << dval << endl;
//}

//int main()
//{
//	test_string12();
//	return 0;
//}



// HJ1 字符串最后一个单词的长度

// https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&qru=/ta/huawei/question-ranking

//#include <iostream>
//using namespace std;
//
//int main() {
//
//	string str;
//	// cin>>str;
//	getline(cin, str);
//	size_t pos = str.rfind(' ');
//	// size是最后一个字符的下一个位置
//	// cin输入多个字符串的时候是空格或者换行来间隔的
//	// 输入的这一行里面本身就有空格，cin就会认为这个空格是多个值之间的分割
//	// 比如hello nowcoder，cin里面就只有hello，nowcoder在缓冲区
//
//	if (pos != string::npos)
//	{
//		cout << str.size() - pos - 1 << endl;
//	}
//	// 如果找不到空格，那长度就是size
//	else
//	{
//		cout << str.size() << endl;
//	}
//
//	return 0;
//}


// 387. 字符串中的第一个唯一字符

// https://leetcode.cn/problems/first-unique-character-in-a-string/description/


//class Solution {
//public:
//	int firstUniqChar(string s) {
//		// 首先，创建一个数组存储
//		int count[256] = { 0 };
//		int n = s.size();
//		// 统计每个字符出现的次数
//		for (int i = 0; i < n; ++i)
//		{
//			count[s[i]] += 1;
//		}
//		// 按照字符次序从前往后找只出现一次的字符
//		for (int i = 0; i < n; ++i)
//		{
//			if (count[s[i]] == 1)
//			{
//				return i;
//			}
//
//		}
//		return -1;
//	}
//};

// 125. 验证回文串

// https://leetcode.cn/problems/valid-palindrome/description/


//class Solution {
//public:
//	// 判断是不是字母和数字
//	bool isLetterOrNumber(char ch)
//	{
//		return (ch >= '0' && ch <= '9')
//			|| (ch >= 'a' && ch <= 'z');
//	}
//	bool isPalindrome(string s) {
//
//		// 加了引用，所以可以把大写字符转小写
//		for (auto& ch : s)
//		{
//			if (ch >= 'A' && ch <= 'Z')
//			{
//				ch += 32; // ASCII中，大写字母+32就是对应的小写字母
//			}
//		}
//
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin])) // 如果是字母数字就停下来
//			{
//				// 如果不是字母数字就跳过
//				++begin;
//			}
//			while (begin < end && !isLetterOrNumber(s[end])) // 如果是字母数字就停下来
//			{
//				// 如果不是字母数字就跳过
//				--end;
//			}
//			if (s[begin] == s[end])
//			{
//				// 相等就继续比较
//				++begin;
//				--end;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//};


#include"string.h"

int main()
{
	try 
	{
		bit::test_string8();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}