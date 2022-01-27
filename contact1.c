#define _CRT_SECURE_NO_WARNINGS
#include "contactgame.h"
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录满了");
		return;
	}
	//输入联系人
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
	printf("增加联系人成功;\n");
}
void ShowContact(const Contact* pc)
{
	//判断指针不为空
	assert(pc);
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-13s\n", "名字", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-15s\t%-13s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].addr, pc->data[i].tele);
	}
}
int FindByname(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;

}
void DeleteContact(Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入要删除人的名字：");
	scanf("%s", name);
	//查找
	int pos = FindByname(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
	//删除
		int j = 0;
		for (j = pos; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc ->sz--;
		printf("已删除\n");
	}
}
