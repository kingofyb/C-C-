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
//	// �ո�ĵط�����'20%'
//	//for (size_t i = 0; i < str.size();)
//	//{
//	//	if (str[i] == ' ')
//	//	{
//	//		str.insert(i, "20%"); // һֱ�ڵ�һ���ո�ĵط���20%��
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
//	// Ч�ʲ��� O(N^2)
//	// ----------------------------------------------------------------
//	//for (size_t i = 0; i < str.size(); ++i)
//	//{
//	//	if (str[i] == ' ')
//	//	{
//	//		str.insert(i, "20%"); // һֱ�ڵ�һ���ո�ĵط���20%��
//	//		i += 3;
//	//	}
//	//}
//	//cout << str << endl;
//
//	//// �ѿո��滻��%20
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
//	// �Կռ任ʱ�� O(N)
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
//	// ����c����Щ�ӿڲ�֧�� string
//	string filename("test.cpp");
//
//	cout << filename << endl; // �ߵ�string��������
//	cout << filename.c_str() << endl; // ���ص�const char* ���ַ���
//
//	// ��������Ҫ����c������ļ�������
//	// 
//	// c_str()����c���ַ���
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
//	// ƽʱ��������һ���ģ�����Щʱ��һ��
//	string filename("test.cpp");
//	cout << filename << endl; // �ߵ�string��������
//	cout << filename.c_str() << endl; // ���ص�const char* ���ַ���
//
//	filename += '\0';
//	filename += "string.cpp";
//
//	// ��������Ľ���Ͳ�һ����
//	cout << filename << endl; // string �����sizeΪ׼
//	cout << filename.c_str() << endl; // �����ַ�����\0Ϊ׼����\0��ֹͣ
//	/*
//	test.cppstring.cpp
//	test.cpp
//	*/
//	cout << filename.size() << endl;
//	string copy = filename;
//	cout << copy << endl << endl;
//
//	// ��ӡASCII��
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
//	// ��һ��������://�ֿ���
//	// �ڶ�������/
//
//	size_t pos1 = url.find("://");
//	if (pos1 == string::npos) // ���û�ҵ�://
//	{
//		cout << "�Ƿ�url" << endl;
//		return;
//	}
//	string protocol = url.substr(0, pos1); // ����:������5��λ�ã���Ϊ������0��ʼ����ô����pos1 - 0��ǰ��ĳ��Ⱦ���5
//	cout << protocol << endl;
//
//	// ����
//	size_t pos2 = url.find('/', pos1 + 3); // ��pos1+3��ʼ��/������c++������url��˵���Ǵ�c��ʼ��
//	if (pos2 == string::npos) // ���û�ҵ�/
//	{
//		cout << "�Ƿ�url" << endl;
//		return;
//	}
//	// ��ʼλ�þ���:λ�õ�+3������λ�þ�����һ��/
//	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3); // �����ĳ���
//	cout << domain << endl;
//
//	// uri����Դ��λ
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
//	// �Һ�׺ - ����ֱ���� .
//	// size_t pos = filename.find('.'); // Ĭ�ϴ�0��ʼ��
//
//	// ��������кܶ�.zip.cppʲô�ģ����Ҫȡ���һ����׺�أ�
//	// ��rfind��reverse find
//	size_t pos = filename.rfind('.');
//
//	if (pos != string::npos) // ���û���ҵ�.��npos������ľ�̬��Ա�������ǹ��еģ�������������������������ж���
//	{
//		// string suff = filename.substr(pos, filename.size() - pos); // ��������
//
//		string suff = filename.substr(pos); // Ĭ��ȡ������������Ҳ����
//		
//
//		cout << suff << endl;
//	}
//
//	string url1 = "https://cplusplus.com/search";
//	string url2 = "https://moodle.ucl.ac.uk/enrol/index.php?id=36510";
//
//	// ��Ҫ���������ֹ��ɣ�
//	/*
//	1.��Э����
//	���� https
//	2������
//	���� cplusplus.com
//	3��·���������
//	���� search
//	*/
//
//	// ��ΰ�url�ָ����������
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



// HJ1 �ַ������һ�����ʵĳ���

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
//	// size�����һ���ַ�����һ��λ��
//	// cin�������ַ�����ʱ���ǿո���߻����������
//	// �������һ�����汾����пո�cin�ͻ���Ϊ����ո��Ƕ��ֵ֮��ķָ�
//	// ����hello nowcoder��cin�����ֻ��hello��nowcoder�ڻ�����
//
//	if (pos != string::npos)
//	{
//		cout << str.size() - pos - 1 << endl;
//	}
//	// ����Ҳ����ո��ǳ��Ⱦ���size
//	else
//	{
//		cout << str.size() << endl;
//	}
//
//	return 0;
//}


// 387. �ַ����еĵ�һ��Ψһ�ַ�

// https://leetcode.cn/problems/first-unique-character-in-a-string/description/


//class Solution {
//public:
//	int firstUniqChar(string s) {
//		// ���ȣ�����һ������洢
//		int count[256] = { 0 };
//		int n = s.size();
//		// ͳ��ÿ���ַ����ֵĴ���
//		for (int i = 0; i < n; ++i)
//		{
//			count[s[i]] += 1;
//		}
//		// �����ַ������ǰ������ֻ����һ�ε��ַ�
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

// 125. ��֤���Ĵ�

// https://leetcode.cn/problems/valid-palindrome/description/


//class Solution {
//public:
//	// �ж��ǲ�����ĸ������
//	bool isLetterOrNumber(char ch)
//	{
//		return (ch >= '0' && ch <= '9')
//			|| (ch >= 'a' && ch <= 'z');
//	}
//	bool isPalindrome(string s) {
//
//		// �������ã����Կ��԰Ѵ�д�ַ�תСд
//		for (auto& ch : s)
//		{
//			if (ch >= 'A' && ch <= 'Z')
//			{
//				ch += 32; // ASCII�У���д��ĸ+32���Ƕ�Ӧ��Сд��ĸ
//			}
//		}
//
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin])) // �������ĸ���־�ͣ����
//			{
//				// ���������ĸ���־�����
//				++begin;
//			}
//			while (begin < end && !isLetterOrNumber(s[end])) // �������ĸ���־�ͣ����
//			{
//				// ���������ĸ���־�����
//				--end;
//			}
//			if (s[begin] == s[end])
//			{
//				// ��Ⱦͼ����Ƚ�
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