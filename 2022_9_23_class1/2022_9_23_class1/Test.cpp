#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<map>
#include<string>
using namespace std;

#include"f.h"

//ADD���������ĺ꺯��

//#define ADD(a+b) ((a)+(b))
//#define ADD(a,b) {(a)+(b)}
//#define ADD(a,b) a+b
//#define ADD(a,b) (a+b)
//#define ADD(a,b) {return a + b;}
//#define ADD(int a, int b) {return (a)+(b);}
//#define ADD(a,b) ((a)+(b));

//#define ADD(a,b) ((a)+(b))
//
//// Ԥ����--�滻
//int main()
//{
//	ADD(1, 2); // ((1) + (2))
//
//	if (ADD(1, 2)) // 	if (((1)+(2)))
//	{}
//
//	ADD(1, 2) * 3; // ((1)+(2))*3
//	int x = 1, y = 2;
//	ADD(x|y, x&y); // ((x|y)+(x&y))   (x|y+ x&y)   
//
//
//	return 0;
//}

//#define ADD(a,b) ((a)+(b))
//
//// Ԥ����--�滻
//int main()
//{
//	ADD(1, 2); // ((1) + (2))
//
//	if (ADD(1, 2)) // 	if (((1)+(2)))
//	{
//	}
//
//	ADD(1, 2) * 3; // ((1)+(2))*3
//	int x = 1, y = 2;
//	ADD(x | y, x&y); // ((x|y)+(x&y))   (x|y+ x&y)   
//
//
//	return 0;
//}

// inline  ����������������ڵ��õط�չ��
//inline int Add(int a, int b)
//{
//	printf("int Add(%d, %d)->\n", a, b);
//	return a + b;
//}
//
//
//int main()
//{
//	cout << Add(1, 2) << endl; // ((1) + (2))
//
//	if (Add(1, 2)) // 	if (((1)+(2)))
//	{
//		cout << Add(1, 2) << endl;
//	}
//
//	cout << Add(1, 2) * 3 << endl;; // ((1)+(2))*3
//
//	int x = 1, y = 2;
//	cout << Add(x | y, x&y) << endl; // ((x|y)+(x&y))   (x|y+ x&y)   
//
//	return 0;
//}

//inline void Add(int a, int b)
//{
//	int c = a + b;
//	printf("Add(%d, %d)->%d\n", a, b, c);
//}
//
//inline void func(int a, int b)
//{
//	//cout << a + b << endl;
//	//cout << a + b << endl;
//	//cout << a + b << endl;
//	int c = a + b;
//	c = a * b;
//	c = a * b;
//	c = a + b;
//	c = a / b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//	c = a * b;
//}
//
//
//int main()
//{
//	Add(1, 2);
//	func(1, 2);
//
//	return 0;
//}

//int main()
//{
//	func(1, 2);
//
//	return 0;
//}

int TestAuto()
{
	return 10;
}

//int main()
//{
//	int a = 10;
//	auto b = a; // �Զ��Ƶ�����
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	//TestFor(a);
//
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		a[i]++;
//	}
//
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//
//	// ��Χfor
//	// �Զ�����ȡa�����ݣ���ֵ��e
//	// �Զ��������Զ��жϽ���
//	for (auto& e : a)
//	{
//		e--;
//	}
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	// ���ͱȽϳ���ʱ��auto�Զ��Ƶ�
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	auto it = dict.begin();
//
//
//	//int x = 10;
//	//auto a = &x;  // int*
//	//auto* b = &x;  // int* ǿ��һ��Ҫ��ָ��
//	//auto& c = x;   // int ǿ��c��һ������
//	//cout << typeid(a).name() << endl;
//	//cout << typeid(b).name() << endl;
//	//cout << typeid(c).name() << endl;
//
//	return 0;
//}


void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

//int main()
//{
//	int* p = NULL;
//	f(0);
//	f(NULL);
//	f(p);
//
//	// C++11 nullptr �ؼ��� ���NULL
//	f(nullptr);
//	int* ptr = nullptr;
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////
// c
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* ps);
//void StackPush(struct Stack* ps, int x);
//void StackPop(struct Stack* ps);

//  ����c struct �﷨
// C++ͬʱ��struct ����������

// ��Ա����
// ��Ա����
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
//
//// C
//typedef struct ListNode_C
//{
//	struct ListNode_C* next;
//	int val;
//}LTNode;
//
//// C++
//struct ListNode_CPP
//{
//	ListNode_CPP* next;
//	int val;
//};
//
//int main()
//{
//	struct Stack st1;
//	Stack st2;
//
//	st1.Init();
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//
//	return 0;
//}

//struct Stack
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

	int Top()
	{
		return a[top - 1];
	}
	//private:
	//protected:
	int* a;
	int top;
	int capacity;
};

int main()
{
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);

	//cout << st.a[st.top] << endl;
	//cout << st.a[st.top-1] << endl;

	cout << st.Top() << endl;


	//st.a = nullptr;

	Queue q;
	q.Init();
	q.Push(1);
	q.Push(2);
	q.Push(3);

	return 0;
}