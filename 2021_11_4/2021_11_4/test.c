#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//��˳���ӡһ������ÿһλ
//void Print(int n)
//{
//	if (n > 9)
//	{
//		Print(n / 10);
//	}
//	printf("%d", n % 10);
//}

//��׳�
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("%d\n", ret);
//	return 0;
//}


//�ݹ鷽��ʵ��strlen
//int my_strlen(char* s)
//{
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(s + 1);
//
//	}
//}
//�ǵݹ�
//int my_strlen(char* str)
//{
//	int count = 0;
//	while ('\0' != *str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	//���ַ�������
//	char arr[] = "abc";//a b c \0
//	//arr������������������������Ԫ�صĵ�ַ
//	int len = my_strlen(arr);//char*
//
//	printf("%d\n", len);
//	return 0;
//}


//�ݹ�ʵ��abc--cba
//void reverse_string(char* arr)
//{
//	if (arr[0] != '\0')
//	{
//		reverse_string(arr + 1);
//		printf("%c", *arr);
//	}
//}
//int main()
//{
//	char a[] = "abcdef";
//	reverse_string(a);
//	//printf("%s", a);
//	return 0;
//}

//�ݹ�ʵ��ÿһλ��֮��
//int DigitSum(int n)
//{
//	if (n <= 9)
//	{
//		return n;
//	}
//	return DigitSum(n / 10) + n % 10;
//}
//int main()
//{
//	int n = 1729;
//	printf("%d\n", DigitSum(n));
//	return 0;
//}

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��

//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}
//int main()
//{
//	int n = 3;
//	printf("%d\n", fac(n));
//	return 0;
//}