#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "contactgame.h"
void menu()
{
	printf("*******    1.���  2.ɾ��\n");
	printf("*******    3.����  4.�޸�\n");
	printf("*******    5.����  0.�˳�\n");
	printf("*******    6.��ʾ        \n");

}
int main()
{
	int n = 0;
	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��\n");
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
			printf("�˳���Ϸ\n");
			break;
		default :
			printf("ѡ�����/n");
			break;
		}

	} while (n);
	return 0;
}