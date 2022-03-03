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
//初始化通讯录
void InitContact(Contact* pc);
//增加通讯录人员
void AddContact(Contact* pc);
//显示通讯录人员
void ShowContact(Contact* pc);
//查找通讯录人员
int FindContact(Contact* pc, char* name);
//删除通讯录人员
void DeleteContact(Contact* pc, char* name);
//查找通讯录人员
void SearchContact(Contact* pc, char* name);
//修改通讯录人员
void ModifyContact(Contact* pc, char* name);
//排序通讯录人员
void SortContact(Contact* pc);
