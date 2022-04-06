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
//��ʼ���ṹ��
void HeapInit(HP* php);
//���ٽṹ��
void HeapDestroy(HP* php);
//������������
void HeapPush(HP* php, HPDataType x);
//�������и���
void HeapSwap(HPDataType* pa, HPDataType* pb);
//ɾ���Ѷ�����
void HeapPop(HP* php);
//�����±��ӡ��
void HeapPrint(HP* php);
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php);
//������м���Ԫ��
size_t HeapSize(HP* php);
//�õ��Ѷ���ֵ
HPDataType HeapTop(HP* php);
