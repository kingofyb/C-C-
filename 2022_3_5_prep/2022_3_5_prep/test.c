#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//ʵ��һ�����������������ַ����е�k���ַ�

//void left_move(char* str, int k)
//{
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		//ÿ����תһ���ַ�
//		char tmp = *str;
//		int len = strlen(str);
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		*(str + len - 1) = tmp;
//	}
//}

//�����ַ���
//void reverse(char* left, char* right)
//{
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* str, int k)
//{
//	int len = strlen(str);
//	k %= len;
//	reverse(str, str+k-1);//ǰ
//	reverse(str+k, str+len-1);//��
//	reverse(str, str+len-1);//����
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	//
//	//abcdef
//	//bafedc
//	//cdefab
//	//
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k);
//
//	printf("%s\n", arr);
//	return 0;
//}
//
//<��ת�ַ���>
//����������
//

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//���Ͼ���
//
//
// 1 2 3 
// 4 5 6
// 7 8 9
//

//void find_int_arr(int arr[3][3], int *px, int *py, int k)
//{
//	int x = 0;
//	int y = *py-1;
//	while (y >= 0 && x <= *px-1)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return;
//		}
//	}
//	*px = -1;
//	*py = -1;
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 0;
//	int x = 3;
//	int y = 3;
//
//	scanf("%d", &k);
//
//	//�����Ƿ����Ͳ���
//	find_int_arr(arr, &x, &y, k);
//	if (x == -1 && y == -1)
//	{
//		printf("�Ҳ�����\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d %d\n", x, y);
//	}
//
//	return 0;
//}

//void left_move(char* str, int k)
//{
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		//ÿ����תһ���ַ�
//		char tmp = *str;
//		int len = strlen(str);
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		*(str + len - 1) = tmp;
//	}
//}
//
//int is_left_move(char*arr1, char* arr2)
//{
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);
//		if (strcmp(arr1, arr2) == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "ABCD";
//	//ABCDA
//	//BCDAA
//	//CDAAB
//	//DAABC
//	//AABCD
//	char arr2[] = "BCDAA";
//	//�ж�arr2�ǲ���arr1��ת�õ���
//	int ret = is_left_move(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}
//


//int is_left_move(char* arr1, char* arr2)
//{
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//
//	strncat(arr1, arr1, len1);
//	if (strstr(arr1, arr2))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr1[20] = "AABCD";
//	//AABCDAABCD
//	char arr2[] = "BCDAA";
//	//�ж�arr2�ǲ���arr1��ת�õ���
//	int ret = is_left_move(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}

//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ��� ƽ̨��VS2013�����ԣ�C����*/
//int main(int argc, char* argv[])
//{
//    struct tagTest1
//    {
//        short a;//0~1 2
//        //2
//        char d;//1 4 1 2
//        //3 - �˷�
//        long b;//4 4 4 4~7
//        long c;//4 4 4 8~11
//    };//12
//    
//    struct tagTest2
//    {
//        long b;//0~3 4
//        //4
//        short c;//2 4 2 4~5
//        char d;//1 4 1 6
//        //7 -�˷���
//        long a;//4 4 4 8~11
//    };//12 
//
//    struct tagTest3
//    {
//        short c;//0~1
//        //2~3
//        long b;//4 4 4 4~7
//        char d;//1 4 1 8
//        //9~11
//        long a;//4 4 4 12~15
//    };//16
//
//    struct tagTest1 stT1;
//    struct tagTest2 stT2;
//    struct tagTest3 stT3;
//
//    printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//    return 0;
//}


//#pragma pack()
//typedef struct {
//	int a;//0~3 4
//	char b;//4
//	//5
//	short c;//6~7
//	short d;//8~9
//	//10~11
//}AA_t;//10 12
//
//
//int main()
//{
//	printf("%d\n", sizeof(AA_t));
//	return 0;
//}