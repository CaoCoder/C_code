#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

//����һ���½ڵ�
LN* BuynewNode(LNDataType x)
{
	LN* newNode = (LN*)malloc(sizeof(LN));
	if (newNode == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->val = x;
	return newNode;
}
//��ʼ���ڵ�
void ListNodeInit(LN** pphead)
{
	LN* newNode = BuynewNode(0);
	*pphead = newNode;
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
//β��
void ListNodePushBack(LN* phead, LNDataType x)
{
	assert(phead);
	LN* newNode = BuynewNode(x);
	LN* tail = phead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}
//��ӡ
void ListNodePrint(LN* phead)
{
	assert(phead);
	LN* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
//����
LN* ListNodeFind(LN* phead, LNDataType x)
{
	LN* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//ָ��λ��ǰ���룬������ͷ��
void ListNodeInsert(LN* phead, LN* pos, LNDataType x)
{
	if (pos == NULL)
	{
		printf("û���ҵ������\n");
		return;
	}
	LN* newNode = BuynewNode(x);
	LN* tailPrev = pos->prev;
	tailPrev->next = newNode;
	newNode->prev = tailPrev;
	newNode->next = pos;
	pos->prev = newNode;
}
//ָ��λ�ú���룬������β��
void ListNodeInsertBack(LN* phead, LN* pos, LNDataType x)
{
	if (pos == NULL)
	{
		return;
	}
	LN* newNode = BuynewNode(x);
	LN* posNext = pos->next;
	pos->next = newNode;
	newNode->prev = pos;
	newNode->next = posNext;
	posNext->prev = newNode;
}
//ָ��λ��ɾ��
void ListNodeErease(LN* phead, LN* pos)
{
	if (pos == phead || pos == NULL)
	{
		printf("posָ��ͷ����Ϊ��\n");
		return;
	}
	LN* posPrev = pos->prev;
	LN* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}
//��������
void ListNodeDestroy(LN* phead)
{
	LN* cur = phead->next;
	while (cur != phead)
	{

	}
}