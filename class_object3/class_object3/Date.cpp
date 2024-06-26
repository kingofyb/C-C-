#include"Date.h"
#include<iostream>
using namespace std;

// 任何一个类，只需要写一个>= 或者 <= 重载，剩下的比较运算符重载复用即可

// d1 = d2
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}	

// d1 != d2
bool Date::operator!=(const Date& d)
{
	//return _year != d._year
	//	&& _month != d._month
	//	&& _day != d._day;
	return !(*this == d);
}

// d1 > d2
bool Date::operator>(const Date& d)
{
	if (_year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day)) // 年大
	{
		return true;
	}
	//else if (_year == d._year && _month > d._month) // 年一样比较月
	//{
	//	return true;
	//}
	//else if (_year == d._year && _month == d._month && _day > d._day) // 年月相等比较天
	//{
	//	return true;
	//}
	else
	{
		return false;
	}
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

// d1 < d2
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

// d1 <= d2
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 + 100
Date Date::operator+(int day)
{
	//Date ret = *this; // 也是拷贝构造
	Date ret(*this); // 拷贝构造
	ret += day;

	return ret;
}

// d2 += d1 += 100
Date& Date::operator+=(int day) 
{
	_day += day;
	while (_day > GetMonthDay(_year, _month)) // 如果day超过了month或year的范围
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this; // 出了作用域用引用返回，因为返回的是自己this
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

Date& Date::operator++() // 前置
{
	//*this += 1;
	//return *this;

	return *this += 1;
}
Date Date::operator++(int) // 后置
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}