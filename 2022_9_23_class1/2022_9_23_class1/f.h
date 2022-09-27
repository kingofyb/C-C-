#pragma once

//inline void func(int a, int b);

//inline void func(int a, int b)
//{
//	int c = a + b;
//	c = a * b;
//	c = a * b;
//	c = a + b;
//	c = a / b;
//	c = a * b;
//	c = a * b;
//}

struct QueueNode
{
	QueueNode* next;
	int val;
};

// 
// 
class Queue
{
public:
	//inline void Init();
	void Init();
	void Push(int x);
	void Pop();
private:
	QueueNode* head;
	QueueNode* tail;
};