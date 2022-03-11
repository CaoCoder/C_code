#define _CRT_SECURE_NO_WARNINGS
//��ֹ���ظ�����
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//Ҫ��洢�����ݱ����0��ʼ�����������洢
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//���ݸ���
	int capacity;//���ݿռ��С
}SL, SeqList;
//��ʼ��
void SeqListInit(SeqList* psl);
//����
void SeqListCheckCapacity(SeqList* psl);
//β��O(1)
void SeqListPushBack(SeqList* psl, SLDataType x);
//��ӡ
void SeqListPrint(SeqList* psl);
//ͷ��O(n)
void SeqListPushFront(SeqList* psl, SLDataType x);
//ָ��λ�ò���O(n)
void SeqListInsert(SeqList* psl, SLDataType pos, SLDataType x);
//βɾO(1)
void SeqListPopBack(SeqList* psl);
//ͷɾO(n)
void SeqListPopFront(SeqList* psl);
//ָ��λ��ɾ��
void SeqListErease(SeqList* psl, SLDataType pos);
//���ٶ�̬���ٵĿռ�
void SeqListDestroy(SeqList* psl);
//����
void SeqListFind(SeqList* psl, SLDataType x);
