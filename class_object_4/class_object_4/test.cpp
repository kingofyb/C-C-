#include<iostream>
using namespace std;

//每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//类中包含以下成员，必须放在初始化列表位置进行初始化：
//
//**引用成员变量
//**const成员变量
//**自定义类型成员(且该类没有默认构造函数时)


// 函数体内初始化
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

// 有更优的方式初始化
// 初始化列表
// 初始化列表：以一个冒号开始，接着是一个以逗号分隔的数据成员列表，每个"成员变量"后面跟一个放在括号中的初始值或表达式。
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class Time
//{
//public:
//	// Time(int hour = 0) // 提供了默认构造
//	Time(int hour)		// 没提供默认构造
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// 要初始化_t对象，只能通过初始化列表
//	Date(int year, int hour)
//		:_t(hour)
//	{
//		// 下面叫做函数体内初始化
//		_year = year;
//		// 下面这种构造太麻烦
//		// 不能访问私有，构造一个对象，利用赋值初始化
//		//Time t(hour);
//		//_t = t;
//	}
//private:
//	int _year; // 对内置类型不处理
//	// 无参、全缺省、没写编译器默认生成的都可以叫做默认构造
//	Time _t; // 默认构造，编译器默认生成，调用了Time的默认构造
//};
//
//
//int main()
//{
//	Date d(2022, 1);
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0) // 提供了默认构造
//	// Time(int hour)		// 没提供默认构造
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// 要初始化_t对象，只能通过初始化列表
//	Date(int year, int hour)
//		//:_t(hour)
//	{
//		// 下面叫做函数体内初始化
//		_year = year;
//		// 下面这种构造太麻烦
//		// 不能访问私有，构造一个对象，利用赋值初始化
//		Time t(hour);
//		_t = t;
//	}
//private:
//	int _year; // 对内置类型不处理
//	// 无参、全缺省、没写编译器默认生成的都可以叫做默认构造
//	Time _t; // 默认构造，编译器默认生成，调用了Time的默认构造
//};
//
//// 结论：自定义类型成员，推荐使用初始化列表初始化
//// ***************************************初始化列表可以认为是成员变量定义的地方
//
//
//// 有些情况还是要在函数体内初始化的，因为有的地方使用初始化列表很别扭
//// 有些初始化工作还是必须在函数体内完成
//// 比如下方初始化一个数组：
//class A
//{
//public:
//	A(int N)
//	{
//		_a = (int*)malloc(sizeof(int) * N);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}
//private:
//	int* _a;
//	int _N;
//};
//
//
//class B {
//public:
//	B(int x) 
//		: value(x) 
//	{}  // 带参数的构造函数
//private:
//	int value;
//};
//
//class C {
//public:
//	C() : value(0) {}  // 默认构造函数
//	C(int x)
//		: value(x)
//	{}  // 带参数的构造函数
//private:
//	int value;
//};
//
//
//
//int main()
//{
//	//Date d(2022, 1);
//
//	A aa(10);
//
//	//B obj; // 错误：没有默认构造函数
//	//B obj2(10); // 正确：使用带参数的构造函数
//
//	C obj; // 使用默认构造函数
//	C obj2(10); // 使用带参数的构造函数
//
//	return 0;
//}


// 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//class A
//{
//public:
// //初始化按声明顺序初始化
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}
// 
// 虽然a1在前面，但是初始化是按谁先声明谁先初始化，a2先声明所以先初始化a2
// 直接初始化a2那a2就是个随机值，然后再初始化a1，a1是1
// 
// _a2先被初始化，此时 _a2 被初始化为 _a1 的值，而 _a1 还未初始化，所以 _a2 得到一个随机值（未定义行为）。
// 然后 _a1 被初始化为 a 的值，即 1
// // D
////A.输出1 1
////B.程序崩溃
////C.编译不通过
////D.输出1 随机值

class Date
{
public:
	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
	// explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
	explicit Date(int year)
		:_year(year)
	{}
	/*
	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转
   换作用
	// explicit修饰构造函数，禁止类型转换
	explicit Date(int year, int month = 1, int day = 1)
	: _year(year)
	, _month(month)
	, _day(day)
	{}
	*/
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	Date d1(2022);
	// 用一个整形变量给日期类型对象赋值
	// 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
	//d1 = 2023;
	// 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转换的作用
}

class Date1
{
public:
	//explicit Date1(int year) // 可以防止隐式类型转换成日期类
	Date1(int year)
		:_year(year)
	{
		cout << "   Date1(int year)" << endl;
	}
	Date1(const Date& d) // 验证有没有用到拷贝构造
	{
		cout << "Date1(const Date& d)" << endl;
	}

	~Date1() // 析构函数
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
};

//int main()
//{
//	Date1 d1(2022); // 直接调用构造
//	// 隐式类型的转换
//	Date1 d2 = 2022; // 构造 + 拷贝构造 + 编译器优化 -> 直接调用构造
//	const Date1& d3 = 2022; // 这里引用的是中间产生的临时变量，不是2022
//
//	//int i = 10;
//	//const double& d = i; // i是在这个中间产生一个临时变量，这个临时变量是double类型，把d的类型转换成临时变量，然后再拷贝给d
//
//
//	// 匿名对象 - 生命周期只有这一行
//	Date1(2000);
//
//	return 0;
//}

/*
传参尽量用引用，引用尽量用const
自定义类型传参为什么建议加const和引用

提高效率：

避免拷贝：
传递大对象或复杂对象时，如果按值传递，会调用拷贝构造函数生成一个对象的副本，这样会消耗额外的时间和空间。使用引用可以避免这种拷贝。
减少内存开销：通过引用传递只传递一个指针（引用本质上是一个指针的语法糖），而不需要整个对象的内存分配和复制，这大大减少了内存开销。

保持对象的原始状态：

避免不必要的修改：
通过const修饰参数，保证在函数内部不修改传入的对象。这不仅提高了代码的安全性，还使代码更易于理解和维护。
明确意图：使用const可以清楚地表明该函数不会修改传入的对象，使得代码的意图更加明确。

假设有一个自定义类型MyClass：
class MyClass {
public:
	MyClass(int x) : value(x) {}
	int getValue() const { return value; }
private:
	int value;
};
我们有一个函数需要处理MyClass类型的对象：
void process(MyClass obj) {
	// 处理对象
}

如果按值传递：
MyClass obj1(10);
process(obj1);

在上述情况下，process函数调用时会创建obj1的副本，这会调用拷贝构造函数，增加不必要的开销。改为按引用传递可以避免这个问题：
void process(const MyClass& obj) {
	// 处理对象
}

现在调用时：
MyClass obj1(10);
process(obj1);

*/


/////////////////////////////////////////////////////////////////////////////////////
// 静态成员

//声明为static的类成员称为类的静态成员，用static修饰的成员变量，称之为静态成员变量；用static修饰的
//成员函数，称之为静态成员函数。静态成员变量一定要在类外进行初始化
// 属于整个类，也属于这个类的所有对象
//1. 静态成员为所有类对象所共享，不属于某个具体的对象，存放在静态区
//2. 静态成员变量必须在类外定义，定义时不添加static关键字，类中只是声明
//3. 类静态成员即可用 类名::静态成员 或者 对象.静态成员 来访问
//4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
//5. 静态成员也是类的成员，受public、protected、private 访问限定符的限制

//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t) { ++_scount; }
//
//	// 静态成员函数 -- 没有this指针
//	static int GetCount()
//	{
//		return _scount;
//	}
//
//	//int GetCount()
//	//{
//	//	return _scount;
//	//}
////private:
//private:
//	int _a;
//	// 静态成员变量，属于整个类，生命周期整个程序运行期间，存在静态区
//	static int _scount; // 声明
//};
//
//// 只能在类外面定义初始化
//int A::_scount = 0;
//
//int main()
//{
//	A a1;
//	A a2;
//	A a3(a2);
//
//	// 但是如果是私有的就不行
//	//cout << a1._scount << endl;
//	//cout << a2._scount << endl;
//	//cout << A::_scount << endl;
//
//	// 如果是私有的就用静态成员函数
//	//cout << a1.GetCount() << endl;
//
//	// 如果不想用类去调，可以用静态成员函数
//}

//---------------------------------------
// 设计一个只能在栈上定义对象的类
//class StackOnly
//{
//public:
//	static StackOnly CreateObj() // 满足全局变量的封装
//	{
//		StackOnly so;
//		return so; // 使用的传值返回，会再拷贝，所以出了作用域还是有效
//	}
//
//private:
//	StackOnly(int x = 0, int y = 0)
//		:_x(x)
//		, _y(0)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//
//int main()
//{
//	//StackOnly so1; // 栈
//	//static StackOnly so2; // 静态区
//
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}

/*
1. 静态成员函数可以调用非静态成员函数吗？
不能，因为没有this

2. 非静态成员函数可以调用类的静态成员函数吗？
可以，因为属于整个类
*/





//W f(W u)
//{
//	W v(u); // 拷贝一次
//	W w = v; // 拷贝一次
//	return w;
//}
//
//int main()
//{
//	W x; // 这有一次构造
// // y拷贝一次，f(x) 拷贝一次
//	W y = f(x); // 1次构造 4次拷贝
//
//	return 0;
//}



// ------------------------------------------------------------------
//W f(W u)
//{
//	W v(u); // 拷贝一次
//	W w = v; // 拷贝一次
//	return w;
//}
//
//int main()
//{
//	W x; // 这有一次构造
// // y拷贝一次，f(x) 拷贝一次
//	W y = f(f(x)); // 1次构造 7次拷贝，如果编译器不优化就是加上两次的tmp就是拷贝9次，优化到最高级别就是五次(release)，把W w = v 给优化了
//
//	return 0;
//}