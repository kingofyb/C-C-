#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}

//дһ����������������һ���ַ��������ݡ�
//int main()
//{
//	char ch1[100] = { "there is a banana" };
//	char ch2[100];
//	int len = strlen(ch1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		ch2[i] = ch1[len - i - 1];
//		printf("%c", ch2[i]);
//	}
//	return 0;
//}

//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int num = 3;
//	int len = 3;
//	int sum = 0;
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		tmp = tmp * 10 + num;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}


//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//��:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 100000; i++)
//	{
//		int n = 1;
//		int sum = 0;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp = tmp / 10;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}


//��ӡ����
int main()
{
	int line = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &line);
	//�ϰ벿��
	for (i = 0; i < line; i++)
	{
		for (n = 0; n < line - i - 1; n++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//�°벿��
	for (i = 0; i < line; i++)
	{
		for (n = 0; n < i + 1; n++)
		{
			printf(" ");
		}
		for (j = 0; j < (line - i - 1) * 2 - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}