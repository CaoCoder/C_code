#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	size_t size;
	size_t capacity;
}HP;
//初始化结构体
void HeapInit(HP* php);
//销毁结构体
void HeapDestroy(HP* php);
//向堆里插入数据
void HeapPush(HP* php, HPDataType x);
//交换堆中父子
void HeapSwap(HPDataType* pa, HPDataType* pb);
//删除堆顶数据
void HeapPop(HP* php);
//按照下标打印堆
void HeapPrint(HP* php);
//判断堆是否为空
bool HeapEmpty(HP* php);
//求堆中有几个元素
size_t HeapSize(HP* php);
//得到堆顶的值
HPDataType HeapTop(HP* php);
