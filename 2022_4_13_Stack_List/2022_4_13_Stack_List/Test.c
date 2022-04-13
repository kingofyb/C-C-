#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);

	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 3);
	StackPush(&st, 4);



	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);
}

//leetcode 20. 有效的括号
//bool isValid(char* s) {
//    ST st;
//    StackInit(&st);
//
//    while (*s)
//    {
//        if (*s == '[' || *s == '(' || *s == '{')
//        {
//            StackPush(&st, *s);
//            ++s;
//        }
//        else
//        {
//            if (StackEmpty(&st))
//            {
//                //如果栈为空
//                return false;
//            }
//            char top = StackTop(&st);
//            StackPop(&st);
//
//            if (*s == ']' && top != '[')
//            {
//                StackDestory(&st);
//                return false;
//            }
//            else if (*s == ')' && top != '(')
//            {
//                StackDestory(&st);
//                return false;
//            }
//            else if (*s == '}' && top != '{')
//            {
//                StackDestory(&st);
//                return false;
//            }
//            else
//            {
//                //匹配
//                ++s;
//            }
//        }
//    }
//    //栈为空，说明所有左括号都匹配
//    bool ret = StackEmpty(&st);
//    return ret;
//}

int main()
{
	TestStack();

	return 0;
}