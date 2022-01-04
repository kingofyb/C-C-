#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//BC121 小乐乐学编程
//int main()
//{
//    printf("Practice makes perfect!\n");
//    return 0;
//}

//BC122 小乐乐算平均分
//int main()
//{
//    float a, b, c;
//    scanf("%f %f %f", &a, &b, &c);
//    double avg = 0;
//    double sum = 0;
//    sum = a + b + c;
//    avg = sum / 3.0;
//    printf("%.2f %.2f", sum, avg);
//    return 0;
//}


//BC123 小乐乐找最大数
//int main()
//{
//    int arr[4] = { 0 };
//    int i = 0;
//    int tmp = 0;
//    for (i = 0; i < 4; i++)
//    {
//        scanf("%d ", &arr[i]);
//        if (arr[i] > tmp)
//        {
//            tmp = arr[i];
//        }
//    }
//    printf("%d\n", tmp);
//    return 0;
//}


//小乐乐的班级进行了一次期中考试，考试一共有3门科目：数学，语文，英语，
//小乐乐的班主任决定给没有通过考核的同学家长开一次家长会，
//考核的标准是三科平均分不低于60分，所以现在想请你帮忙算一算小乐乐会不会被叫家长。

//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    double avg = 0;
//    avg = (a + b + c) / 3.0;
//    if (avg >= 60)
//    {
//        printf("NO\n");
//    }
//    else
//    {
//        printf("YES\n");
//    }
//    return 0;
//}


//小乐乐输入百分制成绩，他想将成绩转换成等级制。转换规则为：90 - 100为’A’，80 - 89为’B’，
//70 - 79为’C’，60 - 69为’D’，59以下为’E’。如果输入的成绩不在0 - 100之间，输出’F’。

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    if (n <= 100 && n >= 90)
//    {
//        printf("A");
//    }
//    else if (n <= 89 && n >= 80)
//    {
//        printf("B");
//    }
//    else if (n <= 79 && n >= 70)
//    {
//        printf("C");
//    }
//    else if (n <= 69 && n >= 60)
//    {
//        printf("D");
//    }
//    else if (n < 60 && n >= 0)
//    {
//        printf("E");
//    }
//    else
//    {
//        printf("F");
//    }
//    return 0;
//}