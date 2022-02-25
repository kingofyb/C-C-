#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//位段的声明和结构是类似的，有两个不同：
//1.位段的成员必须是int, unsigned int 或 signed int
//2.位段的成员名后面有一个冒号和一个数字

//struct A
//{
//	//4byte
//	int _a : 2;//30      00/01/10/11
//	int _b : 5;//25
//	int _c : 10;//15
//	//4byte -32bit
//	int _d : 30;
//};//8个字节 
////假设表示年龄
////
////int age:10;//给age十个比特位
////
//
//struct S
//{
//	//1byte-8bit
//	char a : 3;//5
//	char b : 4;//1
//	//1byte-8bit
//	char c : 5;//3
//	//1byte-8bit
//	char d : 4;//
//};

//struct S
//{
//	char a : 3;
//	char b : 4;
//  //开辟新字节
//	char c : 5;
//  //开辟新字节
//	char d : 4;
//};
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	struct S s = { 0 };
//	s.a = 10; //1010 只能存3bit 就是010存进去了
//	s.b = 12; //1100 全部存入
//	s.c = 3; //00011，因为c占5bit
//	s.d = 4; //0100
//
//	return 0;
//}

enum Day
{
	//枚举的可能取值
	Mon,
	Tues,
	Wed,
	Thir,
	Fri,
	Sta,
	Sun
};
//enum Sex
//{
//	MALE,//0
//	FEMALE,//1
//	SECRET//2
//};

//int main()
//{
//	enum Day d = Sun;
//	enum Sex s = SECRET;
//	Sex s2 = MALE;
//
//	printf("%d\n", sizeof(s2));//4
//
//	//printf("%d\n", MALE);
//	//printf("%d\n", FEMALE);
//	//printf("%d\n", SECRET);
//
//	return 0;
//}