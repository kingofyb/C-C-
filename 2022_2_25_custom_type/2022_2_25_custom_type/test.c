#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//λ�ε������ͽṹ�����Ƶģ���������ͬ��
//1.λ�εĳ�Ա������int, unsigned int �� signed int
//2.λ�εĳ�Ա��������һ��ð�ź�һ������

//struct A
//{
//	//4byte
//	int _a : 2;//30      00/01/10/11
//	int _b : 5;//25
//	int _c : 10;//15
//	//4byte -32bit
//	int _d : 30;
//};//8���ֽ� 
////�����ʾ����
////
////int age:10;//��ageʮ������λ
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
//  //�������ֽ�
//	char c : 5;
//  //�������ֽ�
//	char d : 4;
//};
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	struct S s = { 0 };
//	s.a = 10; //1010 ֻ�ܴ�3bit ����010���ȥ��
//	s.b = 12; //1100 ȫ������
//	s.c = 3; //00011����Ϊcռ5bit
//	s.d = 4; //0100
//
//	return 0;
//}

enum Day
{
	//ö�ٵĿ���ȡֵ
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