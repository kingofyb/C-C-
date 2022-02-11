#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//strcpy(接收拷贝的字符串，源字符串)
//源字符串必须以'\0'结尾
//char* my_strcpy(char* dest, char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
////指针不知道赋什么值，就给NULL
////指针使用完后，赋值NULL
//
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);//判断是不是空指针
//	//1.目标空间中的\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.追加内容到目标空间
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
////strcmp - 字符串比较
////比较是对应位置上的字符大小
//int mystr_cmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	//if (*str1 > *str2)
//	//{
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return -1;
//	//}
//	return *str1 - *str2;
//}

// **************** 受长度限制函数 ********************
//strncpy(arr1,arr2,n) 拷贝arr2的前n个字符到arr1


//int main()
//{
//	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, * p[4], i;
//	for (i = 0; i < 4; i++)
//		p[i] = &a[i * 3];
//	printf("%d\n",p[3][2]);
//	return 0;
//}

//int main()
//{
//	char a = 'a', b;
//	printf("%c,", ++a);
//	printf("%c\n", b = a++);
//	return 0;
//}


//返回两个数中所有的自除数
//e.g. 128可以被1，2，8整除 所以是自除数
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* ret = malloc(sizeof(int) * 200);
    int i = 0;
    while (left <= right) {
        int tmp = left;
        while (tmp != 0) {
            int sign = tmp % 10;
            if (sign == 0) {
                break;
            }
            if (left % sign != 0)
            {
                break;
            }
            tmp = tmp / 10;
        }
        if (tmp == 0) {
            ret[i] = left;
            left++;
            i++;
        }
        else {
            left++;
        }
    }
    *returnSize = i;
    return ret;
}

//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//输入: nums = [1, 2, 3, 4]
//输出 : [24, 12, 8, 6]
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//    int i = 0;
//    int product = 1;
//    int* ret = malloc(numsSize * sizeof(int));
//    for (i = 0; i < numsSize; i++) {
//        ret[i] = product;
//        product = product * nums[i];
//    }
//    product = 1;
//    for (i = numsSize - 1; i >= 0; i--) {
//        ret[i] = ret[i] * product;
//        product = nums[i] * product;
//    }
//    *returnSize = numsSize;
//    return ret;
//}