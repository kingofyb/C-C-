#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

// �κ�һ���ֻ࣬��Ҫдһ��> == ���� < ==���� ʣ�±Ƚ���������ظ��ü���
bool Date::operator== (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// d1 != d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

// d1 > d2
bool Date::operator>(const Date& d)
{
	if ((_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>=(const Date& d)
{
	return (*this > d) || (*this == d);
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 + 100
Date Date::operator+(int day)
{
	//Date ret(*this);
	Date ret = *this;
	ret += day;

	return ret;
}

// d2 += d1 += 100
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//Date Date::operator+(int day)
//{
//	Date ret = *this;
//	// ...
//	ret._day += day;
//	while (ret._day > GetMonthDay(ret._year, ret._month))
//	{
//		//...
//	}
//
//	return ret;
//}
//
//// d1 += 100
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//
//	return *this;
//}

Date& Date::operator++() // ǰ��
{
	//*this += 1;
	//return *this;

	return *this += 1;
}

Date Date::operator++(int) // ����
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}