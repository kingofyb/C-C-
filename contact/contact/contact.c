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
		printf("ͨѶ¼���ˣ��޷����\n");
		return;
	}

	//������ϵ��
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("������ϵ�˳ɹ�\n"); 
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	//������ - ��
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");

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
	return -1;//�Ҳ���
}
void DeleteContact(Contact* pc)
{
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}

	printf("������Ҫɾ�����˵�����:>");
	scanf("%s", name);
	//����ָ����ϵ��
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	else
	{
		//ɾ��
		int j = 0;
		for (j = pos; j < pc->sz; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("ɾ��ָ����ϵ�˳ɹ�\n");
	}

}

void FindContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		return;
	}

	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
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
		printf("ͨѶ¼Ϊ�գ��޷��޸�\n");
		return;
	}

	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}

	printf("������Ҫ�޸ĵ���Ϣ (1.���� 2.���� 3.�Ա� 4.�绰 5.��ַ :>)");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].age);
		break;
	case 3:
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ�\n");
}

void ClearContact(Contact* pc)
{
	assert(pc);
	InitContact(pc);
	printf("���������ϵ�˳ɹ�!\n");
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
			//���j��name��j+1��,j��j+1��������Ϣ����
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
			}
		}
	}
}