#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

//int main()
//{
	//memcmp(arr1,arr2,9)//�Ƚ�9���ֽ�
	//arr1����arr2 ����1
	//arr1С��arr2 ����-1
	//arr1����arr2 ����0
	//char arr[20] = { 0 };
	//memset(arr, 'x', 10);//arr[20]={x,x,x,x,x,x,x,x,x,x}//����10���ֽ�
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //memset(arr, 'x', 10);
	////00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 ...
//	return 0;
//}

//int my_strlen(const char* str)
//{
//	assert(str);
//	int cnt = 0;
//	while (*str)
//	{
//		cnt++;
//		str++;
//	}
//	return cnt;
//}
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);//�ж��ǲ��ǿ�ָ��
//	//1.Ŀ��ռ��е�\0
//	while (*dest)
//	{
//		dest++;
//	}
//	//2.׷�����ݵ�Ŀ��ռ�
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//char* my_strcpy(char* dest, char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int mystr_cmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//char* my_strstr(const char* str, const char* substr)
//{
//	assert(str && substr);
//
//	const char* s1 = str;
//	const char* s2 = substr;
//	const char* cur = str;
//	if (*substr == '\0')
//	{
//		return (char*)str;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//
//}
//int main()
//{
//	char str[] = "lazy";
//	char string[] = "The quick brown dog jumps over the lazy fox";
//	char fmt1[] = "         1         2         3         4         5";
//	char fmt2[] = "12345678901234567890123456789012345678901234567890";
//
//	char* pdest;
//	int  result;
//	printf("String to be searched:\n\t%s\n", string);
//	printf("\t%s\n\t%s\n\n", fmt1, fmt2);
//	pdest = my_strstr(string, str);
//	result = pdest - string + 1;
//	if (pdest != NULL)
//		printf("%s found at position %d\n\n", str, result);
//	else
//		printf("%s not found\n", str);
//
//	return 0;
//}

