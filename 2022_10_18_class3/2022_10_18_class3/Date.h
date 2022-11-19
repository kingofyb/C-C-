#pragma once

#include<iostream>
using namespace std;


// 一个到底可以重载哪些运算符？-》哪些运算符对这个类型有意义
class Date
{
public:
	// 获取某年某月的天数
	// 会频繁调用，所以直接放在类里面定义作为inline
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}

		return day;
	}

	// 构造会频繁调用，所以直接放在类里面定义作为inline
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print();

	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);
	Date& operator+=(int day);

	// ++d1;
	// d1++;
	// 直接按特性重载，无法区分
	// 特殊处理，使用重载区分，后置++重载增加一个int参数跟前置构成函数重载进行区分
	Date& operator++(); // 前置
	Date operator++(int); // 后置

private:
	int _year;
	int _month;
	int _day;
};
