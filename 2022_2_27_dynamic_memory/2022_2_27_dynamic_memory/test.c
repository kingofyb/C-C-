#define _CRT_SECURE_NO_WARNINGS 1
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


//1.对NULL指针的解引用操作
//int main()
//{
//	int* p = (int*)malloc(INT_MAX);
//	if (p == NULL)
//		return 0;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	return 0;
//}


//逆序单词
//void reverse(char* l, char* r)
//{
//    assert(l && r);
//    while (l < r)
//    {
//        char tmp = *l;
//        *l = *r;
//        *r = tmp;
//        l++;
//        r--;
//    }
//}
//
//int main()
//{
//    char arr[100] = { 0 };
//    //输入
//    gets(arr);
//    int len = strlen(arr);
//    //逆序
//    //1. 逆序整个字符串
//    char* left = arr;
//    char* right = arr + len - 1;
//    reverse(left, right);
//
//    //2. 逆序每个单词
//    char* cur = arr;
//    char* start = arr;
//
//    while (*cur != '\0')
//    {
//        while (*cur != ' ' && *cur != '\0')
//        {
//            cur++;
//        }
//        reverse(start, cur - 1);
//        start = cur + 1;
//        if (*cur != '\0')
//            cur++;
//    }
//    printf("%s\n", arr);
//
//    return 0;
//}

//2.对动态开辟空间的越界访问

//int main()
//{
//	char* p = (char*)malloc(10 * sizeof(char));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用
//	int i = 0;
//	//for (i = 0; i <= 10; i++)//越界
//	for(i=0; i<10; i++)
//	{
//		*(p + i) = 'a'+i;
//	}
//
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//3.对非动态开辟内存使用free释放

//int main()
//{
//	//int* p = (int*)malloc(40);
//	////
//	//free(p);
//	//p = NULL;
//
//	int a = 10;
//	int*p = &a;
//	//写代码
//
//	free(p);//err
//	p = NULL;
//
//	return 0;
//}

//4.使用free释放一块动态开辟内存的一部分
//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用内存
//	int i = 0;
//	//1~5
//	for (i = 0; i < 5; i++)
//	{
//		*p = i+1;
//		p++;
//	}
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}

//5.对同一块动态内存多次释放

//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//使用内存
//	int i = 0;
//	//1~5
//	for (i = 0; i < 5; i++)
//	{
//		*(p+i) = i + 1;
//	}
//	//释放
//	free(p);
//	p = NULL;
//
//	free(p);//err
//
//	return 0;
//}

//动态开辟内存忘记释放（内存泄漏）

//int* test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//使用
//	
//	//忘记释放，就会出现内存泄露的问题
//	//return p;
//}
//
//int main()
//{
//	int*ptr = test();
//	//free(ptr);
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//		return 0;
//	//使用
//	
//	while (1)
//		;
//
//	return 0;
//}
//