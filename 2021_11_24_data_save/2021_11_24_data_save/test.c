#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//1. const ���α���
//const int num = 10
//num = 20//error

//2. const ����ָ��
//const int* p //const������*����ߣ����ε���*p��ʹ��*p����ͨ��p���ı䣬����p���Ա��ı�
//int* const p //const������*���ұߣ����ε���p��p���ܱ��ı䣬����*p���Ա��ı�
//const int* const p //p��*p�����ܱ��ı�

//ctrl+g ����ָ����

//ģ��ʵ��strlen
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}
//int main()
//{
//	char arr[] = "abcdef";
//
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//�����Ķ����Ʊ�ʾ��3�б����ʽ��ԭ�룬���룬����
//���ڴ��д洢���Ƕ����ƵĲ���

//��������ԭ�룬���벹����ͬ

//��������
//ԭ�룺 ����һ����������ֱ��д�����Ķ����ƾ���ԭ��
//���룺 ����λ���䣬����λ����λȡ��
//~ - ���˺Ű�λȡ��������λһ��ȡ��
//���룺 ����Ķ���������+1���ǲ���

//�������ڴ��д洢���ǲ���

//����ֽ���洢��
//��һ�����ݵĵ��ֽڵ����ݴ���ڸߵ�ַ�������ֽ�������ݷ��ڵ͵�ַ��

//С���ֽ���洢��
//��һ�����ݵĵ��ֽڵ����ݴ���ڵ͵�ַ�������ֽ�������ݷ��ڸߵ�ַ��

//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}

//ģ��⺯����ʵ��strlen
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - str;
//}

//ģ��⺯����ʵ��strcpy
//char my_strcpy(char* dst, const char* start)
//{
//	assert(dst && start);
//	while (*dst++ = *start++)
//	{
//		;
//	}
//	return dst;
//}
//
//
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	//printf("%d\n", len);
//	return 0;
//}


//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

void swap(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		//������
		while (arr[left] % 2 == 1)
		{
			left++;
		}
		//��ż��
		while (arr[right] % 2 == 0)
		{
			right--;
		}
		//����
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}

}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	swap(arr, sz);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}