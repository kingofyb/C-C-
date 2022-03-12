#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//scanf 从标准输入流(stdin)上进士格式化输入的函数
//printf 向标准输出流(stdout)上进行格式化的输出函数

//fscanf 可以从标准输入流、或者是指定的文件上读取格式化的数据
//fprintf 把数据按照格式化的方式输出到标准输出流、或者指定的文件流

//sscanf 可以从一个字符串中提取(转化)出格式化数据
//sprintf 把一个格式化的数据转换成字符串

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);//2
//	//定位文件指针
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

//读
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//b
//
//	//定位文件指针
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

//写
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	int ch = 0;
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//
//	//定位文件指针
//	//fseek(pf, 3, SEEK_CUR);
//	//fseek(pf, 5, SEEK_SET);
//	fseek(pf, -2, SEEK_END);
//
//	fputc('#', pf);//y修改为#
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	int a = 10000;//二进制 0000 0000 0000 0000 0010 0111 0001 0000
//	//            十六进制   0    0    0    0    2    7    1    0
//	//0x 00 00 27 10
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//feof不能直接用来判断文件是否结束
//而是在文件读取结束后，判断是读取失败结束，还是遇到文件尾结束
//fgetc 字符 - 判断是否为EOF
//fgets 文本行 - 判断是否为NULL
//fread 二进制 - 判断返回值是否小于实际要读的个数