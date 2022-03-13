#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType data;
	struct SListNode* next;
}SListNode;
//��̬����һ���ڵ�
SListNode* SListNodeBuyNewnode(SLNDataType x);
//β��
void SListNodePushBack(SListNode** pphead, SLNDataType x);
//��ӡ
void SListNodePrint(SListNode** pphead);
//ͷ��
void SListNodePushFront(SListNode** pphead, SLNDataType x);
//βɾ
void SListNodePopBack(SListNode** pphead);
//ͷɾ
void SListNodePopFront(SListNode** pphead);
//����
SListNode* SListNodeFind(SListNode** pphead, SLNDataType x);
//��һ����ַǰ�����һ���ڵ�
void SListInsert(SListNode** pphead, SListNode* pos, SLNDataType x);
//����
void SListNodeDestory(SListNode** pphead);
