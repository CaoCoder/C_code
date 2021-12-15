#define _CRT_SECURE_NO_WARNINGS
/*上1*/
#include<stdio.h>
int main()
{
	struct student //结构体类型
	{
		//结构体成员
		int c;
		char name[100];
		float s;
	};
	struct student stu = {0};//结构体变量的定义和初始化
	printf("请输入一个学生得信息：\n");
	scanf("%d%s%f", &stu.c, &stu.name, &stu.s);
	printf("学号：%d，姓名：%s，成绩为 %.1f", stu.c, stu.name, stu.s);
	return 0;
}
/*上2*/
#include<stdio.h>
int main()
{
	struct student
	{
		int a;
		char name[20];
		float s;
	};
	struct student Stu[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d%s%f", &Stu[i].a, Stu[i].name, &Stu[i].s);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d %s %f", Stu[i].a, Stu[i].name, Stu[i].s);
		printf("\n");
	}
	return 0;
}
/*上3*/
#include<stdio.h>
int main()
{
	struct student
	{
		int a;
		char name[20];
		float b;
		float c;
	};
	struct student Stu = { 0 };
	scanf("%d%s%f%f", &Stu.a, Stu.name, &Stu.b, &Stu.c);
	printf("%d %s %.1f %.1f", Stu.a, Stu.name, Stu.b + Stu.c, (Stu.b + Stu.c) / 2);
	return 0;
}
/*上4*/
#include<stdio.h>
int main()
{
	struct student
	{
		int a;
		char name[20];
		float b;
		float c;
	};
	struct student Stu[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d%s%f%f", &Stu[i].a, Stu[i].name, &Stu[i].b,&Stu[i].c);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d %s %.1f %.1f", Stu[i].a, Stu[i].name, Stu[i].b + Stu[i].c, (Stu[i].b + Stu[i].c) / 2);
		printf("\n");
	}
	return 0;
}
/*上5*/
#include<stdio.h>
#include<string.h>
int main()
{
	struct student
	{
		char name[20];
		char num[20];
	};
	struct student Stu[5] = { 0 };
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%s%s", Stu[i].name, Stu[i].num);
	}
	int flag = 0;
	char arr[20] = { 0 };
	scanf("%s", arr);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(arr, Stu[i].name) == 0)
		{
			printf("%s\n", Stu[i].num);
			flag = 1;
		}
	}
	if (0 == flag)
	{
		printf("找不到");
	}
	return 0;
}