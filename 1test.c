#define _CRT_SECURE_NO_WARNINGS
#include "12_9game.h"
game()
{
	system("cls");//�Ի������������ʹҳ���ࡣ
	char mine[ROWS][COLS] = { 0 };//����11*11����
	char show[ROWS][COLS] = { 0 };
	//��һ�δ�mine������
	InitMine(mine, ROWS, COLS, '0');
	//�ڶ��δ�show������
	InitMine(show, ROWS, COLS, '*');
	//��A���̲����ף�������Ҫ��mine������
	SetMine(mine, ROW, COL);
	//��B�̽���չʾ�׵���Ϣ�ͽ��
	DisplayMine(show, ROW, COL);
	//��������
	FindMine(mine, show, ROW, COL);
}
menu()
{
	printf("����������������������������������������������������������������������������������\n");
	printf("�ǩ������������ϩ�����������1.PLAY�����������������ϩ�����������������������\n");
	printf("�ǩ������������ϩ�����������1.EXIT�����������������ϩ�����������������������\n");
	printf("����������������������������������������������������������������������������������\n");
}
test()
{
	//��rand()����֮ǰ��Ҫ����srand������
	srand((unsigned int)time(NULL));
	int n = 0;
	//��Ϸ��ȥ֮����Ҫ���и��˵���������do���
	do
	{
		//��ӡ�˵�
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (n);
}
//��������
int main()
{
	test();
	return 0;
}