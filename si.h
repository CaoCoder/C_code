#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define Init_SZ 4

typedef int DataType;
//����ѧ����������Ϣ
typedef struct StudentInfo
{
	int number;//ѧ��
	char name[10];
	char sex[10];
	int score;
}StuInfo;

//�������ѧ�����������
typedef struct Student
{
	StuInfo* a;//�൱���������ڴ������
	int sz;//��¼��Ч��ѧ����Ϣ����
	int capacity;//��¼��ǰѧ����Ϣ����������
}Stu;
//��ʼ��ѧ����Ϣ��
void InitStu(Stu* ps);
//����ѧ����Ϣ��
void DestoryStu(Stu* ps);
//����ѧ������Ϣ��
void AddStu(Stu* ps);
//չʾ��Ϣ��
void ShowStu(Stu* ps);
//����Ϣ�������д���ļ�
void SaveStu(Stu* ps);
//������Ϣ��
void SortStu(Stu* ps);
//��Ů�� �� �����ֿ�
int SeparateStu(Stu* ps);
//Ů���ϸ���
void GirlPass(Stu* ps);
//�����ϸ���
void ManPass(Stu* ps);
//�ܵ�ƽ����
void TotalScore(Stu* ps);