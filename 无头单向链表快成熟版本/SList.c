#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
//��̬����һ���ڵ�
SListNode* SListNodeBuyNewnode(SLNDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newnode)
	{
		printf("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	return newnode;
}
//β��
void SListNodePushBack(SListNode** pphead, SLNDataType x)
{
	SListNode* newnode = SListNodeBuyNewnode(x);
	//������Ϊ�յ�ʱ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//����Ϊ�յ�ʱ��
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//��ӡ
void SListNodePrint(SListNode** pphead)
{
	while (*pphead != NULL)
	{
		printf("%d->", (*pphead)->data);
		(*pphead) = (*pphead)->next;
	}
	printf("NULL\n");
}
//ͷ��
void SListNodePushFront(SListNode** pphead, SLNDataType x)
{
	SListNode* newnode = SListNodeBuyNewnode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//βɾ
void SListNodePopBack(SListNode** pphead)
{
	assert(pphead);
	//����Ϊ��ʱ
	if (*pphead == NULL)
	{
		return;
	}
	//����ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//����Ϊ��
	else 
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
	}
}
//ͷɾ
void SListNodePopFront(SListNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* current = (*pphead)->next;
	free(*pphead);
	*pphead = current;
}
//����
SListNode* SListNodeFind(SListNode** pphead, SLNDataType x)
{
	SListNode* cur = *pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;

}
//��һ����ַǰ�����һ���ڵ�
void SListInsert(SListNode** pphead, SListNode* pos, SLNDataType x)
{
	SListNode* newnode = SListNodeBuyNewnode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
//����
void SListNodeDestory(SListNode** pphead)
{
	assert(pphead);

	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}
