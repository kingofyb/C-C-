#define _CRT_SECURE_NO_WARNINGS 1

#include "Person.h"

//int main()
//{
//	cout << "static size:" << &size << endl;
//	cout << "age:" << &age << endl;
//
//	//cout << sizeof(Person) << endl;
//
//	Person p1; // 类的实例化
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
//	// 崩溃  编译报错 正常运行
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
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{};

//int main()//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	// 没有成员变量的类对象，给1byte，占位不存储实际数据，标识对象存在
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
// 单词和单词之间首字母大写间隔  -- 驼峰法   GetYear
// 单词全部小写，单词之间_分割              get_year
// 课堂：驼峰法
// a、函数名、类名等所有单词首字母大写 DateMgr
// b、变量首字母小写，后面单词首字母大写 dateMgr
// c、成员变量，首单词前面加_   _dateMgr
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
//	// 实参和形参位置不能显示传递和接收this指针
//	// 但是可以在成员函数内部使用this指针
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
//	int _year;     // 年   -> 声明
//	int _month;    // 月
//	int _day;      // 日
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

// 1.下面程序编译运行结果是？  A、编译报错  B、运行崩溃  C、正常运行 -- ok
// 2.this指针存在哪里？  堆  栈  静态区 常量区  -- 栈，因为他是一个形参
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
//	//p->Print();  // C、正常运行
//	//p->PrintA();   // B、运行崩溃
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
//	//		perror("malloc申请空间失败!!!");
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
//			perror("malloc申请空间失败!!!");
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
//// 调用Init初始化,可能会忘记！导致崩溃出现随机值
//// 能不能保证对象一定被初始化？-- 构造函数
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
	int _year = 1;   // 注意这里不是初始化，给缺省值
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
			perror("malloc申请空间失败!!!");
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

// C++类型分类：
// 内置类型/基本类型：int/double/char/指针等等 
// 自定义类型：struct/class

class MyQueue
{
private:
	int _size;
	Stack _st1;
	Stack _st2;
};

int main()
{
	// 默认生成构造函数，a:内置类型成员不做处理 b：自定义类型成员回去调用他的默认构造函数
	// 设计是C++早期设计的一个缺陷，默认生成构造函数，本来应该内置类型也一并处理
	// C++11 打了一个补丁
	Date d;
	MyQueue q;
	Stack st;

	return 0;
}