#include<iostream>
using namespace std;

// 拷贝构造函数：只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存在的类类型
// 对象创建新对象时由编译器自动调用。

//拷贝构造函数也是特殊的成员函数，其特征如下：
//1. 拷贝构造函数是构造函数的一个重载形式。
//2. 拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，因为会引发
//无穷递归调用。

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d); // 正确写法
//	// 错误写法：编译报错，会引发无穷递归
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class Time
{
public:
	Time()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;
	}
	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
		cout << "Time::Time(const Time&)" << endl;
	}


private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:

	// 进本类型（内置类型）
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	Time _t;
};


int main()
{
	Date d1;

	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
	// 但Date类并没有显示定义拷贝函数，则编译器会给Date类生成一个默认的拷贝构造函数
	Date d2(d1);
	return 0;
}