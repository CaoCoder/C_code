#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;
typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);
//��ʾ��ϵ��
void ShowContact(const Contact* pc);
//ɾ����ϵ��
void DeleteContact(Contact* pc);
