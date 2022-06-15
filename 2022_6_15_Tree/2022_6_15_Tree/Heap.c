#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include"heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2; //��ʽ
	while ()
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		//����

	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP* php); //ɾ���Ѷ�
HPDataType HeapTop(HP* php); //ȡ�Ѷ�������
bool HeapEmpty(HP* php);
int HeapSize(HP* php);