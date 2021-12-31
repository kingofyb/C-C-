#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//一行，输入两个整数n和m，用空格分隔，第二行包含n*m个整数（范围-231~231-1）。(1≤n≤10, 1≤m≤10)
//输出规划后n行m列的矩阵，每个数的后面有一个空格。

//int main()
//{
//    int n, m, i, j;
//    scanf("%d %d", &n, &m);
//    int arr[10][10] = { 0 };
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}



//第一行包含两个整数n和m，表示这个方阵队列包含n行m列。从2到n+1行，每行输入m个整数（范围-231~231-1），
//用空格分隔，共输入n*m个数，表示方阵中的所有人的身高（保证输入身高都不相同）。(1≤x≤n≤10，1≤y≤m≤10)
//一行，输出两个整数，用空格分隔，表示方阵中身高最高的人所在的行号和列号。


//int main()
//{
//    int n, m, i, j, max;
//    int x = 0;
//    int y = 0;
//    int arr[10][10] = { 0 };
//    scanf("%d %d", &n, &m);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//            if (arr[i][j] > max)
//            {
//                x = i + 1;
//                y = j + 1;
//                max = arr[i][j];
//            }
//        }
//    }
//    printf("%d %d", x, y);
//    return 0;
//}



//第一行包含两个整数n和m，表示两个矩阵包含n行m列，用空格分隔。
//从2到n + 1行，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第一个矩阵中的元素。
//从n + 2行到2n + 1，每行输入m个整数（范围 - 231~231 - 1），用空格分隔，共输入n * m个数，表示第二个矩阵中的元素。
//1 < n, m < 10
//一行，如果两个矩阵相等输出"Yes"并换行，否则输出"No"并换行。


//int main()
//{
//    int n, m, i, j;
//    int sum = 0;
//    scanf("%d %d", &n, &m);
//    int arr[20][20] = { 0 };
//    for (i = 0; i < 2 * n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d ", &arr[i][j]);
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            if (arr[i][j] == arr[i + n][j])
//            {
//                sum++;
//            }
//        }
//    }
//    if (sum == n * m)
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//    return 0;
//}