#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
//union Un
//{
//	char c;//1
//	int i;//4
//};
//
//int main() 
//{
//	union Un u = {0};
//	u.c = 'w';
//	u.i = 0x11223344;
//	//printf("%d\n", sizeof(u));//4
//  ////������Ҳ�й�����
//	//printf("%p\n", &u);//02E2F8A0
//	//printf("%p\n", &(u.c));//һ�� - 02E2F8A0
//	//printf("%p\n", &(u.i));//һ�� - 02E2F8A0
//
//	return 0;
//}

//�жϴ�С��
//int cheak_sys()
//{
//	int a = 1;
//	//ǿת�����õ͵�ַ�����Ϊ1����С�ˣ������Ǵ��
//	if (*(char*)&a == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int cheak_sys()
//{
//	int a = 1;
//	return (*(char*)&a);
//}

//int cheak_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}

//int cheak_sys()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}

//int main()
//{
//	int ret = cheak_sys();
//	if (1 == ret)
//		printf("С��\n");
//	else
//		printf("���\n");
//
//	//�������1����ʾС��
//	//�������0����ʾ���
//	return 0;
//}

//union Un1
//{
//	char c[5];//5 1,8 - 1 (char)������
//	int i;    //4 4,8 - 4 (int) 5����4�ı����������˷������ֽڣ�8
//};
//
//union Un2
//{
//	short c[7];//14 2,8-2
//	int i;     //4  4,8-4 14����4�ı�����16��
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));//8
//	printf("%d\n", sizeof(union Un2));//16
//
//	return 0;
//}

//int main()
//{
//	//����10�����͵Ŀռ�
//	//int arr[10];
//	int* p = (int*)malloc(40);
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ��
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//�ͷ�
//	free(p);//���ͷź�p����Ұָ����
//	p = NULL;
//	
//	return 0;
//}

//int main()
//{
//	//����10�����͵Ŀռ�
//	//int arr[10];
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ��
//	int  i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//	//����10�����͵Ŀռ�
//	//int arr[10];
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//ʹ��
//	int  i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//��Ҫ���� - 80
//	int*ptr = (int*)realloc(p, 80);
//	if (NULL != ptr)
//	{
//		p = ptr;
//		ptr = NULL;
//	}
//	//����ʹ����
//	
//	//�ͷ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}

int main()
{
	//����10�����͵Ŀռ�
	//int arr[10];
	int* p = (int*)realloc(NULL, 40);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//ʹ��
	int  i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}

	//�ͷ�
	free(p);
	p = NULL;

	return 0;
}