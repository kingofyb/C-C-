#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	//str��NULLָ�룬��Ƿ������ڴ棬��������
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//******************** ��ȷ
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	//
//	strcpy(str, "hello world");
//	printf(str);
//	//�ͷ�
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;//�Ȱ�p��ֵ�ŵ��Ĵ����������
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);//ͨ���Ĵ�������ȥ����Ϊ�Ĵ�����������
//	//
//	strcpy(str, "hello world");
//	printf(str);
//	//�ͷ�
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//***********************�����ӡ����������Ϊp�Ѿ�������
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//int* test()
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int *p = test();
//	printf("hehehhhhh\n");
//  //���û�������hehe���ͻ���10����Ϊû��������ڴ�,����û������
//	printf("%d\n", *p);//10
//
//	return 0;
//}