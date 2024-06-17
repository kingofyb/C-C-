#pragma once
// #include<iostream>
// using namespace std;
// 模拟实现
namespace bit
{
	class string
	{
		// 不能直接:_str(str)，因为str是const

		// 只有初始化一般才用初始化列表
		// 正常函数一般赋值
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str; // 返回第一个位置
		}
		iterator end()
		{
			return _str + _size; // 返回最后一个位置的下一个位置 
		}

		// const对象提供const迭代器，只能读不能写
		const_iterator begin() const
		{
			return _str; // 返回第一个位置
		}
		const_iterator end() const
		{
			return _str + _size; // 返回最后一个位置的下一个位置 
		}


		//string()
		//	:_str(new char[1])
		//	, _size(0)
		//	, _capacity(0) 
		//{
		//	_str[0] = '\0'; // 哪怕是一个空对象也会有一个\0
		//}

		// string(const char* str = "\0") // 可以这样写，但有点多此一举
		//string(const char* str = "") // 全缺省，里面有个默认隐含的\0
		//	:_str(new char[strlen(str) + 1]) // strlen的效率 - O(N)
		//	, _size(strlen(str))
		//	, _capacity(strlen(str)) // _capacity存储有效字符的空间，不包含\0
		//{
		//	strcpy(_str, str); // 拷贝构造
		//}

		// 推荐在函数体内
		// 如果有依赖顺序就不要用初始化列表
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// 不能这么写
		// 因为会按声明顺序初始化，会先初始化_str，这时capacity是一个随机值
		//string(const char* str = "") // 全缺省，里面有个默认隐含的\0
		//	: _size(strlen(str))
		//	, _capacity(_size) 
		//	, _str(new char[_capacity + 1])
		//{
		//	strcpy(_str, str); // 拷贝构造
		//}

		// string要深拷贝
		// 指向自己的独立空间，然后拷贝数据
		// 这样释放和修改都会在自己的空间进行
		// 
		// 所以要自己写拷贝构造
		// 
		// 
		// 传统写法
		// s2(s1)
		// this就是s2，s2要和s1有一样大的空间和值，s就是s1
		//string(const string& s)
		//	: _str(new char[s._capacity+1])
		//	, _size(s._size)
		//	, _capacity(s._capacity)
		//{
		//	strcpy(_str, s._str);
		//}

		//// s1 = s3
		//// s1 = s1
		//string& operator=(const string& s)
		//{
		//	// 释放s1的空间
		//	// 开一段跟s3一样大的空间，然后拷贝s3的空间拷贝过去，然后指向新空间
		//	// size不需要\0
		//	// 开空间的时候要+1

		//	// 如果自己不等于自己
		//	if (this != &s)
		//	{
		//		// 如果空间有问题，就不会破坏原有空间
		//		char* tmp = new char[s._capacity + 1]; // +1给\0准备
		//		strcpy(tmp, s._str); // s就是s3，this就是s1

		//		delete[] _str;

		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	// 自己等于自己直接返回
		//	return *this;
		//}


		// 现代写法 -- 资本主义/老板思维
		// s2(s1)

		void swap(string& tmp)
		{
			// 这里调用的是全局的swap
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}

		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp); // 其实就是this->swap(tmp);
		}

		// s1 = s3
		// 还能简化
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		// 调构造
		//		string tmp(s._str);
		//		// 调拷贝构造
		//		// string tmp(s)
		//		swap(tmp); // this->swap(tmp); // this就是s1
		//	}	
		//	return *this;
		//}

		// 简化后 - 直接传值传参
		// s1 = s3
		// s顶替tmp，做打工人
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		// const对象只能读
		char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		// 普通对象可读可写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// 这个函数帮助扩容等
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // 分配新的内存空间
				strcpy(tmp, _str); // 将旧字符串内容拷贝到新内存空间
				delete[] _str; // 释放旧的内存空间

				_str = tmp; // 更新指向新内存空间的指针
				_capacity = n; // 更新容量

			}
		}

		// 开空间+初始化
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = ch;
					++_size;
				}

				_str[_size] = '\0';
			}
		}



		// 在动态字符串（或类似的动态数组）中添加一个字符，并在必要时扩展存储空间。
		void push_back(char ch)
		{
			//// 满了就扩容
			//if (_size == _capacity)
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2); // 如果缺省值为0就设为4，不为0就*2
			//}
			//_str[_size] = ch; // 在当前大小位置添加新字符
			//++_size; // 增加大小计数
			//// 处理\0
			//_str[_size] = '\0'; // 在新的位置添加字符串终止符

			// 可以直接用insert
			insert(_size, ch);
		}


		void append(const char* str)
		{
			//size_t len = strlen(str);

			//// 满了就扩容
			//// _size是现有的字符数量
			//// len是现有的+要插入的（现在需要的）

			//// _size + len   
			//// 假设
			//// 
			////    8      18      10   10 < 26 至少开26
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}

			//// 加一个字符串时，把str的每一个字符依次拷贝过去。以及\0
			//// strcat(_str, str); // 也行，strcat是从\0开始追加，不会浪费\0，直接会把原来的\0覆盖掉
			//// strcat最大的问题是找\0，效率低，实际当中能不用就不用
			//strcpy(_str + _size, str); // copy的起始位置是_str+_size

			//// 再把size移动到最后
			//_size += len;

			// 可以直接复用insert
			insert(_size, str);
		}

		// 都不用提供这个 -- 函数重载，并且下面这两个用的少
		void append(const string& s)
		{
			append(s._str);
		}

		void append(size_t n, char ch)
		{
			reserve(_size + n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(ch);
			}

		}


		// 要支持连续的+=，返回自己这个对象，作用域还在，所以用引用
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{

			assert(pos <= _size);

			// 满了就扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2); // 
			}

			//// 挪动数据
			// // 如果插入位置为0就有问题
			//size_t end = _size;
			//// 看截图
			//while (end >= pos)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			// 挪动数据
			// 推荐
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size); // <= 就是尾插
			size_t len = strlen(str);
			// 扩容
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			size_t end = _size + len;
			while (end >= pos + len) // 或者 while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			// 不能用strcpy，因为会把\0拷进来
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		// 模拟string的03:09:00
		void erase(size_t pos, size_t len = npos) // npos就是不传的话默认删完
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}


		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}


		// 找子串
		// "hello world bit"
		size_t find(const char* sub, size_t pos = 0) const
		{
			// 直接用c语言里面的strstr
			// 可以用kmp/bm算法
			const char* ptr = strstr(_str + pos, sub);
			// 如果没有找到匹配的子串
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str; // ptr减去初始位置
			}
		}

		// "hello world bit"
		string substr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);

			// pos就是起始位置
			size_t realLen = len;
			if (len == npos || pos + len > _size)
			{
				realLen = _size - pos;
			}

			string sub;
			for (size_t i = 0; i < realLen; ++i)
			{
				sub += _str[pos + i];
			}
			return sub;
		}

		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}


		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		// 后面直接复用
		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		//static size_t npos;

		// static size_t npos = -1; // 静态的话不能在类里面给缺省
		// 但是加const就可以
		// const static C++特殊处理
		// 直接可以当成定义初始化
	public:
		const static size_t npos = -1;
	};

	// 类里面声明，类外面定义
	// size_t string::npos = -1;


	// 不是必须是友原，因为不用访问私有
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}

	//istream& operator>>(istream& in, string& s)
	//{
	//	// 输入字符串很长，不断+=，频繁扩容，效率很低，要想办法优化一下
	//	char ch;
	//	// in >> ch;
	//	ch = in.get();

	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}
	//	return in;
	//}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		// 输入字符串很长，不断+=，频繁扩容，效率很低，要想办法优化一下
		char ch;
		ch = in.get();

		const size_t N = 128;
		char buff[N];
		size_t i = 0;

		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	void test_string1()
	{
		string s1("hello world");
		string s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		// 可读可写
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}
		cout << endl;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			// 迭代器打印
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			// 迭代器打印
			*it += 1;
			++it;
		}
		cout << endl;

		// ch相当于就是把*it给s1
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void test_string3()
	{
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s2[0] = 'x';
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("111111111111111111111");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

		s1 = s1;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		string s2("xxxxxxxxx");

		s1.swap(s2); // 直接交换内部的成员变量(用的是bit里面的那个swap)
		//swap(s1, s2); // 代价很大，空间都没了，对于深拷贝的类，一般不用这个
	}
	void test_string5()
	{
		string s1("hello");
		cout << s1.c_str() << endl;
		s1.push_back('x');
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl;

		s1 += 'x';
		s1 += 'y';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		s1 += 'z';
		cout << s1.c_str() << endl;
		cout << s1.capacity() << endl; // 查看是否扩容

	}


	void test_string6()
	{
		string s1("hello");
		cout << s1.c_str() << endl;

		s1 += ' ';
		s1.append("world");
		s1 += " bit hello";
		cout << s1.c_str() << endl;

		s1.insert(5, '#');
		cout << s1.c_str() << endl;

		s1.insert(0, '#');
		cout << s1.c_str() << endl;
	}

	void test_string7()
	{
		string s1("hello");
		cout << s1.c_str() << endl;

		s1.insert(2, "world");
		cout << s1.c_str() << endl; // 输出：heworldllo

		s1.insert(0, "world");
		cout << s1.c_str() << endl; // worldheworldllo
	}

	void test_string8()
	{
		string s1("hello");
		s1.erase(1, 10);
		cout << s1.c_str() << endl; // h

		string s2("hello");
		s2.erase(1);
		cout << s2.c_str() << endl; // h

		string s3("hello");
		s3.erase(1, 2);
		cout << s3.c_str() << endl; // hlo
	}


	void test_string9()
	{
		string s1("hello");
		cout << s1 << endl; // operator<<(cout,s1)
		cout << s1.c_str() << endl;

		s1 += '\0';
		s1 += "world";
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		string s3, s4;
		cin >> s3 >> s4;
		cout << s3 << "---" << s4 << endl;
	}

	void test_string10()
	{
		std::string s1;
		s1.resize(20);

		std::string s2("hello");
		s1.resize(20, 'x');

		s2.resize(10);
	}
}
