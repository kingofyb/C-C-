#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data; // val
	struct SListNode* next; // �洢��һ���ڵ�ĵ�ַ
}SListNode, SLN;

void SListPrint(SListNode* phead);
void SListPushBack(SListNode** pphead, SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopBack(SListNode** pphead);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);

// ��posλ��֮ǰ����
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x);
// ɾ��pos λ��
void SListErase(SListNode** pphead, SListNode* pos);

// ��pos֮�����
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ɾ��posλ�ú����ֵ
void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode** pphead);