#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
	//����ݴ�ӡ100����3�ı���
	//for (int i = 3; i <= 100; i += 3)
	//{
	//	printf("%d ", i);
	//}
	//�����Լ��
	//int m = 0;
	//int n = 0;
	//int ret = 0;
	//scanf("%d %d", &m, &n);
	//if (m > n)
	//	ret = n;
	//else
	//	ret = m;
	//while (1)
	//{
	//	if (n % ret == 0 && m % ret == 0)
	//	{
	//		break;
	//	}
	//	ret--;
	//}
	//printf("%d", ret);

	//շת�����
	//int m = 0;
	//int n = 0;
	//int ret = 0;
	//scanf("%d %d", &m, &n);
	//while (ret = m % n)
	//{
	//	m = n;
	//	n = ret;
	//}
	//printf("%d\n", n);

	//m*n/���Լ�� = ��С������

	//�����жϵĹ���
	//1.�ܱ�4���������Ҳ��ܱ�100����������
	//2.�ܱ�400����������

	//int y = 0;
	//int count = 0;
	//for (y = 1000; y <= 2000; y++)
	//{
		////�ж�y�ǲ�������
	//	if (((y % 4 == 0) && (y % 100 != 0))|| (y % 400 == 0))
	//	{
	//		count++;
	//		printf("%d ", y);
	//	}       
	//}
	//printf("\ncount = %d\n", count);


	//�ж�����
	//1
	//int y = 0;
	//for (y = 100; y <= 200; y++)
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < squrt(y); n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y��������
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//2
	//y=a*b
	//��ôa��b֮�����һ����<=y��ƽ����

	//int y = 0;
	//for (y = 100; y <= sqrt(y); y++) //***
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < y; n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y��������
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//�Ż�
	//int y = 0;
	//for (y = 100; y <= 200; y+=2) //***
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < y; n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y��������
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ���ֻ���������������룬���������ȷ��
	//��ʾ��¼�ɣ�������ξ�����������˳�����
	

	//strcmp = string compare	
	//����0��˵�������ַ������
	//���ش���0������
	//����С��0������
	//char password[20] = "";
	//int i = 0;
	//for(i=0;i<3;i++)
	//{
	//	printf("����������:>");
	//	scanf("%s", password);//��Ϊpassword�������������鱾�����ǵ�ַ
	//	if (strcmp(password, "123456") == 0)
	//	{
	//		printf("��½�ɹ�\n");
	//		break;
	//	}
	//	else
	//	{
	//		printf("�������\n");
	//	}
	//}
	//if (i == 3)
	//{
	//	printf("�������������\n");
	//}
//	return 0;
//}




//�����������һ��1-100������
//������
//��Ҳ�С�ˣ����Ի���߲�С��
//��Ҳ´��ˣ����Ի���߲´���

void menu()
{
	printf("**************************\n");
	printf("****&   1. play    *******\n");
	printf("****&   0. exit    *******\n");
	printf("**************************\n");
}
void game()
{
	int guess = 0;
	//��������Ϸ�Ĺ���
	//���������
	int r = rand()%100+1;//(0~99)+1
	//������
	while (1)
	{
		printf("������:>");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("��С��\n");
		}
		else if (guess > r)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ��¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ʱ��-�����������������
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}