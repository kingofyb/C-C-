#include<iostream>
using namespace std;

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？不需要
//	free(p3);
//}


//C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力，而且使用起来比较麻烦，因
//此C++又提出了自己的内存管理方式：通过new和delete操作符进行动态内存管理。


// new和delet时操作符
//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//
//	// 动态申请10个int类型的空间
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

// 代码 -> 文件 -> 磁盘
// 编译链接 -- 可执行程序(文件(二进制整理代码，数据，...))

// calloc 初始化成0
// realloc 空间扩容

// C++不支持扩容
//void Test()
//{
//	// new根据内置类型只是开空间
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 申请5个int的数组
//	int* p3 = new int[5]; 
//
//	// 申请1个int对象，初始化为5
//	int* p4 = new int(5);
//
//	// C++11，支持对多个数组初始化 new[]用{}初始化，C++98不支持
//	int* p5 = new int[5] {1, 2, 3};
//
//	free(p1);
//
//	delete p2;
//	delete[] p3; // 释放多个对象就用[]
//	delete p4;
//	delete[] p5;
//
//	// 针对内置类型，new/delete跟malloc/free没有本质区别，只有用法区别
//	// new/delete用法简化
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
		//比特就业课
		//	注意：在申请自定义类型的空间时，new会调用构造函数，delete会调用析构函数，而malloc与
		//	free不会。
		//	4. operator new与operator delete函数（重要点进行讲解）
		//	4.1 operator new与operator delete函数（重点）
		//	new和delete是用户进行动态内存申请和释放的操作符，operator new 和operator delete是
		//	系统提供的全局函数，new在底层调用operator new全局函数来申请空间，delete在底层通过
		//	operator delete全局函数来释放空间。
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
//	// 1、堆上申请空间
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		return 0;
//	}
//
//	// 1、释放空间
//	free(p1);
//
//	cout << endl << endl;
//
//	// 1、堆上申请空间 2、还会调用构造函数初始化
//	A* p2 = new A; // 不仅仅开空间，还会调用构造函数初始化
//
//	// 如果没有默认构造 - A(int a)
//	// 可以 A* p2 = new A(10);
//
//	// 1、释放空间 2、调用析构函数清理对象中的资源
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[10];
//	// 后定义先析构，析构是清理资源
//	delete[10] p3;
//
//	// 结论：new/delete 是为**自定义类型**准备的。
//  // 不仅在堆申请出来，还会调用构造和析构初始化和清理
//
//	return 0;
//}

//int main()
//{
//	// 失败返回NULL
//	//char* p1 = (char*)malloc(1024 * 1024 * 1024);
//	//printf("%p\n", p1);
//
//	// new失败，不需要检查返回值，它失败是抛异常
//	//char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
//	//printf("%p\n", p2);
//
//
//	return 0;
//}

// 重载operator delete，在申请空间时：打印在哪个文件、哪个函数、第多少行，申请了多少个字节
//void* operator new(size_t size, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	void* p = ::operator new(size); // ::域作用限定符
//	cout << "new: " << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||"
//		<< size << endl;
//	return p;
//}
//// 重载operator delete，在释放空间时：打印再那个文件、哪个函数、第多少行释放
//void operator delete(void* p, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	cout << "delete: " << fileName << "||" << funcName << "||" << lineNo << "||" << p <<
//		endl;
//	::operator delete(p);
//}

//int main()
//{
//	// 对重载的operator new 和 operator delete进行调用
//	int* p = new(__FILE__, __FUNCTION__, __LINE__) int;
//	operator delete(p, __FILE__, __FUNCTION__, __LINE__);
//	return 0;
//}
// 上述调用显然太麻烦了，可以使用宏对调用进行简化
// 只有在Debug方式下，才调用用户重载的 operator new 和 operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//
//
//int main()
//{
//	// 假设有两个地方有内存泄露，该怎么找出来呢
//	A* p1 = new A;
//	delete p1;
//	//delete(p1); // 这样能调到，但是这样delete的用法就变了，实际当中不能变使用方式
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

// new -> operator new + 构造函数
// 默认情况下，operator new使用全局库里面
// 每个类可以去实现自己专属的operator new，new这个类对象，它就会调自己实现的这个operator new 
// 实现一个类专属的operator new
struct ListNode
{
	int _val;
	ListNode* _next;
	// 内存池
	static allocator<ListNode> alloc;

	// 解决大量申请node，不是重载，而是特性
	void* operator new(size_t n)
	{	
		cout << "void operator new -> STL内存池申请" << endl;
		void* obj = alloc.allocate(1);
		return obj;
	}

	void operator delete(void* ptr)
	{
		cout << "void operator delete -> STL内存池申请" << endl;
		alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{

	}
};

// 在类外面定义，指定它属于这个类域
allocator<ListNode> ListNode::alloc;

int main()
{
	// 频繁申请node，想提高效率 - 申请listnode时，不去malloc，而是自己定制内存池
	ListNode* node1 = new ListNode(1); // 先找类里面有没有operator new，有就用类里面的
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);

	// 有没有内存泄露可以一眼看出来
	delete node1;
	delete node2;
	delete node3;

	return 0;
}