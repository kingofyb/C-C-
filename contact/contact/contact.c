#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == MAX)
	{
		printf("通讯录满了，无法添加\n");
		return;
	}

	//输入联系人
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加联系人成功\n"); 
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	//左对齐加 - 号
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n", 
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}
int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}
void DeleteContact(Contact* pc)
{
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}

	printf("请输入要删除的人的名字:>");
	scanf("%s", name);
	//查找指定联系人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	else
	{
		//删除
		int j = 0;
		for (j = pos; j < pc->sz; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("删除指定联系人成功\n");
	}

}

void FindContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("通讯录为空，无法查找\n");
		return;
	}

	printf("请输入要查找的人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}

	printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
		pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);

}

void ModifyContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int n = 0;

	if (pc->sz == 0)
	{
		printf("通讯录为空，无法修改\n");
		return;
	}

	printf("请输入要查找的人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}

	printf("请输入要修改的信息 (1.姓名 2.年龄 3.性别 4.电话 5.地址 :>)");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		printf("请输入新的姓名:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("请输入新的年龄:>");
		scanf("%s", pc->data[pos].age);
		break;
	case 3:
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("输入有误，修改失败\n");
		return;
	}
	printf("修改成功\n");
}

void ClearContact(Contact* pc)
{
	assert(pc);
	InitContact(pc);
	printf("清空所有联系人成功!\n");
}

void SortContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	int j = 0;
	PeoInfo tmp;
	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - 1; j++)
		{
			//如果j的name比j+1大,j和j+1的所有信息互换
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
}