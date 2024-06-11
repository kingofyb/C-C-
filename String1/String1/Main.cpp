#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};



// replacement new - 定位new

//int main()
//{
//	A* p1 = new A;
//
//	// p2现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// 在已分配的原始内存空间中调用构造函数初始化一个对象
//	new(p2)A; // 注意：如果A类的构造函数有参数时，此处需要传参\
//	// new(p2)A(10); // 也可以传参
//
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

// ...
// 
// 模版 - 泛型编程
// typename后面类型名字T是随便取的，Ty，K，V，一般大写字母或单词首字母大写
// T代表一个模版（虚拟）类型
// template<typename T> // 模版参数（模版类型） -- 类似函数参数（参数对象）
//template<class T> // typename和class在大部分情况下没有区别
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	Swap(i, j);
//	Swap(x, y);
//
//	char m = 'A', n = 'B';
//	Swap(m, n);
//
//	cout << i << j << endl;
//	cout << x << y << endl;
//	cout << m << n << endl;
//	return 0;
//}

// swap库里面就有
// https://cplusplus.com/reference/

//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	swap(i, j);
//	swap(x, y);
//
//	char m = 'A', n = 'B';
//	swap(m, n);
//
//	cout << i << j << endl;
//	cout << x << y << endl;
//	cout << m << n << endl;
//	return 0;
//}
//template<class T>
//T Add(const T& left, const T& right) 
//{
//	return left + right;
//}
//template<class T>
//T* Func(int n)
//{
//	T* a = new T[n];
//	return  a;
//}
//
//int main()
//{
//
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0; 
//	Add(a1, a2);
//	Add(d1, d2); 
//
//	// Add(1.1, 2); // 推演实例化报错
//
//	//该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	// 编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//
//	// 推演实例化矛盾，报错
//	// Add(1.1, 2);
//
//	// 编译器自动推演，隐式实例化
//	Add(a1, (int)d1);
//
//	// 显式实例化
//	Add<double>(1.1, 2);
//
//	// 必须显示实例化才能调用
//	Func<A>(10);
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////
// 类模板
//typedef int STDataType; // 不属于泛型
//
//class Stack
//{
//private:
//	STDataType* _a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	// 解决不了一个类中st1存char，st2存int
//	Stack st1; // char
//	Stack st2; // int
//
//	return 0;
//}

template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 4)
		:_a(nullptr)
		, _capacity(0)
		, _top(0)
	{
		if (capacity > 0)
		{
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}

	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

	void Push(const T& x)
	{
		// 插入的是一个T类型的数据
		if (_top == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			// 手动扩容
			// 开新空间
			T* tmp = new T[newCapacity];
			if (_a)
			{
				memcpy(tmp, _a, sizeof(T) * _top); // 拷贝数据
				delete[] _a; // 释放释放旧空间
			}

			_a = tmp;
			_capacity - newCapacity;
		}
		// 放数据
		_a[_top] = x;
		++_top;
	}

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}

	bool Empty()
	{
		return _top == 0;
	}

	// 引用返回是可以被修改的，所以加const
	const T& Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}

private:
	// 跟上面不加:_a等等的本质是一样的
	//T* _a = nullptr;
	//size_t _top = 0
	//size_t _capacity = 0;
	T* _a;
	size_t _top;
	size_t _capacity;
};

// 模版不支持分离编译。声明放在.h 定义放在.cpp，
// 但是在同一个文件内可以声明和定义分离的


int main()
{
	// 规范写，抛异常
	try 
	{
		// 类模板都是显示实例化
		// 虽然它们用了同一个类模板，但是它们不是一个类型
		//Stack<int> st1;
		//Stack<char> st2;

		//// 知道要存100个数据，避免插入时扩容消耗
		//Stack<int> st3(100);
		//Stack<int> st3(0);

		Stack<int> st1;
		st1.Push(1);
		st1.Push(2);
		st1.Push(3);
		st1.Push(4);
		st1.Push(5);

		while (!st1.Empty())
		{
			cout << st1.Top() << " ";
			st1.Pop();
		}
		cout << endl;
		
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}



 	return 0;
}