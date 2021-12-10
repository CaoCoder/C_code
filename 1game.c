#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"//�����Լ�������ͷ�ļ���˫����
//��9*9����������*��������minecount���бȽϡ�
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
//�õݹ飬����ʵ��һƬչ���Ĺ���
void SpreadMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//����CountMine�������в�����Χ�˸�λ���׵ĸ�����
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
		//�����λ�����ף����׵ĸ�����ʾ�ڴ�λ��
		show[x][y] = count + '0';
		//���ڡ�0���ĵ�ASCII��ֵΪ48����1����ASCII��ֵ��49.
		// ����
		//1 + '0' = '1'
		//2 + '0' = '2'
	}
}
//���ҷ���λ����Χ�˸�λ���ж�����
int CountMine(char mine[ROWS][COLS], int x, int y)
{
	return  (mine[x - 1][y + 1] + mine[x][y + 1]
		+ mine[x + 1][y + 1] + mine[x - 1][y]
		+ mine[x + 1][y] + mine[x - 1][y - 1]
		+ mine[x][y - 1] + mine[x + 1][y - 1] - 8 * '0');
}
//ɨ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int c = row * col - minecount;

	while (1)
	{
		printf("����������(x,y)��");
		scanf("%d%d", &x, &y);
		//�����������������9*9������
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			if (mine[x][y] == '0')
			{
				SpreadMine(mine, show, x, y);
				system("cls");
				DisplayMine(show, ROW, COL);
				if (is_win(show, ROW, COL) == minecount)
				{
					printf("��ϲ��Ӯ��!\n");
					DisplayMine(mine, ROW, COL);
					break;
				}
			}
			else
			{
				printf("���ź��㱻ը����~\n");
				DisplayMine(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("��������Խ��,���������룺");
		}
	}
}
//��ʼ�����̣�һ�����������ε��á�
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
//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{

	int c = 0;
	while (c != minecount)
	{
		int x = rand() % row + 1;
		//��rand()������9����õ�0~9��ʮ�������ټ�һ�͵õ�1~10.
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			//�����λ��Ϊ��0����������
			//������Ϊ��1��������
			mine[x][y] = '1';
			c++;
		}
	}
}
//����˫��ѭ����ӡ9*9��B����
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
