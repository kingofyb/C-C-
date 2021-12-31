#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************************\n");
	printf("********  1.play  *******\n");
	printf("********  0.exit  *******\n");
	printf("*************************\n");
}
void game()
{
	//数据存储到一个字符的二维数组中，玩家下棋是'*',电脑下棋是'#'
	char board[ROW][COL] = { 0 };//数组的内容应该是全部空格
	InitBoard(board, ROW, COL);//初始化棋盘
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//实现下棋逻辑
	char ret = 0;
	while (1)
	{
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}