#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//max
//int max(int a, int b, int c)
//{
//    if (a > b)
//    {
//        b = a;
//    }
//    return b > c ? b : c;
//}
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    printf("%.2f\n", (float)max(a + b, b, c) / (max(a, b + c, c) + max(a, b, b + c)));
//    return 0;
//}



//给定n个整数和一个整数x，小乐乐想从n个整数中判断x出现几次，请编程帮他实现。
//输入描述：
//共3行
//第一行，一个整数，表示n（1 <= n <= 100）。
//第二行，共输入n个整数，两个整数之间用空格分隔。
//第三行，输入一个整数，表示要查找的整数x。

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[100] = { 0 };
//    int i, m;
//    int cnt = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d ", &arr[i]);
//    }
//    scanf("%d", &m);
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i] == m)
//        {
//            cnt++;
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}


