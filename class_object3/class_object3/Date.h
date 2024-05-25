#pragma once

// һ���ൽ�׿���������Щ������� ��> ��Щ��������������������
class Date
{
public:

	void Print();

	// ��ȡĳ��ĳ�µ�����
	// ��������ᱻƵ���ĵ��ã�����inline��������棩
	int GetMonthDay(int year, int month)
	{
		// static����������Ͳ���һֱ��ʼ���ģ���һ�ξͳ�ʼ�������Կ�������Ч��
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

	// ���캯����Ƶ���ĵ��ã�����ֱ�ӷ��������涨�壬��Ϊinline
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// d1 = d3;
	// d3����ı�
	//Date& operator = (const Date& d) // ���d����d3�������÷���
	//{
	//	//cout << "Date(const Date& d)" << endl;
	//	if (this != &d) // d2 = d2
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this; // this�ǵ�ַ��*this��d1
	//}

	// ����
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

	// ֱ�Ӱ��������أ��޷�����
	// ���⴦��ʹ���������֣�����++��������һ��int������ǰ�ù��ɺ������ؽ�������
	Date& operator++(); // ǰ��
	Date operator++(int); // ����

	// d1 - 100
	Date operator-(int day);
	Date& operator-=(int day);

	// ֱ�Ӱ��������أ��޷�����
	// ���⴦��ʹ���������֣�����++��������һ��int������ǰ�ù��ɺ������ؽ�������
	Date& operator--(); // ǰ��
	Date operator--(int); // ����

	// d1 - d2
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};