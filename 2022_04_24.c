#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void BubbleSort(int* a, int n)
{
	int i = 0;
	int tag = 1;
	for (i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tag = 0;
				int t = 0;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (tag == 1)
		{
			break;
		}
	}
}
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void BubbleTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	Print(arr, n);
}

void swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] > a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[key], &a[left]);

	return left;
}
// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int pit = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[pit] = a[right];
		pit = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[pit] = a[left];
		pit = left;
	}
	a[pit] = key;

	return pit;
}
//前后指针法(最新优化版本)
int PartSort3(int* a, int left, int right)
{
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		
		if (a[cur] < a[key] && a[++prev] != a[cur])
		{
			swap(&a[cur], &a[prev]);

		}
		++cur;

	}
	swap(&a[prev], &a[key]);

	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (right - left < 1)
		return;
	//int div = PartSort1(a, left, right);
	//int div = PartSort2(a, left, right);
	int div = PartSort3(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
void QuickTest()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0};
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	//int arr[] = { 6,1,2,7,9,3,4,5,10,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, n - 1);
}
int main()
{
	//冒泡排序
	//BubbleTest();
	//快速排序
	QuickTest();
	return 0;
}
