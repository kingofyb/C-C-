#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	//arr���Ⱥ����Ž������������
//	int* arr[10];//ָ������-��ŵ���int*
//	char* ch[5];//ָ������-��ŵ���char*
//
//	return 0;
//}


//ʵ��һ�����������������ַ����е�k���ַ�
//void left(char* ch, int n)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(ch);
//	int tmp = 0;
//	n %= len;
//	//����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ�����
//	for (i = 0; i < n; i++)//ִ��k�εĵ���ƽ��
//	{
//		tmp = ch[0];
//		for (j = 0; j < len - 1; j++)//����ƽ��
//		{
//			ch[j] = ch[j + 1];
//		}
//		ch[j] = tmp;
//	}
//}


//�Ľ�һ
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len; //�Ͽ�λ�õ��±�
//	char tmp[256] = { 0 }; //��׼ȷ�Ļ�����ѡ��malloc len + 1���ֽڵĿռ��������tmp
//
//	strcpy(tmp, src + pos); //�Ƚ������ȫ��������
//	strncat(tmp, src, pos); //Ȼ��ǰ�漸������
//	strcpy(src, tmp); //��󿽻�ȥ
//}

//�Ľ���
//void reverse_part(char* str, int start, int end) //���ַ�����start��end��һ������
//{
//	int i, j;
//	char tmp;
//
//	for (i = start, j = end; i < j; i++, j--)
//	{
//		tmp = str[i];
//		str[i] = str[j];
//		str[j] = tmp;
//	}
//}
//
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len;
//	reverse_part(src, 0, pos - 1); //����ǰ��
//	reverse_part(src, pos, len - 1); //������
//	reverse_part(src, 0, len - 1); //��������
//}

//int main()
//{
//	char ch[] = "ABCD";
//	int n = 2;
//	left(ch, n);
//	printf("%c ", ch[0]);
//	printf("%c ", ch[1]);
//}



//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);

//int findnum(int a[][3], int x, int y, int f) //��һ��������������Ҫ����
//{
//	int i = 0, j = x - 1; //�����Ͻǿ�ʼ����
//
//	while (j >= 0 && i < y)
//	{
//		if (a[i][j] < f) //���Ҵ������
//		{
//			i++;
//		}
//		else if (a[i][j] > f) //����С������
//		{
//			j--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int a[][3] = { {1, 3, 5},
//				  {3, 5, 7},
//				  {5, 7, 9} }; //һ��ʾ��
//
//	if (findnum(a, 3, 3, 2))
//	{
//		printf("It has been found!\n");
//	}
//	else
//	{
//		printf("It hasn't been found!\n");
//	}
//
//	return 0;
//}