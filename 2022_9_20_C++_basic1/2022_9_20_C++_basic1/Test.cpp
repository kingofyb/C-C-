#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//7.9����

//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 100;
//	int d = 200;
//
//	b = c;
//	d = b;
//
//
//	return 0;
//}

#include <time.h>
struct A { int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }

// ���÷���
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << typeid(a).name() <<endl;
//	cout << typeid(b).name() << endl;
//
//	// Ȩ�޲��ܷŴ�
//	const int c = 20;
//	//int& d = c;
//	const int& d = c;
//
//	// Ȩ�޿�����С
//	int e = 30;
//	const int& f = e;
//
//	int ii = 1;
//	double dd = ii;
//	//double dd = (double)ii;
//	// ����ת����������ı�ԭ�������ͣ��м䶼�����һ����ʱ����
//
//	//double& rdd = ii;
//	const double& rdd = ii;
//
//	const int& x = 10;
//
//	return 0;
//}

void func1(int n)
{}

//void func2(int& n)
// ���ʹ�����ô��Σ�������������ı�n����ô���龡����const���ô���
void func2(const int& n)
{}

//int main()
//{
//	int a = 10;
//	const int b = 20;
//	func1(a);
//	func1(b);
//	func1(30);
//
//	func2(a);
//	func2(b);
//	func2(30);
//	func2(1.11);
//	double d = 2.22;
//	func2(d);
//
//	return 0;
//}

int main()
{
	// �﷨�ĽǶȣ�raû�п��ռ�
	int a = 10;
	int& ra = a;
	ra = 20;

	// �﷨�ĽǶȣ�paû�п���4 or 8 byte�ռ�
	int* pa = &a;
	*pa = 20;

	func1(10);

	return 0;
}