#define _CRT_SECURE_NO_WARNINGS 1
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//  //�����ͷ�
//	free(str);
//	str = NULL;
//
//	if (str != NULL)
//	{
//		//��Ϊ֮ǰ��strָ��Ŀռ��Ѿ��ͷţ������ٴ�ʹ��
//      //�γɷǷ�����
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//��������

//struct S1
//{
//	int n;
//	int arr[0];//��С��δָ��
//};
//
//struct S2
//{
//	int n;
//	int arr[];//
//};
////flexible array
////�ṹ�е����������Աǰ���������һ��������Ա
////sizeof���ص����ֽṹ��С����������������ڴ�
////�������������Ա�Ľṹ��malloc()���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С
////����Ӧ���������Ԥ�ڴ�С
//int main()
//{
//	//printf("%d\n", sizeof(struct S1));
//	struct S2* ps = (struct S2*)malloc(sizeof(struct S2) + 40);//40�Ǹ�arr��
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//����
//	struct S2* ptr = (struct S2*)realloc(ps, sizeof(struct S2)+80);
//	if (ptr == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		ps = ptr;
//	}
//	//�ͷ�
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
//
//struct S
//{
//	int n;
//	int* arr;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->n = 100;
//	ps->arr = (int*)malloc(40);
//	//ʹ��
//	//����
//
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}
//