#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d", &money);

	total = money;
	empty = money;
	while (empty >= 1)
	{
		empty = money / 2;
		total += empty;
		break;
	}
	printf("%d\n", total);
	return 0;
}