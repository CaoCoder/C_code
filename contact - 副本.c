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
		printf("ͨѶ¼����");
		return;
	}
	printf("������Ҫ�����ϵ�˵�������");
	scanf("%s", pc->date[pc->sz].name);
	printf("������Ҫ�����ϵ�˵��Ա�");
	scanf("%s", pc->date[pc->sz].sex);
	printf("������Ҫ�����ϵ�˵����䣺");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("������Ҫ�����ϵ�˵ĵ绰��");
	scanf("%s", pc->date[pc->sz].tel);
	printf("������Ҫ�����ϵ�˵ĵ�ַ��");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("�����ϵ�˳ɹ�\n");
}
void ShowContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%10s\t%5s\t%5s\t%20s\t%20s\t\n","����","�Ա�","����","�绰","��ַ");
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
		printf("�Ѿ�û����ϵ�ˣ�����ɾ��\n");
	}
	int ret = FindContact(pc, name);
	if (ret == -1)
	{
		printf("û�д���\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->date[j] = pc->date[j + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(Contact* pc, char* name)
{
	assert(pc && name);
	int ret = FindContact(pc, name);
	if (ret != -1)
	{
		printf("�ҵ���\n");
		printf("%10s\t%5s\t%5d\t%20s\t%20s\t\n", pc->date[ret].name, pc->date[ret].sex, pc->date[ret].age, pc->date[ret].tel, pc->date[ret].addr);
	}
	else
	{
		printf("û���ҵ�\n");
	}
}
void ModifyContact( Contact* pc, char* name)
{
	assert(pc && name);
	int ret = FindContact(pc, name);
	if (ret != -1)
	{
		printf("�ҵ���\n");
		printf("%10s\t%5s\t%5s\t%20s\t%20s\t\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%10s\t%5s\t%5d\t%20s\t%20s\t\n", pc->date[ret].name, pc->date[ret].sex, pc->date[ret].age, pc->date[ret].tel, pc->date[ret].addr);
		printf("���޸�\n");
		printf("��������ϵ�˵����֣�");
		scanf("%s", pc->date[ret].name);
		printf("��������ϵ�˵��Ա�");
		scanf("%s", pc->date[ret].sex);

		printf("��������ϵ�˵����䣺");
		scanf("%d", &pc->date[ret].age);

		printf("��������ϵ�˵ĵ绰��");
		scanf("%s", pc->date[ret].tel);

		printf("��������ϵ�˵ĵ�ַ��");
		scanf("%s", pc->date[ret].addr);
		printf("�޸ĳɹ���\n");

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
	printf("�������\n");
}



