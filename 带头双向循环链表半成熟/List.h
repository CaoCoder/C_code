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
//创建新节点
LN* BuynewNode(LNDataType x);
//哨兵位节点初始化
void ListNodeInit(LN** pphead);
//尾插
void ListNodePushBack(LN* phead, LNDataType x);
//打印
void ListNodePrint(LN* phead);
//查找
LN* ListNodeFind(LN* phead, LNDataType x);
//指定位置前插入
void ListNodeInsert(LN* phead, LN* pos, LNDataType x);
//指定位置后插入
void ListNodeInsertBack(LN* phead, LN* pos, LNDataType x);
//指定位置删除
void ListNodeErease(LN* phead, LN* pos);
//链表销毁
void ListNodeDestroy(LN* phead);
//尾删
void ListNodePopBack(LN* phead);
//头插
void ListNodePushFront(LN* phead, LNDataType x);
//头删
void ListNodePopFront(LN* phead);