#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int num = 10;
//	&num;//ȡ��num�ĵ�ַ
//	//ע������num��4���ֽڣ�ÿ���ֽڶ��е�ַ��ȡ�����ǵ�һ���ֽڵĵ�ַ����С�ĵ�ַ��
//	printf("%p\n", &num);//��ӡ��ַ��%p���Ե�ַ����ʽ��ӡ
//	return 0;
//}
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;//pc��������ŵ�ַ�ģ��������ǰ�p��Ϊָ�����
//	*pc = 'q';//*�Ľ����ò�������*pc����˼����ͨ��p�е�ֵ���ҵ�pc��ָ��Ķ���Ҳ����˵*pc����ch
//	printf("%c\n", ch);
//	return 0;
//}

//int main()
//{
//	//32λ������ָ���С��4���ֽ�
//	//64λ������ָ���С��8���ֽ�
//	printf("%d\n", sizeof(char*));//4
//	printf("%d\n", sizeof(short*));//4
//	printf("%d\n", sizeof(int*));//4
//	printf("%d\n", sizeof(long*));//4
//	printf("%d\n", sizeof(float*));//4
//	printf("%d\n", sizeof(double*));//4
//	
//	return 0;
//}

//�ṹ��
//struct Stu
//{
//	//�ṹ���Ա
//	char name[20];
//	int age;
//	char sex[10];
//};
//int main()
//{
//	//�����ṹ����������ҳ�ʼ��
//	struct Stu zhangsan = { "����",30,"��" };
//	struct Stu lisi = { "����",24,"����" };
//	//printf("%s %d %s\n", zhangsan.name, zhangsan.age, zhangsan.sex);
//	//->���������
//	struct Stu* p1 = &lisi;
//	printf("%s %d %s\n", (*p1).name, (*p1).age, (*p1).sex);
//	printf("%s %d %s", p1->name, p1->age, p1->sex);
//	return 0;
//}

//�Ӵ�С����
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int c = 1;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a=%d b=%d c=%d", a, b, c);
//	return 0;
//}

//100����3�ı���
//int main()
//{
//	for (int i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//20 40���Լ��
//int main()
//{
//	int a = 50;
//	int b = 1500;
//	int c = 0;
//	if (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}

//��ӡ1000�굽2000��֮�������
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if (i % 4 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//дһ�����룺��ӡ100~200֮�������
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int j = 2;
//		for (j = 2;j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}