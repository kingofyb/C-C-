#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>

#include<stdio.h>
#include<string.h>

//void left(char* ch, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(ch);
//	int tmp = 0;
//	n %= len;
//	for (i = 0; i < n; i++)
//	{
//		tmp = ch[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			ch[j] = ch[j + 1];
//		}
//		ch[j] = tmp;
//	}
//}
//
//int main()
//{
//	char arr[5] = "ABCD";
//	left(arr, 2);
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	return 0;
//}



//int youngT(int a[][3], int x, int y, int f) //��һ��������������Ҫ����
//{
//	int i = 0, j = x - 1; //�����Ͻǿ�ʼ����
//
//	while (j >= 0 && i < y)
//	{
//		if (a[i][j] < f) //���Ҵ������
//		{
//			i++;
//		}
//		else if (a[i][j] > f) //����С������
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a[][3] = { {1, 3, 5},
//				  {3, 5, 7},
//				  {5, 7, 9} }; //һ��ʾ��
//
//	if (youngT(a, 3, 3, 2))
//	{
//		printf("Exist\n");
//	}
//	else
//	{
//		printf("Not exist\n");
//	}
//
//	return 0;
//}