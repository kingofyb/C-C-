#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void test(char** p)
//{
//
//}
//
//int main()
//{
//	char ch = 'W';
//	char* p = &ch;
//	char* pp = &p;
//	char* arr[5];
//
//	test(&p);
//	test(pp);
//	test(arr);
//
//	return 0;
//}

//����ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//void test(char* str)
//{
//
//}
//int main()
//{
//	//printf("%p\n", &Add);
//	//printf("%p\n", Add);
//	int (*pf)(int, int) = &Add;//pf�Ǻ���ָ��
//
//	//void (*pt)(char*) = test;
//	//�ڶ������� -> �������ò�����
//	//int sum = (*pf)(2, 3);
//	int sum = (pf)(2, 3);
//	return 0;
//}

//int main()
//{
//	//1. ��0ǿ������ת��Ϊvoid(*)()���͵ĺ���ָ��
//	//2. ��ȥ����0��ַ���������Ϊ�޲Σ�����������void�ĺ���
//	//(*(void(*)())0)();//����һ�κ������ã�����0��ַ���ĺ���
//	//0 -> 0x0012ff44���Ǹ�����
//
//	void(*signal(int, void(*)(int)))(int);
//	//����signal�϶��Ⱥͺ�������Ž�ϣ�����siganl�Ǹ����������ǲ�û�д��Σ������Ǻ�������
//	//������2���� int -> ���ͣ�void(*)(int) -> ����ָ������
//	//ʣ�µ�void(*)(int)���Ǹ�����ָ�����͵ķ���ֵ����ָ��ָ��ĺ�������int������������void
//	return 0;
//}


//����ָ������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int (*pfArr[4])(int, int) = { Add,Sub,Mul,Div };//����ָ������
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int ret = pfArr[i](8, 4);
//		printf("%d\n", ret);//12,4,32,2
//	}
//	return 0;
//}