#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//����һ��������������������ַ�������ʽ�������
//���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
//�����ַ�������Ȼ���ٵ������
//int main()
//{
//    char str[32] = { 0 };
//    scanf("%s", str);
//    int i = 0;
//    for (i = strlen(str) - 1; i >= 0; i--)
//    {
//        printf("%c", str[i]);
//    }
//    return 0;
//}

//������ӵ�����
//
//ʾ��1
//���룺
//I am a student
//
//�����
//student a am I

//int main()
//{
//    char s[10000] = { 0 };
//    gets(s);
//    int len = strlen(s);
//    int p1 = len - 1;
//    int p2 = len;
//    while (p1 >= 0)
//    {
//        while (p1 >= 0 && !isalpha(s[p1]))
//            p1--;//��s[p1]�����ַ�ʱ����p1ָ��ǰ�������һ��Ԫ��
//        p2 = p1;//��p2���ڵ�ǰ�������һ��Ԫ��
//        while (p1 >= 0 && isalpha(s[p1]))
//            p1--;//��s[p1]���ַ�ʱͬ������--�����p1+1ָ��õ��ʿ�ͷ
//        for (int i = p1 + 1; i <= p2; i++)
//            printf("%c", s[i]);//��ӡһ������
//        printf(" ");
//    }
//    return 0;
//}

//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ�
//�������Ӷ��������ʵ�n���µ���������Ϊ���٣�

//int fib(int n)
//{
//    if (n == 1 || n == 2)
//    {
//        return 1;
//    }
//    return fib(n - 1) + fib(n - 2);//쳲���������
//}
//int main()
//{
//    int n = 0;
//    int ret = 0;
//    while (scanf("%d\n", &n) != EOF)
//    {
//        ret = fib(n);
//        printf("%d\n", ret);
//    }
//    return 0;
//}



//���еĶ������£����еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�
//81 4
//94.73
//
//2 2
//3.41

//int main()
//{
//    double n = 0.00;
//    int m = 0;
//    while (scanf("%lf %d", &n, &m) != EOF)
//    {
//        double sum = 0.00;
//        for (int i = 0; i < m; i++)//ǰm���ƽ�������
//        {
//            sum += n;
//            n = sqrt(n);
//        }
//        printf("%.2lf\n", sum);
//    }
//    return 0;
//}

//����������Ϸ��the game of master mind�����淨���¡�
//
//�������4���ۣ�ÿ���۷�һ������ɫ�����Ǻ�ɫ��R������ɫ��Y������ɫ��G������ɫ��B����
//���磬�����������RGGB 4�֣���1Ϊ��ɫ����2��3Ϊ��ɫ����4Ϊ��ɫ������Ϊ�û�������ͼ�³���ɫ��ϡ�����ȷ�������ܻ��YRGB��Ҫ�ǲ¶�ĳ���۵���ɫ������һ�Ρ����С���Ҫ��ֻ�¶���ɫ����λ�´��ˣ�����һ�Ρ�α���С���ע�⣬�����С��������롰α���С���
//
//����һ����ɫ���solution��һ���²�guess����дһ�����������ز��к�α���еĴ���answer��
//����answer[0]Ϊ���еĴ�����answer[1]Ϊα���еĴ�����
//
//ʾ����
//
//���룺 solution = "RGBY", guess = "GGRR"
//�����[1, 1]
//���ͣ� ����1�Σ�α����1�Ρ�
//
//int* masterMind(char* solution, char* guess, int* returnSize)
//{
//	*returnSize = 2;
//	int* ret = (int*)malloc(2 * sizeof(int));
//	int cnt = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		if (solution[i] == guess[i])
//		{
//			solution[i] = 0;
//			guess[i] = 0;
//			cnt++;
//		}
//	}
//	ret[0] = cnt;
//	cnt = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (solution[i] == guess[j] && guess[j] != 0)
//			{
//				guess[j] = 0;
//				cnt++;
//				break;
//			}
//		}
//	}
//	ret[1] = cnt;
//	return ret;
//}



//����һ���������� numbers ��һ��Ŀ��ֵ target�������������ҳ���������������Ŀ��ֵ�������±꣬
//���ص��±갴�������С�
//���룺
//[3, 2, 4], 6
//����
//����ֵ��
//[2, 3]
//����
//˵����
//��Ϊ 2 + 4 = 6 ���� 2���±�Ϊ2 �� 4���±�Ϊ3 ������Ϊ �±�2 < �±�3 �����Է���[2, 3]
//int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < numbersLen; i++)
//    {
//        if (numbers[i] > target)
//            continue;
//        for (int j = i + 1; j < numbersLen; j++)
//        {
//            int sum = numbers[i] + numbers[j];
//            if (sum == target)
//            {
//                ret[0] = i + 1;
//                ret[1] = j + 1;
//                *returnSize = 2;
//                return ret;
//            }
//        }
//    }
//    *returnSize = 0;
//    return 0;
//}