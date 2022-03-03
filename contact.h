#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>



#define CONTACT_MAX 1000
#define NAME_MAX 10
#define SEX_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 30

typedef struct student
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Student;

typedef struct contact
{
	Student date[CONTACT_MAX];
	int sz;
}Contact;

enum contactmenu
{
	exitcontact,
	Add,
	Delete,
	Search,
	Modify,
	Show,
	Sort,
};
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//����ͨѶ¼��Ա
void AddContact(Contact* pc);
//��ʾͨѶ¼��Ա
void ShowContact(Contact* pc);
//����ͨѶ¼��Ա
int FindContact(Contact* pc, char* name);
//ɾ��ͨѶ¼��Ա
void DeleteContact(Contact* pc, char* name);
//����ͨѶ¼��Ա
void SearchContact(Contact* pc, char* name);
//�޸�ͨѶ¼��Ա
void ModifyContact(Contact* pc, char* name);
//����ͨѶ¼��Ա
void SortContact(Contact* pc);
