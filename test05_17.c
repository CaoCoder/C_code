#define _CRT_SECURE_NO_WARNINGS
#include "si.h"
void menu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.Add    2.Show  ****\n");
	printf("******3.Save   4.Sort  ****\n");
	printf("******5.Girl   6.Man   ****\n");
	printf("******7.Total  0.Exit  ****\n");
	printf("***************************\n");
	printf("***************************\n");
}
int main()
{
	//������Ϣ�����s
	Stu s;
	//��ʼ��
	InitStu(&s);
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("�˳�����\n");
			break;
		case 1:
			printf("���ӳ�Ա��\n");
			//����ѧ������Ϣ��
			AddStu(&s);			
			break;
		case 2:
			//չʾ��Ϣ��
			ShowStu(&s);
			break;
		case 3:
			//������Ϣ���ļ�
			SaveStu(&s);
			break;
		case 4:
			//����
			SortStu(&s);
			break;
		case 5:
			//Ů���ϸ���
			GirlPass(&s);
			break;
		case 6:
			//�����ϸ���
			ManPass(&s);
			break;
		case 7:
			//�ܵ�ƽ����
			TotalScore(&s);
			break;
		default:
			printf("����������������룺");
			break;
		}
	} while (n);
	//������Ϣ��
	DestoryStu(&s);
	return 0;
}