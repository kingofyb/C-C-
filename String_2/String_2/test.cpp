#include<iostream>
#include<string>
#include<list>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello world");
	// 也可以这样写：
	// string s2 = "hello world"; // 隐式类型转换

	cout << s1 << endl;
	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	// copy (2)	: string(const string & str);
	string s4(s2, 6, 5);
	cout << s4 << endl;

	// string (const string& str, size_t pos, size_t len = npos);
	// len短的话直接拷贝，大于后面字符长度的话有多少拷多少
	string s5(s2, 6, 15);
	cout << s5 << endl;

	// 不给第三个参数就是默认拷到结尾
	string s6(s2, 6);
	cout << s6 << endl;

	string s7("hello world", 5); // 前五个
	cout << s7 << endl;

	string s8(100, 'x'); // 构造100个x
	cout << s8 << endl;
}

void test_string2()
{
	string s1;
	string s2 = "hello world"; // 构造 + 拷贝构造 -> 优化 - 直接构造

	// 都支持
	s1 = s2;
	s1 = "xxxx"; // = 调赋值
	s1 = 'y';
}

void test_string3()
{
	string s1("hello world");
	// 可以读这个位置的字符
	cout << s1[0] << endl;

	// 也可以写
	s1[0] = 'x'; // 转换成 s1.operator[](0)
	// 引用做返回
	// 1、减少拷贝
	// 2、修改返回对象
	//cout << s1[0] << endl;


	// char& operator[] (size_t pos); 
	// const char& operator[] (size_t pos) const;

	// 要求遍历string，每个字符+1
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	cout << s1 << endl;

	const string s2("world"); // 不能修改

	// s2[6]; // 内部会检查越界(断言)
	// at跟operator []的功能是一致的 
	// at越界以后抛异常

}

void test_string4()
{
	string s("hello");
	// 任何类型的迭代器都属于自己的类域
	// iterator像指针一样的类型，有可能就是指针，也有可能不是指针
	// 但是它的用法像指针一样
	string::iterator it = s.begin(); // 返回第一个字符位置的迭代器
	while (it != s.end()) // 左闭右开，end是最后一个位置的下一个位置的迭代器(\0) [)
	{
		// (*it)++; // 可以读也可以写
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 但是string不喜欢用iterator，因为[]更好用
	// 因为string和vertor都是连续的空间(顺序表)
	// list/map/set... 只能用迭代器访问(链表)
	// iterator是所有容器通用的访问方式，并且用法都类似

	// 范围for -- 自动迭代(++)，自动判断结束
	for (auto ch : s) // 依次取s中的每个字符，赋值给ch
	{
		cout << ch << " ";
	}
	cout << endl;

	// ch是*it的拷贝，所以ch的改变不影响s
	// 如果要修改s，要传地址(加引用)
	//for (auto& ch : s) // 依次取s中的每个字符，赋值给ch
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

	// 范围for的底层其实就是迭代器

}

void PrintString(const string& str) // 要拷贝所以传值传参不好
{
	// const只能读不能写
	// string::const_iterator it = str.begin();
	auto it = str.begin(); // 也可以写auto，自动推
	while (it != str.end())
	{
		// *it = 'x';
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// 四种 iterator 类型
// iterator/const_iterator
// reverse_iterator/const_reverse_iterator

void test_string5()
{
	string s("hello");
	// 反向遍历
	// 右闭左开
	string::reverse_iterator rit = s.rbegin(); // rend在-1,rbegin在最后一个元素
	while (rit != s.rend())
	{
		cout << *rit << " ";
		// ++朝左边走
		++rit;
	}
	cout << endl;

	PrintString(s);
}

void test_string6()
{
	string s("hello");

	// 插入字符
	s.push_back('-');
	s.push_back('-');
	s.append("world");
	cout << s << endl;

	// 更好用，+=用的最多
	string str("我来了");
	s += '@';
	s += str;
	s += "!!!";
	cout << s << endl; // hello--world@我来了!!!

	s.append(++str.begin(), --str.end()); // 会把编码打乱
	cout << s << endl;

	//string copy(++s.begin(), --s.end()); // 不要第一个和最后一个字符
	//cout << copy << endl;


}

void test_string7()
{
	//// string增容
	//string s1;
	//string s2("11111111");
	//cout << s1.max_size() << endl;
	//cout << s2.max_size() << endl;

	//cout << s1.capacity() << endl; // 容量大小
	//cout << s2.capacity() << endl;

	// 利用reserve提高插入数据的效率，避免增容带来的开销
	//====================================================================================

	string s;
	// 比如说知道要用1000个字符，可以提前reserve保留(开空间)
	s.reserve(1000);
	// s.resize(1000); // 开空间+初始化，不给值默认就是0

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n'; // 但没有算\0的储存空间。15个能存储有效字符的空间
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