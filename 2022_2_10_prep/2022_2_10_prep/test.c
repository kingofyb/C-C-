#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//�����±��������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ�
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

//��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ��� ASCII �뷶Χ��(0~127 ������ 0 �� 127)��
//���б�ʾ���������������ַ�����ڷ�Χ�ڵĲ���ͳ�ơ������ͬ���ַ�ֻ����һ��
//���磬�����ַ��� abaca ���ԣ��� a��b��c ���ֲ�ͬ���ַ��������� 3 ��
//
//int main()
//{
//    char arr[501] = { '\0' };//����ַ���
//    int cnt[128] = { 0 };//���ַ�����Ӧ��ascii����Ϊ�±�
//    int sum = 0;//���㲻ͬ�ַ�����
//	  int i = 0;
//    scanf("%s", arr);
//    for (i = 0; i < strlen(arr); ++i)
//    {
//        cnt[arr[i]]++;
//    }
//    //ֻҪ��Ϊ0 sum�ͼ�
//    for (i = 0; i < 128; ++i)
//    {
//        if (cnt[i])
//            sum++;
//    }
//    printf("%d", sum);
//}

//������
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