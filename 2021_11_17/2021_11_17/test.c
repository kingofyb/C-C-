#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//ָ�����ڴ���һ����С�ĵ�Ԫ��ţ�Ҳ���ǵ�ַ
//ƽʱ������˵��ָ�룬ͨ��ָ����ָ�����������������ڴ��ַ�ı���
//��ַ - �ڴ浥Ԫ�ı��
//�ߵ�Ƶ - 1      �͵�Ƶ - 0
//32λ - 32����ַ�� - ����ĵ��� - ͨ�� - 1/0

//1 . ָ�����;������ڽ����õ���һ���ܷ��ʼ����ֽڣ�ָ���Ȩ�ޣ�
//int* --> 4
//float* --> 4
//char* --> 1
//double* --> 8

//2 . ָ�����;�����ָ����ǰ���������һ�����߶����루��λ���ֽڣ�

//int main()
//{
//	//��ָ���ʼ��
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	//���Ŵ�ӡ
//	int* q = &arr[9];
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *q);
//		q--;
//	}
//
//	return 0;
//}

//һ���ַ�һ���ַ�
//int main()
//{
//	int arr[10] = { 0 };
//	char* p = (char*)arr;
//
//	return 0;
//}

//Ұָ��
//int main()
//{
//	//int* p;//Ұָ��
//
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		//����Խ��
//		*p = i;
//		p++;
//	}
//	return 0;
//}

//                             ָ������
//ָ�� +/- ����
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//���Ŵ�ӡ
	//int* q = arr + sz - 1;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", *(q - i));
	//}
//
//	return 0;
//}

//ָ�� - ָ�� = ����ָ��֮���Ԫ�ظ���


// ����������
//int my_strlen(char* s)
//{
//	int count = 0;
//	while (*s != '\0')
//	{
//		count++;
//		s++;
//	}
//	return count;
//}

//ָ�� - ָ�� �ķ���
//int my_strlen(char* s)
//{
//	char* start = s;
//	while (*s != '\0')
//	{
//		s++;
//	}
//	return s - start;
//}
////���ַ�������
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//����ָ��
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;//ppa����һ������ָ��

	return 0;
}