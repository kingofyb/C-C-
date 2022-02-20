#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stddef.h>
//现在有一个长度为 n 的正整数序列，其中只有一种数值出现了奇数次，
//其他数值均出现偶数次，请你找出那个出现奇数次的数值。
//输入：
//5
//2 1 2 3 1
//
//输出：
//3

//利用异或运算
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


//输入：
//[2, 4, 1, 2, 7, 8, 4]
//返回值：
//1
//说明：
//4和8都是峰值元素，返回4的索引1或者8的索引5都可以

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
//            //nums[mid] < nums[mid + 1]说明在“上坡”，
//            //则可以使left = mid + 1（因为mid肯定不是峰值），向“峰”处压缩
//        }
//        else
//        {
//            right = mid;
//            //nums[mid] > nums[mid + 1]说明在“下坡”，
//            //则应该使right = mid（mid可能是峰值），往“峰”处压缩
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
//unsigned char 8 位数据位，范围在 0 - 255 
//7 4 1 -> 共(7 - 1) / 3 + 1 = 3 次 （1 - 3 = -2，即 254 ，继续循环）
//254 251 ... 5 2 -> 共(254 - 2) / 3 + 1 = 85 次（2 - 3 = -1，即 255 ，继续循环）
//255 252 ... 6 3 -> 共(255 - 5) / 3 + 1 = 85 次（ 3 - 3 = 0 ，退出循环） 所以总共 173 次



//牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
//
//但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
//牛牛希望你能帮他计算一共有多少个可能的数对。
//
//输入描述：
//输入包括两个正整数n, k(1 <= n <= 10 ^ 5, 0 <= k <= n - 1)。turn 0;
//
//输入：
//5 2
//输出：
//7
//说明：
//满足条件的数对有(2, 3), (2, 4), (2, 5), (3, 4), (3, 5), (4, 5), (5, 3)
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



//输入：
//abABCcDEF
//6
//
//输出：
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
//	struct Data d = { {"lisi", "nv", 30, 166},'w', 3.14};//嵌套
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
//  //结构体内存对齐
//  //1.结构体的第一个成员，存放在结构体变量开始位置的0偏移处
//  //VS环境有一个默认对齐数：8
//  //2.从第二个成员开始，都要对齐到某个数字（对齐数）的整数倍数的对齐处
//  //对齐数：编译器默认的对齐数与该成员大小的较小值
//  //3.结构体的总大小，必须是最大的对齐数的整数倍
//  //Linux环境没有默认对齐数
//  //4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体
//  //的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍e.g. s3自己的最大对齐数是8
//	//printf("%d\n", offsetof(struct S1, c1));//0
//	//printf("%d\n", offsetof(struct S1, i));//4
//	//printf("%d\n", offsetof(struct S1, c2));//8
//
//	return 0;
//}