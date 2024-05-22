#include<iostream>
#include<cstdlib>
#include<assert.h>
using namespace std;
// 构造函数 - 初始化工作 Constructor
//class Time
//{
//public:
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
//private:
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//
//	Time _t;
//};
//
////class Date
////{
////public:
////	// 1.无参构造函数
////	Date()
////	{
////		_year = 1900;
////		_month = 1;
////		_day = 1;
////	}
////	// 2.带参构造函数
////	Date(int year, int month , int day)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////void TestDate()
////{
////	Date d1; // 调用无参构造函数
////	Date d2(2015, 1, 1); // 调用带参的构造函数
////	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
////	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
////	// warning C4930: “Date d3(void)”: 未调用原型函数(是否是有意用变量定义的?)
////	Date d3();
////}
//
//
//
//class User
//{
//public:
//	// 1.无参构造函数
//	User()
//	{
//
//	}
//	// 2.带参构造函数
//	User(string name, int height, int weight)
//	{
//		_name = name;
//		_height = height;
//		_weight = weight;
//	}
//	void print()
//	{
//		cout << _name << " - " << _height << "cm - " << _weight << "kg" << endl;
//	}
//private:
//	string _name;
//	int _height;
//	int _weight;
//};
//
// 
// // 232. 用栈实现队列
// https://leetcode.cn/problems/implement-queue-using-stacks/description/
//
//class MyQueue {
//public:
//
//	void push(int x)
//	{
//
//	}
//
//private:
//	Stack _st1;
//	Stack _st2;
//
//};
////**************************************************************************************************************
////**************************************************************************************************************
////**************************************************************************************************************
//
//// 析构函数 - 清理工作 Destructor
typedef int datatype;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (datatype*)malloc(sizeof(datatype) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void push(datatype data)
	{
		// checkcapacity();
		_array[_size] = data;
		_size++;
	}

	// 栈需要析构
	~Stack()
	{
		free(_array);
		_capacity = _size = 0;
		_array = nullptr;
	}
private:
	datatype* _array;
	int _capacity;
	int _size;
};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	
	//// 析构函数，~按位取反，！逻辑取反，跟构造函数constructor相反
	//~Date()
	//{
	//	//~Date()没有什么需要清理
	//	cout << "~Date()" << endl;
	//}
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};

void func()
{
	Date d1;
	Stack st;
}


int main()
{
	//// constructor
	//User s1;
	//User s2("laoma", 120, 30);
	//s2.print();

	//Date d;

	//// MyQueue 用默认生成的构造函数就挺好，不需要显示写
	func();

	return 0;
}
// 构造函数 - 初始化工作 Constructor
// 析构函数 - 清理工作 Destructor
// 拷贝构造 - 同类对象初始化创建对象
// 赋值重载 - 把一个对象赋值给另一个对象 Overloading
//