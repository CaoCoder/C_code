#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("***************************\n");
	printf("***************************\n");
	printf("******1.Add    2.Delete****\n");
	printf("******3.Search 4.Modify****\n");
	printf("******5.Show   6.Sort******\n");
	printf("******0.exit           ****\n");
	printf("***************************\n");
	printf("***************************\n");

}
int main()
{
	int n = 0;
	Contact con;
	char name[10] = { 0 };
	InitContact(&con);
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case exitcontact:
			printf("�˳�����\n");
			break;
		case Add:
			printf("����ͨѶ¼��Ա��\n");
			AddContact(&con);
			break;
		case Delete:
			printf("ɾ��ͨѶ¼��Ա��");
			printf("������Ҫɾ������Ա����");
			scanf("%s", name);
			DeleteContact(&con, name);
			break;
		case Search:
			printf("��������Ҫ���ҵ���ϵ��\n");
			scanf("%s", name);
			SearchContact(&con, name);
			break;
		case Modify:
			printf("������Ҫ�޸ĵ���ϵ������:");
			scanf("%s", name);
			ModifyContact(&con, name);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Sort:
			printf("����ͨѶ¼��Ա��\n");
			SortContact(&con);
			break;
		default:
			printf("����������������룺");
			break;
		}
	} while (n);
	return 0;
}