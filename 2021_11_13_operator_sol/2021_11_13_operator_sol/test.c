#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�����������������������������Ƹ�ʽ�ж��ٸ�λ��ͬ
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int count = 0;
//	scanf("%d %d", &a, &b);
//	int c = a ^ b;
//	while (c)
//	{
//		count++;
//		c = c & (c - 1);
//	}
//	printf("%d\n", count);
//	return 0;
//}

//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int i = 0;
//	for (i = 0; i <= 31; i += 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	for (i = 1; i <= 31; i += 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	return 0;
//}

//дһ���������ز����������� 1 �ĸ���
//int Numberof1(int n)
//{
//	int count = 0;
//	while (n != 0)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	return count;
//}
//int main()
//{
//	int n = 15;
//	int count = Numberof1(n);
//	printf("%d",count);
//	return 0;
//}

//����������ʱ������������������������
int main()
{
	int a = 5;
	int b = 10;
	printf("����ǰ a=%d b=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("������ a=%d b=%d\n", a, b);
	return 0;
}