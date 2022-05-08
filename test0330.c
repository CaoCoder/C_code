#define _CRT_SECURE_NO_WARNINGS
#include "Snake.h"
void Game();
int max;
int grade;



int main()
{

	max = 0, grade = 0; //��ʼ������
	system("title ̰����"); //����cmd���ڵ�����
	system("mode con cols=84 lines=23"); //����cmd���ڵĴ�С
	HideCursor(); //���ع��
	ReadGrade(); //���ļ���ȡ��߷ֵ�max����
	InitInterface(); //��ʼ������
	InitSnake(); //��ʼ����
	srand((unsigned int)time(NULL)); //����������������
	RandFood(); //�������ʳ��
	DrawSnake(1); //��ӡ��
	Game(); //��ʼ��Ϸ
	return 0;
}

//��Ϸ�����߼�����
void Game()
{
	int n = RIGHT; //��ʼ��Ϸʱ��Ĭ������ƶ�
	int tmp = 0; //��¼�ߵ��ƶ�����
	goto first; //��һ�ν���ѭ������Ĭ�Ϸ���ǰ��
	while (1)
	{
		n = getch(); //��ȡ��ֵ
		//��ִ��ǰ����Ҫ������ȡ�İ������е���
		switch (n)
		{
		case UP:
		case DOWN: //����û����ǡ��ϡ����¡�
			if (tmp != LEFT && tmp != RIGHT) //������һ���ߵ��ƶ������ǡ��󡱻��ҡ�
			{
				n = tmp; //��ô��һ���ߵ��ƶ���������Ϊ��һ���ߵ��ƶ�����
			}
			break;
		case LEFT:
		case RIGHT: //����û����ǡ��󡱻��ҡ�
			if (tmp != UP && tmp != DOWN) //������һ���ߵ��ƶ������ǡ��ϡ����¡�
			{
				n = tmp; //��ô��һ���ߵ��ƶ���������Ϊ��һ���ߵ��ƶ�����
			}
		case SPACE:
		case ESC:
		case 'r':
		case 'R':
			break; //���ĸ��������
		default:
			n = tmp; //��������Ч��Ĭ��Ϊ��һ�����ƶ��ķ���
			break;
		}
	first: //��һ�ν���ѭ������Ĭ�Ϸ���ǰ��
		switch (n)
		{
		case UP: //���������
			run(0, -1); //�����ƶ���������ƫ��Ϊ0��������ƫ��Ϊ-1��
			tmp = UP; //��¼��ǰ�ߵ��ƶ�����
			break;
		case DOWN: //���������
			run(0, 1); //�����ƶ���������ƫ��Ϊ0��������ƫ��Ϊ1��
			tmp = DOWN; //��¼��ǰ�ߵ��ƶ�����
			break;
		case LEFT: //���������
			run(-1, 0); //�����ƶ���������ƫ��Ϊ-1��������ƫ��Ϊ0��
			tmp = LEFT; //��¼��ǰ�ߵ��ƶ�����
			break;
		case RIGHT: //���������
			run(1, 0); //�����ƶ���������ƫ��Ϊ1��������ƫ��Ϊ0��
			tmp = RIGHT; //��¼��ǰ�ߵ��ƶ�����
			break;
		case SPACE: //��ͣ
			system("pause>nul"); //��ͣ�����������
			break;
		case ESC: //�˳�
			system("cls"); //�����Ļ
			color(7); //��ɫ����Ϊ��ɫ
			CursorJump(COL - 8, ROW / 2);
			printf("  ��Ϸ����  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		case 'r':
		case 'R': //���¿�ʼ
			system("cls"); //�����Ļ
			main(); //����ִ��������
		}
	}
}

