#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%p\n", &a[0][0]);
//	printf("%p\n", &a+1);
//
//	////printf("%p\n", a[0] + 1);
//	//printf("%p\n", a + 1);
//	//int* p = a + 1;
//	
//	//printf("%d\n", sizeof(a));//数组名单独放在sizeof内部，计算的是整个数组的大小
//	//printf("%d\n", sizeof(a[0][0]));
//	//printf("%d\n", sizeof(a[0]));//a[0]表示第一行的数组名，a[0]作为数组名单独放在sizeof内部，计算的是第一行的大小。16个字节
//	//printf("%d\n", sizeof(a[0] + 1));//a[0]+1是第一行第二个元素的地址，是地址就4/8
//	//printf("%d\n", sizeof(*(a[0] + 1)));//第一行第二个元素，4
//	//printf("%d\n", sizeof(a + 1))//;a+1是第二行地址，是类型为int(*)[4]的数组指针，是地址就是4/8字节
//	//printf("%d\n", sizeof(*(a + 1)));//*(a+1)就是第二行，相当于第二行的数组名,*(a+1)->a[1],计算的是第二行的大小，16字节
//	//printf("%d\n", sizeof(&a[0] + 1));//&a[0]+1就是第二行的地址，是地址就4/8字节
//	//printf("%d\n", sizeof(*(&a[0] + 1)));//相当于第二行，也就是a[1]，大小是16字节
//	//printf("%d\n", sizeof(*a));//二维数组的首元素，也就是第一行 *a -> *(a+0) -> a[0]，16个字节
//	//printf("%d\n", sizeof(a[3]));//感觉a[3]是越界了，但是没关系，16个自己
//
//	return 0; 
//}

//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//跳过二十个字节 0x100014(16进制)
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//
//	printf("%x\n", p + 0x1);
//	printf("%x\n", (unsigned long)p + 0x1);
//	printf("%x\n", (unsigned int*)p + 0x1);
//	//%p 以地址的形式打印，不省略
//	//%x 就是打印16进制，省略
//	return 0;
//}

//int main()
//{
//    int a[4] = { 1, 2, 3, 4 };
//    int* ptr1 = (int*)(&a + 1);
//    int* ptr2 = (int*)((int)a + 1);//一个数加1 0x02 00 00 00
//    printf("%x,%x", ptr1[-1], *ptr2);//4 2000000
//    //小端：
//    //(01 00 00 00) (02 00 00 00) (03 00 00 00) (04 00 00 00)
//    //低                                                   高
//    //假设首元素地址a为0x10(16） .01 00 00 00
//    //16+1=17 0x11
//    //01. (00 00 00 02)
//    //0x02 00 00 00
//    return 0;
//}

//int main()
//{
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    逗号表达式：
//    第一行：1 3
//    第二行：5 0
//    第三行：0 0
//    int* p;
//    p = a[0];//a[0] = 1
//    printf("%d", p[0]);//p[0] = *p = 1
//    return 0;
//}

//int main()
//{
//    int a[5][5];
//    int(*p)[4];//p是一个数组指针，p能够指向的数组是4个元素
//    p = a;
//    //p[4][2] --> *(*(p+4)+2) *(p+4) -> a[3][1]
//    //p每次+1都跳过a里的4个元素
//    //*(*(p+4)+2) -> a[3][3]
//    printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//(ff ff ff fc) (-4) 
//    //                 整型地址   整型地址 
//    //计算的是&p[4][2] - &a[4][2]元素个数
//    return 0;
//}

//int main()
//{
//    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int* ptr1 = (int*)(&aa + 1);
//    int* ptr2 = (int*)(*(aa + 1));//aa+1指向第二行
//    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10 5
//    return 0;
//}

//int main()
//{
//	for (int i = 0; i || i++ < 5;)
//	{
//		printf("*\n");
//	}
//	return 0;
//}


//给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
//请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。
//如果是，则返回 最大元素的下标 ，否则返回 - 1 。
//示例 1：
//
//输入：nums = [3, 6, 1, 0]
//输出：1
//解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
//int dominantIndex(int* nums, int numsSize) {
//    int m1 = -1;
//    int m2 = -1;
//    int index = -1;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > m1)
//        {
//            m2 = m1;
//            m1 = nums[i];
//            index = i;
//        }
//        else if (nums[i] > m2)
//        {
//            m2 = nums[i];
//        }
//    }
//    return m1 >= m2 * 2 ? index : -1;
//}


//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是唯一的。
//我们可以 不考虑输出结果的顺序 。
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]

//int cmp(const void* e1, const void* e2) {
//    return (*(int*)e1 - *(int*)e2);
//}
//
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    int* res = (int*)malloc(sizeof(int) * nums1Size);
//    *returnSize = 0;
//
//    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
//    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);
//
//    for (int i = 0, j = 0; i < nums1Size; ++i) {
//        if (i != 0 && nums1[i] == nums1[i - 1])
//            continue;
//        int left = 0, right = nums2Size - 1, mid;
//        while (left <= right) {
//            mid = (left + right) / 2;
//            if (nums2[mid] == nums1[i]) {
//                res[j++] = nums1[i];
//                (*returnSize)++;
//                break;
//            }
//            else if (nums2[mid] < nums1[i])
//                left = mid + 1;
//            else
//                right = mid - 1;
//        }
//    }
//    return res;
//}