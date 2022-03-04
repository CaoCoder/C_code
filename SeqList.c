#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
#pragma once
void SeqListInit(SL* ps1)
{
	//为何强转为int类型？而sizeof是结构体变量？
	ps1->a = (SLDataType*)malloc(sizeof(SL));
	if (ps1->a == NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
	ps1->capacity = 1;
	ps1->size = 0;
}
//销毁
void SeqListDestory(SL* ps1)
{
	free(ps1->a);
	ps1->a = NULL;
	ps1->size = 0;
	ps1->capacity = 0;
}
//插入之前判断是否满了
void SeqListCheck(SL* ps1)
{
	assert(ps1);
	if (ps1->capacity == ps1->size)
	{
		ps1->capacity *= 2;
		SLDataType* newa = (SLDataType*)realloc(ps1->a, ps1->capacity * sizeof(SLDataType));
		ps1->a = newa;
	}
	if (ps1->a == NULL)
	{
		printf("capacity fail");
		exit(-1);
	}
}

void SeqListPrint(SL* ps1)
{
	assert(ps1);
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		printf("%d ", ps1->a[i]);
	}
	printf("\n");
}
void SeqListPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);
	SeqListCheck(ps1);
	//依次往后挪一个单位
	for (int i = ps1->size; i > 0; i--)
	{
		ps1->a[i] = ps1->a[i - 1];
	}
	ps1->a[0] = x;
	ps1->size++;
}

void SeqListPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);
	SeqListCheck(ps1);
	//直接插入
	ps1->a[ps1->size] = x;
	ps1->size++;
}

void SeqListPopFront(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	ps1->size--;
}

void SeqListPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	//直接size--就可以了，很多人误以为置为0，其实是错的。
	ps1->size--;
}

int SeqListFind(SL* ps1, SLDataType x)
{
	assert(ps1);
	int i = 0;
	for (i = 0; i < ps1->size; i++)
	{
		if (ps1->a[i] == x)
		{
			printf("找到了,下标是%d\n", i);
			return i;
		}
	}
		printf("查无次数\n");
		return -1;
}
 
void SeqListChange(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(pos >= 1);
	assert(pos <= ps1->size);
	if (ps1->size == 0)
	{
		printf("没有目标数据\n");
		return;
	}
	ps1->a[pos - 1] = x;
}

void SeqListInsert(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(pos > 0);
	int i = 0;
	for (i = ps1->size; i >= pos; i--)
	{
		ps1->a[i] = ps1->a[i - 1];

	}
	ps1->a[pos - 1] = x;
	ps1->size++;
}
void SeqListDelete(SL* ps1, SLDataType x)
{
	assert(ps1);
	int pos = SeqListFind(ps1, x);
	if (pos == -1)
	{
		printf("要删除的数据不存在\n");
		return;
	}
	for (int i = pos; i < ps1->size - 1; i++)
	{
		ps1->a[i] = ps1->a[i + 1];
	}
	ps1->size--;
	printf("删除成功\n");

}



