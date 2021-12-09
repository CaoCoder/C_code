#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"
game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitMine(mine, ROWS, COLS, '0');
	InitMine(show, ROWS, COLS, '@');
	SetMine(mine, ROW, COL);
	DisplayMine(show, ROW, COL);
	/*DisplayMine(mine, ROW, COL);*/
	FindMine(mine,show, ROW, COL);
}
menu()
{
	printf("******     1.play          ***\n");
	printf("******     0.exit          ***\n");
}
test()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (n);
}
int main()
{
	test();
	return 0;
}