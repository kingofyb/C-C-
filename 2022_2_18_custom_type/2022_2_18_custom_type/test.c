#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stddef.h>
//�Զ�������
//�ṹ��
//ö��
//������
//struct Stu
//{
//  //��Ա�б�
//	char name[20];
//	char sex[5];
//	int age;
//	int hight;
//}s2, s3, s4;//s2,s3,s4ȫ�ֱ���//�����б�
//
//struct Stu s5;
//
//int main()
//{
//	struct Stu s1;//�ṹ�����
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
//	//��������Ϊ�Ⱥ�����ʱ��ͬ�Ľṹ�����ͣ���������д��ʱ�����
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
////����
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

//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ������ҳ�������[1, n] ��Χ�ڵ�û
//�г����� nums �е����֣������������ʽ���ؽ��
//�� leetcode ��ţ�448.�ҵ�������������ʧ�����֡����Ѷȣ��򵥡�
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int i = 0;
//    *returnSize = 0;
//
//    for (i = 0; i < numsSize; i++) 
//    {
//        /* �ѵ�ǰλ���ϵ�Ԫ�ؼ�1�����±꣬
//         * �ٰ��մ��±�����ӦԪ�ؽ��м�numsSize����
//         */
//        nums[(nums[i] - 1) % numsSize] += numsSize;
//    }
//
//    for (i = 0; i < numsSize; i++) 
//    {
//        /* ����ǰ�±�� Ԫ��ֵ <= numsSize,
//         * ��ô��ʾԭ�����ﵱǰ�±��1��Ԫ�س���0�Σ���ȱ�ٴ�Ԫ��
//         */
//        if (nums[i] <= numsSize) {
//            nums[*returnSize] = i + 1;
//            /* ���ﷵ������ĵĴ�С��ʾ����ԭ���鷵�أ�
//             * ������Ĳ��Ժ�������ֻȡǰ*returnSize ��ô��λ�����ж�
//             */
//            (*returnSize)++;
//        }
//    }
//
//    return nums;
//}

//������� 1 �ĸ���
//ʾ����
//���룺[1, 1, 0, 1, 1, 1]
//�����3
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


//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
//���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1 + 2 + 4 + 7 + 14 = 28��
//����n�������n����(��n)��ȫ���ĸ�����
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
