#define _CRT_SECURE_NO_WARNINGS 1
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


//1.��NULLָ��Ľ����ò���
//int main()
//{
//	int* p = (int*)malloc(INT_MAX);
//	if (p == NULL)
//		return 0;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	return 0;
//}


//���򵥴�
//void reverse(char* l, char* r)
//{
//    assert(l && r);
//    while (l < r)
//    {
//        char tmp = *l;
//        *l = *r;
//        *r = tmp;
//        l++;
//        r--;
//    }
//}
//
//int main()
//{
//    char arr[100] = { 0 };
//    //����
//    gets(arr);
//    int len = strlen(arr);
//    //����
//    //1. ���������ַ���
//    char* left = arr;
//    char* right = arr + len - 1;
//    reverse(left, right);
//
//    //2. ����ÿ������
//    char* cur = arr;
//    char* start = arr;
//
//    while (*cur != '\0')
//    {
//        while (*cur != ' ' && *cur != '\0')
//        {
//            cur++;
//        }
//        reverse(start, cur - 1);
//        start = cur + 1;
//        if (*cur != '\0')
//            cur++;
//    }
//    printf("%s\n", arr);
//
//    return 0;
//}

//2.�Զ�̬���ٿռ��Խ�����

//int main()
//{
//	char* p = (char*)malloc(10 * sizeof(char));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ��
//	int i = 0;
//	//for (i = 0; i <= 10; i++)//Խ��
//	for(i=0; i<10; i++)
//	{
//		*(p + i) = 'a'+i;
//	}
//
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�

//int main()
//{
//	//int* p = (int*)malloc(40);
//	////
//	//free(p);
//	//p = NULL;
//
//	int a = 10;
//	int*p = &a;
//	//д����
//
//	free(p);//err
//	p = NULL;
//
//	return 0;
//}

//4.ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ���ڴ�
//	int i = 0;
//	//1~5
//	for (i = 0; i < 5; i++)
//	{
//		*p = i+1;
//		p++;
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//	return 0;
//}

//5.��ͬһ�鶯̬�ڴ����ͷ�

//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ���ڴ�
//	int i = 0;
//	//1~5
//	for (i = 0; i < 5; i++)
//	{
//		*(p+i) = i + 1;
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	free(p);//err
//
//	return 0;
//}

//��̬�����ڴ������ͷţ��ڴ�й©��

//int* test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//ʹ��
//	
//	//�����ͷţ��ͻ�����ڴ�й¶������
//	//return p;
//}
//
//int main()
//{
//	int*ptr = test();
//	//free(ptr);
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//		return 0;
//	//ʹ��
//	
//	while (1)
//		;
//
//	return 0;
//}
//