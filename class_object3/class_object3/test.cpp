#include<iostream>
using namespace std;
#include"Date.h"

// ������������
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "~A(int a = 0)->" << _a << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()->" << _a << endl;
//	}
//
//private:
//	int _a;
//};
//int main()
//{
//	// ����õ�������
//	A aa1(1);
//	A aa2(2); // ����ջ�ĺ���ȳ�
//
//	//  ~A(int a = 0)->1
//	//	~A(int a = 0)->2
//	//	~A()->2
//	//	~A()->1
//
//	return 0;
//}

//A aa3(3);
//int main()
//{
//	static A aa0(0);
//	A aa1(1);
//	A aa2(2); 
//	static A aa4(4);
//
//	//  ~A(int a = 0)->3
//	//	~A(int a = 0)->0
//	//	~A(int a = 0)->1
//	//	~A(int a = 0)->2
//	//	~A(int a = 0)->4
//	// 
//	//	~A()->2
//	//	~A()->1
//	//	~A()->4
//	//	~A()->0
//	//	~A()->3
//
//	return 0;
//}


//A aa3(3);
//
//void f()
//{
//	static A aa0(0);
//	A aa1(1);
//	A aa2(2); 
//	static A aa4(4);
//}

// ����˳�򣺵�һ�ι��죨3 0 1 2 4��
// �ڶ��ι���ʱ��3 0 1 2 4 1 2
// ��̬��ֻ�ڵ�һ�ι��죬�ڶ���aa0��aa4û�����٣����Բ����ٴα�����

// ����˳��~2 ~1 ~2 ~1 ~4 ~0 ~3
// ��һ��f������ֱ������2��1

//int main()
//{
//	f();
//	f();
//	return 0;
//}

// ����
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "~A(int a = 0)->" << _a << endl;
//	}
//
//	// ����
//	// A aa2(aa1)
//	A(const A& aa) // _a���ʵ���this
//	{
//		_a = aa._a;
//		cout << "~A(const A& aa)->" << _a << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()->" << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//void func1(A aa) // ��ֵ����
//{
//
//}
//
//void func2(A& aa) // ���ô���
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
//
//}
//
//int main()
//{
//	//A aa1(1);
//	//A aa2(aa1);
//
//	//func1(aa1);
//	//func2(aa1);
//
//	func3();
//	cout << endl << endl;
//	func4();
//	return 0;
//}


//void TestDate()
//{
//	Date d1(2022, 7, 24);
//	Date d2(d1);
//
//	Date d3(2022, 8, 24);
//	d2 = d1 = d3; // ��ֵ����������� - d1.operator(&d1, d3)��d1�ĵ�ַ����d3
//}

void TestDate1()
{
	Date d1(2022, 7, 24);
	Date d2(2022, 7, 25);
	Date d3(2021, 7, 24);

	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 == d3) << endl;
	cout << (d1 > d3) << endl;
}

void TestDate2()
{
	Date d1(2022, 7, 24);
	//Date d2 = d1 + 4;
	//d2.Print();

	//d1 += 4;
	//d1.Print();

	//d1 += 40; // ����
	//d1.Print();

	//d1 += 400; // ����
	//d1.Print();

	//d1 += 4000; // ������
	//d1.Print();

	(d1 + 4).Print(); // ���ﲻ�������÷��أ���Խ��
	(d1 + 40).Print();
	(d1 + 400).Print();
	(d1 + 4000).Print();

	Date ret1 = ++d1; // d1.operator++(&d1)
	Date ret2 = d1++; // d1.operator++(&d2, 0)
}

int main()
{
	//TestDate();
	//TestDate1();
	TestDate2();
	return 0;
}