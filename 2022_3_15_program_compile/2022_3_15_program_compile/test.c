#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//************************** ���뻷��
//1.Դ�ļ�

//2.����
//�ڱ�������(Ԥ����/Ԥ���� - ���� - ���)
//Linux������Ŀ���ļ��ĺ�׺��.o
//��Windows������Ŀ���ļ��ĺ�׺��.obj

//Ԥ����/Ԥ���� gcc -E test.c -o test.i
//1.ͷ�ļ��İ��� #include
//2.ɾ��ע��
//3.#define ������ŵ��滻 
//�ı�����

//���� gcc -S test.i ����test.s
//��C���Դ���ת���ɻ�����
//1.�﷨����
//2.�ʷ�����
//3.�������
//4.���Ż���

//��� gcc -c test.s ����test.o elf
//readelf ���߿��Խ���elf��ʽ���ļ�
//�ѻ�����ת���ɶ����Ƶ�ָ��
//1.�γɷ��ű�

//test.c����test.obj

//3.����
//obj�����ӿ�һ��ͨ�����������ɿ�ִ���ļ� .exe
//1.�ϲ��α�
//2.���ű�ĺϲ����ض�λ
//���Ŀ���ļ��������ӵ�ʱ���ͨ�����ű�鿴�����ⲿ�ķ����Ƿ���ʵ����

//4.��ִ�г��� test.exe

//********************* ���л���
//���������ڴ�
//����ʼִ�У�����main����
//ִ�д��룬ʹ��һ������ʱ��ջ������ջ֡��
//��ֹ����

//int main()
//{
//	//printf("%s\n", __FILE__);//�ļ�·��
//	//printf("%d\n",__LINE__);//��һ�е��к�
//	//printf("%s\n", __DATE__);//����
//	//printf("%s\n", __TIME__);//ʱ��
//
//	int i = 0;
//	//��¼��־
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "%s %s %s %d %d\n", __DATE__, __TIME__, __FILE__, __LINE__, i);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//VS2022 �ǲ���ѭ ANSI C

#define M 1000
#define reg register
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PRINT(n) printf("the value of " #n " is %d\n",n);
#define CAT(C, num) Class##num

int main()
{
	//register int num = 10;
	//reg int num = 20;
	//int a = 10;
	//PRINT(a);

	//int b = 20;
	//PRINT(b);
	//int c = MAX(a, b);
	//printf("%d\n", c);

	int Class104 = 10000;
	printf("%d\n", CAT(C, 104));//Class104


	return 0;
}