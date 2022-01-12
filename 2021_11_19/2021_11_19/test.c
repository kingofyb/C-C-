#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//m & (m-1) 会把m的二进制序列中最右边的1去掉

int count_number_of_1(int m)
{
	int count = 0;
	while (m)
	{
		m = m & (m - 1);
		count++;
	}
	return count;
}
//异或操作符
//相同为0，相异为1
int count_diff_bit(int m, int n)
{
	int i = 0;
	int c = 0;
	int tmp = m ^ n;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		c++;
	}
	return c;
}

//sizeof操作符 计算的结果的类型是size_t
//是无符号整形的！！！

//int main()
//{
//	char v[] = { 'a','e','i','o','u','A','E','I','O','U' };
//
//	char ch = 0;
//	//%c是从缓冲区拿走一个字符，后面如果有\n也会把缓冲区的\n也拿走
//	while (~scanf("%c\n", &ch))
//	{
//
//	}
//	return 0;
//}

//数组：一组相同类型元素的集合
//结构体就是用来描述复杂对象的
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//}s1, s2;//s1,s2是两个结构体变量,是全局的
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	struct Stu s = { "zhansgan",20,95.5f };//定义一个结构体变量，局部的
//}

//结构体传参
struct S
{
	int arr[1000];
	float f;
	char ch[100];
};
void print(struct S* ps)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	printf("%f\n", ps->f);
	printf("%s\n", ps->ch);
}
//函数传参时，参数是需要压栈的
//如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大
//所以会导致性能的下降
int main()
{
	struct S s = { {1,2,3,4,5,6,7,8,9,10},5.5f,"hi" };
	print(&s);
	return 0;
}
