#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//void NMergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	int gap = 1;
//	while (gap < n)
//	{
//		//间隔为gap的是一组，两两归并
//		for (int i = 0; i < n; i = i + gap * 2)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + gap * 2 - 1;
//			//end1越界修正。
//			if (end1 >= n)
//				end1 = n - 1;
//			//begin2 越界,让第二个区间不存在
//			if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			//begin2 ok,end2越界,修正end2即可
//			if (begin2 < n && end2 >= n)
//				end2 = n - 1;
//			int index = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//					tmp[index++] = a[begin1++];
//				else
//					tmp[index++] = a[begin2++];
//			}
//			while (begin1 <= end1)
//				tmp[index++] = a[begin1++];
//			while (begin2 <= end2)
//				tmp[index++] = a[begin2++];
//		}
//		memcpy(a, tmp, n * sizeof(int));
//		gap = gap * 2;
//	}
//	free(tmp);
//}
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	NMergeSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
#include <stdio.h>
//void CountSort(int* a, int n)
//{
//	int min = a[0], max = a[0];
//	for (int i = 1; i < n; ++i)
//	{
//		if (a[i] < min)
//			min = a[i];
//		if (a[i] > max)
//			max = a[i];
//	}
//	int range = max - min + 1;
//	int* countA = (int*)malloc(sizeof(int) * range);
//	memset(countA, 0, sizeof(int) * range);
//	//计数
//	for (int i = 0; i < n; ++i)
//	{
//		countA[a[i] - min]++;
//	}
//	//排序
//	int j = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while (countA[i]--)
//		{
//			a[j++] = i + min;
//		}
//	}
//}
#include <assert.h>
#include <stdlib.h>
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	assert(countA);
	memset(countA, 0, sizeof(int) * range);

	// 计数
	for (int i = 0; i < n; ++i)
	{
		countA[a[i] - min]++;
	}

	// 排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}
}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, sz);
	Print(arr, sz);
	return 0;
}