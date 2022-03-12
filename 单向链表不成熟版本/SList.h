#define _CRT_SECURE_NO_WARNINGS
#pragma once//防止被重复包含
#include<stdio.h>
#include<stdlib.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
//打印
void SListPrint(SLTNode* phead);
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//动态申请节点
SLTNode* BuyListNode(SLTDataType x);
//头插
void SListPushFront(SLTNode** pphead, SLTDataType X);
//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);