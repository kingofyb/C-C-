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

//ͨѶ¼�Ľṹ��
typedef struct Contact
{
	PeoInfo data[MAX];//�������
	int sz;//ͨѶ¼����Ч��Ϣ�ĸ���
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ�˵�ͨѶ¼
void AddContact(Contact* pc);

//��ӡͨѶ¼����Ϣ
void ShowContact(const Contact* pc);

//ɾ��
void DeleteContact(Contact* pc);

//����ָ����ϵ��
void FindContact(Contact* pc);

//�޸�
void ModifyContact(Contact* pc);

//���
void ClearContact(Contact* pc);

//����������
void SortContact(Contact* pc);