#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
//初始化结构体
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
//销毁结构体
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}
//交换
void HeapSwap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//向上调整
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

//插入堆
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
	//向上调整
	AdjustUp(php->a, php->size - 1);
}
//向下调整
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
//删除堆的值
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	//交换堆顶和堆尾的值。然后删除堆尾的值
	HeapSwap(php->a, &php->a[php->size - 1]);
	--php->size;
	//向下调整
	AdjustDown(php->a, php->size, 0);
}
//打印堆
void HeapPrint(HP* php)
{
	assert(php);
	for (size_t i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
//判断堆是否为空
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;

}
//求堆中有几个元素
size_t HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
//得到堆顶的值
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}