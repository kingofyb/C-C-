#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//��n��̨�ף�ÿ�ο�����һ�׻�������
//int fib(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//1 1 
//	//2 2
//	//		1 f(n-1)
//	//f(n)
//	//		2 f(n-2)
//	//f(n)=f(n-1)+f(n-2)
//	int ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}


//����ȥ�أ�Ȼ���С��������

//����һ�������飬�����ַŵ���Ӧ�������±꣬���������ظ�
//���Ǹ�����ȥ����һ����ֵ
//��̬���� �Կռ��ʹ��û�кķ�̫���ջ�ռ�
//int arr[100001] = { 0 };
//int main()
//{
//	//�ȽϺķ�ջ�ռ�
//	//int arr[100001] = { 0 };
//	int n = 0;
//	int k = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &k);
//		arr[k] = k;
//	}
//	for (i = 0; i < 100001; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}


//С����ѧУ��ѧ¥�ĵ���ǰ���˺ܶ��ˣ�����ǰ����n�����ڵȵ���
//����ÿ�ο�����12�ˣ�ÿ������ʱ��Ϊ4����(��ȥ2���ӣ�����2����)
//����С������Ҫ�ȶ��ٷ��Ӳ��ܳ˵��ݵ�¥�ϣ��������һ��ʼ��1��

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int t = (n / 12) * 4 + 2;
//	printf("%d\n", t);
//	return 0;
//}

//������������ڣ���������һ��ĵڼ��졣
//��֤���Ϊ4λ�������ںϷ���

//int main()
//{
//    int m[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    scanf("%d %d %d", &year, &month, &day);
//    int cnt = 0;
//    if (month >= 2)
//    {
//        cnt = m[month - 2] + day;
//    }
//    else
//    {
//        cnt = day;
//    }
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 && month >= 3)
//    {
//        cnt++;
//    }
//    printf("%d\n", cnt);
//    return 0;
//}