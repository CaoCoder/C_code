#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
//动态申请一个节点
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
//尾插
void SListNodePushBack(SListNode** pphead, SLNDataType x)
{
	SListNode* newnode = SListNodeBuyNewnode(x);
	//当链表为空的时候
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//当不为空的时候
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
//打印
void SListNodePrint(SListNode** pphead)
{
	while (*pphead != NULL)
	{
		printf("%d->", (*pphead)->data);
		(*pphead) = (*pphead)->next;
	}
	printf("NULL\n");
}
//头插
void SListNodePushFront(SListNode** pphead, SLNDataType x)
{
	SListNode* newnode = SListNodeBuyNewnode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SListNodePopBack(SListNode** pphead)
{
	assert(pphead);
	//当表为空时
	if (*pphead == NULL)
	{
		return;
	}
	//当表只有一个节点
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	//当表不为空
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
//头删
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
//查找
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
//在一个地址前面插入一个节点
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
//销毁
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
