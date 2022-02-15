#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//错误码 - 错误信息
//0 - "No Error"
//1 - Operation not permitted
//2 - No such file or directory

//strerror - 可以把错误码翻译成错误信息
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%s\n", strerror(i));
//	}
//	return 0;
//}

//当库函数使用的时候，发生错误会把errno这个全局的错误变量设置为本次执行库函数产生的错误码
//errno是c语言提供的一个全局变量，可以直接使用，放在errno.h文件中的
#include<errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		//出错误的原因是什么
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	//...
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//字符分类函数
#include<ctype.h>
//int main()
//{
//	//判断是否为空白字符
//	//printf("%d\n", isspace(' '));
//	//char ch = '0';
//	//if (isdigit(ch))
//	//{
//
//	//}
//
//	//转换大小写
//	//char ch = '0';
//	//ch = getchar();
//	//if (islower(ch))
//	//{
//	//	ch = toupper(ch);
//	//}
//	//else
//	//{
//	//	ch = tolower(ch);
//	//}
//	//printf("%c\n", ch);
//	return 0;
//}

//内存函数
//void* my_memcpy(void* dest, const void* src, size_t num)//num - 字节
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//拷贝一个字节
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}

void* my_memove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	if (dest < src)
	{
		//前 -> 后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//后 -> 前
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
}
void test1()
{
	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1 2 3 4 5拷贝到 3 4 5 6 7
	//1 2 1 2 3 4 5 8 9 10
	//my_memcpy(arr3 + 2, arr3, 5 * sizeof(arr3[0]));
	my_memove(arr3 + 2, arr3, 5 * sizeof(arr3[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr3[i]);
	}
}
int main()
{
	test1();
	//char arr1[] = "adcdef";
	//char arr2[20] = { 0 };
	//strcpy(arr2, arr1);

	//int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr4[5] = { 0 };
	////memcpy(arr4, arr3+5, 5 * sizeof(arr3[0]));//内存拷贝
	//my_memcpy(arr4, arr3 + 5, 5 * sizeof(arr3[0]));
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", arr4[i]);//6 7 8 9 10
	//}

	//memove - 拷贝内存可以重叠
	//其实c语言只要求memcpy能拷贝不重叠的内存空间就可以了
	//但是发现VS memcpy函数也能实现重叠拷贝
	return 0;
}