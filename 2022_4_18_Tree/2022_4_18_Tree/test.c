#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// ����ָ�����Ķ�
//#define N 5
//struct TreeNode
//{
//	int data;
//	struct TreeNode* subs[N];  // ָ������
//};

// ��֪�����Ķ�
//struct TreeNode
//{
//	int data;
//	// ˳���溢�ӵ�ָ��
//	//SeqList _sl; // SLDateType -> struct TreeNode*
//	// vector<struct TreeNode*> _subs; C++
//};

// �����ֵܱ�ʾ��
typedef int DataType;
struct TreeNode
{
	struct TreeNode* firstChild;    // ��һ�����ӽ��
	struct TreeNode* pNextBrother;  // ָ������һ���ֵܽ��
	DataType data;                  // ����е�������
};

int main()
{
	return 0;
}




//leetcode 232. ��ջʵ�ֶ���

//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;		// ջ����λ��
//	int capacity;	// ����
//}ST;
//
//void StackInit(ST* ps);
//void StackDestory(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//STDataType StackTop(ST* ps);
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//
//void StackDestory(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	// 
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		ps->a = (STDataType*)realloc(ps->a, newCapacity * sizeof(STDataType));
//		if (ps->a == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//
//		ps->capacity = newCapacity;
//	}
//
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	--ps->top;
//}
//
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	/*if (ps->top > 0)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}*/
//	return ps->top == 0;
//}
//
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//
//	return ps->a[ps->top - 1];
//}
//
//
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//typedef struct {
//	ST pushST;
//	ST popST;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&obj->pushST);
//	StackInit(&obj->popST);
//
//	return obj;
//
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	assert(obj);
//	StackPush(&obj->pushST, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//	assert(obj);
//	// ���popSTΪ�գ���pushST�����ݵ��������ͷ����Ƚ��ȳ���˳����
//	if (StackEmpty(&obj->popST))
//	{
//		while (!StackEmpty(&obj->pushST))
//		{
//			StackPush(&obj->popST, StackTop(&obj->pushST));
//			StackPop(&obj->pushST);
//		}
//	}
//
//	int front = StackTop(&obj->popST);
//	StackPop(&obj->popST);
//
//	return front;
//}
//
//int myQueuePeek(MyQueue* obj) {
//	//���ؿ�ͷ
//	assert(obj);
//	// ���popSTΪ�գ���pushST�����ݵ��������ͷ����Ƚ��ȳ���˳����
//	if (StackEmpty(&obj->popST))
//	{
//		while (!StackEmpty(&obj->pushST))
//		{
//			StackPush(&obj->popST, StackTop(&obj->pushST));
//			StackPop(&obj->pushST);
//		}
//	}
//
//	return StackTop(&obj->popST);
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//	assert(obj);
//	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
//}
//
//void myQueueFree(MyQueue* obj) {
//	assert(obj);
//
//	StackDestory(&obj->pushST);
//	StackDestory(&obj->popST);
//
//	free(obj);
//}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/