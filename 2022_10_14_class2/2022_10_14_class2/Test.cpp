#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	// 1.无参构造函数
//	Date()
//	{}
//
//	// 2.带参构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1; // 调用存在歧义/二义性
//	Date d2(2022, 7, 23);
//
//	return 0;
//}

//class Time
//{
//public:
//	//Time(int hour)
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	// 不写 默认生成构造函数
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//
//	//Time* _t;  // 指针都是内置类型
//	Time _t;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)* capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue {
//public:
//	void push(int x) {}
//	//...
//private:
//	size_t _size = 0;
//	Stack _st1;
//	Stack _st2;
//};
//
//int main()
//{
//	Date d1;
//	// MyQueue 用默认生成构造函数就挺好，不需要显示写
//	MyQueue q;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 不需要写，默认生成就够用。但是默认生成的也没做什么事情
//	//~Date()
//	//{
//	//	//~Date()没有什么需要清理
//	//	cout << "~Date()" << endl;
//	//}
//
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//// Queue
//// List
//// SeqList
//// BinaryTree
////...
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)* capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 需要显示写，手动明释放资源
//	~Stack()
//	{
//		cout << "~Stack()->" << _array << endl;
//		free(_array);
//		_capacity = _size = 0;
//		_array = nullptr;
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue {
//public:
//	void push(int x) {}
//	//...
//
//	// 不需要写，默认生成就够用。但是默认生成对于Stack自定义成员，调用Stack析构函数
//private:
//	size_t _size = 0;
//	Stack _st1;
//	Stack _st2;
//};
//
//void func()
//{
//	Date d;
//	Stack st;
//	MyQueue q;
//}
//
//int main()
//{
//	func();
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// 拷贝构造
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// Date d2(d1);
//	//Date(const Date& d)
//	//{
//	//	cout << "Date(Date& d)" << endl;
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//
//	//	/*d._year = _year;
//	//	d._month = _month;
//	//	d._day = _day;*/
//	//}
//
//	//Date(Date* d)
//	//{
//	//	cout << "Date(Date& d)" << endl;
//	//	_year = d->_year;
//	//	_month = d->_month;
//	//	_day = d->_day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// Queue
//// List
//// SeqList
//// BinaryTree
////...
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)* capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	// 拷贝构造需要自己实现深拷贝，-- 后面有一章节专门讲解
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 需要显示写，手动明释放资源
//	~Stack()
//	{
//		cout << "~Stack()->" << _array << endl;
//		free(_array);
//		_capacity = _size = 0;
//		_array = nullptr;
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue {
//public:
//	void push(int x) {}
//	//...
//private:
//	size_t _size = 0;
//	Stack _st1;
//	Stack _st2;
//};
//
//void get1(Date d)
//{}
//
//void get2(Date& d)
//{}
//
////void func()
////{
////	Date d0;
////	Date d1(2022, 7, 23);
////	//get1(d1);
////	//get2(d1);
////
////	Date d2(d1);
////	Date d3 = d1;
////
////	//Date d4(&d1);
////	//Date d5 = &d1;
////	int i = 0;
////	int j = i;
////
////	// 1 3 2 6 7 打印一下路径值
////	//Stack path;
////	//Stack copy(path);
////	//while (!copy.Empty())
////	//{
////	//	cout << copy.Top() << endl;
////	//	copy.Pop();
////	//}
////}
//
//void func()
//{
//	Date d1(2022, 7, 23);
//	Date d2(d1);
//
//	Stack st1;
//	Stack st2(st1);
//}
//
//int main()
//{
//	func();
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////
// 运算符重载
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//int GetYear()
//	//{
//	//	return _year;
//	//}
//
//	bool operator==(const Date& x)
//	{
//		return _year == x._year
//			&& _month == x._month
//			&& _day == x._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool DateEquel(Date x1, Date x2)
////bool func(Date x1, Date x2)
////bool riqixiangdeng(Date x1, Date x2)
////{
////	return x1._year == x2._year
////		&& x1._month == x2._month
////		&& x1._day == x2._day;
////}
//
////bool operator==(Date x1, Date x2)
////bool operator==(const Date& x1, const Date& x2)
////{
////	return x1._year == x2._year
////		&& x1._month == x2._month
////		&& x1._day == x2._day;
////}
//
////int operator-(Date x1, Date x2)
////{}
//
//int main()
//{
//	Date d1(2022, 7, 23);
//	Date d2(2022, 7, 24);
//
//	// 内置类型可以直接使用运算符运算，编译器知道要如何运算
//	// 自定义类型无法直接使用运算法，编译器也不知道要如何运算。想支持，自己实现运算符重载即可
//	//cout << operator==(d1,d2) << endl;
//	cout << d1.operator==(d2) << endl; // -> d1.operator==(&d1, d2)
//	cout << (d1 == d2) << endl;
//
//	//d1 < d2;
//	//d1++;
//	//d1 + 100;
//	//Date d3(20202, 10, 1);
//	//d3 - d2;
//
//	return 0;
//}
//


//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//int GetYear()
//	//{
//	//	return _year;
//	//}
//
//	bool operator==(const Date& x)
//	{
//		return _year == x._year
//			&& _month == x._month
//			&& _day == x._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//bool DateEquel(Date x1, Date x2)
//bool func(Date x1, Date x2)
//bool riqixiangdeng(Date x1, Date x2)
//{
//	return x1._year == x2._year
//		&& x1._month == x2._month
//		&& x1._day == x2._day;
//}

//bool operator==(Date x1, Date x2)
//bool operator==(const Date& x1, const Date& x2)
//{
//	return x1._year == x2._year
//		&& x1._month == x2._month
//		&& x1._day == x2._day;
//}

//int operator-(Date x1, Date x2)
//{}


class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		//if (month == 2 && IsLeapYear(year))
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return days[month];
		}
	}

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& x)
	{
		return _year == x._year
			&& _month == x._month
			&& _day == x._day;
	}

	bool operator<(const Date& x);
	bool operator>(const Date& x);
	bool operator>=(const Date& x);
	bool operator<=(const Date& x);
	bool operator!=(const Date& x);

	// d1 += 100;
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}

		return *this;
	}

	// d1 + 100;
	//Date operator+(int day)
	//{
	//	Date ret(*this);
	//	ret._day += day;
	//	while (ret._day > GetMonthDay(ret._year, ret._month))
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		++ret._month;
	//		if (ret._month == 13)
	//		{
	//			ret._month = 1;
	//			ret._year++;
	//		}
	//	}

	//	return ret;
	//}
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			++ret._month;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2022, 7, 23);
	Date d2(2022, 7, 24);
	d1 == d2;
	//d1 < d2;
	Date ret = d1 + 50;
	//Date ret(d1 + 50);
	d1 += 50;
	//d1++;

	/*int i = 10;
	i + 50;
	i += 50;*/

	//Date d3(20202, 10, 1);
	//d3 - d2;

	return 0;
}