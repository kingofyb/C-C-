#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//输入一个整数，将这个整数以字符串的形式逆序输出
//程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//当成字符串接收然后再倒叙输出
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

//输出句子的逆序
//
//示例1
//输入：
//I am a student
//
//输出：
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
//            p1--;//当s[p1]不是字符时，让p1指向当前单词最后一个元素
//        p2 = p1;//让p2等于当前单词最后一个元素
//        while (p1 >= 0 && isalpha(s[p1]))
//            p1--;//当s[p1]是字符时同样让它--，最后p1+1指向该单词开头
//        for (int i = p1 + 1; i <= p2; i++)
//            printf("%c", s[i]);//打印一个单词
//        printf(" ");
//    }
//    return 0;
//}

//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，
//假如兔子都不死，问第n个月的兔子总数为多少？

//int fib(int n)
//{
//    if (n == 1 || n == 2)
//    {
//        return 1;
//    }
//    return fib(n - 1) + fib(n - 2);//斐波那契数列
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



//数列的定义如下：数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
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
//        for (int i = 0; i < m; i++)//前m相的平方根相加
//        {
//            sum += n;
//            n = sqrt(n);
//        }
//        printf("%.2lf\n", sum);
//    }
//    return 0;
//}

//珠玑妙算游戏（the game of master mind）的玩法如下。
//
//计算机有4个槽，每个槽放一个球，颜色可能是红色（R）、黄色（Y）、绿色（G）或蓝色（B）。
//例如，计算机可能有RGGB 4种（槽1为红色，槽2、3为绿色，槽4为蓝色）。作为用户，你试图猜出颜色组合。打个比方，你可能会猜YRGB。要是猜对某个槽的颜色，则算一次“猜中”；要是只猜对颜色但槽位猜错了，则算一次“伪猜中”。注意，“猜中”不能算入“伪猜中”。
//
//给定一种颜色组合solution和一个猜测guess，编写一个方法，返回猜中和伪猜中的次数answer，
//其中answer[0]为猜中的次数，answer[1]为伪猜中的次数。
//
//示例：
//
//输入： solution = "RGBY", guess = "GGRR"
//输出：[1, 1]
//解释： 猜中1次，伪猜中1次。
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



//给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，
//返回的下标按升序排列。
//输入：
//[3, 2, 4], 6
//复制
//返回值：
//[2, 3]
//复制
//说明：
//因为 2 + 4 = 6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2, 3]
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