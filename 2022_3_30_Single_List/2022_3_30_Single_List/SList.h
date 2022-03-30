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
	struct SListNode* next; // 存储下一个节点的地址
}SListNode, SLN;

void SListPrint(SListNode* phead);
void SListPushBack(SListNode** pphead, SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopBack(SListNode** pphead);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);

// 在pos位置之前插入
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x);
// 删除pos 位置
void SListErase(SListNode** pphead, SListNode* pos);

// 在pos之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 删除pos位置后面的值
void SListEraseAfter(SListNode* pos);

void SListDestroy(SListNode** pphead);