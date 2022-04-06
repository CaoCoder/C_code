#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
//��ʼ���ṹ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
//���ٽṹ��
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
//����
void HeapSwap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//���ϵ���
void AdjustUp(HPDataType* a, size_t child)
{
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			HeapSwap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//�����
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType)* newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	++php->size;
	//���ϵ���
	AdjustUp(php->a, php->size - 1);
}
//���µ���
AdjustDown(HPDataType* a,size_t size, size_t root)
{
	 size_t parent= root;
	 size_t child= parent * 2 + 1;
	 while (child < size)
	 {
		 if (child+1 < size && a[child + 1] < a[child])
		 {
			 ++child;
		 }
		 if (a[child] < a[parent])
		 {
			 HeapSwap(&a[parent], &a[child]);
			 parent = child;
			 child = parent * 2 + 1;
		 }
		 else
		 {
			 break;
		 }
	
	 }	
}
//ɾ���ѵ�ֵ
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	//�����Ѷ��Ͷ�β��ֵ��Ȼ��ɾ����β��ֵ
	HeapSwap(php->a, &php->a[php->size - 1]);
	--php->size;
	//���µ���
	AdjustDown(php->a, php->size, 0);
}
//��ӡ��
void HeapPrint(HP* php)
{
	assert(php);
	for (size_t i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;

}
//������м���Ԫ��
size_t HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
//�õ��Ѷ���ֵ
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}