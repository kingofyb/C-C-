#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"

int age = 0; // ����

// ������Ҫָ��PrintPersonInfo������Person�������
void Person::PrintPersonInfo()  // ����
{
	cout << "static size:" << &size << endl;
	cout << "age:" << &age << endl;


	cout << _name << " " << _gender << " " << _age << endl;
}