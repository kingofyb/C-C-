#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//scanf �ӱ�׼������(stdin)�Ͻ�ʿ��ʽ������ĺ���
//printf ���׼�����(stdout)�Ͻ��и�ʽ�����������

//fscanf ���Դӱ�׼��������������ָ�����ļ��϶�ȡ��ʽ��������
//fprintf �����ݰ��ո�ʽ���ķ�ʽ�������׼�����������ָ�����ļ���

//sscanf ���Դ�һ���ַ�������ȡ(ת��)����ʽ������
//sprintf ��һ����ʽ��������ת�����ַ���

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);//2
//	//��λ�ļ�ָ��
//	fseek(pf, 3, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//f
//
//	rewind(pf);
//	//fseek(pf,0,SEEK_SET);
//
//	ret = ftell(pf);
//	printf("%d\n", ret);//0
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//��
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	//��λ�ļ�ָ��
//	//fseek(pf, 3, SEEK_CUR);
//	//fseek(pf, 5, SEEK_SET);
//	fseek(pf, -1, SEEK_END);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//f
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//д
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	int ch = 0;
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//
//	//��λ�ļ�ָ��
//	//fseek(pf, 3, SEEK_CUR);
//	//fseek(pf, 5, SEEK_SET);
//	fseek(pf, -2, SEEK_END);
//
//	fputc('#', pf);//y�޸�Ϊ#
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	int a = 10000;//������ 0000 0000 0000 0000 0010 0111 0001 0000
//	//            ʮ������   0    0    0    0    2    7    1    0
//	//0x 00 00 27 10
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//feof����ֱ�������ж��ļ��Ƿ����
//�������ļ���ȡ�������ж��Ƕ�ȡʧ�ܽ��������������ļ�β����
//fgetc �ַ� - �ж��Ƿ�ΪEOF
//fgets �ı��� - �ж��Ƿ�ΪNULL
//fread ������ - �жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���