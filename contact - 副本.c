#include "contact.h"
#define _CRT_SECURE_NO_WARNINGS

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->date, 0, sizeof(pc->date));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == CONTACT_MAX)
	{
		printf("通讯录满了");
		return;
	}
	printf("请输入要添加联系人的姓名：");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入要添加联系人的性别：");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入要添加联系人的年龄：");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("请输入要添加联系人的电话：");
	scanf("%s", pc->date[pc->sz].tel);
	printf("请输入要添加联系人的地址：");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("添加联系人成功\n");
}
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%20s\t%20s\t\n","姓名","性别","年龄","电话","地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%5s\t%5d\t%20s\t%20s\t\n", pc->date[i].name, pc->date[i].sex, pc->date[i].age, pc->date[i].tel, pc->date[i].addr);
	}
}

int FindContact(Contact* pc, char* name)
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, name)==0)
		{
			return i;
		}
	}
	return -1;
}

void DeleteContact(Contact* pc, char* name)
{
	assert(pc && name);
	if (pc->sz == 0)
	{
		printf("已经没有联系人，不可删除\n");
	}
	int ret = FindContact(pc, name);
	if (ret == -1)
	{
		printf("没有此人\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->date[j] = pc->date[j + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}

void SearchContact(Contact* pc, char* name)
{
	assert(pc && name);
	int ret = FindContact(pc, name);
	if (ret != -1)
	{
		printf("找到了\n");
		printf("%10s\t%5s\t%5d\t%20s\t%20s\t\n", pc->date[ret].name, pc->date[ret].sex, pc->date[ret].age, pc->date[ret].tel, pc->date[ret].addr);
	}
	else
	{
		printf("没有找到\n");
	}
}
void ModifyContact( Contact* pc, char* name)
{
	assert(pc && name);
	int ret = FindContact(pc, name);
	if (ret != -1)
	{
		printf("找到了\n");
		printf("%10s\t%5s\t%5s\t%20s\t%20s\t\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%10s\t%5s\t%5d\t%20s\t%20s\t\n", pc->date[ret].name, pc->date[ret].sex, pc->date[ret].age, pc->date[ret].tel, pc->date[ret].addr);
		printf("请修改\n");
		printf("请输入联系人的名字：");
		scanf("%s", pc->date[ret].name);
		printf("请输入联系人的性别：");
		scanf("%s", pc->date[ret].sex);

		printf("请输入联系人的年龄：");
		scanf("%d", &pc->date[ret].age);

		printf("请输入联系人的电话：");
		scanf("%s", pc->date[ret].tel);

		printf("请输入联系人的地址：");
		scanf("%s", pc->date[ret].addr);
		printf("修改成功！\n");

	}
}
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((Student*)e1)->name, ((Student*)e2)->name);
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->date, pc->sz, sizeof(pc->date[0]), cmp_name);
	printf("排序完成\n");
}



