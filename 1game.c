#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"//引用自己创建的头文件用双引号
//对9*9雷区遍历查*的数量和minecount进行比较。
int is_win(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int c = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if ('*' == show[i][j])
			{
				c++;
			}
		}
	}
	return c;
}
//用递归，进行实现一片展开的功能
void SpreadMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//调用CountMine函数进行查找周围八个位置雷的个数。
	int count = CountMine(mine, x, y);
	if (0 == count)
	{
		show[x][y] = ' ';
		if (show[x][y + 1] == '*')
			SpreadMine(mine, show, x, y + 1);
		if (show[x][y - 1] == '*')
			SpreadMine(mine, show, x, y - 1);
		if (show[x + 1][y] == '*')
			SpreadMine(mine, show, x + 1, y);
		if (show[x + 1][y - 1] == '*')
			SpreadMine(mine, show, x + 1, y - 1);
		if (show[x + 1][y + 1] == '*')
			SpreadMine(mine, show, x + 1, y + 1);
		if (show[x - 1][y] == '*')
			SpreadMine(mine, show, x - 1, y);
		if (show[x - 1][y + 1] == '*')
			SpreadMine(mine, show, x - 1, y + 1);
		if (show[x - 1][y - 1] == '*')
			SpreadMine(mine, show, x - 1, y - 1);
	}
	else
	{
		//如果该位置是雷，则将雷的个数显示在此位置
		show[x][y] = count + '0';
		//由于‘0’的的ASCII码值为48，‘1’的ASCII码值是49.
		// 所以
		//1 + '0' = '1'
		//2 + '0' = '2'
	}
}
//查找非雷位置周围八个位置有多少雷
int CountMine(char mine[ROWS][COLS], int x, int y)
{
	return  (mine[x - 1][y + 1] + mine[x][y + 1]
		+ mine[x + 1][y + 1] + mine[x - 1][y]
		+ mine[x + 1][y] + mine[x - 1][y - 1]
		+ mine[x][y - 1] + mine[x + 1][y - 1] - 8 * '0');
}
//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int c = row * col - minecount;

	while (1)
	{
		printf("请输入坐标(x,y)：");
		scanf("%d%d", &x, &y);
		//将输入的坐标限制在9*9的雷区
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (mine[x][y] == '0')
			{
				SpreadMine(mine, show, x, y);
				system("cls");
				DisplayMine(show, ROW, COL);
				if (is_win(show, ROW, COL) == minecount)
				{
					printf("恭喜你赢了!\n");
					DisplayMine(mine, ROW, COL);
					break;
				}
			}
			else
			{
				printf("很遗憾你被炸死了~\n");
				DisplayMine(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("输入坐标越界,请重新输入：");
		}
	}
}
//初始化棋盘，一个函数，两次调用。
void InitMine(char mine[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			mine[i][j] = set;
		}
	}
}
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{

	int c = 0;
	while (c != minecount)
	{
		int x = rand() % row + 1;
		//用rand()函数对9求余得到0~9这十个数，再加一就得到1~10.
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			//如果此位置为‘0’，即非雷
			//则设置为‘1’，即雷
			mine[x][y] = '1';
			c++;
		}
	}
}
//运用双重循环打印9*9的B雷区
void DisplayMine(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			if (0 == i)
			{
				printf("%d ", j);
			}
			else
			{
				printf("%c ", show[i][j]);
			}
		}
		printf("\n");
	}
}
