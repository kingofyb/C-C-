#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//欧几里得算法算公约公倍的和
//假如需要求 1997 和 615 两个正整数的最大公约数, 用欧几里得算法，是这样进行的：
//1997 / 615 = 3 (余 152)
//615 / 152 = 4(余7)
//152 / 7 = 21(余5)
//7 / 5 = 1 (余2)
//5 / 2 = 2 (余1)
//2 / 1 = 2 (余0)
//至此，最大公约数为1
//以除数和余数反复做除法运算，当余数为 0 时，取当前算式除数为最大公约数，
//所以就得出了 1997 和 615 的最大公约数 1。

//int main()
//{
//    long n, m, gy, gb, k;
//    scanf("%ld %ld", &n, &m);
//    k = n * m;
//    while (n && m)
//    {
//        if (n > m)
//        {
//            n %= m;
//        }
//        else
//        {
//            m %= n;
//        }
//    }
//    gy = n > m ? n : m;
//    gb = k / gy;
//    printf("%ld\n", gy + gb);
//    return 0;
//}

//可以先找到所有的C然后用所有的C去匹配所有的H，找到所有的CH之后再用所有CH匹配N组合成CHN
//例如：
//CHNNCCHN;
//你先找到所有的C：总共有3个-- > 之后用这3个C去找H：一个C可对应2个H则3个C可对应出6个CH
//用你找到的6个CH去匹配N-- > 一个CH对应可对应3个N 则6个CH可对应出18个CHN
//所以可以找到18个CHN

//int main()
//{
//    char arr[8001];
//    scanf("%s", arr);
//    char* p = arr;
//    long long ans = 0, sum = 0;
//    int c = 0, h = 0;
//    while (*p)
//    {
//        if (*p == 'C')
//        {
//            c++;
//        }
//        else if (*p == 'H')
//        {
//            h += c;
//        }
//        else if (*p == 'N')
//        {
//            ans += h;
//        }
//        p++;
//    }
//    printf("%lld", ans);
//    return 0;
//}