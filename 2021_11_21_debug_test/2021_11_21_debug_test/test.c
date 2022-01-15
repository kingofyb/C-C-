#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//Debug通常称为调试版本 -- 可以调试
//它包含调试信息，并且不作任何优化，便于程序员调试 程序
//Release称为发布版本，它-往往是进行了各种优化 -- 不能调试
//使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用

//断点 - 程序执行到断点处就会主动停下来 
//F5虽然叫开始测试
//通常使用F5跳到想要的断点处
//F5会向后执行代码，到下一个逻辑上的断点
//F10 - 逐过程
//F11 - 逐语句

//1 - n的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		
//		for (j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//		ret = 1;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//i和arr是局部变量
//局部变量是放在栈区上的
//栈区上内存的使用习惯是：先使用高地址处的空间，再使用低地址处的空间 
//数组随着下标的增长，地址是由低到高变化
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 9; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}

//char my_strcpy(char* dest, const char* src)
//{
//	//assert(dest != NULL);//断言
//	//assert(src != NULL);
//	assert(dest && src);
//
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//处理\0
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello";
//	//strcpy(arr1, arr2);
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//const 修饰变量
//const 修饰指针

int main()
{
	int n = 10;
	//const修饰指针
	//1. 放在*左边
	//const修饰的是指针指向的内容，表示指针指向的内容不能通过指针来改变
	//但是指针变量本身是可以改变的
	//比如
	//const int* p = &n;
	//p = &m;
	//2. 放在*右边
	//const修饰的是指针变量本身，指针变量的内容不能被修改
	//但是指针指向的内容是可以通过指针来改变
	//int* const p = &n;
	//*p = 20
	

	return 0;
}