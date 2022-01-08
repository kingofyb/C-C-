#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//针对每行输入，输出该数是奇数（Odd）还是偶数（Even）。
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

//针对每组输入，输出为一行，如果输入字母是元音（包括大小写），输出“Vowel”，
//如果输入字母是非元音，输出“Consonant”。
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