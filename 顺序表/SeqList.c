#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//销毁
void SeqListDestroy(SeqList* psl)
{
	assert(psl);
	free(psl->a);
	psl ->a = NULL;
	psl->capacity = psl->size = 0;
}
//初始化
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}
//打印
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
//检查是否需要扩容
void SeqListCheckCapacity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		else
		{
			psl->a = tmp;
			psl->capacity =newCapacity;
		}
	}
}
//尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListCheckCapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}
//尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	if (psl->size > 0)
	{
		psl->size--;
	}
}
//头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
//头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	//挪出数据，腾出头部空间
	if (psl->size > 0)
	{
		int begin = 1;
		while (begin < psl->size)
		{
			psl->a[begin - 1] = psl->a[begin];
			++begin;
		}
		--psl->size;
	}
}
//指定位置插入
void SeqListInsert(SeqList* psl, SLDataType pos, SLDataType x)
{
	assert(psl);
	if (pos > psl->size)
	{
		printf("pos越界");
		return;
	}
	else
	{
		int end = psl->size;
		SeqListCheckCapacity(psl);
		while (end > pos)
		{
			psl->a[end] = psl->a[end - 1];
			--end;
		}
		psl->a[pos] = x;
		++psl->size;
	}

}
//指定位置删除O(n)
void SeqListErease(SeqList* psl, SLDataType pos)
{
	assert(psl);
	if (pos > 0 && pos < psl->size)
	{
		int begin = pos;
		while (begin < psl->size)
		{
			psl->a[begin - 1] = psl->a[begin];
			++begin;
		}
		--psl->size;
	}
}
//查找
void SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}
