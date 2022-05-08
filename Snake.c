#define _CRT_SECURE_NO_WARNINGS
#include "Snake.h"
extern int max;
extern int grade;

//���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;//��������Ϣ
	curInfo.dwSize = 1;//���û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE;//���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo);//���ù����Ϣ
}
//�����ת
void CursorJump(int x, int y)
{
	COORD pos;//������λ�õĽṹ�����
	pos.X = x;
	pos.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
	SetConsoleCursorPosition(handle, pos);//���ù����Ϣ��
}
//��ʼ������
void InitInterface()
{
	color(6);//��ɫ����Ϊ����ɫ
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL;//��Ǹ�λ��Ϊǽ��
				//�����ת ʲô��˼��
				CursorJump(2 * j, i);
				printf("��");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL;//��Ǹ�λ��Ϊǽ
				printf("��");

			}
			else
			{
				face[i][j] = KONG;//��Ǹ�λ��Ϊ��
			}
		}
	}
	color(7);//����Ϊ��ɫ
	CursorJump(0, ROW);
	printf("��ǰ�÷֣�%d", grade);
	CursorJump(COL, ROW);
	printf("��ʷ��ߵ÷֣�%d", max);
}
//��ɫ����
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//��ɫ����
	//ע��SetConsoleTextAttribute��һ��API��Ӧ�ó����̽ӿڣ�
}
//���ļ���ȡ��߷�
void ReadGrade()
{
	FILE* pf = fopen("̰������ߵ÷ּ�¼.txt", "r");//ֻ���ķ�ʽ���ļ�
	if (pf == NULL)
	{
		pf = fopen("̰������ߵ÷ּ�¼.txt", "w");//��ֻд�ķ�ʽ���ļ�
		fwrite(&max, sizeof(int), 1, pf);//��maxд���ļ�����ʱmaxΪ0������ߵ÷ֳ�ʼ��Ϊ0.
	}
	fseek(pf, 0, SEEK_SET);//ʹ�ļ�ָ��pfָ���ļ���ͷ
	fread(&max, sizeof(int), 1, pf);//��ȡ�ļ����е���ߵ÷ֵ�max��
	fclose(pf);//�ر��ļ�
	pf = NULL;//�ļ�ָ���ÿ�
}
//������߷ֵ��ļ�
void WriteGrade()
{
	FILE* pf = fopen("̰������ߵ÷ּ�¼.txt", "w");//��ֻд�ķ�ʽ���ļ�
	if (pf == NULL)
	{
		printf("������ߵ÷ּ�¼ʧ��\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf);//��������Ϸ�÷�д���ļ���
	fclose(pf);//�ر��ļ�
	pf = NULL;
}
//��ʼ����
void InitSnake()
{
	snake.len = 2;// �ߵ����峤��ʼΪ2
	snake.x = COL / 2;//��ͷλ�õĺ�����
	snake.y = ROW / 2;//��ͷλ�õ�������
	//��������ĳ�ʼ��
	body[0].x = COL / 2 - 1;
	body[0].y = ROW / 2;
	body[1].x = COL / 2 - 2;
	body[1].y = ROW / 2;
	//����ͷ������λ�ý��б��
	face[snake.y][snake.x] = HEAD;
	face[body[0].y][body[0].x] = BODY;
	face[body[1].y][body[1].x] = BODY;

}
//�������ʳ��
void RandFood()
{
	int i = 0;
	int j = 0;
	do
	{
		//�������ʳ��ĺ�������
		i = rand() % ROW;
		j = rand() & COL;
	} while (face[i][j] != KONG);
	face[i][j] = FOOD;//��ʳ��λ�ý��б��
	color(12);//��ɫ����Ϊ��ɫ
	CursorJump(2 * j, i);//�����ת�����ɵ����λ�ô�
	printf("��");//��ӡʳ��
}
//�жϵ÷������
void JudgeFunc(int x, int y)
{
	//����ͷ���������λ����ʳ���÷�
	if (face[snake.y + y][snake.x + x] == FOOD)
	{
		snake.len++;// �����ӳ�
		grade += 10;//���µ�ǰ�÷�
		color(7);//��ɫ����Ϊ��ɫ
		CursorJump(0, ROW);
		printf("��ǰ�÷֣�%d", grade);//���´�ӡ��ǰ�÷�
		RandFood();//�����������ʳ��
	}
	//����ͷ���������λ����ǽ��������������Ϸ����
	if (face[snake.y + y][snake.x + x] == WALL || WALL || face[snake.y + y][snake.x] == BODY)
	{
		Sleep(1000);//������ҷ�Ӧʱ��
		system("cls");//�����Ļ
		color(7);//��ɫ����Ϊ��ɫ
		CursorJump(2 * (COL / 3), ROW / 2 - 3);
		if (grade > max)
		{
			printf("��ϲ�������߼�¼����߼�¼����Ϊ%d", grade);
			WriteGrade();
		}
		else if (grade == max)
		{
			printf("����߼�¼��ƽ�������ٴ��Ѽ�%d", grade);
		}
		else
		{
			printf("��������ͣ���ǰ����߼�¼���%d", max - grade);
		}
		CursorJump(2 * (COL / 3), ROW / 2);
		printf("GAME OVER");
		while (1)//ѯ������Ƿ�����һ��
		{
			char ch;
			CursorJump(2 * (COL / 3), ROW / 2 + 3);
			printf("����һ��?(y/n):");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				system("cls");
				main();
			}
			else if (ch == 'n' || ch == 'N')
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				exit(0);
			}
			else
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				printf("ѡ��������ٴ�ѡ��");
			}
		}
	}
}
//��ӡ���븲����
void DrawSnake(int flag)
{
	if (flag == 1)//��ӡ��
	{
		color(10);//��ɫ����Ϊ��ɫ
		CursorJump(2 * snake.x, snake.y);
		printf("��"); //��ӡ��ͷ
		for (int i = 0; i < snake.len; i++)
		{
			CursorJump(2 * body[i].x, body[i].y);
			printf("��"); //��ӡ����
		}
	}
	else//������
	{
		if (body[snake.len - 1].x != 0)//��ֹlen++��(0.0)λ��ǽ����
		{
			//����β����Ϊ�ո񼴿�
			CursorJump(2 * body[snake.len - 1].x, body[snake.len - 1].y);
			printf("  ");
		}
	}
	
}
//�ƶ���
void MoveSnake(int x, int y)
{
	DrawSnake(0); //�ȸ��ǵ�ǰ����ʾ����
	face[body[snake.len - 1].y][body[snake.len - 1].x] = KONG; //���ƶ�����β���±��Ϊ��
	face[snake.y][snake.x] = BODY; //���ƶ�����ͷ��λ�ñ�Ϊ����
	//���ƶ����������λ��������Ҫ����
	for (int i = snake.len - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	//���ƶ�����ͷλ����Ϣ��Ϊ��0��������λ����Ϣ
	body[0].x = snake.x;
	body[0].y = snake.y;
	//��ͷ��λ�ø���
	snake.x = snake.x + x;
	snake.y = snake.y + y;
	DrawSnake(1); //��ӡ�ƶ������
}
//ִ�а���
void run(int x, int y)
{
	int t = 0;
	while (1)
	{
		if (t == 0)
			t = 3000; //����tԽС�����ƶ��ٶ�Խ�죨���Ը��ݴ�������Ϸ�Ѷȣ�
		while (--t)
		{
			if (kbhit() != 0) //�����̱��û������˳�ѭ��
				break;
		}
		if (t == 0) //����δ���û�
		{
			JudgeFunc(x, y); //�жϵ����λ�ú��Ƿ�÷�����Ϸ����
			MoveSnake(x, y); //�ƶ���
		}
		else //���̱��û�
		{
			break; //����Game������ȡ��ֵ
		}
	}
}