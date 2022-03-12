#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
//��ӡ
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);


	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//��̬����ڵ�
SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;

}
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	//��ʹΪ�ձ���������
	newnode->next = *pphead;
	*pphead = newnode;
}
//βɾ
void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}