#include<iostream>
#include<cstdlib>
#include<assert.h>
using namespace std;
// ���캯�� - ��ʼ������ Constructor
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
////	// 1.�޲ι��캯��
////	Date()
////	{
////		_year = 1900;
////		_month = 1;
////		_day = 1;
////	}
////	// 2.���ι��캯��
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
////	Date d1; // �����޲ι��캯��
////	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
////	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
////	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
////	// warning C4930: ��Date d3(void)��: δ����ԭ�ͺ���(�Ƿ��������ñ��������?)
////	Date d3();
////}
//
//
//
//class User
//{
//public:
//	// 1.�޲ι��캯��
//	User()
//	{
//
//	}
//	// 2.���ι��캯��
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
// // 232. ��ջʵ�ֶ���
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
//// �������� - ������ Destructor
typedef int datatype;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (datatype*)malloc(sizeof(datatype) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��");
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

	// ջ��Ҫ����
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

	
	//// ����������~��λȡ�������߼�ȡ���������캯��constructor�෴
	//~Date()
	//{
	//	//~Date()û��ʲô��Ҫ����
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

	//// MyQueue ��Ĭ�����ɵĹ��캯����ͦ�ã�����Ҫ��ʾд
	func();

	return 0;
}
// ���캯�� - ��ʼ������ Constructor
// �������� - ������ Destructor
// �������� - ͬ������ʼ����������
// ��ֵ���� - ��һ������ֵ����һ������ Overloading
//