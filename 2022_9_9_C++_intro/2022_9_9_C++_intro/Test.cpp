#define _CRT_SECURE_NO_WARNINGS 1
// ����c����
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

// �����ռ�

//// ������ͻ
//int rand = 0;
//
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}


// ������ͻ

// �����ռ���
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
//	// ::�������޶���
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

// ����Ƕ��
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
		int top;		// ջ����λ��
		int capacity;	// ����
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

// std��C++��׼��������ռ�
//using namespace std;

//int main()
//{
//	// ����ȫ����ȥ�ң����û�л����չ����bit����ȥ��
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
//	// << �������������
//	std::cout << "hello world" << std::endl;
//	std::cout << "hello world" << "\n";
//
//	// �Զ�ʶ������
//	int i = 11;
//	double d = 11.11;
//	//std::cout << i <<","<< d << std::endl;
//
//	scanf("%d%lf", &i, &d);
//	printf("%d,%lf\n", i, d);
//
//	// >>����ȡ
//	std::cin >> i >> d;
//	std::cout << i << "," << d << std::endl;
//
//	return 0;
//}

using std::cout;
using std::cin;

int main()
{
	// �Զ�ʶ������
	int i = 11;
	double d = 11.11;
	//std::cout << i <<","<< d << std::endl;

	scanf("%d%lf", &i, &d);
	printf("%d,%lf\n", i, d);

	// >>����ȡ
	cin >> i >> d;
	cout << i << "," << d << std::endl;

	return 0;
}