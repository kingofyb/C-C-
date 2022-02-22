#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)//num - 字节
{
	void* ret = dest;
	assert(dest && src);
	while (num--)
	{
		*(char*)dest = *(char*)src;//拷贝一个字节
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
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
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1 2 3 4 5拷贝到 3 4 5 6 7
	//1 2 1 2 3 4 5 8 9 10
	//my_memcpy(arr + 2, arr, 5 * sizeof(arr[0]));
	my_memove(arr + 2, arr, 5 * sizeof(arr[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}