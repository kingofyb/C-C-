#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//C99��׼֮ǰ�ǲ�֧��ʹ�ñ��� eg int arr[n]�� ֻ���ǳ��� int arr[10]
//C99֮�������˳�����ĸ����������Ĵ�С�Ǳ���
//����Ҫ�������֧��C99��׼

//strlen��һ���⺯������������ַ����ĳ��ȣ�����ֻ������ַ���
//��ע�����ַ������Ƿ���\n���������\0֮ǰ���ַ�����

//sizeof��һ�����������������
//sizeof���������������ռ�ڴ�ռ��С�ģ��κ����Ͷ��ǿ���ʹ��
//ֻ��ע�ռ��С�����ں��ڴ����Ƿ����\0

//һά�������ڴ�����������ŵ�

//ð������
//void bubble_sort(int arr[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,5,6,9,8,7,6 };
//	bubble_sort(arr, 7);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

////ʵ�ֺ���init() ��ʼ������Ϊȫ0
//void inti(int arr[], int sz, int n)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = n;
//	}
//}
//
//ʵ��Print()  ��ӡ�����ÿ��Ԫ��
void Print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

////ʵ��reverse()  �����������Ԫ�ص����á�
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = 0;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("�������Ϊ: \n");
//	Print(arr, 10);
//	printf("\n");
//	printf("��ת����\n");
//	reverse(arr, 10);
//	Print(arr, 10);
//	printf("\n");
//	printf("��ʼ������\n");
//	inti(arr, 10, 1);
//	Print(arr, 10);
//
//	return 0;
//}

//������A�е����ݺ�����B�е����ݽ��н�����������һ����
void swap(int arr1[], int arr2[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 5,4,3,2,1 };
	printf("ԭ����arr1Ϊ��\n");
	Print(arr1, 5);
	printf("\n");
	printf("ԭ����arr2Ϊ��\n");
	Print(arr2, 5);
	printf("\n");
	swap(arr1, arr2, 5);
	printf("ת����arr1Ϊ��\n");
	Print(arr1, 5);
	printf("\n");
	printf("ת����arr2Ϊ��\n");
	Print(arr2, 5);
	return 0;
}