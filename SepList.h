#pragma once

#define N 10
#include<stdio.h>
#include<string.h>
typedef int SQDataType;
struct SeqList
{
	SQDataType a[N];
	int size;
};
typedef struct SeqList SL;
//��ɾ��ĵȽӿں���
void SepListInit(SL* ps);