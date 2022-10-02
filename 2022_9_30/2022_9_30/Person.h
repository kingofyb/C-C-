#pragma once
#include<iostream>
using namespace std;


extern int age;              // 声明

// 链接属性不一样
//int age;        // 链接属性所有文件可见 -- 可见就是放入符号表
static int size;  // 链接属性当前文件可见  // 定义

class Person
{
public:
	void PrintPersonInfo();  // 声明
private:
	char _name[20];          // 声明
	char _gender[3];
	int  _age;
};

struct ListNode
{
	struct ListNode* next; // 声明
	int val;
};
