#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//ͨѶ¼��
//1. ���Դ��1000���˵���Ϣ
//2. �˵���Ϣ�����֣����䣬�绰��סַ���Ա�
//3. ������ϵ��
//4. ɾ����ϵ��
//5. ������ϵ��
//6. �޸���ϵ��
//7. �������� / ���䣩

enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
	CLEAR
};
void menu()
{
	printf("***************************************\n");
	printf("********     1.add      2.del     *****\n");
	printf("********     3.search   4.modify  *****\n");
	printf("********     5.sort     6.show    *****\n");
	printf("********     7.clear    0.exit    *****\n");
	printf("***************************************\n");
}
int main()
{
	int input = 0;
	Contact con = {0};//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DeleteContact(&con);
			break;
		case SEARCH:
			FindContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
