#include<iostream>
#include<map>
#include<string>
using namespace std;
//��inline���εĺ���������������
//int main()
//{
//	cout << "Hello World" << endl;
//	return 0;
//}

//ADD���������ĺ꺯��
// Ԥ���� - - �滻
//#define ADD(a,b) ((a)+(b))


//inline��һ���Կռ任ʱ���������ʡȥ���ú�����������Դ���ܳ������еݹ�ĺ��������ˡ���Ϊ���չ���ᵼ�±��������ִ�г�����
//��������������£��ڵ��õĵط�չ��
//inline���ڱ���������ֻ��һ�����飬���������Զ��Ż����������Ϊinline�ĺ����ڲ�ʵ�ִ���ָ��Ƚϳ������еݹ�ȣ��������Ż�ʱ����Ե�������
//�Ƚϳ�ֱ�Ӳ�չ����10�����ң���ͬ�ı������ǲ�ͬ��
//inline�����������Ͷ�����룬����ᵼ�����Ӵ�����Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ��Ҳ�����

//�Ƚϳ�
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
//	ADD(1, 2) * 3; // ((1)+(2))*3 ���������õĳ���
//	int x = 1;
//	int y = 2;
//	ADD(x | y, x & y); // ((x|y)+(x&y)) ���������õĳ������漰��������ȼ�����
//	return 0;
//}


//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a; //�Զ��Ƶ�����
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };// ��������a
//	//
//	//// ��Χfor
//	//// �Զ�����ȡa�����ݣ���ֵ��e
//	//// �Զ��������Զ��жϽ���
//	// 
//	//// �����ã�ȡ��ַ��ֵ
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
//	//// ���ͱȽϳ���ʱ��auto�Զ��Ƶ�
//	//std::map<std::string, std::string> dict;
//	////std::map<std::string, int>::iterator it = dict.begin();
//	//auto it = dict.begin();
//
//
//	//int x = 10;
//	//auto a = &x; // int*
//	//auto* b = &x; // int* ǿ��һ��Ҫ��ָ��
//	//auto& c = x; // int ǿ��c��һ������
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
//	f(NULL); //f(int) NULL����0���Ǹ���
//	f(p); //f(int*)
//
//	//c++11 nullptr �ؼ������NULL
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

// c++ Struct ����c���﷨
// c++ ͬʱ��struct����������

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


	// class��Ĭ�Ϸ���Ȩ��Ϊprivate��structΪpublic��ΪstructҪ����C
	// protect��privateֻ������������ʣ�public�����������������
	// protect��private�����̳��Ժ��������
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);

	//st.a = nullptr;

	return 0;
}
// ��Ķ���:
// С���������Ϊinline��ֱ���������涨�弴��
// ����Ǵ�����Ӧ�������Ͷ������
