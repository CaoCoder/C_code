#define _CRT_SECURE_NO_WARNINGS
#pragma once//��ֹ���ظ�����
#include<stdio.h>
#include<stdlib.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
//��ӡ
void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//��̬����ڵ�
SLTNode* BuyListNode(SLTDataType x);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType X);
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);