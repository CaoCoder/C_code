#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LNDataType;

typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LNDataType val;
}LN;
//�����½ڵ�
LN* BuynewNode(LNDataType x);
//�ڱ�λ�ڵ��ʼ��
void ListNodeInit(LN** pphead);
//β��
void ListNodePushBack(LN* phead, LNDataType x);
//��ӡ
void ListNodePrint(LN* phead);
//����
LN* ListNodeFind(LN* phead, LNDataType x);
//ָ��λ��ǰ����
void ListNodeInsert(LN* phead, LN* pos, LNDataType x);
//ָ��λ�ú����
void ListNodeInsertBack(LN* phead, LN* pos, LNDataType x);
//ָ��λ��ɾ��
void ListNodeErease(LN* phead, LN* pos);
//��������
void ListNodeDestroy(LN* phead);
//βɾ
void ListNodePopBack(LN* phead);
//ͷ��
void ListNodePushFront(LN* phead, LNDataType x);
//ͷɾ
void ListNodePopFront(LN* phead);