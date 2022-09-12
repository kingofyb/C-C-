#define _CRT_SECURE_NO_WARNINGS 1
// 兼容c语言
#include <stdio.h>
#include <stdlib.h>
//
//int main()
//{
//	printf("hello world\n");
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world"<<endl;
//}

// 命名空间

//// 命名冲突
//int rand = 0;
//
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}


// 命名冲突

// 命名空间域
//namespace bit
//{
//	int rand = 0;
//}
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%p\n", bit::rand);
//
//	return 0;
//}

//int a = 0;
//int main()
//{
//	int a = 1;
//	printf("%d\n", a);
//
//	// ::域作用限定符
//	printf("%d\n", ::a);
//
//	return 0;
//}

//namespace bit
//{
//	int rand = 0;
//	void func()
//	{
//		printf("func()\n");
//	}
//
//	struct TreeNode
//	{
//		struct TreeNode* left;
//		struct TreeNode* right;
//		int val;
//	};
//}
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%p\n", bit::rand);
//
//	bit::func();
//
//	struct bit::TreeNode node;
//
//	return 0;
//}

// 可以嵌套
//namespace sql
//{
//	int a = 0;
//	namespace bit
//	{
//		int rand = 0;
//		void func()
//		{
//			printf("func()\n");
//		}
//
//		struct TreeNode
//		{
//			struct TreeNode* left;
//			struct TreeNode* right;
//			int val;
//		};
//	}
//}
//
//
//int main()
//{
//	printf("%p\n", rand);
//	printf("%p\n", sql::bit::rand);
//
//	sql::bit::func();
//
//	struct sql::bit::TreeNode node;
//
//	return 0;
//}

namespace ch
{
	typedef int STDataType;
	typedef struct Stack
	{
		STDataType* a;
		int top;		// 栈顶的位置
		int capacity;	// 容量
	}ST;
}

#include "Stack.h"
#include "Queue.h"

//int main()
//{
//	bit::ST st;
//	bit::StackInit(&st);
//
//	bit::Queue q;
//	bit::QueueInit(&q);
//}

using namespace bit;

// std是C++标准库的命名空间
//using namespace std;

//int main()
//{
//	// 现在全局域去找，如果没有还会带展开的bit域中去找
//	ST st;
//	StackInit(&st);
//
//	Queue q;
//	QueueInit(&q);
//
//	return 0;
//}

#include <iostream>
//using namespace std;
//int main()
//{
//	// << 是流插入运算符
//	std::cout << "hello world" << std::endl;
//	std::cout << "hello world" << "\n";
//
//	// 自动识别类型
//	int i = 11;
//	double d = 11.11;
//	//std::cout << i <<","<< d << std::endl;
//
//	scanf("%d%lf", &i, &d);
//	printf("%d,%lf\n", i, d);
//
//	// >>流提取
//	std::cin >> i >> d;
//	std::cout << i << "," << d << std::endl;
//
//	return 0;
//}

using std::cout;
using std::cin;

int main()
{
	// 自动识别类型
	int i = 11;
	double d = 11.11;
	//std::cout << i <<","<< d << std::endl;

	scanf("%d%lf", &i, &d);
	printf("%d,%lf\n", i, d);

	// >>流提取
	cin >> i >> d;
	cout << i << "," << d << std::endl;

	return 0;
}