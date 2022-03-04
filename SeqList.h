#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;//动态开辟数组
	size_t size;
	size_t capacity;
}SL;

//初始化顺序表
void SeqListInit(SL* ps1);
//free空间
void SeqListDestory(SL* ps1);
//判断是否满了
void SeqListCheck(SL* ps1);
//打印
void SeqListPrint(SL* ps1);
//头插
void SeqListPushFront(SL* ps1, SLDataType x);
//尾插
void SeqListPushBack(SL* ps1, SLDataType x);
//头删
void SeqListPopFront(SL* ps1);
//尾删
void SeqListPopBack(SL* ps1);
//查找
int SeqListFind(SL* ps1, SLDataType x);
//修改
void SeqListChange(SL* ps1, int pos, SLDataType x);
//指定位置前插入x
void SeqListInsert(SL* ps1, int pos, SLDataType x);
//指定位置删除x
void SeqListDelete(SL* ps1, SLDataType x);


