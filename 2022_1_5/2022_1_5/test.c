#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//С���ֵİ�������ͳ��һ�°༶��һ���ж�������Ҫ����ҳ��������ɼ������ģ���ѧ�����
//ƽ���ֵ���60�Ľ�����ҳ���
//С�������̰�����������һ���ж���ͬѧ���мҳ���

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


//С���ֵ���ʦBoBo��֪���༶��˭����ѧ�ɼ���ߣ����̰���ʵ�֡�

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

//С���������һ��1!+ 2!+ 3!+ ... + n!��

//int fac(int n)//�ݹ���׳�
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