#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//走n个台阶，每次可以走一阶或者两阶
//int fib(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	//1 1 
//	//2 2
//	//		1 f(n-1)
//	//f(n)
//	//		2 f(n-2)
//	//f(n)=f(n-1)+f(n-2)
//	int ret = fib(n);
//	printf("%d\n", ret);
//	return 0;
//}


//数组去重，然后从小到大排列

//创建一个大数组，把数字放到相应的数组下标，这样不论重复
//还是改来改去都是一样的值
//静态变量 对空间的使用没有耗费太多的栈空间
//int arr[100001] = { 0 };
//int main()
//{
//	//比较耗费栈空间
//	//int arr[100001] = { 0 };
//	int n = 0;
//	int k = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &k);
//		arr[k] = k;
//	}
//	for (i = 0; i < 100001; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}


//小乐乐学校教学楼的电梯前排了很多人，他的前面有n个人在等电梯
//电梯每次可以坐12人，每次上下时间为4分钟(上去2分钟，下来2分钟)
//计算小乐乐需要等多少分钟才能乘电梯到楼上，假设电梯一开始在1层

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int t = (n / 12) * 4 + 2;
//	printf("%d\n", t);
//	return 0;
//}

//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。

//int main()
//{
//    int m[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year = 0;
//    int month = 0;
//    int day = 0;
//    scanf("%d %d %d", &year, &month, &day);
//    int cnt = 0;
//    if (month >= 2)
//    {
//        cnt = m[month - 2] + day;
//    }
//    else
//    {
//        cnt = day;
//    }
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 && month >= 3)
//    {
//        cnt++;
//    }
//    printf("%d\n", cnt);
//    return 0;
//}