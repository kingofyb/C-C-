#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//BC121 С����ѧ���
//int main()
//{
//    printf("Practice makes perfect!\n");
//    return 0;
//}

//BC122 С������ƽ����
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


//BC123 С�����������
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


//С���ֵİ༶������һ�����п��ԣ�����һ����3�ſ�Ŀ����ѧ�����ģ�Ӣ�
//С���ֵİ����ξ�����û��ͨ�����˵�ͬѧ�ҳ���һ�μҳ��ᣬ
//���˵ı�׼������ƽ���ֲ�����60�֣����������������æ��һ��С���ֻ᲻�ᱻ�мҳ���

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


//С��������ٷ��Ƴɼ������뽫�ɼ�ת���ɵȼ��ơ�ת������Ϊ��90 - 100Ϊ��A����80 - 89Ϊ��B����
//70 - 79Ϊ��C����60 - 69Ϊ��D����59����Ϊ��E�����������ĳɼ�����0 - 100֮�䣬�����F����

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