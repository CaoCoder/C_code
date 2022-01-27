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
		printf("ͨѶ¼����");
		return;
	}
	//������ϵ��
	printf("���������֣�");
	scanf("%s", pc->data[pc->sz].name);
	printf("���������䣺");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("�������ַ");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
	printf("������ϵ�˳ɹ�;\n");
}
void ShowContact(const Contact* pc)
{
	//�ж�ָ�벻Ϊ��
	assert(pc);
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-13s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ���˵����֣�");
	scanf("%s", name);
	//����
	int pos = FindByname(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
	//ɾ��
		int j = 0;
		for (j = pos; j < pc->sz-1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc ->sz--;
		printf("��ɾ��\n");
	}
}
