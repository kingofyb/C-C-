#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//7.9下午

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
// 值返回
A TestFunc1() { return a; }

// 引用返回
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// 计算两个函数运算完成之后的时间
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
//	// 权限不能放大
//	const int c = 20;
//	//int& d = c;
//	const int& d = c;
//
//	// 权限可以缩小
//	int e = 30;
//	const int& f = e;
//
//	int ii = 1;
//	double dd = ii;
//	//double dd = (double)ii;
//	// 类型转换，并不会改变原变量类型，中间都会产生一个临时变量
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
// 如果使用引用传参，函数内如果不改变n，那么建议尽量用const引用传参
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
	// 语法的角度，ra没有开空间
	int a = 10;
	int& ra = a;
	ra = 20;

	// 语法的角度，pa没有开了4 or 8 byte空间
	int* pa = &a;
	*pa = 20;

	func1(10);

	return 0;
}