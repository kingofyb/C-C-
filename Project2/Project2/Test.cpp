#include<iostream>
using namespace std;

// �������캯����ֻ�е����βΣ����β��ǶԱ������Ͷ��������(һ�㳣��const����)�������Ѵ��ڵ�������
// ���󴴽��¶���ʱ�ɱ������Զ����á�

//�������캯��Ҳ������ĳ�Ա���������������£�
//1. �������캯���ǹ��캯����һ��������ʽ��
//2. �������캯���Ĳ���ֻ��һ���ұ����������Ͷ�������ã�ʹ�ô�ֵ��ʽ������ֱ�ӱ�����Ϊ������
//����ݹ���á�

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
//	Date(const Date& d); // ��ȷд��
//	// ����д�������뱨������������ݹ�
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

	// �������ͣ��������ͣ�
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	// �Զ�������
	Time _t;
};


int main()
{
	Date d1;

	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
	// ��Date�ಢû����ʾ���忽������������������Date������һ��Ĭ�ϵĿ������캯��
	Date d2(d1);
	return 0;
}