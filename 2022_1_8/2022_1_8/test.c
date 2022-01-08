#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//复习考试中
//三科最好成绩

//int max(int a, int b, int c)
//{
//    if (a > b)
//    {
//        return a > c ? a : c;
//    }
//    else
//    {
//        return b > c ? b : c;
//    }
//}
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    printf("%d", max(a, b, c));
//    return 0;
//}



//求三位数的素数

//int main()
//{
//    int cnt = 0;
//    int n = 1;
//    for (int i = 100; i < 999; i++)
//    {
//        n = 1;
//        for (int j = 2; j < i; j++)
//        {
//            if (i % j == 0)
//            {
//                n = 0;
//            }
//        }
//        if (n)
//        {
//            cnt++;
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}
