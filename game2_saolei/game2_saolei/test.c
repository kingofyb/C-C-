#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("********  1. play  ********\n");
	printf("********  0. exit  ********\n");
	printf("***************************\n");
}

void game()
{
	//创建数组，一个存放雷的信息，一个显示
	//存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };

	//初始化mine数组为全'0'
	InitBoard(mine, ROWS, COLS, '0');
	//初始化show数组为全'*'
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排雷
	FindMine(mine, show, ROW, COL);
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
			//扫雷
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

//展开一片
//a.该坐标处不是雷
//b.该坐标周围也没有雷
//c.该坐标没有被排查过