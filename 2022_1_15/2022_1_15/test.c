#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>


//������Ϊ1��ż����Ϊ0
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 0;
//	int tmp = 0;
//	while (n)
//	{
//		tmp = n % 10;
//		if (tmp % 2 == 1)
//		{
//			tmp = 1;
//		}
//		else
//		{
//			tmp = 0;
//		}
//		sum += tmp * pow(10, i++);
//		n /= 10;
//	}
//	printf("%d\n", sum);
//	return 0;
//}



//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3��
//���ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
//1. �÷���һ�������б��������ӡ
//2. n Ϊ������

//static int arr[100010];
//int* printNumbers(int n, int* returnSize) {
//	// write code here
//	int num = 1;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		num *= 10;
//	}
//	for (i = 1; i < num; i++)
//	{
//		arr[i - 1] = i;
//	}
//	*returnSize = --i;
//	return arr;
//}