#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int a = 10;
//	//int b = ++a;//先++，后使用
//	//printf("a=%d b=%d\n", a, b);//11 
//
//	//int b = a++;//再++，先使用
//	//printf("a=%d b=%d\n", a, b);//11 10
//
//	int* pa = &a;
//	*pa = 20;//解引用操作符
//	printf("%d\n", a);//20
//
//	return 0;
//}

//int main()
//{
//	//int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//
//	//printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);//1,2,3,4
//
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	i = a++ || ++b || d++;
//
//	printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);//2,2,3,4
//	//&& - 左操作数为假，右边不计算
//	//|| - 左操作数为真，右边不计算
//	return 0;
//}

//条件操作符 也叫三目操作符
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = 0;
//	max = (a > b ? a : b);
//	printf("%d", max);
//	return 0;
// }

//逗号表达式
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 6;
//	int d = (a += 2, b = a - c, c = a + 2 * b);
//
//	printf("%d", d);
//	return 0;
//}

//结构体
//struct Stu
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct Stu s = { "zhangsan",20,85.5 };
//	//.
//	printf("%s %d %.1lf\n", s.name, s.age, s.score);//结构体变量.结构体成员
//	//->
//	struct Stu* ps = &s;
//	printf("%s %d %.1lf\n", (*ps).name, (*ps).age, (*ps).score);
//	printf("%s %d %.1lf\n", ps->name, ps->age, ps->score);//结构体指针->结构体成员
//
//	return 0;
//}

int main()
{
	char a = 5;
	//00000000000000000000000000000101 - 5
	//a -- 00000101 截断

	char b = 126;
	//00000000000000000000000001111110 - 126
	//b -- 01111110

	//00000101
	//01111110
	//当a和b相加时，a和b都是char类型
	//表达式计算的时候就要发生整型提升
	//00000000000000000000000001111110
	//+
	//00000000000000000000000000000101
	//=
	//00000000000000000000000010000011
	char c = a + b;
	//c -- 10000011
	//11111111111111111111111110000011 - 补码
	//11111111111111111111111110000010
	//10000000000000000000000001111101 - -125
	printf("%d\n", c);//-125
	return 0;
}