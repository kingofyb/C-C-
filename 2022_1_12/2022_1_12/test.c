#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//����һ���������У�KiKi������е��ظ�������ȥ��������ȥ�غ�����д�С�����������

//int main()
//{
//    int n, i, j, tmp;
//    scanf("%d", &n);
//    int a[100];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d ", &a[i]);
//    }
//    for (i = 0; i < n - 1; i++)
//    {
//        for (j = i + 1; j < n; j++)
//        {
//            if (a[j] == a[i])
//            {
//                a[j] = -1;
//            }
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = i; j < n; j++)
//        {
//            if (a[j] < a[i])
//            {
//                tmp = a[j];
//                a[j] = a[i];
//                a[i] = tmp;
//            }
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        if (a[i] != -1)
//        {
//            printf("%d ", a[i]);
//        }
//    }
//    return 0;
//}


//KiKi��֪��һ��n�׷����Ƿ�Ϊ�����Ǿ������������ж���
//�����Ǿ������Խ������µ�Ԫ�ض�Ϊ0�ľ������Խ���Ϊ�Ӿ�������Ͻ������½ǵ����ߡ�
//3
//1 2 3
//0 4 5
//0 0 6
//�����
//YES

//int main()
//{
//    int n, i, j;
//    int arr[10][10];
//    int sum = 0;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//            while (i > j)
//            {
//                sum += arr[i][j];
//                break;
//            }
//        }
//    }
//    if (sum == 0)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}