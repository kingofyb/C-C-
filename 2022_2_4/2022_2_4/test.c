#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//int checkRound(char* src, char* check)
//{
//	char tmp[256] = { 0 };
//	strcpy(tmp, src);
//	strcat(tmp, src);
//	return strstr(tmp, check) != NULL;
//}
//int main()
//{
//	char str1[5] = { 'A','A','B','C','D' };
//	char str2[5] = { 'A','B','C','D','A' };
//	int n = checkRound(str1, str2);
//	printf("%d\n", n);
//}


//��Ƴ�˹����
//int main()
//{
//    int num = 0;
//    while (scanf("%d", &num) != EOF)
//    {
//        int c = num * num * num;
//        for (int i = 1; i < 100000; i += 2)
//        {
//            int sum = (i + (i + (num - 1) * 2)) * num / 2;
//            if (sum == c)
//            {
//                for (int j = 0; j < num - 1; j++)
//                {
//                    printf("%d+", i + 2 * j);
//                }
//                printf("%d\n", i + 2 * (num - 1));
//            }
//        }
//    }
//    return 0;
//}



//�Ȳ����� 2��5��8��11��14��������
//����������
//����һ��������n��
//���������
//���һ����Ӻ��������
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        printf("%d\n", (2 + (2 + (3 * (n - 1)))) * n / 2);
//    }
//    return 0;
//}