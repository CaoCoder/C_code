#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void Swap(int* x, int* y)
{
	int t = 0;
	t = *x;
	*x = *y;
	*y = t;
}
void Print(int* a, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
/*最搓之优化后的冒泡排序*/


//void BubbleSort(int* arr, int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < sz - i - 1; ++j)
//		{
//			flag = 1;
//			if (arr[j] > arr[j + 1])
//			{
//				Swap(&arr[j], &arr[j + 1]);
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
/*选择排序*/
//void SelectSort(int* a, int sz)
//{
//	for (int i = 0; i < sz -1; ++i)
//	{
//		int min = i;
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (a[j] < a[min])
//			{
//				min = j;
//			}
//		}
//		Swap(&a[i], &a[min]);
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,6,4,3,2,1,5,4,};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	SelectSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
/*在有序情况下牛逼的插入排序*/
//void InsertSort(int* a, int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,6,4,3,2,1,5,4};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	InsertSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
/*插入排序升级之希尔排序*/
//void ShellSort(int* a, int sz)
//{
//	int gap = sz;
//	while (gap > 1)
//	{
//		gap = gap / 2;
//		for (int i = 0; i < sz - gap; ++i)
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
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	ShellSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
/*交换排序之快速排序递归Hoare版本*/
//int GetMidIndex(int* a, int left, int right)
//{
//	//int mid = (left + right) / 2;
//	int mid = left + (right - left) / 2;
//	// left < mid < right
//	if (a[left] < a[mid])
//	{
//		//left < mid < right
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		// right< left < mid
//		else if (a[left] > a[right])
//		{
//			return left;
//		}
//		// left < right <mid
//		else
//		{
//			return right;
//		}
//	}
//	else // a[left] > a[mid]
//	{
//		// left > mid > right
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		// right > left > mid
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		//left > right > mid
//		else
//		{
//			return right;
//		}
//	}
//}

//int PartSort(int* a, int left, int right)
//{
//	int midi = GetMidIndex(a, left, right);
//	Swap(&a[midi], &a[left]);
//	int key = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[left], &a[key]);
//	return left;
//}
/*快速排序指针递归版本*/
//int PartSort(int* a, int left, int right)
//{
//	int midi = GetMidIndex(a, left, right);
//	Swap(&a[midi], &a[left]);
//	int keyi = left;
//	int prev = left;
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi])
//		{
//			++prev;
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[prev], &a[keyi]);
//
//	return prev;
//}
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//	int div = PartSort(a, left, right);
//	QuickSort(a, left, div - 1);
//	QuickSort(a, div + 1, right);
//}
//int main()
//{
//	int arr[] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	QuickSort(arr, 0, sz - 1);
//	Print(arr, sz);
//	return 0;
//}
/*归并排序递归版本*/
//void _mergeSort(int* a, int left, int right, int* tmp)
//{
//	//分离
//	if (left >= right)
//		return;
//	int mid = right - ((right - left) >> 1);
//	_mergeSort(a, left, mid - 1, tmp);
//	_mergeSort(a, mid, right, tmp);
//	//合并
//	int begin1 = left, end1 = mid - 1;
//	int begin2 = mid, end2 = right;
//	int begin = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[begin++] = a[begin1++];
//		}
//		else
//		{
//			tmp[begin++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[begin++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[begin++] = a[begin2++];
//	}
//	//拷贝到a数组里面
//	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//}
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	_mergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	MergeSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}
/*排升序 建大堆堆排序*/
void AdjustDown(int* a, int n)
{
	
}
void HeapSort(int* a, int n)
{
	AdjustDown();
} 
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	Print(arr, sz);
	return 0;
}
/*快速排序非递归*/

/*归并排序非递归*/