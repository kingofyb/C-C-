#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	int m, n;
//	printf("Enter m,n;");
//	scanf("%d%d", &m, &n);
//	while (m != n) //1
//	{
//		while (m > n) m = m - n; //2
//		while (n > m) n = n - m; //3
//	} 
//	printf("m=%d\n", m);
//	return 0;
//}
//
//int main()
//{
//	int n = 0; 
//	char ch[100] = { 0 };
//	for (ch = getchar(); ch != '\n'; n++);
//	return 0;
//}

//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//		do
//		{
//			switch (c = getchar())
//			{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default: v0 += 1; v2 += 1;
//			}
//		} while (c != '\n');
//		printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//		return 0;
//}
//int main()
//{
//	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
//	for (i = 1; i < 5; i++)
//	{
//		t = a[i];
//		j = i - 1;
//		while (j >= 0 && t < a[j])
//		{
//			a[j + 1] = a[j];
//			--j;
//		} a
//			[j + 1] = t;
//
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了
//成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//示例 1：
//
//输入：nums = [1, 2, 2, 4]
//输出：[2, 3]
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    int* arr1 = (int*)malloc(sizeof(int) * (numsSize));
//    for (int i = 0; i < numsSize; i++) {      // 初始化数组
//        arr1[i] = 0;
//    }
//    for (int i = 0; i < numsSize; i++) {      // 关键：记录各个数字出现的频次
//        arr1[nums[i] - 1]++;
//    }
//    int* arr2 = (int*)malloc(sizeof(int) * 2);
//    for (int i = 0; i < numsSize; i++) {
//        if (arr1[i] == 2) {
//            arr2[0] = i + 1;
//        }
//        if (arr1[i] == 0) {
//            arr2[1] = i + 1;
//        }
//    }
//    *returnSize = 2;
//    return arr2;
//}



//小明同学最近开发了一个网站，在用户注册账户的时候，需要设置账户的密码，为了加强账户的安全性，
//小明对密码强度有一定要求：
//
//1. 密码只能由大写字母，小写字母，数字构成；
//
//2. 密码不能以数字开头；
//
//3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；
//
//4. 密码长度至少为8
//
//现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的。
//
//输入描述：
//输入一个数n，接下来有n(n≤100)行，每行一个字符串，表示一个密码，输入保证字符串中只出现大写字母，
//小写字母和数字，字符串长度不超过100。
//输出描述：
//输入n行，如果密码合法，输出YES，不合法输出NO
//int main()
//{
//    int n = 0;
//    int i = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (i = 0; i < n; i++)
//        {
//            char pwd[101] = { 0 };
//            scanf("%s", pwd);
//            int upper = 0;
//            int lower = 0;
//            int num = 0;
//            int illegal = 0;
//            for (i = 0; pwd[i] != '\0'; i++)
//            {
//                if (pwd[i] >= '0' && pwd[i] <= '9')
//                    num++;//数字
//                else if (pwd[i] >= 'a' && pwd[i] <= 'z')
//                    lower++;//小写字母
//                else if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//                    upper++;//大写字母
//                else
//                    illegal++;//不合法
//                //1. 密码只能由大写字母，小写字母，数字构成；
//            }
//            if (pwd[0] >= '9' && pwd[0] <= '0')
//            {
//                printf("NO\n");
//                continue;
//                //2.密码不能以数字开头；
//            }
//            if ((num > 0) + (lower > 0) + (upper > 0) < 2)
//            {
//                printf("NO\n");
//                continue;
//                //3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；
//            }
//            if (strlen(pwd) < 8)
//            {
//                printf("NO\n");
//                continue;
//                //4. 密码长度至少为8
//            }
//            if (illegal != 0)
//            {
//                printf("NO\n");
//                continue;
//                //非法字符
//            }
//            printf("YES\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//    //把大写改成小写
//    //char ch[80] = "123abcdEFG*&";
//    //int j;
//    //puts(ch);
//    //for (j = 0; ch[j] != '\0'; j++)
//    //    if (ch[j] >= 'A' && ch[j] <= 'Z')
//    //        ch[j] = ch[j] + 'e' - 'E';
//    //puts(ch);
//
//    
//    int t = 0;
//    while (printf("*"))
//    {
//        t++;
//        if (t < 3)
//            break;
//    }
//    return 0;
//}


//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		putchar(ch);
//	} 
//	printf("\n");
//	return 0;
//}

//给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
//数据范围：0 \le n \le 1000, 0 \le k \le 1000≤n≤1000, 0≤k≤100，
//数组中每个元素的值满足 0 \le val \le 1000≤val≤100
//要求：空间复杂度 O(1)O(1)，时间复杂度 O(logn)O(logn)
//示例1
//输入：
//[1, 2, 3, 3, 3, 3, 4, 5], 3
//复制
//返回值： 4

//int GetNumberOfK(int* data, int dataLen, int k) {
//    // write code here
//    int i = 0;
//    int cnt = 0;
//    for (i = 0; i < dataLen; i++)
//    {
//        if (data[i] == k)
//        {
//            cnt++;
//        }
//    }
//    return cnt;
//}

//整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
//示例1 :
//输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
//输出：2
//int convertInteger(int A, int B) {
    //int cnt = 0;
    //int i = 0;
    //int ret = A ^ B;
    //for (i = 0; i < 32; i++)
    //{
    //    if ((ret >> i) & 1)
    //    {
    //        cnt++;
    //    }
    //}
    //return cnt;
//}