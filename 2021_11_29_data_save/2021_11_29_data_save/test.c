#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<limits.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d ,b=%d ,c=%d", a, b, c);//-1 -1 255
//	return 0;
//}


//int main()
//{
//	char a = -128;
//	printf("%u\n", a);//4294967168
//	return 0;
//}

//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);//-10
//	return 0;
//}


int main()
{
	unsigned int i;
	//�޷���i ÿһλ������Чλ��û�и���
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
		Sleep(1000);
	}
	return 0;
} 

//signed char 1 byte - 8 bit ȡֵ��Χ��-128 - 127
//unsigned char 1 byte - 8 bit ȡֵ��Χ��0 - 255
//signed short 2 byte - 16 bit ȡֵ��Χ��-32768 - 32767  