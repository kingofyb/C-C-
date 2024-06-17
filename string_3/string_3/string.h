#pragma once
// #include<iostream>
// using namespace std;
// ģ��ʵ��
namespace bit
{
	class string
	{
		// ����ֱ��:_str(str)����Ϊstr��const

		// ֻ�г�ʼ��һ����ó�ʼ���б�
		// ��������һ�㸳ֵ
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str; // ���ص�һ��λ��
		}
		iterator end()
		{
			return _str + _size; // �������һ��λ�õ���һ��λ�� 
		}

		// const�����ṩconst��������ֻ�ܶ�����д
		const_iterator begin() const
		{
			return _str; // ���ص�һ��λ��
		}
		const_iterator end() const
		{
			return _str + _size; // �������һ��λ�õ���һ��λ�� 
		}


		//string()
		//	:_str(new char[1])
		//	, _size(0)
		//	, _capacity(0) 
		//{
		//	_str[0] = '\0'; // ������һ���ն���Ҳ����һ��\0
		//}

		// string(const char* str = "\0") // ��������д�����е���һ��
		//string(const char* str = "") // ȫȱʡ�������и�Ĭ��������\0
		//	:_str(new char[strlen(str) + 1]) // strlen��Ч�� - O(N)
		//	, _size(strlen(str))
		//	, _capacity(strlen(str)) // _capacity�洢��Ч�ַ��Ŀռ䣬������\0
		//{
		//	strcpy(_str, str); // ��������
		//}

		// �Ƽ��ں�������
		// ���������˳��Ͳ�Ҫ�ó�ʼ���б�
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// ������ôд
		// ��Ϊ�ᰴ����˳���ʼ�������ȳ�ʼ��_str����ʱcapacity��һ�����ֵ
		//string(const char* str = "") // ȫȱʡ�������и�Ĭ��������\0
		//	: _size(strlen(str))
		//	, _capacity(_size) 
		//	, _str(new char[_capacity + 1])
		//{
		//	strcpy(_str, str); // ��������
		//}

		// stringҪ���
		// ָ���Լ��Ķ����ռ䣬Ȼ�󿽱�����
		// �����ͷź��޸Ķ������Լ��Ŀռ����
		// 
		// ����Ҫ�Լ�д��������
		// 
		// 
		// ��ͳд��
		// s2(s1)
		// this����s2��s2Ҫ��s1��һ����Ŀռ��ֵ��s����s1
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
		//	// �ͷ�s1�Ŀռ�
		//	// ��һ�θ�s3һ����Ŀռ䣬Ȼ�󿽱�s3�Ŀռ俽����ȥ��Ȼ��ָ���¿ռ�
		//	// size����Ҫ\0
		//	// ���ռ��ʱ��Ҫ+1

		//	// ����Լ��������Լ�
		//	if (this != &s)
		//	{
		//		// ����ռ������⣬�Ͳ����ƻ�ԭ�пռ�
		//		char* tmp = new char[s._capacity + 1]; // +1��\0׼��
		//		strcpy(tmp, s._str); // s����s3��this����s1

		//		delete[] _str;

		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	// �Լ������Լ�ֱ�ӷ���
		//	return *this;
		//}


		// �ִ�д�� -- �ʱ�����/�ϰ�˼ά
		// s2(s1)

		void swap(string& tmp)
		{
			// ������õ���ȫ�ֵ�swap
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
			swap(tmp); // ��ʵ����this->swap(tmp);
		}

		// s1 = s3
		// ���ܼ�
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		// ������
		//		string tmp(s._str);
		//		// ����������
		//		// string tmp(s)
		//		swap(tmp); // this->swap(tmp); // this����s1
		//	}	
		//	return *this;
		//}

		// �򻯺� - ֱ�Ӵ�ֵ����
		// s1 = s3
		// s����tmp��������
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

		// const����ֻ�ܶ�
		char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		// ��ͨ����ɶ���д
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// ��������������ݵ�
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // �����µ��ڴ�ռ�
				strcpy(tmp, _str); // �����ַ������ݿ��������ڴ�ռ�
				delete[] _str; // �ͷžɵ��ڴ�ռ�

				_str = tmp; // ����ָ�����ڴ�ռ��ָ��
				_capacity = n; // ��������

			}
		}

		// ���ռ�+��ʼ��
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



		// �ڶ�̬�ַ����������ƵĶ�̬���飩�����һ���ַ������ڱ�Ҫʱ��չ�洢�ռ䡣
		void push_back(char ch)
		{
			//// ���˾�����
			//if (_size == _capacity)
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2); // ���ȱʡֵΪ0����Ϊ4����Ϊ0��*2
			//}
			//_str[_size] = ch; // �ڵ�ǰ��Сλ��������ַ�
			//++_size; // ���Ӵ�С����
			//// ����\0
			//_str[_size] = '\0'; // ���µ�λ������ַ�����ֹ��

			// ����ֱ����insert
			insert(_size, ch);
		}


		void append(const char* str)
		{
			//size_t len = strlen(str);

			//// ���˾�����
			//// _size�����е��ַ�����
			//// len�����е�+Ҫ����ģ�������Ҫ�ģ�

			//// _size + len   
			//// ����
			//// 
			////    8      18      10   10 < 26 ���ٿ�26
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}

			//// ��һ���ַ���ʱ����str��ÿһ���ַ����ο�����ȥ���Լ�\0
			//// strcat(_str, str); // Ҳ�У�strcat�Ǵ�\0��ʼ׷�ӣ������˷�\0��ֱ�ӻ��ԭ����\0���ǵ�
			//// strcat������������\0��Ч�ʵͣ�ʵ�ʵ����ܲ��þͲ���
			//strcpy(_str + _size, str); // copy����ʼλ����_str+_size

			//// �ٰ�size�ƶ������
			//_size += len;

			// ����ֱ�Ӹ���insert
			insert(_size, str);
		}

		// �������ṩ��� -- �������أ����������������õ���
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


		// Ҫ֧��������+=�������Լ���������������ڣ�����������
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

			// ���˾�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2); // 
			}

			//// Ų������
			// // �������λ��Ϊ0��������
			//size_t end = _size;
			//// ����ͼ
			//while (end >= pos)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			// Ų������
			// �Ƽ�
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
			assert(pos <= _size); // <= ����β��
			size_t len = strlen(str);
			// ����
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// Ų������
			size_t end = _size + len;
			while (end >= pos + len) // ���� while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			// ������strcpy����Ϊ���\0������
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		// ģ��string��03:09:00
		void erase(size_t pos, size_t len = npos) // npos���ǲ����Ļ�Ĭ��ɾ��
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


		// ���Ӵ�
		// "hello world bit"
		size_t find(const char* sub, size_t pos = 0) const
		{
			// ֱ����c���������strstr
			// ������kmp/bm�㷨
			const char* ptr = strstr(_str + pos, sub);
			// ���û���ҵ�ƥ����Ӵ�
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str; // ptr��ȥ��ʼλ��
			}
		}

		// "hello world bit"
		string substr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);

			// pos������ʼλ��
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

		// ����ֱ�Ӹ���
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

		// static size_t npos = -1; // ��̬�Ļ��������������ȱʡ
		// ���Ǽ�const�Ϳ���
		// const static C++���⴦��
		// ֱ�ӿ��Ե��ɶ����ʼ��
	public:
		const static size_t npos = -1;
	};

	// �����������������涨��
	// size_t string::npos = -1;


	// ���Ǳ�������ԭ����Ϊ���÷���˽��
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
	//	// �����ַ����ܳ�������+=��Ƶ�����ݣ�Ч�ʺܵͣ�Ҫ��취�Ż�һ��
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

		// �����ַ����ܳ�������+=��Ƶ�����ݣ�Ч�ʺܵͣ�Ҫ��취�Ż�һ��
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

		// �ɶ���д
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
			// ��������ӡ
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			// ��������ӡ
			*it += 1;
			++it;
		}
		cout << endl;

		// ch�൱�ھ��ǰ�*it��s1
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

		s1.swap(s2); // ֱ�ӽ����ڲ��ĳ�Ա����(�õ���bit������Ǹ�swap)
		//swap(s1, s2); // ���ۺܴ󣬿ռ䶼û�ˣ�����������࣬һ�㲻�����
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
		cout << s1.capacity() << endl; // �鿴�Ƿ�����

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
		cout << s1.c_str() << endl; // �����heworldllo

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
