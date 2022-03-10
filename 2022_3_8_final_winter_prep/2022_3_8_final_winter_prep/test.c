#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
//enum State
//{
//	Valid,
//	Invalid,
//};
//enum State state = Invalid; 
//int my_Atoi(const char* string)
//{
//	assert(string); 
//	if (*string == '\0')
//	{
//		return 0;//空字符
//	}
//	int flag = 1;
//	while (!isdigit(*string))	//跳过不是数字的字符
//	{
//		string++;
//	}
//	if (*(string - 1) == '-')	//查看数字前是否有负号
//	{
//		flag *= -1;
//	}
//
//	int ret = 0;
//
//	while (*string)	//遍历字符串，将数字写入ret中
//	{
//		if (isdigit(*string))
//		{
//			ret = 10 * ret + flag * (*string - '0');
//			string++;
//		}
//		else
//		{
//			state = Valid;
//			return ret;
//		}
//
//	}
//	state = Valid;
//	return ret;
//}
//
//void main()
//{
//	char* c = "abcd -112233";
//	int n = 0;
//	n = my_Atoi(c);
//	printf("%d\n",n);
//	return 0;
//}

//void* my_strncat(char* dest, const char* src, int n)
//{
//	assert(dest && src);
//	char* tmp = dest;
//	int cnt = 0;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (cnt < n)
//	{
//		*dest++ = *src++;
//		cnt++;
//	}
//	*dest = '\0';
//	return tmp;
//}
//int main()
//{
//	char arr1[30] = "abc";
//	char arr2[] = "defghijklmn";
//	int num = 0;
//	scanf("%d", &num);
//	my_strncat(arr1, arr2, num);
//	puts(arr1);
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6};
//	
//	int ret = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		//先异或
//		ret ^= arr[i];
//	}
//	//计算ret的二进制中第几个位是1
//	int pos = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	//按照第pos位为0或1来分组
//	int n = 0;
//	int m = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			n ^= arr[i];
//		}
//	}
//
//	m = ret ^ n;
//	printf("%d %d\n", n, m);
//
//	return 0;
//}

//char* my_strncpy(const char* src, char* dest, int sz)
//{
//	assert(src && dest);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*(dest + i) = *(src + i);
//	}
//	*(dest + i) = '\0';
//	return dest;
//}
//
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[10] = { 0 };
//	int n = 3;
//	int i = 0;
//
//	printf("%s", my_strncpy(arr1, arr2, n));
//
//	return 0;
//}