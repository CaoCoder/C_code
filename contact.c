#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "contactgame.h"
void menu()
{
	printf("*******    1.添加  2.删除\n");
	printf("*******    3.查找  4.修改\n");
	printf("*******    5.排序  0.退出\n");
	printf("*******    6.显示        \n");

}
int main()
{
	int n = 0;
	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DeleteContact(&con);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			ShowContact(&con);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("选择错误/n");
			break;
		}

	} while (n);
	return 0;
}