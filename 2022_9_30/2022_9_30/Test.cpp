#define _CRT_SECURE_NO_WARNINGS 1

#include "Person.h"

//int main()
//{
//	cout << "static size:" << &size << endl;
//	cout << "age:" << &age << endl;
//
//	//cout << sizeof(Person) << endl;
//
//	Person p1; // ���ʵ����
//	Person p2;
//	Person p3;
//	p1.PrintPersonInfo();
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void func()
//	{
//		cout << "void A::func()" << endl;
//	}
////private:
//	char _a;
//};
//
//int main()
//{
//	//cout << sizeof(A) << endl;
//	/*A aa1;
//	A aa2;
//	aa1._a = 1;
//	aa2._a = 2;
//	aa1.PrintA();
//	aa2.PrintA();*/
//
//	// ����  ���뱨�� ��������
//	A* ptr = nullptr;
//	ptr->func();
//
//	return 0;
//}


//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void func()
//	{
//		cout << "void A::func()" << endl;
//	}
//private:
//	char _a;
//	int _i;
//};
//
//
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//
//// ����ʲô��û��---����
//class A3
//{};

//int main()//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	// û�г�Ա����������󣬸�1byte��ռλ���洢ʵ�����ݣ���ʶ�������
//	A2 aa2;
//	A2 aaa2;
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//
//	A3 aa3;
//
//	return 0;
//}
/*
class Date
{
public:
	void init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
*/
// ���ʺ͵���֮������ĸ��д���  -- �շ巨   GetYear
// ����ȫ��Сд������֮��_�ָ�              get_year
// ���ã��շ巨
// a�������������������е�������ĸ��д DateMgr
// b����������ĸСд�����浥������ĸ��д dateMgr
// c����Ա�������׵���ǰ���_   _dateMgr
//class Date
//{
//public:
//
//	/*void Init(Date* const this, int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void Print(Date* const this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}*/
//
//	// ʵ�κ��β�λ�ò�����ʾ���ݺͽ���thisָ��
//	// ���ǿ����ڳ�Ա�����ڲ�ʹ��thisָ��
//	void Init(int year, int month, int day)
//	{
//		//this = nullptr;
//		cout << this << endl;
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void Print()
//	{
//		cout << this << endl;
//		cout << this->_year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;     // ��   -> ����
//	int _month;    // ��
//	int _day;      // ��
//};

//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 17);
//
//	Date d2;
//	d2.Init(2022, 7, 18);
//
//	d1.Print();
//	d2.Print();
//
//	/*Date d1;
//	d1.Init(&d1, 2022, 7, 17);
//
//	Date d2;
//	d2.Init(&d2, 2022, 7, 18);
//
//	d1.Print(&d1);
//	d2.Print(&d2);*/
//
//	return 0;
//}

// 1.�������������н���ǣ�  A�����뱨��  B�����б���  C���������� -- ok
// 2.thisָ��������  ��  ջ  ��̬�� ������  -- ջ����Ϊ����һ���β�
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << this << endl;
//		cout << _a << endl;
//		cout << _a << endl;
//		cout << _a << endl;
//		cout << _a << endl;
//		cout << _a << endl;
//		cout << _a << endl;
//	}
//
//	void Print(int x)
//	{
//		cout << this << endl;
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//A* p = nullptr;
//	//p->Print();  // C����������
//	//p->PrintA();   // B�����б���
//
//	A aa;
//	aa.Print(1);
//
//
//	return 0;
//}

//class Date
//{
//public:
//	/*void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	//void Init(size_t capacity = 3)
//	//{
//	//	_array = (DataType*)malloc(sizeof(DataType)* capacity);
//	//	if (NULL == _array)
//	//	{
//	//		perror("malloc����ռ�ʧ��!!!");
//	//		return;
//	//	}
//
//	//	_capacity = capacity;
//	//	_size = 0;
//	//}
//
//	Stack(int capacity = 4)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)*capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//
//// ����Init��ʼ��,���ܻ����ǣ����±����������ֵ
//// �ܲ��ܱ�֤����һ������ʼ����-- ���캯��
////int main()
////{
////	Date d1;
////	d1.Print();
////
////	d1.Init(2022, 7, 5);
////	d1.Print();
////
////	Date d2;
////	d2.Init(2022, 7, 6);
////	d2.Print();
////
////
////	Stack st;
////	//st.Init();
////	st.Push(9);
////	st.Push(0);
////
////	return 0;
////}
//
//int main()
//{
//	Date d1(2022, 7, 17);
//	Date d2;
//	Date d3(2022);
//
//	Stack st;
//	st.Push(9);
//	st.Push(0);
//
//	return 0;
//}


class Date
{
public:
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year = 1;   // ע�����ﲻ�ǳ�ʼ������ȱʡֵ
	int _month = 1;
	int _day = 1;
};

typedef int DataType;
class Stack
{
public:
	Stack(int capacity)
	{
		cout << "Stack(int capacity = 4)" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}

		_size = 0;
		_capacity = capacity;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};

// C++���ͷ��ࣺ
// ��������/�������ͣ�int/double/char/ָ��ȵ� 
// �Զ������ͣ�struct/class

class MyQueue
{
private:
	int _size;
	Stack _st1;
	Stack _st2;
};

int main()
{
	// Ĭ�����ɹ��캯����a:�������ͳ�Ա�������� b���Զ������ͳ�Ա��ȥ��������Ĭ�Ϲ��캯��
	// �����C++������Ƶ�һ��ȱ�ݣ�Ĭ�����ɹ��캯��������Ӧ����������Ҳһ������
	// C++11 ����һ������
	Date d;
	MyQueue q;
	Stack st;

	return 0;
}