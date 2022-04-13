#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//struct Stack
//{
//	int a[N];
//	int top; // 栈顶的位置
//};

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶的位置
	int capacity;	// 容量
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
bool StackEmpty(ST* ps);
int StackSize(ST* ps);
STDataType StackTop(ST* ps);