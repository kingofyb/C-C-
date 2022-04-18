#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


//leetcode 225. 用队列实现栈
//typedef struct {
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//    assert(pst);
//
//    QueueInit(&pst->q1);
//    QueueInit(&pst->q2);
//
//    return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    assert(obj);
//
//    if (!QueueEmpty(&obj->q1))
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackPop(MyStack* obj) {
//    assert(obj);
//    Queue* emptyQ = &obj->q1;
//    Queue* nonEmptyQ = &obj->q2;
//    if (!QueueEmpty(&obj->q1))
//    {
//        emptyQ = &obj->q2;
//        nonEmptyQ = &obj->q1;
//    }
//    //非空队列的前N个数据，导入空数据，剩下一个删掉
//    //就实现了后进先出
//    while (QueueSize(nonEmptyQ) > 1)
//    {
//        int front = QueueFront(nonEmptyQ);
//        //非空的对头导入空
//        QueuePush(emptyQ, front);
//        //删掉头
//        QueuePop(nonEmptyQ);
//    }
//    //返回栈顶元素(剩的这个就是要删除的这个)
//    int top = QueueFront(nonEmptyQ);
//    QueuePop(nonEmptyQ);
//
//    return top;
//}
//
//int myStackTop(MyStack* obj) {
//    assert(obj);
//
//    if (!QueueEmpty(&obj->q1))
//    {
//        return QueueBack(&obj->q1);
//    }
//    else
//    {
//        return QueueBack(&obj->q2);
//    }
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//    assert(obj);
//
//    QueueDestory(&obj->q1);
//    QueueDestory(&obj->q2);
//
//    free(obj);
//}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/



//leetcode 622. 设计循环队列
//typedef struct {
//    //数组
//    int* a;
//    int front;
//    int tail;
//    int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    assert(obj);
//    obj->a = (int*)malloc(sizeof(int) * (k + 1));
//    obj->front = obj->tail = 0;
//    obj->k = k;
//
//    return obj;
//}
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    if (myCircularQueueIsFull(obj))
//    {
//        //如果满了
//        return false;
//    }
//    //直接把值放在tail
//    obj->a[obj->tail] = value;
//    if (obj->tail == obj->k)
//    {
//        obj->tail = 0;
//    }
//    else
//    {
//        obj->tail++;
//    }
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        //如果空
//        return false;
//    }
//    if (obj->front == obj->k)
//    {
//        obj->front = 0;
//    }
//    else
//    {
//        obj->front++;
//    }
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        //如果空
//        return -1;
//    }
//    return obj->a[obj->front];
//
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (myCircularQueueIsEmpty(obj))
//    {
//        //如果空
//        return -1;
//    }
//    if (obj->tail == 0)
//    {
//        //如果0，就在上一个位置
//        return obj->a[obj->k];
//    }
//    else
//    {
//        return obj->a[obj->tail - 1];
//    }
//
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    return obj->front == obj->tail;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    if (obj->tail == obj->k && obj->front == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return obj->tail + 1 == obj->front;
//    }
//
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    //不光free结构体，还要free数组
//    free(obj->a);
//    free(obj);
//}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/