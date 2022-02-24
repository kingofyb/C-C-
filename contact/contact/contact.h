#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//通讯录的结构体
typedef struct Contact
{
	PeoInfo data[MAX];//存放数据
	int sz;//通讯录中有效信息的个数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//打印通讯录的信息
void ShowContact(const Contact* pc);

//删除
void DeleteContact(Contact* pc);

//查找指定联系人
void FindContact(Contact* pc);

//修改
void ModifyContact(Contact* pc);

//清空
void ClearContact(Contact* pc);

//按名字排序
void SortContact(Contact* pc);