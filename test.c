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
			printf("退出程序\n");
			break;
		case Add:
			printf("增加通讯录成员：\n");
			AddContact(&con);
			break;
		case Delete:
			printf("删除通讯录人员：");
			printf("请输入要删除的人员名字");
			scanf("%s", name);
			DeleteContact(&con, name);
			break;
		case Search:
			printf("请输入你要查找的联系人\n");
			scanf("%s", name);
			SearchContact(&con, name);
			break;
		case Modify:
			printf("请输入要修改的联系人名字:");
			scanf("%s", name);
			ModifyContact(&con, name);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Sort:
			printf("排序通讯录人员：\n");
			SortContact(&con);
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	} while (n);
	return 0;
}