#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		//���λ
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		//��ʮλ
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//�������
//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
//int main()
//{
//	int odd = 1;
//	double total = 0.0;
//	for (int i = 1; i <= 100; i++)
//	{
//		total += odd * 1.0 / i;
//		total *= -1;
//	}
//	printf("%1f\n", total);
//	return 0;
//}

//��ʮ�������е����ֵ
//int main()
//{
//	int arr[10] = {0};
//
//	printf("�������Ǹ�����,�ÿո����:");
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}

//����Ļ�����9*9�˷��ھ���
//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			printf("%d * %d = %d\n", i, j, i * j);
//		}
//	}
//	return 0;
//}

//���ֲ���
//��д������һ���������������в��Ҿ����ĳ����
//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("�Ҳ���\n");
	}
	return 0;
}