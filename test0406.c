#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"
void testHeap()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 5);
	HeapPush(&hp, 4);
	HeapPush(&hp, 3);
	HeapPush(&hp, 2);
	HeapPush(&hp, 1);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}
void HeapSort(HPDataType* a, int size)
{
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, a[i]);

	}
	size_t j = 0;
	while (!HeapEmpty(&hp))
	{
		a[j] = HeapTop(&hp);
		j++;
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
	
}
int main()
{
	testHeap();
	int a[] = { 4,2,7,8,5,1,0,6 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}