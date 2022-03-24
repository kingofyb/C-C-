#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListPrint(SeqList* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	// ˣҪ
	if (psl->size == psl->capacity)
	{
		size_t newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			psl->a = tmp;
			psl->capacity = newCapacity;
		}
	}

	psl->a[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	//psl->a[psl->size - 1] = 0;
	if (psl->size > 0)
	{
		psl->size--;
	}
}

void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);