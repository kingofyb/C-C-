#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Date.h"
using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)->" << _a << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()->" << _a <<endl;
//	}
//
//private:
//	int _a;
//};
//
//A aa3(3);
//
//void f()
//{
//	static int i = 0;
//	//�ȶ��������������������������aa2��aa1������
//	//aa2������ջ֡
//	static A aa0(0);
//	A aa1(1);
//	A aa2(2);
//	static A aa4(4);
//	//����˳�� 2->1->4->0->3
//}
//
//// ����˳��: 2 1 2 1 4 0 3
//// ����˳��: 3 0 1 2 4 1 2
//int main()
//{
//	f();
//	f();
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//	{
//      _a = a;
//		cout << "A(int a = 0)->" <<_a<< endl;
//	}
//
//	~A()
//	{
//		cout << "~A()->" <<_a<<endl;
//	}
//private:
//	int _a;
//};
//
//A aa3(3);
//
//void f()
//{
//	static int i = 0;
//	static A aa0(0);
//	A aa1(1);
//	A aa2(2);
//	static A aa4(4);
//}
//
//// ����˳��3 0 1 2 4 1 2
//// ����˳��~2 ~1 ~2 ~1 ~4 ~0 ~3
//int main()
//{
//	f();
//	f();
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a = 0)->" << _a << endl;
//	}
//
//	// A aa2(aa1);
//	A(const A& aa)
//	{
//		_a = aa._a;
//		cout << "A(const A& aa)->" << _a << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()->" << _a << endl;
//	}
//private:
//	int _a;
//};
//
//void func1(A aa)
//{
//
//}
//
//void func2(A& aa)
//{
//
//}
//
//A func3()
//{
//	static A aa(3);
//	return aa;
//}
//
//A& func4()
//{
//	static A aa(4);
//	return aa;
//}
//
//int main()
//{
//	//A aa1(1);
//	//A aa2(aa1);
//
//	//func1(aa1);
//	//func2(aa1);
//	func3();
//	cout << endl << endl;
//	func4();
//
//	//int i = 0;
//	//int& j = i;
//	//cout << typeid(j).name() << endl;
//
//	return 0;
//}

//#pragma once
//
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//
//	Time& operator=(const Time& t)
//	{
//		cout << "Time& operator=(const Time& t)" << endl;
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//
//		return *this;
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
//	// �����Ƶ�����ã�����ֱ�ӷ��������涨����Ϊinline
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// d1 = d3;
//	// d2 = d2;
//	//Date& operator=(const Date& d)
//	////Date operator=(const Date d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//
//	//	return *this;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	// �Զ�������
//	Time _t;
//};
//
//// ��Ϣ11:17����
//
//// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType *_array;
//	size_t _size;
//	size_t _capacity;
//};
//
//// ��Ӯ -- ���졢�������졢��ֵ���ء�����Ĭ�����ɶ�������
//class MyQueue
//{
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
//void Test()
//{
//	Date d1(2022, 7, 24);
//	Date d2(d1);
//
//	Date d3(2022, 8, 24);
//	d2 = d1 = d3; // d1.operator=(&d1, d3)
//	d2 = d2;
//
//	Stack st1;
//	Stack st2;
//	st2.Push(1);
//	st2.Push(2);
//	st1 = st2; // ʵ�������ֵ���
//
//	int i = 0, j = 1, k = 2;
//	k = i = j = 10;
//}

void TestDate1()
{
	Date d1(2022, 7, 24);
	Date d2(2022, 7, 25);
	Date d3(2021, 7, 25);

	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 == d3) << endl;
	cout << (d1 > d3) << endl;
}

void TestDate2()
{
	//Date d1(2022, 7, 24);
	//d1 += 4;
	//d1.Print();

	//d1 += 40; // ����
	//d1.Print();

	//d1 += 400;// ����
	//d1.Print();

	//d1 += 4000; // ������
	//d1.Print();

	Date d1(2022, 7, 24);
	/*Date d2 = d1 + 4;
	d2.Print();*/
	(d1 + 4).Print();
	(d1 + 40).Print();// ����
	(d1 + 400).Print();// ����
	(d1 + 4000).Print(); // ������
	(d1 + 40000).Print();

	Date ret1 = ++d1; // d1.operator++(&d1)
	Date ret2 = d1++; // d1.operator++(&d2, 0)
}

int main()
{
	TestDate2();

	return 0;
}