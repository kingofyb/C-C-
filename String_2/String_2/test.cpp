#include<iostream>
#include<string>
#include<list>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello world");
	// Ҳ��������д��
	// string s2 = "hello world"; // ��ʽ����ת��

	cout << s1 << endl;
	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	// copy (2)	: string(const string & str);
	string s4(s2, 6, 5);
	cout << s4 << endl;

	// string (const string& str, size_t pos, size_t len = npos);
	// len�̵Ļ�ֱ�ӿ��������ں����ַ����ȵĻ��ж��ٿ�����
	string s5(s2, 6, 15);
	cout << s5 << endl;

	// ������������������Ĭ�Ͽ�����β
	string s6(s2, 6);
	cout << s6 << endl;

	string s7("hello world", 5); // ǰ���
	cout << s7 << endl;

	string s8(100, 'x'); // ����100��x
	cout << s8 << endl;
}

void test_string2()
{
	string s1;
	string s2 = "hello world"; // ���� + �������� -> �Ż� - ֱ�ӹ���

	// ��֧��
	s1 = s2;
	s1 = "xxxx"; // = ����ֵ
	s1 = 'y';
}

void test_string3()
{
	string s1("hello world");
	// ���Զ����λ�õ��ַ�
	cout << s1[0] << endl;

	// Ҳ����д
	s1[0] = 'x'; // ת���� s1.operator[](0)
	// ����������
	// 1�����ٿ���
	// 2���޸ķ��ض���
	//cout << s1[0] << endl;


	// char& operator[] (size_t pos); 
	// const char& operator[] (size_t pos) const;

	// Ҫ�����string��ÿ���ַ�+1
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	const string s2("world"); // �����޸�

	// s2[6]; // �ڲ�����Խ��(����)
	// at��operator []�Ĺ�����һ�µ� 
	// atԽ���Ժ����쳣

}

void test_string4()
{
	string s("hello");
	// �κ����͵ĵ������������Լ�������
	// iterator��ָ��һ�������ͣ��п��ܾ���ָ�룬Ҳ�п��ܲ���ָ��
	// ���������÷���ָ��һ��
	string::iterator it = s.begin(); // ���ص�һ���ַ�λ�õĵ�����
	while (it != s.end()) // ����ҿ���end�����һ��λ�õ���һ��λ�õĵ�����(\0) [)
	{
		// (*it)++; // ���Զ�Ҳ����д
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ����string��ϲ����iterator����Ϊ[]������
	// ��Ϊstring��vertor���������Ŀռ�(˳���)
	// list/map/set... ֻ���õ���������(����)
	// iterator����������ͨ�õķ��ʷ�ʽ�������÷�������

	// ��Χfor -- �Զ�����(++)���Զ��жϽ���
	for (auto ch : s) // ����ȡs�е�ÿ���ַ�����ֵ��ch
	{
		cout << ch << " ";
	}
	cout << endl;

	// ch��*it�Ŀ���������ch�ĸı䲻Ӱ��s
	// ���Ҫ�޸�s��Ҫ����ַ(������)
	//for (auto& ch : s) // ����ȡs�е�ÿ���ַ�����ֵ��ch
	//{
	//	++ch;
	//	cout << ch << " ";
	//}
	//cout << endl;

	list<int> lt(10, 1);
	// list<int>::iterator lit = lt.begin();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// ��Χfor�ĵײ���ʵ���ǵ�����

}

void PrintString(const string& str) // Ҫ�������Դ�ֵ���β���
{
	// constֻ�ܶ�����д
	// string::const_iterator it = str.begin();
	auto it = str.begin(); // Ҳ����дauto���Զ���
	while (it != str.end())
	{
		// *it = 'x';
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// ���� iterator ����
// iterator/const_iterator
// reverse_iterator/const_reverse_iterator

void test_string5()
{
	string s("hello");
	// �������
	// �ұ���
	string::reverse_iterator rit = s.rbegin(); // rend��-1,rbegin�����һ��Ԫ��
	while (rit != s.rend())
	{
		cout << *rit << " ";
		// ++�������
		++rit;
	}
	cout << endl;

	PrintString(s);
}

void test_string6()
{
	string s("hello");

	// �����ַ�
	s.push_back('-');
	s.push_back('-');
	s.append("world");
	cout << s << endl;

	// �����ã�+=�õ����
	string str("������");
	s += '@';
	s += str;
	s += "!!!";
	cout << s << endl; // hello--world@������!!!

	s.append(++str.begin(), --str.end()); // ��ѱ������
	cout << s << endl;

	//string copy(++s.begin(), --s.end()); // ��Ҫ��һ�������һ���ַ�
	//cout << copy << endl;


}

void test_string7()
{
	//// string����
	//string s1;
	//string s2("11111111");
	//cout << s1.max_size() << endl;
	//cout << s2.max_size() << endl;

	//cout << s1.capacity() << endl; // ������С
	//cout << s2.capacity() << endl;

	// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
	//====================================================================================

	string s;
	// ����˵֪��Ҫ��1000���ַ���������ǰreserve����(���ռ�)
	s.reserve(1000);
	// s.resize(1000); // ���ռ�+��ʼ��������ֵĬ�Ͼ���0

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n'; // ��û����\0�Ĵ���ռ䡣15���ܴ洢��Ч�ַ��Ŀռ�
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
		{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	test_string7();
	return 0;
}