#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。

int main()
{
    int arr[] = { 1,2,3,4,5,1,2,3,4,6,6,5,8,9 };
    //1. 先异或在一起
    int ret = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    //2. 计算ret的二进制中第几个位是1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            pos = i;
            break;
        }
    }
    //3.按照第pos位为0或1来分组
    int n = 0;
    int m = 0;
    for (i = 0; i < sz; i++)
    {
        if (((arr[i] >> pos) & 1) == 1)
        {
            n ^= arr[i];
        }
    }
    m = ret ^ n;

    //for (i = 0; i < sz; i++)
    //{
    //	if (((arr[i] >> pos) & 1) == 0)
    //	{
    //		m ^= arr[i];
    //	}
    //}
    printf("%d %d\n", n, m);

    return 0;
}
//1 2 3 4 5 1 2 3 4 6
//1 1 3 3 5
//2 2 4 4 6
// 
//1 1 4 4 5
//2 2 3 3 6
//1^2^3^4^n^1^2^3^4^m = 5^6
//101
//110
//011
//

//分组的要求：
//1.只出现1次的2个数字，分别到2个组中，一个组中有一个
//2. 每个组都满足，只有1个数字出现一次，其他数字都是成对出现的

//1 1 5
//2 2 3 3 4 4 6
//对数字进行分组
//1 1 3 3 5 = 5
//2 2 4 4 6 = 6


/*
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);//
    int arr1[n];
    int arr2[m];
    // int arr3[m+n];
     //输入第一个数组
    int i = 0;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    //输入第二个数组
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    //合并输出
    int j = 0;

    i = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            // arr3[k++] = arr1[i];
            printf("%d ", arr1[i]);
            i++;
        }
        else
        {
            //arr3[k++] = arr2[j];
            printf("%d ", arr2[j]);
            j++;
        }
    }
    if (j == m)
    {
        for (; i < n; i++)
        {
            // arr3[k++] = arr1[i];
            printf("%d ", arr1[i]);
        }
    }
    else
    {
        for (; j < m; j++)
        {
            //  arr3[k++] = arr2[j];
            printf("%d ", arr2[j]);
        }
    }
    return 0;
}
*/
