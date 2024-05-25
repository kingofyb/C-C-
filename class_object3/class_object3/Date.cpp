#include"Date.h"
#include<iostream>
using namespace std;

// �κ�һ���ֻ࣬��Ҫдһ��>= ���� <= ���أ�ʣ�µıȽ���������ظ��ü���

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
		|| (_year == d._year && _month == d._month && _day > d._day)) // ���
	{
		return true;
	}
	//else if (_year == d._year && _month > d._month) // ��һ���Ƚ���
	//{
	//	return true;
	//}
	//else if (_year == d._year && _month == d._month && _day > d._day) // ������ȱȽ���
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
	//Date ret = *this; // Ҳ�ǿ�������
	Date ret(*this); // ��������
	ret += day;

	return ret;
}

// d2 += d1 += 100
Date& Date::operator+=(int day) 
{
	_day += day;
	while (_day > GetMonthDay(_year, _month)) // ���day������month��year�ķ�Χ
	{
		_day -= GetMonthDay(_year, _month);
		++_month;

		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this; // ���������������÷��أ���Ϊ���ص����Լ�this
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

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