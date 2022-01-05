#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//小乐乐的班主任想统计一下班级里一共有多少人需要被请家长，三个成绩（语文，数学，外语）
//平均分低于60的将被请家长，
//小乐乐想编程帮助班主任算一下有多少同学被叫家长。

//int main()
//{
//    int n, i, j, s;
//    scanf("%d", &n);
//    int cnt = 0;
//    for (i = 0; i < n; i++)
//    {
//        double avg = 0;
//        int sum = 0;
//        for (j = 0; j < 3; j++)
//        {
//            scanf("%d ", &s);
//            sum += s;
//        }
//        avg = sum / 3.0;
//        if (avg < 60)
//        {
//            cnt++;
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}


//小乐乐的老师BoBo想知道班级中谁的数学成绩最高，请编程帮他实现。

//int main()
//{
//    int n, tmp, i, m;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &m);
//        if (m > tmp)
//        {
//            tmp = m;
//        }
//    }
//    printf("%d", tmp);
//    return 0;
//}

//小乐乐想计算一下1!+ 2!+ 3!+ ... + n!。

//int fac(int n)//递归求阶乘
//{
//    if (n == 1)
//    {
//        return 1;
//    }
//    return n * fac(n - 1);
//}
//int main()
//{
//    int n = 0, i;
//    int sum = 0;
//    scanf("%d", &n);
//    for (i = n; i > 0; i--)
//    {
//        sum += fac(i);
//    }
//    printf("%d", sum);
//    return 0;
//}