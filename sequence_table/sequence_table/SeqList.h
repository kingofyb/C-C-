#pragma once
#include<iostream>
#include <cassert>
#include<stdlib.h>
using namespace std;
//顺序表就是数组
//数据必须从第一个位置开始连续

//#define N 200
//typedef int SLDataType;
//
//// 静态顺序表 -- N太小可能不够用，如果N太大可能浪费空间
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


typedef int SLDataType;

// 静态顺序表 -- N太小可能不够用，如果N太大可能浪费空间
typedef struct SeqList
{
	SLDataType* a; // 指向动态开辟数组指针
	int size; // 数据个数
	int capacity; // 容量空间大小
}SL;

// 增删查改
//void SeqListInit(SL s);
void SLInit(SL* ps);