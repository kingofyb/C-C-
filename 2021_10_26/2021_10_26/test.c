#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
//int main()
//{
//	char input[20] = { 0 };
//	printf("����������;>");
//	scanf("%s", input);
//	//getcahr();//����\n
//	//��������
//	int tmp = 0;
//	while ((tmp = getchar()) != '\n')
//	{
//		;//�����
//	}
//
//	printf("��ȷ������(Y/N):>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}

//int main()
//{
//	//char ch = '\0';
//	//while ((ch = getchar()) != EOF)//EOF = -1
//	//{
//	//	if (ch < '0' || ch > '9')
//	//		continue;
//	//	putchar(ch);
//	//}
//
//	//����3
//	int i = 0;
//	int j = 0;
//	//���ʡ�Ե���ʼ�����֣������ӡ���ٸ�hehe?
//	for (; i < 10; i++)
//	{
//		for (; j < 10; j++)
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//
//}


//����׳�
//1.����n
//2.����1-n�����֣�����
//int  main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		sum += ret;
//		
//	}
//	printf("%d\n", ret);
//	printf("%d\n", sum);
//	return 0;
//}

//���ֲ��� binary search
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//�������飨������
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	        //40         /  4 = 10
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("�ҵ���,�±���%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ�����\n");
//	}
//	return 0;
//}

//hello bit!!!!!!!
//################
//h##############!
//hh############!!
//...
//hello bit!!!!!!!
int main()
{
	char arr1[] = "hello bit!!!!!!!";
	char arr2[] = "################";

	int left = 0;
	int right = strlen(arr1) - 1;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//˯�ߺ���-��λ�Ǻ���
		system("cls");//ִ��ϵͳ�����
		left++;
		right--;
	}
	printf("%s\n", arr2);
	return 0;
}