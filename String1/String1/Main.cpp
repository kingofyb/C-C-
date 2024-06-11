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



// replacement new - ��λnew

//int main()
//{
//	A* p1 = new A;
//
//	// p2����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	// ���ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
//	new(p2)A; // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����\
//	// new(p2)A(10); // Ҳ���Դ���
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
// ģ�� - ���ͱ��
// typename������������T�����ȡ�ģ�Ty��K��V��һ���д��ĸ�򵥴�����ĸ��д
// T����һ��ģ�棨���⣩����
// template<typename T> // ģ�������ģ�����ͣ� -- ���ƺ�����������������
//template<class T> // typename��class�ڴ󲿷������û������
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

// swap���������
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
//	// Add(1.1, 2); // ����ʵ��������
//
//	//����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	// �������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//
//	// ����ʵ����ì�ܣ�����
//	// Add(1.1, 2);
//
//	// �������Զ����ݣ���ʽʵ����
//	Add(a1, (int)d1);
//
//	// ��ʽʵ����
//	Add<double>(1.1, 2);
//
//	// ������ʾʵ�������ܵ���
//	Func<A>(10);
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////
// ��ģ��
//typedef int STDataType; // �����ڷ���
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
//	// �������һ������st1��char��st2��int
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
		// �������һ��T���͵�����
		if (_top == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			// �ֶ�����
			// ���¿ռ�
			T* tmp = new T[newCapacity];
			if (_a)
			{
				memcpy(tmp, _a, sizeof(T) * _top); // ��������
				delete[] _a; // �ͷ��ͷžɿռ�
			}

			_a = tmp;
			_capacity - newCapacity;
		}
		// ������
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

	// ���÷����ǿ��Ա��޸ĵģ����Լ�const
	const T& Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}

private:
	// �����治��:_a�ȵȵı�����һ����
	//T* _a = nullptr;
	//size_t _top = 0
	//size_t _capacity = 0;
	T* _a;
	size_t _top;
	size_t _capacity;
};

// ģ�治֧�ַ�����롣��������.h �������.cpp��
// ������ͬһ���ļ��ڿ��������Ͷ�������


int main()
{
	// �淶д�����쳣
	try 
	{
		// ��ģ�嶼����ʾʵ����
		// ��Ȼ��������ͬһ����ģ�壬�������ǲ���һ������
		//Stack<int> st1;
		//Stack<char> st2;

		//// ֪��Ҫ��100�����ݣ��������ʱ��������
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