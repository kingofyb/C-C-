#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stddef.h>
//������һ������Ϊ n �����������У�����ֻ��һ����ֵ�����������Σ�
//������ֵ������ż���Σ������ҳ��Ǹ����������ε���ֵ��
//���룺
//5
//2 1 2 3 1
//
//�����
//3

//�����������
//a^ a = 0
//0 ^ a = a
//x ^ x ^ x ^ y = x ^ y
//int main()
//{
//    int n = 0;
//    int ret = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        int tmp = 0;
//        scanf("%d", &tmp);
//        ret ^= tmp;
//    }
//    printf("%d\n", ret);
//    return 0;
//}


//���룺
//[2, 4, 1, 2, 7, 8, 4]
//����ֵ��
//1
//˵����
//4��8���Ƿ�ֵԪ�أ�����4������1����8������5������

//int findPeakElement(int* nums, int numsLen) {
//    // write code here
//    int left = 0;
//    int right = numsLen - 1;
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] < nums[mid + 1])
//        {
//            left = mid + 1;
//            //nums[mid] < nums[mid + 1]˵���ڡ����¡���
//            //�����ʹleft = mid + 1����Ϊmid�϶����Ƿ�ֵ�����򡰷塱��ѹ��
//        }
//        else
//        {
//            right = mid;
//            //nums[mid] > nums[mid + 1]˵���ڡ����¡���
//            //��Ӧ��ʹright = mid��mid�����Ƿ�ֵ���������塱��ѹ��
//        }
//    }
//    return left;
//}

	
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	for (; i > 0; i -= 3)
//	{
//		++j;
//	}
//	printf("%d\n", j);
//	return 0;
//}
//unsigned char 8 λ����λ����Χ�� 0 - 255 
//7 4 1 -> ��(7 - 1) / 3 + 1 = 3 �� ��1 - 3 = -2���� 254 ������ѭ����
//254 251 ... 5 2 -> ��(254 - 2) / 3 + 1 = 85 �Σ�2 - 3 = -1���� 255 ������ѭ����
//255 252 ... 6 3 -> ��(255 - 5) / 3 + 1 = 85 �Σ� 3 - 3 = 0 ���˳�ѭ���� �����ܹ� 173 ��



//ţţ��ǰ����ʦ����õ���һ������������(x, y), ţţ�������Ǿ����Ƕ����ˡ�
//
//����ţţ�ǵ���ʦ���߹���x��y��������n, ����x����y���������ڵ���k��
//ţţϣ�����ܰ�������һ���ж��ٸ����ܵ����ԡ�
//
//����������
//�����������������n, k(1 <= n <= 10 ^ 5, 0 <= k <= n - 1)��turn 0;
//
//���룺
//5 2
//�����
//7
//˵����
//����������������(2, 3), (2, 4), (2, 5), (3, 4), (3, 5), (4, 5), (5, 3)
//int main()
//{
//    long n = 0, k = 0;
//    while (scanf("%ld %ld", &n, &k) != EOF)
//    {
//        if (k == 0)
//        {
//            printf("%ld\n", n * n);
//            continue;
//        }
//        long count = 0;
//        for (long y = k + 1; y <= n; y++)
//        {
//            long ret = n % y < k ? 0 : n % y - (k - 1);
//            count += (y - k) * (n / y) + (ret);
//        }
//        printf("%ld\n", count);
//    }
//    return 0;
//}



//���룺
//abABCcDEF
//6
//
//�����
//abABCc

//int main()
//{
//    char str[1001];
//    int n = 0;
//    while (scanf("%s", str) != EOF)
//    {
//        scanf("%d", &n);
//        str[n] = '\0';
//        printf("%s\n", str);
//    }
//
//    return 0;
//}

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//struct Stu
//{
//	char name[20];
//	char sex[5];
//	int age;
//	int hight;
//};
//
//struct Data
//{
//	struct Stu s;
//	char ch;
//	double d;
//};
//
//int main()
//{
//	struct Node n2 = {100, NULL};
//	struct Stu s1 = { "zhangsan", "nan", 20, 180 };
//	struct Data d = { {"lisi", "nv", 30, 166},'w', 3.14};//Ƕ��
//
//	return 0;
//}


//struct S1
//{
//	char c1;//1
//	int i;//4
//	char c2;//1
//};//12
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};//8
//
////offsetof
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	struct S4 s;
//	printf("%d\n", sizeof(struct S1));//12
//	printf("%d\n", sizeof(struct S2));//8
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//
//  //�ṹ���ڴ����
//  //1.�ṹ��ĵ�һ����Ա������ڽṹ�������ʼλ�õ�0ƫ�ƴ�
//  //VS������һ��Ĭ�϶�������8
//  //2.�ӵڶ�����Ա��ʼ����Ҫ���뵽ĳ�����֣��������������������Ķ��봦
//  //��������������Ĭ�ϵĶ�������ó�Ա��С�Ľ�Сֵ
//  //3.�ṹ����ܴ�С�����������Ķ�������������
//  //Linux����û��Ĭ�϶�����
//  //4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��
//  //�������С��������������������Ƕ�׽ṹ��Ķ���������������e.g. s3�Լ�������������8
//	//printf("%d\n", offsetof(struct S1, c1));//0
//	//printf("%d\n", offsetof(struct S1, i));//4
//	//printf("%d\n", offsetof(struct S1, c2));//8
//
//	return 0;
//}