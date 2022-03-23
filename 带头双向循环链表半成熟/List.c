#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

//申请一个新节点
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
//初始化节点
void ListNodeInit(LN** pphead)
{
	LN* newNode = BuynewNode(0);
	*pphead = newNode;
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
//尾插
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
//打印
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
//查找
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
//指定位置前插入，极限是头插
void ListNodeInsert(LN* phead, LN* pos, LNDataType x)
{
	if (pos == NULL)
	{
		printf("没有找到这个数\n");
		return;
	}
	LN* newNode = BuynewNode(x);
	LN* tailPrev = pos->prev;
	tailPrev->next = newNode;
	newNode->prev = tailPrev;
	newNode->next = pos;
	pos->prev = newNode;
}
//指定位置后插入，极限是尾插
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
//指定位置删除
void ListNodeErease(LN* phead, LN* pos)
{
	if (pos == phead || pos == NULL)
	{
		printf("pos指向头，或为空\n");
		return;
	}
	LN* posPrev = pos->prev;
	LN* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}
//链表销毁
void ListNodeDestroy(LN* phead)
{
	assert(phead);
	LN* cur = phead->next;
	LN* next = cur->next;
	while (cur != phead)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	free(phead);
	phead = NULL;
}
//尾删
void ListNodePopBack(LN* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LN* tail = phead->prev;
	LN* tailPrev = tail->prev;
	free(tail);
	tail = NULL;
	phead->prev = tailPrev;
	tailPrev->next = phead;
}
//头插
void ListNodePushFront(LN* phead, LNDataType x)
{
	assert(phead);
	LN* newNode = BuynewNode(x);
	LN* next = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next = next;
	next->prev = newNode;
}
//头删
void ListNodePopFront(LN* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LN* next = phead->next->next;
	free(phead->next);
	phead->next = NULL;
	phead->next = next;
	next->prev = phead;

}