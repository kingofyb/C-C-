#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����ȫ����д
//��������Ҫȫ����д
//#undef �Ƴ��궨��

//�����ж���
//�����ڱ���ָ��ĵط�ָ�����ŵ�ֵ

//ѡ���Ա���
//��������
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//#if 0
//		printf("%d\n", i);		
//#endif
//		//ҵ����
//	}
//	return 0;
//}

//#define M 150
//
//int main()
//{
//#if M<100
//	printf("less\n");
//#elif M==100
//	printf("==\n");
//#elif M>100&&M<200
//	printf("more\n");
//#else
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//#define M 0
//
//int main()
//{
////#if defined(M)//ֻҪ�����������ֵ��ʲô������ִ��
////	printf("hehe\n");
////#endif
////
////#ifdef M
////	printf("haha\n");
////#endif
//
//
////#if !defined(M)
////	printf("hehe\n");
////#endif
////
////#ifndef M
////	printf("haha\n");
////#endif
//
//	return 0;
//}

//#include "test.h"
//#include "test.h"
//#include "test.h"
//#include "test.h"

//#include "test.h"
////#include <stdio.h>
//
//#include "stdio.h"
////1.��ǰ����Ŀ¼����
////2.��Ŀ¼�²���
//
//int main()
//{
//
//	return 0;
//}

//ģ��ʵ��atoi
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

//int my_atoi(char* str)
//{
//	int n = 0;
//	assert(str);
//
//	while (*str)
//	{
//		n = n * 10 + (*str - '0');
//		str++;
//	}
//	return n;
//}
//1. ��ָ��
//2. ���ַ���
//3. �հ��ַ�
//4. +-
//5. �������ַ�
//6. ��������


//
//enum State
//{
//	INVALID,//�Ƿ�
//	VALID   //�Ϸ�
//};
//
//enum State status = INVALID;
//
//int my_atoi(const char* str)
//{
//	assert(str);
//	//���ַ���
//	if (*str == '\0')
//		return 0;
//
//	//�հ��ַ���������
//	while (isspace(*str))
//	{
//		str++;
//	}
//	int flag = 1;
//	
//	//+-
//	if (*str == '+')
//	{
//		str++;
//		flag = 1;
//	}
//	else if (*str == '-')
//	{
//		str++;
//		flag = -1;
//	}
//
//	long long n = 0;
//	while (isdigit(*str))
//	{
//		n = n * 10 + flag*(*str - '0');
//		//Խ���ֵ
//		if (n > INT_MAX || n < INT_MIN)
//		{
//			return 0;
//		}
//		str++;
//	}
//	if (*str == '\0')
//	{
//		//�Ϸ�����
//		status = VALID;
//		return (int)n;
//	}
//
//	return (int)n;
//}

//int main()
//{
//	int ret = my_atoi("");//"0"
//	if (status == VALID)
//		printf("%d\n", ret);
//	else
//		printf("�Ƿ�����\n");
//
//	return 0;
//}