#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//strstr
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

//strtok��ı��ַ������ҵ���һ����ǲ���\0��β
//strtok�����ҵ�һ����ǵ�ʱ�򣬺����ĵ�һ����������NULL
//strtok�����ҷǵ�һ����ǵ�ʱ�򣬺����ĵ�һ��������NULL
//int main()
//{
//	const char* p = "@.#";
//	char arr[] = "zpengwei@yeah.net#hehe";
//	char buf[50] = { 0 };// "zpengwei@yeah.net"
//	strcpy(buf, arr);
//	char* str = NULL;
//
//	for (str = strtok(buf, p); str != NULL; str=strtok(NULL, p))
//	{
//		printf("%s\n", str);
//	}
//
//	//char* str = strtok(buf, p);//zpengwei
//	//printf("%s\n", str);
//	//str = strtok(NULL, p);//yeah
//	//printf("%s\n", str);
//	//str = strtok(NULL, p);//net
//	//printf("%s\n", str);
//	//strtok - ��ʼ����NULL
//
//	return 0;
//}

//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}


//int cmp_int(const void* e1, const void* e2)
//{
//    return (*(int*)e1 - *(int*)e2);
//}
//int cmp_str(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//int main()
//{
//    int arr_int[] = { 3, 5, 9, 7, 1 };
//    char arr_str[20] = "yhsracva";
//    int i = 0;
//    qsort(arr_int, 5, sizeof(arr_int[0]), cmp_int);
//    qsort(arr_str, strlen(arr_str), sizeof(arr_str[0]), cmp_str);
//    for (i = 0; i < 5; i++) 
//    {
//        printf("%d ", arr_int[i]);
//    }
//    printf("\n");
//    for (i = 0; i < 20; i++) 
//    {
//        printf("%c ", arr_str[i]);
//    }
//    return 0;
//}

//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);//������
//	}
//	return count;
//}
//int main()
//{
//	//int ret = func(-1);
//	//printf("%d", ret);
//	int count = 0;
//	int x = -1;
//	while (x)
//	{
//		count++;
//		x = x >> 1;
//	}
//	printf("%d", count);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2, m = 0, n = 0, k;
//	k = (n = b < a) && (m = a);
//	printf("%d,%d\n", k, m);
//	return 0;
//}

//���÷������ӷ�
//int Add(int num1, int num2) {
//    // write code here
//    int m = 0;
//    int n = 0;
//    m = (num1 & num2) << 1;  // ��Ҫ��λ
//    n = num1 ^ num2;        //�����λ    ��ʱm + n���Ǵ𰸣����������ӷ�
//    while (n & m)   // ����Ƿ���Ҫ��λ
//    {
//        num1 = m;
//        num2 = n;
//        m = (num1 & num2) << 1;  //��Ҫ��λ
//        n = num1 ^ num2;        //�����λ
//    }
//
//    return m | n;
//}