#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//m & (m-1) ���m�Ķ��������������ұߵ�1ȥ��

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
//��������
//��ͬΪ0������Ϊ1
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

//sizeof������ ����Ľ����������size_t
//���޷������εģ�����

//int main()
//{
//	char v[] = { 'a','e','i','o','u','A','E','I','O','U' };
//
//	char ch = 0;
//	//%c�Ǵӻ���������һ���ַ������������\nҲ��ѻ�������\nҲ����
//	while (~scanf("%c\n", &ch))
//	{
//
//	}
//	return 0;
//}

//���飺һ����ͬ����Ԫ�صļ���
//�ṹ����������������Ӷ����
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//}s1, s2;//s1,s2�������ṹ�����,��ȫ�ֵ�
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	struct Stu s = { "zhansgan",20,95.5f };//����һ���ṹ��������ֲ���
//}

//�ṹ�崫��
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
//��������ʱ����������Ҫѹջ��
//�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ��ϵͳ�����Ƚϴ�
//���Իᵼ�����ܵ��½�
int main()
{
	struct S s = { {1,2,3,4,5,6,7,8,9,10},5.5f,"hi" };
	print(&s);
	return 0;
}
