#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS] ,int row, int col)
{
	int x = 0;
	int y = 0;
	int c = row * col - minecount;
	while (c)
	{
		scanf("%d%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (mine[x][y] == '0')
			{
				show[x][y] = ' ';
				mine[x][y] = ' ';
				printf("���������룺\n");
				DisplayMine(show, ROW, COL);
				c--;
			}
			else if (mine[x][y] == '1')
			{
				printf("��ϲ�㱻ը����\n");
				DisplayMine(mine, ROW, COL);
				break;
			}
			else
			{
				printf("����Ƿ�������������;\n");
			}
		}
		else
		{
			printf("����Ƿ����������룺\n");
		}
	}
	if (c == 0)
	{
		printf("��ϲ��Ӯ��");
	}
}
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
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	
	int c = 0;
	while (c!=minecount)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] =='0')
		{
			mine[x][y] = '1';
			c++;
		}
	}
}
void DisplayMine(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}
