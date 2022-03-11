#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
//����
void SeqListDestroy(SeqList* psl)
{
	assert(psl);
	free(psl->a);
	psl ->a = NULL;
	psl->capacity = psl->size = 0;
}
//��ʼ��
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}
//��ӡ
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
//����Ƿ���Ҫ����
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
//β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListCheckCapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}
//βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	if (psl->size > 0)
	{
		psl->size--;
	}
}
//ͷ��
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
//ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	//Ų�����ݣ��ڳ�ͷ���ռ�
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
//ָ��λ�ò���
void SeqListInsert(SeqList* psl, SLDataType pos, SLDataType x)
{
	assert(psl);
	if (pos > psl->size)
	{
		printf("posԽ��");
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
//ָ��λ��ɾ��O(n)
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
//����
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
