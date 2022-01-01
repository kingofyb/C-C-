#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//杨辉三角

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



//简易井字棋
//KiKi和BoBo玩 “井”字棋。也就是在九宫格中，只要任意行、列，或者任意对角线上面出现三个连续相同的棋子，
//就能获胜。请根据棋盘状态，判断当前输赢
//三行三列的字符元素，代表棋盘状态，字符元素用空格分开，代表当前棋盘，其中元素为K代表KiKi玩家的棋子，
//为O表示没有棋子，为B代表BoBo玩家的棋子。
//如果KiKi获胜，输出“KiKi wins!”；
//如果BoBo获胜，输出“BoBo wins!”；
//如果没有获胜，输出“No winner!”。

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
//    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])//对角线1
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
//    else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])//对角线2
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
//    else if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2])//第一行
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
//    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])//第二行
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
//    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])//第三行
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
//    else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])//第一类
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
//    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])//第二列
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
//    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])//第三列
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