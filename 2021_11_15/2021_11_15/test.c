#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���ÿ�����룬���������������Odd������ż����Even����
//int main()
//{
//	int num = 0;
//
//
//	while (scanf("%d\n", &num) != EOF)
//	{
//		if (num % 2 == 0)
//		{
//			printf("Even\n");
//		}
//		else
//		{
//			printf("Odd\n");
//		}
//	}
//	return 0;
//}

//���ÿ�����룬���Ϊһ�У����������ĸ��Ԫ����������Сд���������Vowel����
//���������ĸ�Ƿ�Ԫ���������Consonant����
int main()
{
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		getchar();
		if (ch == "\n")
		{
			continue;
		}
		if (ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' || ch == 'i'
			|| ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u')
		{
			printf("Vowel\n");
		}
		else
		{
			printf("Consonant\n");
		}
	}
	return 0;
}