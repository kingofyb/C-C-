#include<iostream>
using namespace std;
#include"Date.h"

// 析构函数补充
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
//	// 后调用的先析构
//	A aa1(1);
//	A aa2(2); // 符合栈的后进先出
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

// 构造顺序：第一次构造（3 0 1 2 4）
// 第二次构造时：3 0 1 2 4 1 2
// 静态区只在第一次构造，第二次aa0和aa4没被销毁，所以不用再次被构造

// 析构顺序：~2 ~1 ~2 ~1 ~4 ~0 ~3
// 第一个f结束就直接析构2和1

//int main()
//{
//	f();
//	f();
//	return 0;
//}

// 拷贝
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "~A(int a = 0)->" << _a << endl;
//	}
//
//	// 拷贝
//	// A aa2(aa1)
//	A(const A& aa) // _a访问的是this
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
//void func1(A aa) // 传值传参
//{
//
//}
//
//void func2(A& aa) // 引用传参
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
//	d2 = d1 = d3; // 赋值运算符的重载 - d1.operator(&d1, d3)，d1的地址传给d3
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

	//d1 += 40; // 跨月
	//d1.Print();

	//d1 += 400; // 跨年
	//d1.Print();

	//d1 += 4000; // 跨闰年
	//d1.Print();

	(d1 + 4).Print(); // 这里不能用引用返回，会越界
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