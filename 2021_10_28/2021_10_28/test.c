#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//int main()
//{
	//更便捷打印100以内3的倍数
	//for (int i = 3; i <= 100; i += 3)
	//{
	//	printf("%d ", i);
	//}
	//求最大公约数
	//int m = 0;
	//int n = 0;
	//int ret = 0;
	//scanf("%d %d", &m, &n);
	//if (m > n)
	//	ret = n;
	//else
	//	ret = m;
	//while (1)
	//{
	//	if (n % ret == 0 && m % ret == 0)
	//	{
	//		break;
	//	}
	//	ret--;
	//}
	//printf("%d", ret);

	//辗转相除法
	//int m = 0;
	//int n = 0;
	//int ret = 0;
	//scanf("%d %d", &m, &n);
	//while (ret = m % n)
	//{
	//	m = n;
	//	n = ret;
	//}
	//printf("%d\n", n);

	//m*n/最大公约数 = 最小公倍数

	//闰年判断的规则
	//1.能被4整除，并且不能被100整除是闰年
	//2.能被400整除是闰年

	//int y = 0;
	//int count = 0;
	//for (y = 1000; y <= 2000; y++)
	//{
		////判断y是不是闰年
	//	if (((y % 4 == 0) && (y % 100 != 0))|| (y % 400 == 0))
	//	{
	//		count++;
	//		printf("%d ", y);
	//	}       
	//}
	//printf("\ncount = %d\n", count);


	//判断素数
	//1
	//int y = 0;
	//for (y = 100; y <= 200; y++)
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < squrt(y); n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y不是素数
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//2
	//y=a*b
	//那么a和b之间必有一个数<=y的平方根

	//int y = 0;
	//for (y = 100; y <= sqrt(y); y++) //***
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < y; n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y不是素数
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//优化
	//int y = 0;
	//for (y = 100; y <= 200; y+=2) //***
	//{
	//	int n = 0;
	//	int flag = 1;
	//	for (n = 2; n < y; n++)
	//	{
	//		if (y % n == 0)
	//		{
	//			flag = 0;//y不是素数
	//			break;
	//		}
	//	}
	//	if (flag == 1)
	//	{
	//		prinf("%d ", y);
	//	}
	//}

	//编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则
	//提示登录成，如果三次均输入错误，则退出程序。
	

	//strcmp = string compare	
	//返回0，说明两个字符串相等
	//返回大于0的数字
	//返回小于0的数字
	//char password[20] = "";
	//int i = 0;
	//for(i=0;i<3;i++)
	//{
	//	printf("请输入密码:>");
	//	scanf("%s", password);//因为password是数组名，数组本来就是地址
	//	if (strcmp(password, "123456") == 0)
	//	{
	//		printf("登陆成功\n");
	//		break;
	//	}
	//	else
	//	{
	//		printf("密码错误\n");
	//	}
	//}
	//if (i == 3)
	//{
	//	printf("三次密码均错误\n");
	//}
//	return 0;
//}




//电脑随机生成一个1-100的数字
//猜数字
//玩家猜小了，电脑会告诉猜小了
//玩家猜大了，电脑会告诉猜大了

void menu()
{
	printf("**************************\n");
	printf("****&   1. play    *******\n");
	printf("****&   0. exit    *******\n");
	printf("**************************\n");
}
void game()
{
	int guess = 0;
	//猜数字游戏的过程
	//生成随机数
	int r = rand()%100+1;//(0~99)+1
	//猜数字
	while (1)
	{
		printf("猜数字:>");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了\n");
		}
		else if (guess > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//时间-设置随机数的生成器
	do
	{
		//打印菜单
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
	return 0;
}