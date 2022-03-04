#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;//��̬��������
	size_t size;
	size_t capacity;
}SL;

//��ʼ��˳���
void SeqListInit(SL* ps1);
//free�ռ�
void SeqListDestory(SL* ps1);
//�ж��Ƿ�����
void SeqListCheck(SL* ps1);
//��ӡ
void SeqListPrint(SL* ps1);
//ͷ��
void SeqListPushFront(SL* ps1, SLDataType x);
//β��
void SeqListPushBack(SL* ps1, SLDataType x);
//ͷɾ
void SeqListPopFront(SL* ps1);
//βɾ
void SeqListPopBack(SL* ps1);
//����
int SeqListFind(SL* ps1, SLDataType x);
//�޸�
void SeqListChange(SL* ps1, int pos, SLDataType x);
//ָ��λ��ǰ����x
void SeqListInsert(SL* ps1, int pos, SLDataType x);
//ָ��λ��ɾ��x
void SeqListDelete(SL* ps1, SLDataType x);


