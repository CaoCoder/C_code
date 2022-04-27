//#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////// 希尔排序
////void InsertSort(int* a, int n)
////{
////	int gap = n;
////	
////	while (gap > 1)
////	{
////		//先进行预排序。直到gap为1.直接插入排序。
////		gap = gap / 2;
////		for (int i = 0; i < n - gap; i++)
////		{
////			//单趟排序
////			int end = i;
////			int tmp = a[end + gap];
////			while (end >= 0)
////			{
////				if (tmp < a[end])
////				{
////					a[end + gap] = a[end];
////					end = end - gap;
////				}
////				//前面有序了，所以直接跳出循环，插入即ok
////				else
////				{
////					break;
////				}
////			}
////			a[end + gap] = tmp;
////		}
////	}
////}
////int main()
////{
////	int arr[] = {9,8,7,6,5,4,3,2,1,0};
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	// 插入排序
////	InsertSort(arr, sz);
////	return 0;
////}
////堆排序
//#include<stdio.h>
//void swap(int* x, int* y)
//{
//	int t = 0;
//	t = *x;
//	*x = *y;
//	*y = t;
//}
//void AdjustUp(int* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] < a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//	
//}
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//选出左右孩子小的那个
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		//2.如果父亲大于孩子，则交换，并继续往下调整父亲。
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			//向下调整父母，因为需要保证下面的树是小堆
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	//向上调整建堆
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//	//向下调整建堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//int main()
//{
//	int arr[] = { 4,2,7,8,5,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//}