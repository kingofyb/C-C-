#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//leetcode 面试题17.04
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	for (i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//	return x;
//}

//leetcode 189 轮转数组
//void reverse(int* nums, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k) {
//	k %= numsSize;
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//}

int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 20);
	SeqListPrint(&s);

	//SeqListPrint(NULL);

	int a[10];
	//a[10] = 1;
	//a[11] = 1;
	a[12] = 1;
	a[100] = 1;

	return 0;
}