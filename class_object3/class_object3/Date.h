#pragma once

// 一个类到底可以重载哪些运算符呢 —> 哪些运算符对这个类型有意义
class Date
{
public:

	void Print();

	// 获取某年某月的天数
	// 这个函数会被频繁的调用，所以inline（类的里面）
	int GetMonthDay(int year, int month)
	{
		// static，后面进来就不会一直初始化的，第一次就初始化，所以可以提升效率
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

	// 构造函数会频繁的调用，所以直接放在类里面定义，作为inline
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// d1 = d3;
	// d3不会改变
	//Date& operator = (const Date& d) // 这个d就是d3，传引用返回
	//{
	//	//cout << "Date(const Date& d)" << endl;
	//	if (this != &d) // d2 = d2
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this; // this是地址，*this是d1
	//}

	// 声明
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);
	Date& operator+=(int day);

	// ++d1;
	// d1++;

	// 直接按特性重载，无法区分
	// 特殊处理，使用重载区分，后置++重载增加一个int参数根前置构成函数重载进行区分
	Date& operator++(); // 前置
	Date operator++(int); // 后置

	// d1 - 100
	Date operator-(int day);
	Date& operator-=(int day);

	// 直接按特性重载，无法区分
	// 特殊处理，使用重载区分，后置++重载增加一个int参数根前置构成函数重载进行区分
	Date& operator--(); // 前置
	Date operator--(int); // 后置

	// d1 - d2
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};