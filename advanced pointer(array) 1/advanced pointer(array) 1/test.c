#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	//arr首先和括号结合所以是数组
//	int* arr[10];//指针数组-存放的是int*
//	char* ch[5];//指针数组-存放的是char*
//
//	return 0;
//}


//实现一个函数，可以左旋字符串中的k个字符
//void left(char* ch, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(ch);
//	int tmp = 0;
//	n %= len;
//	//长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推
//	for (i = 0; i < n; i++)//执行k次的单次平移
//	{
//		tmp = ch[0];
//		for (j = 0; j < len - 1; j++)//单次平移
//		{
//			ch[j] = ch[j + 1];
//		}
//		ch[j] = tmp;
//	}
//}


//改进一
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len; //断开位置的下标
//	char tmp[256] = { 0 }; //更准确的话可以选择malloc len + 1个字节的空间来做这个tmp
//
//	strcpy(tmp, src + pos); //先将后面的全部拷过来
//	strncat(tmp, src, pos); //然后将前面几个接上
//	strcpy(src, tmp); //最后拷回去
//}

//改进二
//void reverse_part(char* str, int start, int end) //将字符串从start到end这一段逆序
//{
//	int i, j;
//	char tmp;
//
//	for (i = start, j = end; i < j; i++, j--)
//	{
//		tmp = str[i];
//		str[i] = str[j];
//		str[j] = tmp;
//	}
//}
//
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len;
//	reverse_part(src, 0, pos - 1); //逆序前段
//	reverse_part(src, pos, len - 1); //逆序后段
//	reverse_part(src, 0, len - 1); //整体逆序
//}

//int main()
//{
//	char ch[] = "ABCD";
//	int n = 2;
//	left(ch, n);
//	printf("%c ", ch[0]);
//	printf("%c ", ch[1]);
//}



//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);

//int findnum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
//{
//	int i = 0, j = x - 1; //从左上角开始遍历
//
//	while (j >= 0 && i < y)
//	{
//		if (a[i][j] < f) //比我大就向下
//		{
//			i++;
//		}
//		else if (a[i][j] > f) //比我小就向左
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a[][3] = { {1, 3, 5},
//				  {3, 5, 7},
//				  {5, 7, 9} }; //一个示例
//
//	if (findnum(a, 3, 3, 2))
//	{
//		printf("It has been found!\n");
//	}
//	else
//	{
//		printf("It hasn't been found!\n");
//	}
//
//	return 0;
//}