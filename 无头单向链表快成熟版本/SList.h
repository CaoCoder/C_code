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
//动态申请一个节点
SListNode* SListNodeBuyNewnode(SLNDataType x);
//尾插
void SListNodePushBack(SListNode** pphead, SLNDataType x);
//打印
void SListNodePrint(SListNode** pphead);
//头插
void SListNodePushFront(SListNode** pphead, SLNDataType x);
//尾删
void SListNodePopBack(SListNode** pphead);
//头删
void SListNodePopFront(SListNode** pphead);
//查找
SListNode* SListNodeFind(SListNode** pphead, SLNDataType x);
//在一个地址前面插入一个节点
void SListInsert(SListNode** pphead, SListNode* pos, SLNDataType x);
//销毁
void SListNodeDestory(SListNode** pphead);
