#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//给定一个整数序列，KiKi想把其中的重复的整数去掉，并将去重后的序列从小到大排序输出

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


//KiKi想知道一个n阶方矩是否为上三角矩阵，请帮他编程判定。
//上三角矩阵即主对角线以下的元素都为0的矩阵，主对角线为从矩阵的左上角至右下角的连线。
//3
//1 2 3
//0 4 5
//0 0 6
//输出：
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