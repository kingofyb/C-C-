#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;

}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php); //删除堆顶
HPDataType HeapTop(HP* php); //取堆顶的数据
bool HeapEmpty(HP* php);
int HeapSize(HP* php);