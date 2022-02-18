#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stddef.h>
//自定义类型
//结构体
//枚举
//联合体
//struct Stu
//{
//  //成员列表
//	char name[20];
//	char sex[5];
//	int age;
//	int hight;
//}s2, s3, s4;//s2,s3,s4全局变量//变量列表
//
//struct Stu s5;
//
//int main()
//{
//	struct Stu s1;//结构体变量
//
//	return 0;
//}
//struct
//{
//	char c;
//	int a;
//	double d;
//}sa;
//
//struct
//{
//	char c;
//	int a;
//	double d;
//}* ps;
//
//
//int main()
//{
//	//编译器认为等号两边时不同的结构体类型，所以这种写法时错误的
//	ps = &sa;
//
//	return 0;
//}
////err
//struct Node
//{
//	int data;//4
//	struct Node next;
//};
////链表
//struct Node
//{
//	int data;
//	struct Node* next;
//};

////err
//typedef struct
//{
//	int data;
//	Node* next;
//}Node;

//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。请你找出所有在[1, n] 范围内但没
//有出现在 nums 中的数字，并以数组的形式返回结果
//【 leetcode 题号：448.找到所有数组中消失的数字】【难度：简单】
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int i = 0;
//    *returnSize = 0;
//
//    for (i = 0; i < numsSize; i++) 
//    {
//        /* 把当前位置上的元素减1当作下标，
//         * 再按照此下标对其对应元素进行加numsSize操作
//         */
//        nums[(nums[i] - 1) % numsSize] += numsSize;
//    }
//
//    for (i = 0; i < numsSize; i++) 
//    {
//        /* 若当前下标的 元素值 <= numsSize,
//         * 那么表示原数组里当前下标加1的元素出现0次，既缺少此元素
//         */
//        if (nums[i] <= numsSize) {
//            nums[*returnSize] = i + 1;
//            /* 这里返回数组的的大小表示若以原数组返回，
//             * 在外面的测试函数中则只取前*returnSize 这么多位进行判断
//             */
//            (*returnSize)++;
//        }
//    }
//
//    return nums;
//}

//最大连续 1 的个数
//示例：
//输入：[1, 1, 0, 1, 1, 1]
//输出：3
//int findMaxConsecutiveOnes(int* nums, int numsSize) {
//    int cnt = 0;
//    int tmp = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == 1)
//        {
//            cnt++;
//            if (cnt > tmp)
//            {
//                tmp = cnt;
//            }
//        }
//        else
//        {
//            cnt = 0;
//        }
//    }
//    return tmp;
//}


//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
//输入n，请输出n以内(含n)完全数的个数。
//int main()
//{
//    long n;
//    long cnt = 0;
//    long sum = 0;
//    while (scanf("%ld\n", &n) != EOF)
//    {
//        cnt = 0;
//        for (long i = 1; i <= n; i++)
//        {
//            sum = 0;
//            for (long j = 1; j < i; j++)
//            {
//                if (i % j == 0)
//                {
//                    sum += j;
//                }
//            }
//            if (i == sum)
//            {
//                cnt++;
//            }
//        }
//        printf("%ld\n", cnt);
//    }
//    return 0;
//}
