#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
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