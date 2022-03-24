#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Ҫ�󣺴洢�����ݴ�0��ʼ�����������洢
// ��̬��˳���
// ���⣺��С�ˣ������á������ˣ������˷ѡ�
//#define N 10000
//struct SeqList
//{
//	int a[N];
//	int size; // ��¼�洢�˶��ٸ�����
//};

typedef int SLDataType;

// ��̬��˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;     // �洢���ݸ���
	int capacity; // �洢�ռ��С
}SL, SeqList;

void SeqListPrint(SeqList* psl);

//void SLInit(SeqList* psl);
void SeqListInit(SeqList* psl);
void SeqListDestroy(SeqList* psl);

void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);