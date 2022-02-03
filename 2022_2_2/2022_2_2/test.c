#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int x = 6, y = 7;
//void swap()
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
////typedef int* int_ptr;
////#define INI_PTR int*
//int main()
//{
//	//int x = 3, y = 8;
//	//int i = 0;
//	char arr[3];
//
//	scanf("%s ", &arr);
//	printf("%s ", arr);
//
//	swap();
//	//printf("%d,%d\n", x, y);
//	return 0;
//}
//#define N 2
//#define M N + 1
//#define NUM (M+1)*M/2
//int main()
//{
//	//char s[] = "\\123456\123456\t";
//	//printf("%d\n", strlen(s));
//	printf("%d\n", NUM);
//	return 0;
//}

//int f(int n)
//{
//	static int i = 1;//static ������һ��ʹ�õ�ֵ
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int main()
//{
//	int n = f(1);
//	printf("%d\n", n);
//	return 0;
//}

//�ص���������һ��ͨ������ָ����õĺ���������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��������
//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã�
//�������ض����¼�����������ʱ�������һ�����õģ����ڸ��¼�������������Ӧs

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			//if (arr[j] > arr[j + 1])
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//����Ԫ�صĽ���
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test3()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}