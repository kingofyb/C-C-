#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

namespace bit
{
	typedef int STDataType;

	typedef struct Stack
	{
		STDataType* a;
		int top;		// 
		int capacity;	// 
	}ST;

	void StackInit(ST* ps);
	void StackDestory(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	bool StackEmpty(ST* ps);
	int StackSize(ST* ps);
	STDataType StackTop(ST* ps);
}