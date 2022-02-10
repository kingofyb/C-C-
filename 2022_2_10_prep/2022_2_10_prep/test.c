#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//中心下标左侧所有元素相加的和等于右侧所有元素相加的和
//int pivotIndex(int* nums, int numsSize) {
//    int total = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        total += nums[i];
//    }
//    int sum = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (2 * sum + nums[i] == total)
//        {
//            return i;
//        }
//        sum += nums[i];
//    }
//    return -1;
//}
//#define size 10
//char str1[size], str2[size + 2];
//int num['10'];
//int main()
//{
//	char c[5] = { 'a', 'b', '\0', 'c', '\0' };
//	printf("%s", c);
//	int a[2][3] = { 0 };
//	a[1>2][1] = 1;
//	char b[10] = '5';
//	return 0;
//}

//编写一个函数，计算字符串中含有的不同字符的个数。字符在 ASCII 码范围内(0~127 ，包括 0 和 127)，
//换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
//例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。
//
//int main()
//{
//    char arr[501] = { '\0' };//存放字符串
//    int cnt[128] = { 0 };//把字符串对应的ascii码作为下标
//    int sum = 0;//计算不同字符个数
//	  int i = 0;
//    scanf("%s", arr);
//    for (i = 0; i < strlen(arr); ++i)
//    {
//        cnt[arr[i]]++;
//    }
//    //只要不为0 sum就加
//    for (i = 0; i < 128; ++i)
//    {
//        if (cnt[i])
//            sum++;
//    }
//    printf("%d", sum);
//}

//找众数
//int majorityElement(int* nums, int numsSize) {
//    int mode = nums[0];
//    int cnt = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == mode)
//        {
//            cnt++;
//        }
//        else
//        {
//            cnt--;
//        }
//        if (cnt <= 0)
//        {
//            mode = nums[i + 1];
//        }
//    }
//    return mode;
//}