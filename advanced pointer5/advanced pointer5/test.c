#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//升序
void bubble_sort(int arr[], int sz)
{
	//趟数
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		//每一趟冒泡排序的过程
		//确定一趟排序中比较的对数
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

//qsort - 库函数 - 用快速排序的方法实现的

//比较e1和e2指向的元素
//int cmp_int(const void* e1, const void* e2)//void* 无具体类型的指针
//{
//	//void* 的指针变量可以存放任意类型的地址
//	//void* 的指针不能直接进行解引用操作
//	//void* 的指针不能直接进行 + - 整数
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
////测试qsort排序整型数组
//void test1()
//{
//	int arr[] = { 1,4,2,6,5,3,7,9,0,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//bubble_sort(arr, sz);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//测试qsort排序结构体数据
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
	//按照成绩排序
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


