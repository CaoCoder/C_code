#define _CRT_SECURE_NO_WARNINGS
//防止被重复包含
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//要求存储的数据必须从0开始，依次连续存储
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//数据个数
	int capacity;//数据空间大小
}SL, SeqList;
//初始化
void SeqListInit(SeqList* psl);
//扩容
void SeqListCheckCapacity(SeqList* psl);
//尾插O(1)
void SeqListPushBack(SeqList* psl, SLDataType x);
//打印
void SeqListPrint(SeqList* psl);
//头插O(n)
void SeqListPushFront(SeqList* psl, SLDataType x);
//指定位置插入O(n)
void SeqListInsert(SeqList* psl, SLDataType pos, SLDataType x);
//尾删O(1)
void SeqListPopBack(SeqList* psl);
//头删O(n)
void SeqListPopFront(SeqList* psl);
//指定位置删除
void SeqListErease(SeqList* psl, SLDataType pos);
//销毁动态开辟的空间
void SeqListDestroy(SeqList* psl);
//查找
void SeqListFind(SeqList* psl, SLDataType x);
