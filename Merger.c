#define _CRT_SECURE_NO_WARNINGS
//TopK问题： 找出N个数里面最大/最小的前K个问题。

//这里实现两个版本：

//1. 找最大的K个元素

//假设堆为小堆

//void PrintTopK(int* a, int n, int k)
//
//{
//
//	Heap hp;
//
//	//建立含有K个元素的堆
//
//	HeapInit(&hp, a, k);
//
//
//
//	for (size_t i = k; i < n; ++i)  // N
//
//	{
//
//		//每次和堆顶元素比较，大于堆顶元素，则删除堆顶元素，插入新的元素
//
//		if (a[i] > HeapTop(&hp)) // LogK
//
//		{
//
//			HeapPop(&hp);
//
//			HeapPush(&hp, a[i]);
//
//		}
//
//	}
//
//	for (int i = 0; i < k; ++i) {
//
//		printf("%d ", HeapTop(&hp));
//
//		HeapPop(&hp);
//
//	}
//
//}
//
//
//
////2. 找最小的K个元素
//
////假设堆为大堆
//
//void PrintTopK(int* a, int n, int k)
//
//{
//
//	Heap hp;
//
//	//建立含有K个元素的堆
//
//	HeapInit(&hp, a, k);
//
//
//
//	for (size_t i = k; i < n; ++i)  // N
//
//	{
//
//		//每次和堆顶元素比较，小于堆顶元素，则删除堆顶元素，插入新的元素
//
//		if (a[i] < HeapTop(&hp)) // LogK
//
//		{
//
//			HeapPop(&hp);
//
//			HeapPush(&hp, a[i]);
//
//		}
//
//	}
//
//	for (int i = 0; i < k; ++i) {
//
//		printf("%d ", HeapTop(&hp));
//
//		HeapPop(&hp);
//
//	}
//
//}
//
//void TestTopk()
//
//{
//
//	int n = 10000;
//
//	int* a = (int*)malloc(sizeof(int) * n);
//
//	srand(time(0));
//
//	//随机生成10000个数存入数组，保证元素都小于1000000
//
//	for (size_t i = 0; i < n; ++i)
//
//	{
//
//		a[i] = rand() % 1000000;
//
//	}
//
//	//确定10个最大的数
//
//	a[5] = 1000000 + 1;
//
//	a[1231] = 1000000 + 2;
//
//	a[531] = 1000000 + 3;
//
//	a[5121] = 1000000 + 4;
//
//	a[115] = 1000000 + 5;
//
//	a[2335] = 1000000 + 6;
//
//	a[9999] = 1000000 + 7;
//
//	a[76] = 1000000 + 8;
//
//	a[423] = 1000000 + 9;
//
//	a[3144] = 1000000 + 10;
//
//
//
//	PrintTopK(int* a, n, 10);
//
//}
//
//希尔排序
//void ShellSort(int* a, int sz)
//{
//	//插入排序
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end+ 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end = end - 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//#include <stdio.h>
//int main()
//{
//	int arr[] = {9,8,7,6,5,4,3,2,1,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	ShellSort(arr, sz);
//	return 0;
//}
//void ShellSort(int* a, int sz)
//{
//	int gap = sz;
//	while (gap >= 1)
//	{
//		gap = gap / 2;
//		for (int i = 0; i < sz - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
void QuickSort()
{
	ST st;
	StackInit(&st);


}