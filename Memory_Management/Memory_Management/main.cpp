#include<iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)�𣿲���Ҫ
//	free(p3);
//}


//C�����ڴ����ʽ��C++�п��Լ���ʹ�ã�����Щ�ط�������Ϊ��������ʹ�������Ƚ��鷳����
//��C++��������Լ����ڴ����ʽ��ͨ��new��delete���������ж�̬�ڴ����


// new��deletʱ������
//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//
//	// ��̬����10��int���͵Ŀռ�
//	int* ptr6 = new int[3];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//
//
//int main()
//{
//
//	return 0;
//}

// ���� -> �ļ� -> ����
// �������� -- ��ִ�г���(�ļ�(������������룬���ݣ�...))

// calloc ��ʼ����0
// realloc �ռ�����

// C++��֧������
//void Test()
//{
//	// new������������ֻ�ǿ��ռ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// ����5��int������
//	int* p3 = new int[5]; 
//
//	// ����1��int���󣬳�ʼ��Ϊ5
//	int* p4 = new int(5);
//
//	// C++11��֧�ֶԶ�������ʼ�� new[]��{}��ʼ����C++98��֧��
//	int* p5 = new int[5] {1, 2, 3};
//
//	free(p1);
//
//	delete p2;
//	delete[] p3; // �ͷŶ���������[]
//	delete p4;
//	delete[] p5;
//
//	// ����������ͣ�new/delete��malloc/freeû�б�������ֻ���÷�����
//	// new/delete�÷���
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
		//���ؾ�ҵ��
		//	ע�⣺�������Զ������͵Ŀռ�ʱ��new����ù��캯����delete�����������������malloc��
		//	free���ᡣ
		//	4. operator new��operator delete��������Ҫ����н��⣩
		//	4.1 operator new��operator delete�������ص㣩
		//	new��delete���û����ж�̬�ڴ�������ͷŵĲ�������operator new ��operator delete��
		//	ϵͳ�ṩ��ȫ�ֺ�����new�ڵײ����operator newȫ�ֺ���������ռ䣬delete�ڵײ�ͨ��
		//	operator deleteȫ�ֺ������ͷſռ䡣
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
//
//int main()
//{
//	// 1����������ռ�
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		return 0;
//	}
//
//	// 1���ͷſռ�
//	free(p1);
//
//	cout << endl << endl;
//
//	// 1����������ռ� 2��������ù��캯����ʼ��
//	A* p2 = new A; // ���������ռ䣬������ù��캯����ʼ��
//
//	// ���û��Ĭ�Ϲ��� - A(int a)
//	// ���� A* p2 = new A(10);
//
//	// 1���ͷſռ� 2����������������������е���Դ
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[10];
//	// ������������������������Դ
//	delete[10] p3;
//
//	// ���ۣ�new/delete ��Ϊ**�Զ�������**׼���ġ�
//  // �����ڶ����������������ù����������ʼ��������
//
//	return 0;
//}

//int main()
//{
//	// ʧ�ܷ���NULL
//	//char* p1 = (char*)malloc(1024 * 1024 * 1024);
//	//printf("%p\n", p1);
//
//	// newʧ�ܣ�����Ҫ��鷵��ֵ����ʧ�������쳣
//	//char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
//	//printf("%p\n", p2);
//
//
//	return 0;
//}

// ����operator delete��������ռ�ʱ����ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ��ֽ�
//void* operator new(size_t size, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	void* p = ::operator new(size); // ::�������޶���
//	cout << "new: " << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||"
//		<< size << endl;
//	return p;
//}
//// ����operator delete�����ͷſռ�ʱ����ӡ���Ǹ��ļ����ĸ��������ڶ������ͷ�
//void operator delete(void* p, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	cout << "delete: " << fileName << "||" << funcName << "||" << lineNo << "||" << p <<
//		endl;
//	::operator delete(p);
//}

//int main()
//{
//	// �����ص�operator new �� operator delete���е���
//	int* p = new(__FILE__, __FUNCTION__, __LINE__) int;
//	operator delete(p, __FILE__, __FUNCTION__, __LINE__);
//	return 0;
//}
// ����������Ȼ̫�鷳�ˣ�����ʹ�ú�Ե��ý��м�
// ֻ����Debug��ʽ�£��ŵ����û����ص� operator new �� operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//
//
//int main()
//{
//	// �����������ط����ڴ�й¶������ô�ҳ�����
//	A* p1 = new A;
//	delete p1;
//	//delete(p1); // �����ܵ�������������delete���÷��ͱ��ˣ�ʵ�ʵ��в��ܱ�ʹ�÷�ʽ
//
//	A* p2 = new A[4];
//	//delete[] p2;
//
//	A* p3 = new A;
//	delete p3;
//
//	A* p4 = new A;
//	//delete p4;
//
//	A* p5 = new A;
//	delete p5;
//
//	return 0;
//}

// new -> operator new + ���캯��
// Ĭ������£�operator newʹ��ȫ�ֿ�����
// ÿ�������ȥʵ���Լ�ר����operator new��new�����������ͻ���Լ�ʵ�ֵ����operator new 
// ʵ��һ����ר����operator new
struct ListNode
{
	int _val;
	ListNode* _next;
	// �ڴ��
	static allocator<ListNode> alloc;

	// �����������node���������أ���������
	void* operator new(size_t n)
	{	
		cout << "void operator new -> STL�ڴ������" << endl;
		void* obj = alloc.allocate(1);
		return obj;
	}

	void operator delete(void* ptr)
	{
		cout << "void operator delete -> STL�ڴ������" << endl;
		alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{

	}
};

// �������涨�壬ָ���������������
allocator<ListNode> ListNode::alloc;

int main()
{
	// Ƶ������node�������Ч�� - ����listnodeʱ����ȥmalloc�������Լ������ڴ��
	ListNode* node1 = new ListNode(1); // ������������û��operator new���о����������
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);

	// ��û���ڴ�й¶����һ�ۿ�����
	delete node1;
	delete node2;
	delete node3;

	return 0;
}