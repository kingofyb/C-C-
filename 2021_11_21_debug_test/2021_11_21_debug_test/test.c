#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//Debugͨ����Ϊ���԰汾 -- ���Ե���
//������������Ϣ�����Ҳ����κ��Ż������ڳ���Ա���� ����
//Release��Ϊ�����汾����-�����ǽ����˸����Ż� -- ���ܵ���
//ʹ�ó����ڴ����С�������ٶ��϶������ŵģ��Ա��û��ܺõ�ʹ��

//�ϵ� - ����ִ�е��ϵ㴦�ͻ�����ͣ���� 
//F5��Ȼ�п�ʼ����
//ͨ��ʹ��F5������Ҫ�Ķϵ㴦
//F5�����ִ�д��룬����һ���߼��ϵĶϵ�
//F10 - �����
//F11 - �����

//1 - n�Ľ׳�
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		
//		for (j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//		ret = 1;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//i��arr�Ǿֲ�����
//�ֲ������Ƿ���ջ���ϵ�
//ջ�����ڴ��ʹ��ϰ���ǣ���ʹ�øߵ�ַ���Ŀռ䣬��ʹ�õ͵�ַ���Ŀռ� 
//���������±����������ַ���ɵ͵��߱仯
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 9; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}

//char my_strcpy(char* dest, const char* src)
//{
//	//assert(dest != NULL);//����
//	//assert(src != NULL);
//	assert(dest && src);
//
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//����\0
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello";
//	//strcpy(arr1, arr2);
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//const ���α���
//const ����ָ��

int main()
{
	int n = 10;
	//const����ָ��
	//1. ����*���
	//const���ε���ָ��ָ������ݣ���ʾָ��ָ������ݲ���ͨ��ָ�����ı�
	//����ָ����������ǿ��Ըı��
	//����
	//const int* p = &n;
	//p = &m;
	//2. ����*�ұ�
	//const���ε���ָ���������ָ����������ݲ��ܱ��޸�
	//����ָ��ָ��������ǿ���ͨ��ָ�����ı�
	//int* const p = &n;
	//*p = 20
	

	return 0;
}