#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//�������

//int main()
//{
//    int n = 0;
//    int i, j;
//    int arr[30][30] = { 0 };
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j <= i; j++)
//        {
//            if (j == 0 || i == j)
//            {
//                arr[i][j] = 1;
//            }
//            else
//            {
//                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//            }
//            printf("%5d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}



//���׾�����
//KiKi��BoBo�� ���������塣Ҳ�����ھŹ����У�ֻҪ�����С��У���������Խ��������������������ͬ�����ӣ�
//���ܻ�ʤ�����������״̬���жϵ�ǰ��Ӯ
//�������е��ַ�Ԫ�أ���������״̬���ַ�Ԫ���ÿո�ֿ�������ǰ���̣�����Ԫ��ΪK����KiKi��ҵ����ӣ�
//ΪO��ʾû�����ӣ�ΪB����BoBo��ҵ����ӡ�
//���KiKi��ʤ�������KiKi wins!����
//���BoBo��ʤ�������BoBo wins!����
//���û�л�ʤ�������No winner!����

//void kwin()
//{
//    printf("KiKi wins!");
//}
//void bwin()
//{
//    printf("BoBo wins!");
//}
//void nowin()
//{
//    printf("No winner!");
//}
//int main()
//{
//    char arr[3][3] = { 'O' };
//    int i, j;
//    for (i = 0; i < 3; i++)
//    {
//        for (j = 0; j < 3; j++)
//        {
//            scanf(" %c ", &arr[i][j]);
//        }
//    }
//    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])//�Խ���1
//    {
//        if (arr[0][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[0][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])//�Խ���2
//    {
//        if (arr[0][2] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[0][2] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2])//��һ��
//    {
//        if (arr[0][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[0][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])//�ڶ���
//    {
//        if (arr[1][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[1][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])//������
//    {
//        if (arr[2][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[2][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])//��һ��
//    {
//        if (arr[0][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[0][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])//�ڶ���
//    {
//        if (arr[1][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[1][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])//������
//    {
//        if (arr[2][0] == 'K')
//        {
//            kwin();
//        }
//        else if (arr[2][0] == 'B')
//        {
//            bwin();
//        }
//        else
//        {
//            nowin();
//        }
//    }
//    else
//    {
//        nowin();
//    }
//    return 0;
//}