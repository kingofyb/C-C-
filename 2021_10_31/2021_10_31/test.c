#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//goto���
//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//	return 0;
//}

//дһ���ػ�����
//ֻҪ���������ˣ��͵���ʱ69��ػ������60���ڣ�������: ��������ȡ���ػ�����������룬ʱ�䵽�ػ�

//windows�ṩ�Ĺػ����� - shutdown
//shutdown -s -t 60 --> 60���ػ�
//shutdown -a ȡ���ػ�
//system() - �⺯��-ִ��ϵͳ����
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shut down -s -t 60");
//again:
//	printf("��ע����ĵ�����1�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("$s", input);
//	//�ж�
//	if (strcmp(input, "������") == 0)
//	{
//		//ȡ���ػ�
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

 //����
//int main()
//{
//	char arr[] = "hello world";
//	//��ǰ����ַ��ĳ�x
//	memset(arr, 'x', 5);
//	printf("%s", arr);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	int z = 0;
//	z = (x > y ? x : y);
//	return z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int m = get_max(a, b);
//	printf("%d", m);
//	return 0;
//}

//дһ���������Խ����������ͱ���������
//void swap(int* pa, int* pb)//���庯��ʱ����ʽ����
//{
//	int z = 0;
//	z = *pa;
//	*pa = *pb;
//	*pb = z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ:a=%d b=%d\n", a, b);
//	//����
//	swap(&a,&b);//ʵ�ʲ���
//	printf("������:a=%d b=%d\n", a, b);
//	return 0;
//}

//дһ�������ж��ǲ�������
//int is_prime(int n)
//{
//	//2~n-1�������Գ�
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//����ʵ����������������ֲ���
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
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
			return mid;
		}
	}
	return - 1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k, sz);
	if (ret == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���%d\n", ret);
	}

	return 0;
}