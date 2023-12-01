#include<iostream>
#include<map>
#include<string>
using namespace std;
//用inline修饰的函数叫做内联函数
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}

//ADD两个变量的宏函数
// 预处理 - - 替换
//#define ADD(a,b) ((a)+(b))


//inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有递归的函数不适宜。因为如果展开会导致编译出来可执行程序变大
//符合条件的情况下，在调用的地方展开
//inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数内部实现代码指令比较长或者有递归等，编译器优化时会忽略掉内联。
//比较长直接不展开，10行左右，不同的编译器是不同的
//inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。

//比较长
//inline int func(int a, int b)
//{
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//	cout << a + b << endl;
//}


//inline int ADD(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	ADD(1, 2); // ((1)+(2))
//	if (ADD(1, 2)) // if (((1)+(2)))
//	{}
//	ADD(1, 2) * 3; // ((1)+(2))*3 外面括号用的场景
//	int x = 1;
//	int y = 2;
//	ADD(x | y, x & y); // ((x|y)+(x&y)) 里面括号用的场景，涉及运算符优先级问题
//	return 0;
//}


//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a; //自动推导类型
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };// 遍历数组a
//	//
//	//// 范围for
//	//// 自动依次取a的数据，赋值给e
//	//// 自动迭代，自动判断结束
//	// 
//	//// 用引用，取地址改值
//	//for (auto& e : a)
//	//{
//	//	e--;
//	//}
//
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//// 类型比较长的时候，auto自动推导
//	//std::map<std::string, std::string> dict;
//	////std::map<std::string, int>::iterator it = dict.begin();
//	//auto it = dict.begin();
//
//
//	//int x = 10;
//	//auto a = &x; // int*
//	//auto* b = &x; // int* 强调一定要传指针
//	//auto& c = x; // int 强调c是一个引用
//	//cout << typeid(a).name() << endl;
//	//cout << typeid(b).name() << endl;
//	//cout << typeid(c).name() << endl;
//
//
//
//	return 0;
//}

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	int* p = NULL;
//
//	f(0); //f(int)
//	f(NULL); //f(int) NULL就是0，是个宏
//	f(p); //f(int*)
//
//	//c++11 nullptr 关键字替代NULL
//	f(nullptr);
//
//	return 0;
//}


//////////////////////////////////////
// c
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps);

// c++ Struct 兼容c的语法
// c++ 同时将struct升级成了类

// 成员变量
// 成员函数
//struct Stack
//{
//	void Init()
//	{
//		a = 0;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		// ...
//	}
//
//	void Pop()
//	{
//		// ...
//	}
//
//	int* a;
//	int top;
//	int capacity;
//};

// c++
struct ListNode
{
	ListNode* next;
	int val;
};

class Stack
{
public:
	void Init()
	{
		a = 0;
		top = capacity = 0;
	}

	void Push(int x)
	{
		// ...
	}

	void Pop()
	{
		// ...
	}

private:
	int* a;
	int top;
	int capacity;
};



int main()
{
	//struct Stack st1;
	//Stack st2;

	//st1.Init();
	//st1.Push(1);
	//st1.Push(2);
	//st1.Push(3);


	// class的默认访问权限为private，struct为public因为struct要兼容C
	// protect和private只能在类里面访问，public可以在类里类外访问
	// protect和private讲到继承以后才有区别
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);

	//st.a = nullptr;

	return 0;
}
// 类的定义:
// 小函数，想成为inline，直接在类里面定义即可
// 如果是大函数，应该声明和定义分离
