#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	//str是NULL指针，会非法访问内存，程序会崩溃
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//******************** 正确
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	//
//	strcpy(str, "hello world");
//	printf(str);
//	//释放
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;//先把p的值放到寄存器里，再销毁
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);//通过寄存器带回去，因为寄存器不会销毁
//	//
//	strcpy(str, "hello world");
//	printf(str);
//	//释放
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//***********************这个打印不出来，因为p已经销毁了
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//int* test()
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int *p = test();
//	printf("hehehhhhh\n");
//  //如果没有上面的hehe，就会是10，因为没人用这块内存,所以没被覆盖
//	printf("%d\n", *p);//10
//
//	return 0;
//}