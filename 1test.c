#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"
game()
{
	system("cls");//对画面进行清屏，使页面简洁。
	char mine[ROWS][COLS] = { 0 };//创建11*11数组
	char show[ROWS][COLS] = { 0 };
	//第一次传mine数组名
	InitMine(mine, ROWS, COLS, '0');
	//第二次传show数组名
	InitMine(show, ROWS, COLS, '*');
	//在A雷盘布置雷，所以需要传mine数组名
	SetMine(mine, ROW, COL);
	//用B盘进行展示雷的信息和结果
	DisplayMine(show, ROW, COL);
	//进行排雷
	FindMine(mine, show, ROW, COL);
}
menu()
{
	printf("┏━━━━━━┓━━━━━━━━━━━━━━━━━━━━┓━━━━━━━━━━━┓\n");
	printf("┣━━━━━━┫━━━━━━1.PLAY━━━━━━━━┫━━━━━━━━━━━┫\n");
	printf("┣━━━━━━┫━━━━━━1.EXIT━━━━━━━━┫━━━━━━━━━━━┫\n");
	printf("┗━━━━━━┛━━━━━━━━━━━━━━━━━━━━┛━━━━━━━━━━━┛\n");
}
test()
{
	//用rand()函数之前需要先用srand函数。
	srand((unsigned int)time(NULL));
	int n = 0;
	//游戏进去之后需要先有个菜单所以用上do语句
	do
	{
		//打印菜单
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
//程序的入口
int main()
{
	test();
	return 0;
}