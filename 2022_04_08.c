#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//交换
void HeapSwap(int* pa,int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//向下调整

AdjustDown(int* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
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
void HeapSort(int* a, int n)
{
	// //向上调整--建堆 O(N*logN)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);
	//}

	 //向下调整--建堆 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	size_t end = n - 1;
	//
	while (end > 0)
	{
		HeapSwap(&a[0], &a[end]);
		//向下调整O(logN)
		AdjustDown(a, end, 0);
		--end;
	}

}
int main()
{
	int a[] = { 4,2,7,8,5,1,0,6 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}