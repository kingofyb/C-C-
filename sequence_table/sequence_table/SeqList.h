#pragma once
#include<iostream>
#include <cassert>
#include<stdlib.h>
using namespace std;
//˳����������
//���ݱ���ӵ�һ��λ�ÿ�ʼ����

//#define N 200
//typedef int SLDataType;
//
//// ��̬˳��� -- N̫С���ܲ����ã����N̫������˷ѿռ�
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


typedef int SLDataType;

// ��̬˳��� -- N̫С���ܲ����ã����N̫������˷ѿռ�
typedef struct SeqList
{
	SLDataType* a; // ָ��̬��������ָ��
	int size; // ���ݸ���
	int capacity; // �����ռ��С
}SL;

// ��ɾ���
//void SeqListInit(SL s);
void SLInit(SL* ps);