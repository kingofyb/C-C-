#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�

int main()
{
    int arr[] = { 1,2,3,4,5,1,2,3,4,6,6,5,8,9 };
    //1. �������һ��
    int ret = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        ret ^= arr[i];
    }
    //2. ����ret�Ķ������еڼ���λ��1
    int pos = 0;
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            pos = i;
            break;
        }
    }
    //3.���յ�posλΪ0��1������
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

//�����Ҫ��
//1.ֻ����1�ε�2�����֣��ֱ�2�����У�һ��������һ��
//2. ÿ���鶼���㣬ֻ��1�����ֳ���һ�Σ��������ֶ��ǳɶԳ��ֵ�

//1 1 5
//2 2 3 3 4 4 6
//�����ֽ��з���
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
     //�����һ������
    int i = 0;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    //����ڶ�������
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    //�ϲ����
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
