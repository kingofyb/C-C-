#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//������ - ������Ϣ
//0 - "No Error"
//1 - Operation not permitted
//2 - No such file or directory

//strerror - ���԰Ѵ����뷭��ɴ�����Ϣ
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%s\n", strerror(i));
//	}
//	return 0;
//}

//���⺯��ʹ�õ�ʱ�򣬷���������errno���ȫ�ֵĴ����������Ϊ����ִ�п⺯�������Ĵ�����
//errno��c�����ṩ��һ��ȫ�ֱ���������ֱ��ʹ�ã�����errno.h�ļ��е�
#include<errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		//�������ԭ����ʲô
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	//...
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//�ַ����ຯ��
#include<ctype.h>
//int main()
//{
//	//�ж��Ƿ�Ϊ�հ��ַ�
//	//printf("%d\n", isspace(' '));
//	//char ch = '0';
//	//if (isdigit(ch))
//	//{
//
//	//}
//
//	//ת����Сд
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

//�ڴ溯��
//void* my_memcpy(void* dest, const void* src, size_t num)//num - �ֽ�
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//����һ���ֽ�
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
		//ǰ -> ��
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//�� -> ǰ
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
}
void test1()
{
	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	//1 2 3 4 5������ 3 4 5 6 7
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
	////memcpy(arr4, arr3+5, 5 * sizeof(arr3[0]));//�ڴ濽��
	//my_memcpy(arr4, arr3 + 5, 5 * sizeof(arr3[0]));
	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d\n", arr4[i]);//6 7 8 9 10
	//}

	//memove - �����ڴ�����ص�
	//��ʵc����ֻҪ��memcpy�ܿ������ص����ڴ�ռ�Ϳ�����
	//���Ƿ���VS memcpy����Ҳ��ʵ���ص�����
	return 0;
}