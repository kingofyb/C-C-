#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����
void bubble_sort(int arr[], int sz)
{
	//����
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//ÿһ��ð������Ĺ���
		//ȷ��һ�������бȽϵĶ���
		int j = - 0;
		for (j = 0; j < sz-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
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

//qsort - �⺯�� - �ÿ�������ķ���ʵ�ֵ�

//�Ƚ�e1��e2ָ���Ԫ��
//int cmp_int(const void* e1, const void* e2)//void* �޾������͵�ָ��
//{
//	//void* ��ָ��������Դ���������͵ĵ�ַ
//	//void* ��ָ�벻��ֱ�ӽ��н����ò���
//	//void* ��ָ�벻��ֱ�ӽ��� + - ����
//	//if (*(int*)e1 > *(int*)e2)
//	//{
//	//	return 1;
//	//}
//	//else if (*(int*)e1 < *(int*)e2)
//	//{
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return 0;
//	//}
//	return *(int*)e1 - *(int*)e2;
//}
////����qsort������������
//void test1()
//{
//	int arr[] = { 1,4,2,6,5,3,7,9,0,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//����qsort����ṹ������
struct Stu
{
	char name[20];
	int age;
	float score;
};
int cmp_stu_by_score(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->score - ((struct Stu*)e2)->score;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void print_stu(struct Stu arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d %f\n", arr[i].name, arr[i].age, arr[i].score);
	}
	printf("\n");
}
void test2()
{
	struct Stu arr[] = { {"zhangsan",20,87.5f},{"lisi",22,99.0f},{"wangwu",10,68.5f} };
	//���ճɼ�����
	int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_score);
	qsort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
	print_stu(arr, sz);
}
int main()
{
	//test1();
	test2();
	return 0;
}


