#define _CRT_SECURE_NO_WARNINGS
/*��1*/
#include<stdio.h>
int main()
{
	struct student //�ṹ������
	{
		//�ṹ���Ա
		int c;
		char name[100];
		float s;
	};
	struct student stu = {0};//�ṹ������Ķ���ͳ�ʼ��
	printf("������һ��ѧ������Ϣ��\n");
	scanf("%d%s%f", &stu.c, &stu.name, &stu.s);
	printf("ѧ�ţ�%d��������%s���ɼ�Ϊ %.1f", stu.c, stu.name, stu.s);
	return 0;
}
/*��2*/
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
/*��3*/
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
/*��4*/
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
/*��5*/
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
		printf("�Ҳ���");
	}
	return 0;
}