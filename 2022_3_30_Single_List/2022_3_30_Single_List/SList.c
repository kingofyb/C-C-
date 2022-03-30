#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	return newnode;
}

void SListPushBack(SListNode** pphead, SLTDataType x)
{
	assert(pphead);

	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;

		// ����д��������û����������
		/*SListNode* tail = *pphead;
		while (tail != NULL)
		{
		tail = tail->next;
		}

		tail = newnode;*/
	}
}

void SListPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);

	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SListNode** pphead)
{
	assert(pphead);

	// Ҳ���Ա������Ϊ�յ����
	//assert(*pphead != NULL);

	// 1����
	// 2��һ���ڵ�
	// 3������ڵ�
	if (*pphead == NULL)  // ������
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		/*SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
		prev = tail;
		tail = tail->next;
		}

		free(tail);
		tail = NULL;
		prev->next = NULL;*/

		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SListNode** pphead)
{
	assert(pphead);

	// 1����
	// 2���ǿ�
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

SListNode* SListFind(SListNode* phead, SLTDataType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// ��posλ��֮ǰ����
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	// 1��pos�ǵ�һ���ڵ�
	// 2��pos���ǵ�һ���ڵ�
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SListNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	//SListNode* next = pos->next;
	//SListNode* newnode = BuySListNode(x);

	//pos->next = newnode;
	//newnode->next = next;

	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��pos λ��
void SListErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* next = pos->next;
	if (next)
	{
		pos->next = next->next;
		free(next);
		next = NULL;
	}
}

void SListDestroy(SListNode** pphead)
{
	assert(pphead);

	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}