#pragma once
#include<iostream>
using namespace std;


extern int age;              // ����

// �������Բ�һ��
//int age;        // �������������ļ��ɼ� -- �ɼ����Ƿ�����ű�
static int size;  // �������Ե�ǰ�ļ��ɼ�  // ����

class Person
{
public:
	void PrintPersonInfo();  // ����
private:
	char _name[20];          // ����
	char _gender[3];
	int  _age;
};

struct ListNode
{
	struct ListNode* next; // ����
	int val;
};
