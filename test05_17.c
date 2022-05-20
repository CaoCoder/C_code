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
	//创建信息表对象s
	Stu s;
	//初始化
	InitStu(&s);
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			printf("退出程序\n");
			break;
		case 1:
			printf("增加成员：\n");
			//增加学生到信息表
			AddStu(&s);			
			break;
		case 2:
			//展示信息表
			ShowStu(&s);
			break;
		case 3:
			//保存信息表到文件
			SaveStu(&s);
			break;
		case 4:
			//排序
			SortStu(&s);
			break;
		case 5:
			//女生合格率
			GirlPass(&s);
			break;
		case 6:
			//男生合格率
			ManPass(&s);
			break;
		case 7:
			//总的平均分
			TotalScore(&s);
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	} while (n);
	//销毁信息表
	DestoryStu(&s);
	return 0;
}